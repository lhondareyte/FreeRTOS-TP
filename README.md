# Tests with FreeRTOS kernel

Trying to create a clean separation between application and [the FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel) kernel source code.

    CMakeLists.txt
    FreeRTOS         # FreeRTOS kernel as a submodule
    app              # Separate application source code
    cmake            # Additionnals cmake configuration files
    build.sh         # simple build script 

