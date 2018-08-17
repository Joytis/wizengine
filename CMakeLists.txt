cmake_minimum_required(VERSION 3.3)
project(wizengine)

# set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Os -Wall")

#set(SDL2_IMAGE_LIBRARY_DIR /usr/local/Cellar/sdl2_image/2.0.1_1/lib)

# Opts and stuff
#======================================================================
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Platform Variables
#======================================================================
if(UNIX)
    # set(SDL2_IMAGE_LIBRARY_DIR /usr/local/Cellar/sdl2_image/2.0.5/lib)
elseif(MINGW)
    set(SDL2_IMAGE_LIBRARY_DIR C:/MinGW/lib)
endif()

#
# Source Includes
#=======================================================================
file(GLOB_RECURSE CORE_SOURCES ${PROJECT_SOURCE_DIR}/core/src/*.cpp)
file(GLOB_RECURSE CORE_HEADERS ${PROJECT_SOURCE_DIR}/core/include/*.hpp)
file(GLOB_RECURSE TEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/src/*.cpp)


#
# Directories for libraries     
#=======================================================================
# if(MINGW)
#     set(BOOST_ROOT    "C:/MinGW")
#     set(SDL2_ROOT     "C:/MinGW")
#     set(SDL2_Includes "${SDL2_ROOT}/include")
#     set(SDL2_LibDir   "${SDL2_ROOT}/lib")
#     # imported targets for CMake (cf. https://cmake.org/Wiki/CMake/Tutorials/Exporting_and_Importing_Targets)
#     add_library(SDL2        STATIC IMPORTED)
#     add_library(SDL2main    STATIC IMPORTED)
#     add_library(SDL2_image  STATIC IMPORTED)
#     set_property(TARGET SDL2        PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2.a")
#     set_property(TARGET SDL2main    PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2main.a")
#     set_property(TARGET SDL2_image  PROPERTY IMPORTED_LOCATION "${SDL2_LibDir}/libSDL2_image.a")
#     set(SDL2_IMAGE_LIBS SDL2_image)

#     set(SDL2_LIBRARIES mingw32 SDL2 SDL2main m dinput8 dxguid dxerr8 user32 gdi32 winmm imm32 ole32 oleaut32 shell32 version uuid)

# else()
#     find_package(SDL2 REQUIRED)
#     set(SDL2_LIBRARIES "-L${SDL2_LIBDIR} -lSDL2 -lSDL2main")
#     set(SDL2_IMAGE_LIBS "-L${SDL2_IMAGE_LIBRARY_DIR} -lSDL2_image")
# endif()

find_package(SFML REQUIRED)
# set(SDL2_LIBRARIES "-L${SDL2_LIBDIR} -lSDL2 -lSDL2main")
# set(SDL2_IMAGE_LIBS "-L${SDL2_IMAGE_LIBRARY_DIR} -lSDL2_image")

find_package(Boost REQUIRED)

#
# Includes
#=====================================================================
include_directories(
    ${SFML_INCLUDE_DIR} 
    ${Boost_INCLUDE_DIRS}
)

#
# Includes
#=====================================================================
add_subdirectory(${PROJECT_SOURCE_DIR}/core)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
