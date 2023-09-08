cmake_minimum_required (VERSION 3.25.3)
project (main CXX)

SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
SET(CMAKE_CXX_COMPILER "g++") # compiler
set(CMAKE_CXX_STANDARD 20) # cpp version
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
SET(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES  ${CMAKE_CXX_IMPLICIT_INCLUDE_DIRECTORIES})
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

# folders where a header files (.h, .hpp)
include_directories(include)
include_directories(usr/include)

# source files location (.c, .cpp)
file(GLOB_RECURSE SRC src/*.cpp)
add_executable(main ${SRC})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# dpp library, can't install so its used without installing
add_library(DPP SHARED IMPORTED) 

# tell cmake where dpp library is
set_target_properties(DPP PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/usr/lib/libdpp.so) 

# openssl and zlib are supported by cmake
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED) 

# here happens linking
# there's no official support for sodium or opus in cmake, but nix installs packages from nixpkgs so opus and sodium are installed
# basically it does "-lopus -lsodium" in compiler 
target_link_libraries(main DPP OpenSSL::SSL OpenSSL::Crypto ZLIB::ZLIB opus sodium)

add_custom_target(
	copy-compile-commands ALL
	${CMAKE_COMMAND} -E copy_if_different
	${CMAKE_BINARY_DIR}/compile_commands.json
	${CMAKE_CURRENT_LIST_DIR}
) 