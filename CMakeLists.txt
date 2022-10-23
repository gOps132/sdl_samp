#
#   Made by Epilan Gian Cedrick G.
#
cmake_minimum_required(VERSION 3.17)

project(SDL_SAMP 
		VERSION 1.0.0
		DESCRIPTION "SDL Demo"
		LANGUAGES CXX
)

set(TARGET_NAME ${PROJECT_NAME})

set(SDL_SAMP_SOURCE_FILES
	src/main.cpp
)

# ------------------------------------------
# FIND LIBRARIES
# ------------------------------------------
INCLUDE(FindPkgConfig)

find_package(SDL2 REQUIRED sdl2)

# ------------------------------------------
# GENERATE EXECUTABLE
# ------------------------------------------
add_executable(${TARGET_NAME}  ${SDL_SAMP_SOURCE_FILES})


# ------------------------------------------
# TARGET PROPERTIES
# ------------------------------------------
target_include_directories(${TARGET_NAME}
	PUBLIC ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${TARGET_NAME}
	PUBLIC	${SDL2_LIBRARIES}
)

set_target_properties(${TARGET_NAME} PROPERTIES 
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}-${CMAKE_BUILD_TYPE}"
)