#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <cmocka_init.h>

int main(void)
{
    extern struct CMUnitTest* __start_cmocka_init;
    extern struct CMUnitTest* __stop_cmocka_init;
    __asm__(".global __start_cmocka_init");
    __asm__(".global __stop_cmocka_init");

    struct CMUnitTest* start = (struct CMUnitTest*)&__start_cmocka_init;
    struct CMUnitTest* stop  = (struct CMUnitTest*)&__stop_cmocka_init;
    const size_t len = stop - start;

    if (!len)
        return EXIT_FAILURE;


    /* FIXME: linker is linking 32 byte struct CMUnitTest on 64 byte boundaries
     * with clang -fsanitize=address, gcc seems (good or bad)
     *
     * Review memory map with `nm -n ./alignment`
     */
    {
        extern struct CMUnitTest* test_Test0;
        extern struct CMUnitTest* test_Test1;
        //printf("test_Test0 = %p\n", &test_Test0);
        //printf("test_Test1 = %p\n", &test_Test1);
        size_t offset = (size_t)&test_Test1 - (size_t)&test_Test0;
        size_t size = sizeof(struct CMUnitTest);
        printf("offset = 0x%lx\n", offset);
        printf("size = 0x%lx\n", size);
        assert(offset == size);

        struct CMUnitTest* test = start;
        while (test < stop) {
            printf("test = %p\n", test);
            printf("name = %s\n", test->name);
            test++;
        }

    }

    return _cmocka_run_group_tests("a", start, len, NULL, NULL);
}
