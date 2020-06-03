include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME}_validation_tests ValidationTests.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}_validation_tests gtest gtest_main)
target_link_libraries(${CMAKE_PROJECT_NAME}_validation_tests ${CMAKE_PROJECT_NAME}_lib)