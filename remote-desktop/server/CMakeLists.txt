project(server.bin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Weffc++ -Wextra -Wconversion -Wsign-conversion")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/build)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c" "src/*.h")
add_executable(server.bin ${SOURCES})
set_target_properties(server.bin PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

if(APPLE)
    target_link_libraries(server.bin "-framework CoreGraphics" "-framework CoreFoundation")
endif()
