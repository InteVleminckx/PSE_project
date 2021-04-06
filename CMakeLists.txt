cmake_minimum_required(VERSION 3.6)

project(Project_software_engeneering)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS "-Wall -Werror")
set(CMAKE_EXE_LINKER_FLAGS -pthread)

# Set include dir
include_directories(gtest/include)

# Set Library dir
link_directories(gtest/lib)

# Set source files for RELEASE target
set(RELEASE_SOURCE_FILES
        RunSimilatie.cpp
        FileParser.cpp
        FileParser.h
        Vaccinatiecentrum.cpp
        Vaccinatiecentrum.h
        Transport.cpp
        Transport.h
        DesignByContract.h
        Hub.cpp
        Hub.h
        Vaccin.cpp
        Vaccin.h
        )

# Set source files for DEBUG target
set(DEBUG_SOURCE_FILES
        SimulatieTests.cpp
        FileParser.cpp
        FileParser.h
        Vaccinatiecentrum.cpp
        Vaccinatiecentrum.h
        Transport.cpp
        Transport.h
        DesignByContract.h
        InputTests.cpp
        SystemTests.cpp
        UnitTests.cpp
        Hub.cpp
        Hub.h
        Vaccin.cpp
        Vaccin.h
        SimulatieUtils.cpp SimulatieUtils.h)

# Create RELEASE target
add_executable(ttt ${RELEASE_SOURCE_FILES}
        RunSimilatie.cpp
        FileParser.cpp
        FileParser.h
        TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp
        TinyXML/tinyxml.h
        TinyXML/tinyxml.cpp
        TinyXML/tinystr.h
        TinyXML/tinystr.cpp
        Hub.cpp
        Hub.h
        )

# Create DEBUG target
add_executable(ttt_debug ${DEBUG_SOURCE_FILES}
        SimulatieTests.cpp
        InputTests.cpp
        SystemTests.cpp
        UnitTests.cpp
        Hub.cpp
        Hub.h
        FileParser.cpp
        FileParser.h
        TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp
        TinyXML/tinyxml.h
        TinyXML/tinyxml.cpp
        TinyXML/tinystr.h
        TinyXML/tinystr.cpp
        )

# Link library
target_link_libraries(ttt_debug gtest)