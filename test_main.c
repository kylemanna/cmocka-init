#include <cmocka_init.h>

int main(void)
{
    const size_t len = LINKERSET_SIZE(cmocka_init, size_t);

    struct CMUnitTest **tests = LINKERSET_START(cmocka_init);

    if (!len)
        return EXIT_FAILURE;

    return _cmocka_run_group_tests("a", *tests, len, NULL, NULL);
}
