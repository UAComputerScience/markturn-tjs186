#build for markturn

cmake_minimum_required(VERSION 3.18.4)

project(markturn VERSION "1.0.0")

#find curl
find_package(CURL REQUIRED)
message("-- curl include: " ${CURL_INCLUDE_DIR})
message("-- curl library: " ${CURL_LIBRARY})

#find libxml2
find_package(LibXml2 REQUIRED)
message("-- LibXml2 include: " ${LIBXML2_INCLUDE_DIR})
message("-- LibXml2 library: " ${LIBXML2_LIBRARY})

#
set(LIB_INCLUDE_DIRS ${LIBXML2_INCLUDE_DIR})

# Build markturn
set(MAIN_SOURCE "src/markturn.cpp")
add_executable(markturn ${MAIN_SOURCE})
target_link_libraries(markturn PUBLIC libmarkturn)
target_link_libraries(markturn PUBLIC ${CURL_LIBRARY})

# global libraries
file(GLOB Library_Source "src/*Format.cpp" "src/libmarkturn.cpp")

add_library(library_source_object OBJECT ${Library_Source})
target_include_directories(library_source_object PUBLIC ${LIBXML2_INCLUDE_DIR})

