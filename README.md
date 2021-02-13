# Pong

## Prerequisites

- CMAKE (www.cmake.org)
- SFML 2.4.2 (www.sfml-dev.org)

## Compile

Make a subdirectory 'Debug'. In 'Debug' type 'cmake ..' to generate a makefile.  If SFML is not installed in standard location, you will need to set the LIB and INCLUDE environment variables. For example if SFML is installed in ~/SFML, then you can adjust the environment variables (assuming linux and a BASH-shell) by:

export LIB=$LIB:~/SFML/lib
export INCLUDE=$INCLUDE:~/SFML/include

These environment variables are only valid in your current terminal. To make them permanent, add the above two lines to your '~/.profile' file.

Now that the Makefile has been succesfully generated, you can compile with 'make'. This will produce a 'helloworld' executable that will open a blue window.


## Adding Files

- If you want to add an executable, just add the corresponding .cpp file in the 'bin' subdirectory, and _rerun_ 'cmake .' to update the Makefiles.
- If you want to add a source file, just add the corresponding .cpp file in the 'src' subdirectory, and _rerun_ 'cmake .' to update the Makefile.
- If you want to add a header file, just add the corresponding .h file to the 'include' subdirectory. You do not need to update the Makefile.


## Advanced Compiling

The above instructions will compile your executable with all debug information embedded and compiler optimizations minimized.  To compile a 'release' version, just create a subdirectory 'Release' instead of 'Debug' and follow the same instructions as above. Note: in release mode certain safety checks are disabled and 'assert' statement are ignored. Hence, it is recommended to test your code in 'Debug' mode, and only when everything works, compile it in the 'Release' mode.\

If you want to use additional external libraries, you will need to add them to 'CMakeLists.txt' (line 39). Please refer to the CMake documentation for more information on how to include libraries to your project with CMake.
