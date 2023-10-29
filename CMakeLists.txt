cmake_minimum_required(VERSION 3.15)
project(rayshooter)
set(CMAKE_C_STANDARD 11) # Requires C11 standard

find_package(raylib 4.2 REQUIRED) # Requires at least version 3.0

add_executable(${PROJECT_NAME} rayshooter.c)

target_link_libraries(${PROJECT_NAME} raylib)

#add assets
target_compile_definitions(${PROJECT_NAME} PUBLIC SOUND_PATH="${CMAKE_CURRENT_SOURCE_DIR}/sound/") 
target_compile_definitions(${PROJECT_NAME} PUBLIC SPRITE_PATH="${CMAKE_CURRENT_SOURCE_DIR}/sprite/")