cmake_minimum_required(VERSION 3.1)

project(cmocka-init)

# Download and build cmocka
include(cmocka.cmake)

# Build all local C files
file(GLOB SRC *.c)

# Name of executable
add_executable(simple_init ${SRC})

# Include cmocka headers and linkerset headers
target_include_directories(simple_init PRIVATE ${CMOCKA_INCLUDE_DIR} include)

# Link to cmocka
target_link_libraries(simple_init cmocka)

# Enable ctest helpers
enable_testing()
add_test(init simple_init)
