/*
    convert.cpp

    Client program for the convert utility
*/

#include <CLI11.hpp>
#include "convert.hpp"
#include <curl/curl.h>

int main(int argc, char* argv[]) {

    // command-line parsing
    CLI::App app{"Convert among data formats"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    CLI11_PARSE(app, argc, argv);

    // ...

    // Conversions using libconvert

    return 0;
}
