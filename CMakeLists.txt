cmake_minimum_required(VERSION 3.10)

project(Disease_propagation)

file(GLOB PROJ_SRC
    "sources/*.cpp"
    "includes/*.h"
)

if ((NOT DEFINED VCPKG_TARGET_TRIPLET) AND ("${CMAKE_CXX_COMPILER}" MATCHES  g\\+\\+\\.exe) AND (${CMAKE_SIZEOF_VOID_P} EQUAL 4))
    message("Configuiration pour MinGW 32")
    set(SFML_DIR "${CMAKE_SOURCE_DIR}/dependencies/SFML/lib/cmake/SFML" CACHE FILEPATH "The directory containing a CMake configuration file for SFML.")
endif()

if(WIN32)
    set(SFML_MAIN sfml-main)
endif(WIN32)

add_executable(Disease_propagation ${PROJ_SRC})
target_include_directories(Disease_propagation PRIVATE ${CMAKE_SOURCE_DIR}/includes)

find_package(SFML COMPONENTS system window graphics REQUIRED)
target_link_libraries(Disease_propagation PRIVATE     
        sfml-system
        ${SFML_MAIN}
        sfml-window
        sfml-graphics
    )
target_include_directories(Disease_propagation PRIVATE ${SFML_INCLUDE_DIR})
