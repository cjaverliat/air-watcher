project(${CMAKE_PROJECT_NAME}_lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/application/service/CSVParser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/application/service/Services.cpp

        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Catalog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Cleaner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Coordinates.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Measure.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Sensor.cpp

        application/data/actor/Actor.cpp
        application/data/actor/Decider.cpp
        application/data/actor/PrivateIndividual.cpp
        application/data/actor/Provider.cpp
        application/data/actor/SuperUser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/Utils.cpp)

set(HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/application/service/CSVParser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/application/service/Services.h

        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Catalog.h
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Cleaner.h
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Coordinates.h
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Measure.h
        ${CMAKE_CURRENT_SOURCE_DIR}/application/data/Sensor.h

        application/data/actor/Actor.h
        application/data/actor/Decider.h
        application/data/actor/PrivateIndividual.h
        application/data/actor/Provider.h
        application/data/actor/SuperUser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/utils/Utils.h)

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})

target_link_libraries(${CMAKE_PROJECT_NAME}_lib gtest)

add_executable(${CMAKE_PROJECT_NAME}_run presentation/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_run ${CMAKE_PROJECT_NAME}_lib)