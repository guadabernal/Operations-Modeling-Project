project (Graph)
include_directories(include)
file(GLOB SOURCES "sample/*c" "src/*.c")

add_executable(test ${SOURCES})

