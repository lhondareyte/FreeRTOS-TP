#!/bin/sh
#

cmake -B build -S . #-DFREERTOS_KERNEL_DIR=./FreeRTOS/kernel
cmake --build build
