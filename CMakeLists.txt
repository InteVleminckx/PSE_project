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
        Source_files/RunSimilatie.cpp
        Source_files/FileParser.cpp
        Header_files/FileParser.h
        Source_files/Vaccinatiecentrum.cpp
        Header_files/Vaccinatiecentrum.h
        Source_files/Transport.cpp
        Header_files/Transport.h
        Header_files/DesignByContract.h
        Source_files/Hub.cpp
        Header_files/Hub.h
        Source_files/Vaccin.cpp
        Header_files/Vaccin.h
        )

# Set source_files for DEBUG target
set(DEBUG_SOURCE_FILES
        Source_files/SimulatieTests.cpp
        Source_files/FileParser.cpp
        Header_files/FileParser.h
        Source_files/Vaccinatiecentrum.cpp
        Header_files/Vaccinatiecentrum.h
        Source_files/Transport.cpp
        Header_files/Transport.h
        Header_files/DesignByContract.h
        Source_files/InputTests.cpp
        Source_files/SystemTests.cpp
        Source_files/UnitTests.cpp
        Source_files/Hub.cpp
        Header_files/Hub.h
        Source_files/Vaccin.cpp
        Header_files/Vaccin.h
        Source_files/SimulatieUtils.cpp
        Header_files/SimulatieUtils.h
        Source_files/Distributie.cpp
        Header_files/Distributie.h
        )

# Create RELEASE target
add_executable(ttt ${RELEASE_SOURCE_FILES}
        Source_files/RunSimilatie.cpp
        Source_files/FileParser.cpp
        Header_files/FileParser.h
        TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp
        TinyXML/tinyxml.h
        TinyXML/tinyxml.cpp
        TinyXML/tinystr.h
        TinyXML/tinystr.cpp
        Source_files/Hub.cpp
        Header_files/Hub.h
        )

# Create DEBUG target
add_executable(ttt_debug ${DEBUG_SOURCE_FILES}
        Source_files/SimulatieTests.cpp
        Source_files/InputTests.cpp
        Source_files/SystemTests.cpp
        Source_files/UnitTests.cpp
        Source_files/Hub.cpp
        Header_files/Hub.h
        Source_files/FileParser.cpp
        Header_files/FileParser.h
        TinyXML/tinyxmlparser.cpp
        TinyXML/tinyxmlerror.cpp
        TinyXML/tinyxml.h
        TinyXML/tinyxml.cpp
        TinyXML/tinystr.h
        TinyXML/tinystr.cpp
        )

# Link library
target_link_libraries(ttt_debug gtest)