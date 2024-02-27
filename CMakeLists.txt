cmake_minimum_required(VERSION 3.5)
project(main C CXX)

set(CMAKE_CXX_STANDARD 11)

# Setting parameters for OpenGL
set(OpenGL_GL_PREFERENCE GLVND)

# Setting parameters for raylib
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # or games

add_subdirectory(libs/raylib)

add_executable(${PROJECT_NAME}
	src/main.cpp
	src/core.cpp
	src/scene.cpp
	src/entity.cpp
	src/myscene.cpp
	src/player.cpp
	src/block.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
file(
	COPY assets
	DESTINATION ${CMAKE_BINARY_DIR}
)