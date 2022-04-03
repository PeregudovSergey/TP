cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
#set(CMAKE_SKIP_BUILD_RPATH FALSE)
#set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
#set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

project(SimpleLibrary)

include_directories(include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)
target_link_libraries(MainLib buffer)


install(TARGETS Main DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS MainLib DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(TARGETS buffer DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(TARGETS buffer MainLib PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(DIRECTORY ${SimpleLibrary_SOURCE_DIR}/src ${SimpleLibrary_SOURCE_DIR}/include DESTINATION ${CMAKE_INSTALL_PREFIX})

set_target_properties(MainLib PROPERTIES INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}")
