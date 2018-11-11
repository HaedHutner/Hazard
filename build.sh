#!/bin/bash

if [ "$1" != "" ] && [ "$1" == "clean" ]; then
    if [ -d "build" ]; then
        cd build
        rm -rf *
    else
        mkdir build
    fi
else
    if [ -d "build" ]; then
        cd build
    else
        mkdir build
    fi
fi

cmake ..
make