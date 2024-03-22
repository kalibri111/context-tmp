include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/58d77fa8070e8cec2dc1ed015d66b454c8d78850.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


add_executable(tests stress.cpp unit.cpp)

target_link_libraries(tests PRIVATE switch_context gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)