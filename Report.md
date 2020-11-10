# Report
 Thomas Sutyak \
 tjs186@zips.uakron.edu
# Table of Contents

#### [development Activities](#development-Activities-1)
- [Coding](#Coding)
- [Debugging](#Debugging)
- [Building](#Building)
- [Testing](#Testing)
- [Installation](#Installation)

#### [Tools for development](#tools-for-development-1)
- [Bash aliases and functions](#bash-aliases-and-functions)
- [git, GitHub and alternatives](#git-github-and-alternatives)
- [Make](#make)
- [Ninja](#ninja)
- [cmake](#cmake)
- [ctest](#ctest)
- [cpack](#cpack)
- [Docker](#docker)
- [Docker Compose](#docker-compose)
- [systemd and other init tools](#systemd-and-other-init-tools)

# development Activities

## Coding
When it comes to coding, the first thing a programmer(or team of programmers) should consider before anything else is a version control system
i.e. [git, GitHub and alternatives](#git-github-and-alternatives).
Version control is critical to any software development project but is 
especially important when it comes to managing large teams. Version Control allows a team of developers to work simultaneously without interfering with the work of one another. Vesion Control also allows real-time changes to files within the system and a complete retracing system in order to retrace any previous versions of files and/or releases. 

When coding in a project, useful tools are those associated with [building](#Building) the program(to make sure it compiles...ect) and [Bash aliases and functions](#bash-aliases-and-functions) to create tools to aid in the coding process. For example, while coding a good idea is to implement the code in steps, after each step, compiling and running(maybe using commmand automation) and committing to github. It is never a good idea to attempt to implement all of the source code in one 'go'(i.e. starting with a blank script and implementing everything at once without building and committing).

## Debugging
Debugging is the process of identifying and removing errors from computer hardware or software. There are many tools useful for debugging during software  development:
-[Bash aliases and functions](#bash-aliases-and-functions) can be used in order to repeatedly compile and run without having to type a series of commands each time. Also, this inherently helps eliminate command line errors while debugging. Often times, Compiler messages will point out errors however, in the case that the information provided is not exactly useful; using bash functions and aliases can help cut the time spent resolving the issue. 

-[git, GitHub and alternatives](#git-github-and-alternatives) can be used in scenarios where it is neccesary to revert to older releases, or previous commits while debugging. 


## Building
Building is the process of compiling source code and creating executables.
When building a program, there are many useful tools to aid in that process:
- [Make](#make) create a Makefile for your source code.
- [Ninja](#ninja) an alternative to [Make](#make).
- [cmake](#cmake) to generate Makefiles or ninja equivalent.
- [Bash aliases and functions](#bash-aliases-and-functions) to automate a series of build commands.


## Testing
Testing is exactly as it sounds, every development project should involve multiple layers of testing in order to properly ensure all processes perform as intended. Testing should be taken particularly seriously for this reason.

There are many tools that are extremely useful for testing:
- [Bash aliases and functions](#bash-aliases-and-functions) can be extremely helpful in terms of workflow while testing. Creating Aliases and/or Bash functions in order to eliminate the need to retype long commands to compile, run, mount repositories using [docker](#docker)..ect. This is one of the easiest tools to use for testing and one of the most effective.
- [git, GitHub and alternatives](#git-github-and-alternatives) in order to pull and push source code(or whatever else) in order to test. 
- [Docker](#docker) in order to create a minimalistic environment to build, run, and install the program (on different OS systems maybe or in order to test remotely). 
- [Docker Compose](#docker-compose) in order to thoroughly test the program on multiple docker images at once. 
- [ctest](#ctest) in enable a 'make test' or 'ninja test' to test the program using predefined testing scenarios within the CMakeLists.txt of the project.

## Installation
Installation is equally as important as anything else because if a program cannot be installed correctly, it is useless to everyone else. Tools useful in the Installation development process include:
- [cmake](#cmake) to configure CPack in the CMakeLists.txt file.
- [cpack](#cpack) in order to create package distributions for the software.
- [docker](#docker) to test the installations in general(and in different OS).
- apt install in order to install the package generated. (apt install name_of_package):
```
$ apt install Package_name # to install package
```


# Tools for development

### _Bash aliases and functions_
Bash aliases and functions are a form of command automation. Command automation is possible with the use of certain Command line interfaces(commonly refered to as "shells") and is used to automate the use of commands. There are a large number of CLIs but bash is (probably) the most common. Common approaches to command automation is the use of Configuration files, Aliases, Environment variables and Shell functions. When using command automation, it is important to follow common(best) practices. The command automation must also be repeatable and reduce the cognitive load. For example, It is incredibly useful to create a bash alias for a series of commands used repeatedly(without the need to change them every time) during development activities. Bash aliasing is not useful for one-time uses and will end up costing more time than it is saving in that case.

##### Bash Aliases
Bash Aliases are a user created command in the bash shell that can rename a command or perform a series of commands. Useful for personalization and also to save time when entering long commands or a series of commands repeatedly.

Here an alias is created and when called will perform the 'ls -lh' command:
```
$ # Alias Example
$ # Syntax: $ Alias name_of_command='whatever you would like it to do'
$ Alias lh='ls -lh'
$ lh # will be equivalent to typing ls -lh
```

##### Bash Functions
A Bash Functions are functions you can program within the bash shell. Bash functions can have parameters as well. Useful to save time when entering long commands that can make use of parameters.

Here is a Bash Function example that will make use of parameters.
```
$ # function example to echo its parameter
$ # Syntax:
$ # function function_name {
Whatever you would like the function to do.
}
$ fuction fun {
echo $1
}
$ fun word
word
```
### _git, GitHub and alternatives_
Git, GitHub and alternatives fall into the version control category. Version control is essential to modern day development. version control allows for a developer or team of developers to record and control changes to a file or file system and refer to previous versions of the file or file system. Git is the most widely used version control system created by Linus Torvalds in 2005. Common commands for git:
```
$ git add [NameOfFile] # to add a file to a repository
$ git commit -am "commit message containing details of changes"
$ git push # to update the public or private repository
$ git pull # to update the local repository on your machine
```

alternatives include but are not limited to:
- Helix Core
- Subversion
- mercurial
- CVS

### _Make_
Make is a utility that can be downloaded on most operating systems. Make uses a file called a 'Makefile' which can be written manually or generated by other tools such as [cmake](#cmake). Make determines which pieces of a program that need to be recompiled and subsequently issues the commands to recompile them. Make is commonly used with C/C++ however, it can be used for any language whose compiler can be run with a shell command. Therefore Make is a good option for any language that falls into that category.

Example using make with bash:
```
$ cmake . # cmake will create a Makefile by default
$ make # builds all by default
$ make run # runs the program
$ make test # runs test using CTest
$ make clean # removes executables (.o,.obj ...etc)
```

### _Ninja_
Ninja is a common alternative to [Make](#make) in that it is also a build system. However Ninja is commonly known for its ability to build quickly. It can also be used in conjunction to [cmake](#cmake) just like Make. Ninja looks for a file named build.ninja in the current directory and will build all targets that need to be (re)built.

Example using Ninja with bash:
```
$ cmake . -G Ninja # to generate a ninja.build file
$ ninja # build and compile program
$ ninja run # to run the program
$ ninja test # to test using CTest
$ ninja install # installs the program based on configuration within CMakeLists.txt
$ ninja clean # removes executables 
```

### _cmake_
Cmake is a tool to manage the construction of source code. CMake was originally in conjuction to [Make](#make) and only used to generate Makefiles. However, CMake in its current form can be used in conjuction with [ninja](#ninja) and others like Visual Studio and Xcode. 

Example using cmake with bash:
```
$ cmake . # will generate a Makefile by default(same as cmake . -G Make)
$ cmake . -G Ninja # generates a build file for ninja
```

### _ctest_
CTest is a testing tool used along with CMake to run test scripts created within the CMakeLists.txt file. This will then enable testing using CTest. Examples implementing and using CTest in a bash shell:
- to enable testing in CMakeLists.txt example.
```
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
```
- to run tests(after cmake .; make/ninja;)
```
$ make test # for make
$ ninja test # for ninja
```

### _cpack_
CPack is a tool used along with CMake(most commonly) in order to generate  package distributions of binaries and source code. In order to enable CPack 
simply add this to your CMakeLists.txt:
```CMakeLists.txt
include(CPack)
```
In order to strip executables:
```
set(CPACK_STRIP_FILES ON)
```
It is necesary to add copyright files:
```
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_SOURCE_DIR}/COPYING.txt)
install(FILES ${CMAKE_SOURCE_DIR}/COPYING.txt DESTINATION share/doc/srccomplexity RENAME copyright)
```
To set dependencies:
```
set(CPACK_DEBIAN_PACKAGE_DEBUG OFF)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
set(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)
```
Set up idconfig triggers:
```
# Handle idconfig
set(TRIGGERS_FILE ${CMAKE_CURRENT_BINARY_DIR}/triggers)
file(WRITE ${TRIGGERS_FILE} "activate-noawait ldconfig\n")
set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA ${TRIGGERS_FILE} ${CMAKE_BINARY_DIR}/postinst ${CMAKE_BINARY_DIR}/postrm)
```
to "complete" the process:
```
include(GNUInstallDirs)

set(CPACK_PACKAGE_NAME "markturn")
set(CPACK_PACKAGE_VERSION_MAJOR "1")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_CONTACT "Thomas J. Sutyak <tjs186@zips.uakron.edu>")
include(CPack)
```

You can use CPack to generate Linux RPM, deb, and gzip distributions.
For example:
```
$ cpack -G DEB # for Debian based OS systems
$ # -G indicates the type of package to generate (DEB for debian)
```
### _Docker_
Docker is a platform for developers to build, run and distribute applications with containers. Containerization is the use of containers to deploy applications and is a term commonly associated with docker-one of the most influential tools used in development. Docker can containerize very complex applications efficiently and effectively.
Docker images are containers that include their own private file system and OS. Docker images can be set up and run easily and are extremely portable, meaning they can be built locally, deployed to the cloud and run anywhere there is internet access. In order to create an image, first install docker then create what is called a Dockerfile.
- first create a Dockerfile (no extension) using something like 'touch' or 'subl' ...ect.
- This is an example of a Dockerfile to create a docker image with an Ubuntu OS and various commands(to create a c++ build environment for markturn) it will run upon creation.
```
# Linux C++ build environment
FROM ubuntu:20.10

# Install packages for C++ build environment
RUN apt-get update && apt-get install -y \
	# build
	make \
	ninja-build \
	# compiler
	g++ \
	# Libraries
	libcurl4-openssl-dev \
	libyaml-cpp-dev \
	libjsoncpp-dev \
	libxml2-dev \
	# version control
	lintian\
	git \
	#utility
	curl \
	&& rm -rf /var/lib/apt/lists/*

#Install cmake
RUN curl -L https://cmake.org/files/v3.18/cmake-3.18.4-Linux-x86_64.tar.gz | tar xvz --strip-components=1 -C /usr/local

#Install local version of CLI11
ARG CLI11_VERSION=1.9.1
ARG CLI11_URL=https://github.com/CLIUtils/CLI11/releases/download/v${CLI11_VERSION}/CLI11.hpp
ADD $CLI11_URL /usr/local/include
```
- to build the image:
```
$ docker build wherever_Dockerfile_is_stored -t Whatever_you_want_to_name_the_image
```
- to run the image:
```
$ docker run [OPTIONS] [NameOfImage] [command] [arg...]
```

### _Docker Compose_
Docker Compose is a tool for defining and running multiple docker containers. With one command, Docker Compose can be set to run all of the services in all of the environments set. To set it up, it is a three step process(usually).
define the environment(s) with a Dockerfile, Define the services that make up the application and run:
```
$ docker-compose up # to run app on all containers
```
In order to configure docker compose you must create a docker-compose.yml file. Here is an example file to run an app in two seperate docker images, thus two separate environments:
```
version: '3.8'

services:

  fedora: 
    image: fedora_34
    volumes:
      - type: bind
        source: .
        target: /markturn
        read_only: true
    working_dir: /markturn
    command: bash -c "${COMMAND_NEW- cmake --version}"

  ubuntu: 
    image: ubuntu_2010
    volumes:
      - type: bind
        source: .
        target: /Source
        read_only: true
    working_dir: /Build
    command: bash -c "${COMMAND_PREFIX}
      ls -lh /Source;
      ${COMMAND_SUFFIX}"
```
### _systemd and other init tools_
Systemd allows for services/programs to run upon machine start up. These can be anything from keyboard layouts or processes that run in the background. Useful for personalization and work flow. To set up a new service:
-create a file with a .service extention in the /etc/systemd/system/ directory.
-example process:
```
[Unit]
Description= Markturn
After=network.target
StartLimitIntervalSec=0

[Service]
Type=simple
Restart=always
RestartSec=1
User=root
ExecStart=/Markturn
[Install]
WantedBy=multi-user.target
```