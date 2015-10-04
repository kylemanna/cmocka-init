/*
 * Simple linker set wrapper to automatically build the cmocka unit tests lists
 *
 * Author: Kyle Manna <kyle[at]kylemanna[d0t]com>
 *
 * Inspiration from linkerset.h:
 * https://chromium.googlesource.com/chromiumos/third_party/adhd/+/factory-1235.B/gavd/linkerset.h
 * https://gist.github.com/96a5905a42afeaee92f1
 */
#pragma once

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "linkerset.h"

/*
 * Usage: TEST(name) { ... }
 */
#define TEST(n) static void n(void** state); \
        static cmocka_init_t test_##n = cmocka_unit_test(n); \
        LINKERSET_ADD_ITEM(cmocka_init, test_##n); \
        static void n(void** state)

typedef struct CMUnitTest cmocka_init_t;

LINKERSET_DECLARE(cmocka_init);
