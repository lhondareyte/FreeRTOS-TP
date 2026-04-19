#!/bin/sh
#
if [ ! -f FreeRTOS/CMakeLists.txt ] ; then
	git submodule init
	git submodule update --recursive
fi
cmake -B build -S . #-DFREERTOS_KERNEL_DIR=./FreeRTOS/kernel
cmake --build build
