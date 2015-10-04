# Linker set wrapper for cmocka unit test framework

Wrapper to simplify the use of *cmocka* by using linker sets (aka linker sections with function pointers).  Linker set header that makes the magic happen is form a random branch related to the chromium project.

See `test_simple.c` and `test_more.c` for examples of how to easily add *cmocka* tests.

## Building

    mkdir build
    cd build
    cmake ..
    make

The included `cmocka.cmake` file contains an external project that will download and build *cmocka* locally.  Automagically.

## Testing

Directly

    cd build
    ./simple_init

Or leverage ctest:

    ctest -V

Expected output:

    $ ctest -V
    Constructing a list of tests
    Done constructing a list of tests
    Checking test dependency graph...
    Checking test dependency graph end
    test 1
       Start 1: init

    1: Test command: cmocka-init/build/simple_init
    1: Test timeout computed to be: 9.99988e+06
    1: [==========] Running 2 test(s).
    1: [ RUN      ] Simple_Init
    1: [       OK ] Simple_Init
    1: [ RUN      ] Simple_Life
    1: [       OK ] Simple_Life
    1: [==========] 2 test(s) run.
    1: [  PASSED  ] 2 test(s).
    1/1 Test #1: init .............................   Passed    0.00 sec

    100% tests passed, 0 tests failed out of 1

    Total Test time (real) =   0.00 sec

## Celebrate

Drink!  [Or buy me a drink](http://kylemanna.tip.me)!
