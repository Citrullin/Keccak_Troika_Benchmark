cmake_minimum_required(VERSION 3.0)
project(troika_benchmark)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

find_package(Threads)

set(TROIKA_SOURCE_FILES
        iota/src/iota/transfers.c
        iota/src/iota/bundle.c
        iota/src/iota/addresses.c
        iota/src/iota/signing.c
        iota/src/iota/kerl.c
        troika/src/troika.c
        troika/src/ftroika.c
        ternary_troika.c)

set(KECCAK_SOURCE_FILES
        iota/src/keccak/sha3.c
        binary_keccak.c
        )

include_directories(
        troika/src/
        iota/src/iota
        iota/src/keccak
        iota/src/
)

execute_process(
        COMMAND bash "-c" "build_iota.sh"
)

add_executable(keccak_benchmark ${KECCAK_SOURCE_FILES})
target_link_libraries (keccak_benchmark ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(keccak_benchmark ${CMAKE_SOURCE_DIR}/iota/build/libiota.a)

add_executable(troika_benchmark ${TROIKA_SOURCE_FILES})
target_link_libraries (troika_benchmark ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(troika_benchmark ${CMAKE_SOURCE_DIR}/iota/build/libiota.a)