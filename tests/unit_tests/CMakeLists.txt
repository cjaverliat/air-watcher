include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME}_unit_tests
        ServicesTest.cpp
        UtilsTest.cpp
        ParsingTest.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}_unit_tests gtest gtest_main)
target_link_libraries(${CMAKE_PROJECT_NAME}_unit_tests ${CMAKE_PROJECT_NAME}_lib)