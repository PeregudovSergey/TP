cmake_minimum_required(VERSION 3.10)

project(TASK_TP2)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

set(MAIN_SOURCE ${PROJECT_SOURCE_DIR}/C/main.cpp)
set(MAIN_TEST ${PROJECT_SOURCE_DIR}/C/main_test.cpp)
set(TEST ${PROJECT_SOURCE_DIR}/C/test.cpp)

execute_process(COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py 
				WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

include_directories(${PROJECT_SOURCE_DIR}/B)

add_subdirectory(B)

add_executable(C ${MAIN_SOURCE}) 

target_include_directories(C PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(C MyLib)


include(GoogleTest)
add_executable(CTest ${MAIN_TEST} ${TEST}) 
target_link_libraries(CTest ${GTEST_LIBRARIES})
target_link_libraries(CTest gmock gtest pthread)
target_link_libraries(CTest MyLib)
target_include_directories(CTest PUBLIC ${PROJECT_SOURCE_DIR})