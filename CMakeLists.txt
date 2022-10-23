#
#   Made by Epilan Gian Cedrick G.
#
cmake_minimum_required(VERSION 3.17)

project(SDL_SAMP 
		VERSION 1.0.0
		DESCRIPTION "SDL Demo"
		LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(TARGET_NAME ${PROJECT_NAME})

set(SDL_SAMP_SOURCE_FILES
	src/main.cpp
)

# ------------------------------------------
# FIND LIBRARIES
# ------------------------------------------
set( SDL_STATIC ON CACHE BOOL "" FORCE )
set( SDL_SHARED OFF CACHE BOOL "" FORCE )
# 'external/sdl' should point at a SDL
# repo clone or extracted release tarball
add_subdirectory( lib/SDL2 )

# ------------------------------------------
# GENERATE EXECUTABLE
# ------------------------------------------
add_executable(${TARGET_NAME} ${SDL_SAMP_SOURCE_FILES})

# ------------------------------------------
# TARGET PROPERTIES
# ------------------------------------------
target_link_libraries(${TARGET_NAME}
	PUBLIC SDL2main 
	PUBLIC SDL2-static
)

set_target_properties(${TARGET_NAME} PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)