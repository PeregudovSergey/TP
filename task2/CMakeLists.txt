cmake_minimum_required(VERSION 3.10)

project(TASK_TP2)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

execute_process(COMMAND python3 ${PROJECT_SOURCE_DIR}/A/preparing.py 
				WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

set(MAIN_SOURCE ${PROJECT_SOURCE_DIR}/C/main.cpp)

include_directories(${PROJECT_SOURCE_DIR}/B)

add_subdirectory(B)

add_executable(C ${MAIN_SOURCE}) 

target_link_libraries(C MyLib)

