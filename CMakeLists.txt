#build for markturn

cmake_minimum_required(VERSION 3.18.4)

project(markturn VERSION "1.0.0")

option(LINK_STATIC "Build with static library" OFF)

#find curl
find_package(CURL REQUIRED)
message("-- curl include: " ${CURL_INCLUDE_DIR})
message("-- curl library: " ${CURL_LIBRARY})

#find libxml2
find_package(LibXml2 REQUIRED)
message("-- LibXml2 include: " ${LIBXML2_INCLUDE_DIR})
message("-- LibXml2 library: " ${LIBXML2_LIBRARY})

#find YAML
find_package(yaml-cpp REQUIRED)
set(YAML_DIR "/usr/include/yaml-cpp")
set(YAML_LIBRARY "/usr/lib/x86_64-linux-gnu/libyaml-cpp.so")
message("-- YAML include: " ${YAML_DIR})
message("-- YAML library: " ${YAML_LIBRARY})

#Find JSON
find_package(jsoncpp REQUIRED)
set(JSON_DIR "/usr/include/jsoncpp")
set(JSON_LIBRARY "/usr/lib/x86_64-linux-gnu/libjsoncpp.so")
message("-- JSON include: " ${JSON_DIR})
message("-- JSON library: " ${JSON_LIBRARY})

#
set(LIB_INCLUDE_DIRS ${LIBXML2_INCLUDE_DIR})

# Build markturn
set(MAIN_SOURCE "src/markturn.cpp")
add_executable(markturn ${MAIN_SOURCE})
target_link_libraries(markturn PUBLIC ${CURL_LIBRARY})

# global libraries
file(GLOB Library_Source "src/*Format.cpp" "src/libmarkturn.cpp")

add_library(library_source_object OBJECT ${Library_Source})
target_include_directories(library_source_object PUBLIC ${LIBXML2_INCLUDE_DIR})
target_include_directories(library_source_object PUBLIC ${JSON_DIR})
target_include_directories(library_source_object PUBLIC ${YAML_DIR})

# Static Library for markturn
add_library(markturn_static STATIC $<TARGET_OBJECTS:library_source_object>)
target_link_libraries(markturn_static PUBLIC ${LIBXML2_LIBRARY})
target_link_libraries(markturn_static PUBLIC ${JSON_LIBRARY})
target_link_libraries(markturn_static PUBLIC ${YAML_LIBRARY})



# Shared library for markturn
add_library(markturn_shared SHARED $<TARGET_OBJECTS:library_source_object>)
target_link_libraries(markturn_shared PUBLIC ${LIBXML2_LIBRARY})
target_link_libraries(markturn_shared PUBLIC ${JSON_LIBRARY})
target_link_libraries(markturn_shared PUBLIC ${YAML_LIBRARY})



if(LINK_STATIC)
	message("-- Use Static")
	target_link_libraries(markturn PUBLIC markturn_static)
else()
	message("-- Use Shared")
	target_link_libraries(markturn PUBLIC markturn_shared)
endif()