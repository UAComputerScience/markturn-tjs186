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
find_path(YAML_DIR NAMES yaml-cpp PATHS /usr/include/)
find_path(YAML_LIBRARY NAMES libyaml-cpp.so PATHS /usr/lib/x86_64-linux-gnu/ /usr/lib64/)
set(YAML ${YAML_DIR}/yaml-cpp)
set(YAML_LIBRARY_DIR ${YAML_LIBRARY}/libyaml-cpp.so)
message("-- YAML include: " ${YAML})
message("-- YAML library: " ${YAML_LIBRARY_DIR})

#Find JSON
find_package(jsoncpp REQUIRED)
find_path(JSON_DIR NAMES jsoncpp json PATHS /usr/include)
find_path(JSON_LIBRARY NAMES libjsoncpp.so PATHS /usr/lib/x86_64-linux-gnu/ /usr/lib64/)

if(DISTRO MATCHES "Fedora")
	set(JSON ${JSON_DIR}/json)
else()
	set(JSON ${JSON_DIR}/jsoncpp)
endif()

set(JSON_LIBRARY_DIR ${JSON_LIBRARY}/libjsoncpp.so)
message("-- JSON include: " ${JSON})
message("-- JSON library: " ${JSON_LIBRARY_DIR})


# Build markturn
set(MAIN_SOURCE "src/markturn.cpp")
add_executable(markturn ${MAIN_SOURCE})
target_link_libraries(markturn PUBLIC ${CURL_LIBRARY})

# glob libraries
file(GLOB Library_Source "src/*Format.cpp" "src/libmarkturn.cpp")

#create library object
add_library(library_source_object OBJECT ${Library_Source})
target_include_directories(library_source_object PUBLIC ${LIBXML2_INCLUDE_DIR})
target_include_directories(library_source_object PUBLIC ${JSON_DIR})
target_include_directories(library_source_object PUBLIC ${YAML_DIR})

# Static Library for markturn
add_library(markturn_static STATIC $<TARGET_OBJECTS:library_source_object>)
target_link_libraries(markturn_static PUBLIC ${LIBXML2_LIBRARY})
target_link_libraries(markturn_static PUBLIC ${JSON_LIBRARY})
target_link_libraries(markturn_static PUBLIC ${YAML_LIBRARY})
install(TARGETS markturn_static LIBRARY)


# Shared library for markturn
add_library(markturn_shared SHARED $<TARGET_OBJECTS:library_source_object>)
target_link_libraries(markturn_shared PUBLIC ${LIBXML2_LIBRARY})
target_link_libraries(markturn_shared PUBLIC ${JSON_LIBRARY})
target_link_libraries(markturn_shared PUBLIC ${YAML_LIBRARY})
install(TARGETS markturn_shared LIBRARY)

#option for shared or static libraries
if(LINK_STATIC)
	message("-- Use Static")
	target_link_libraries(markturn PUBLIC markturn_static)
else()
	message("-- Use Shared")
	target_link_libraries(markturn PUBLIC markturn_shared)
endif()
install(TARGETS markturn RUNTIME)

enable_testing()
file(GLOB Test_Source "test/*.cpp")

# Generate test files
foreach(TESTFILE ${Test_Source})
    get_filename_component(TEST_NAME ${TESTFILE} NAME_WLE)
    add_executable(${TEST_NAME} ${TESTFILE})
    target_include_directories(${TEST_NAME} PUBLIC src)
    target_include_directories(${TEST_NAME} PUBLIC ${LIBXML2_INCLUDE_DIR})
    target_link_libraries(${TEST_NAME} PUBLIC ${LIBXML2_LIBRARY})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    message("-- test added ${TEST_NAME}")

endforeach()
Include(CPack)