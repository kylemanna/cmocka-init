#include <cmocka_init.h>

TEST(Simple_Life)
{
    (void)state; /* silence unused warnings */

    const int answer_to_question_of_life = 42;

    assert_true(42 == answer_to_question_of_life);
}
