cmake_minimum_required(VERSION 3.10)
project(airwatcher)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror -Wfatal-errors")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(SOURCES
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/metier/service/CSVParser.cpp
        ${PROJECT_SOURCE_DIR}/metier/service/Services.cpp

        ${PROJECT_SOURCE_DIR}/metier/data/Catalog.cpp
        ${PROJECT_SOURCE_DIR}/metier/data/Cleaner.cpp
        ${PROJECT_SOURCE_DIR}/metier/data/Coordinates.cpp
        ${PROJECT_SOURCE_DIR}/metier/data/Measure.cpp
        ${PROJECT_SOURCE_DIR}/metier/data/Sensor.cpp

        ${PROJECT_SOURCE_DIR}/metier/acteurs/Actor.cpp
        ${PROJECT_SOURCE_DIR}/metier/acteurs/Decider.cpp
        ${PROJECT_SOURCE_DIR}/metier/acteurs/PrivateIndividual.cpp
        ${PROJECT_SOURCE_DIR}/metier/acteurs/Provider.cpp
        ${PROJECT_SOURCE_DIR}/metier/acteurs/SuperUser.cpp
        )

set(HEADERS
        ${PROJECT_SOURCE_DIR}/metier/service/CSVParser.h
        ${PROJECT_SOURCE_DIR}/metier/service/Services.h

        ${PROJECT_SOURCE_DIR}/metier/data/Catalog.h
        ${PROJECT_SOURCE_DIR}/metier/data/Cleaner.h
        ${PROJECT_SOURCE_DIR}/metier/data/Coordinates.h
        ${PROJECT_SOURCE_DIR}/metier/data/Measure.h
        ${PROJECT_SOURCE_DIR}/metier/data/Sensor.h

        ${PROJECT_SOURCE_DIR}/metier/acteurs/Actor.h
        ${PROJECT_SOURCE_DIR}/metier/acteurs/Decider.h
        ${PROJECT_SOURCE_DIR}/metier/acteurs/PrivateIndividual.h
        ${PROJECT_SOURCE_DIR}/metier/acteurs/Provider.h
        ${PROJECT_SOURCE_DIR}/metier/acteurs/SuperUser.h
        utils/Utils.h)

# Copy resources
file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(airwatcher ${SOURCES} ${HEADERS})