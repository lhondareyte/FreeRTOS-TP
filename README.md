# Tests with FreeRTOS kernel

Trying to create a clean separation between application and [the FreeRTOS](https://github.com/FreeRTOS/FreeRTOS-Kernel) kernel source code.

    CMakeLists.txt
    FreeRTOS         # FreeRTOS kernel as a submodule
    app              # Separate application source code
    cmake            # Additionnals cmake configuration files
    build.sh         # simple build script 

# See Also

* [FreeRTOS article from Jean-Michel Friedt](https://connect.ed-diamond.com/hackable/hk-048/freertos-dans-25-kb-de-ram-sur-atmega32u4) - in french -
  * [Github repository](https://github.com/jmfriedt/tp_freertos.git)
* [FreeRTOS on atmega328p from  Huckleberry K. ](https://github.com/peakhunt/freertos_atmega328p)
* [miniAVRfreeRTOS from Phillip Stevens](https://github.com/feilipu/miniAVRfreeRTOS)
