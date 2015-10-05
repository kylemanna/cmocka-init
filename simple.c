#include <cmocka_init.h>

TEST(Simple_Init)
{
    (void)state; /* silence unused warnings */

    const int lucky_number = 0xbabecafe;

    assert_true(0xbabecafe == lucky_number);
}
