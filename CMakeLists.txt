cmake_minimum_required(VERSION 2.8)

project(cmocka-init)

# Download and build cmocka
include(cmocka.cmake)

# Enable ctest helpers
enable_testing()

# Include cmocka headers and linkerset headers
#target_include_directories(simple_init PRIVATE ${CMOCKA_INCLUDE_DIR} include)
include_directories(${CMOCKA_INCLUDE_DIR} include)

# Build simple test
add_executable(simple test_main.c simple.c more.c)
target_link_libraries(simple cmocka)
add_test(simple simple)

# Build alignment test
add_executable(alignment test_alignment.c simple.c more.c ordered.c)
target_link_libraries(alignment cmocka)
add_test(alignment alignment)
