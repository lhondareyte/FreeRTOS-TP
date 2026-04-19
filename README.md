# Some test with FreeRTOS kernel

Trying to create a clean separation between application and kernel source code.


    CMakeLists.txt
    FreeRTOS         # FreeRTOS kernel as a submodule
    app              # Separate application source code
    cmake            # Additionnale cmake configuration files
    build.sh         # simple build script 
