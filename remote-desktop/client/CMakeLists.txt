set(TARGET_NAME "client.bin")

project(${TARGET_NAME})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Weffc++ -Wextra -Wconversion -Wsign-conversion")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "src/*.h")
add_executable(${TARGET_NAME} ${SOURCES})
set_target_properties(${TARGET_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set(SDL2_LIBRARIES "/Library/Frameworks/SDL2.framework")
set(SDL2_IMAGE "/Library/Frameworks/SDL2_image.framework")

target_link_libraries(${TARGET_NAME} ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
