#include <stdlib.h>

#include <cmocka_init.h>

int main(void)
{
    /* Declare access to linker sections */
    extern struct CMUnitTest* __start_cmocka_init;
    extern struct CMUnitTest* __stop_cmocka_init;
    __asm__(".global __start_cmocka_init");
    __asm__(".global __stop_cmocka_init");

    struct CMUnitTest* start = (struct CMUnitTest*)&__start_cmocka_init;
    struct CMUnitTest* stop  = (struct CMUnitTest*)&__stop_cmocka_init;
    const size_t len = stop - start;

    if (!len)
        return EXIT_FAILURE;

    return _cmocka_run_group_tests("a", start, len, NULL, NULL);
}
