#!/bin/bash

if [ "$1" != "" ] && [ "$1" == "clean" ]; then
    if [ ! -d "build" ]; then
        mkdir build
    fi

    cd build
    rm -rf *
else
    if [ ! -d "build" ]; then
        mkdir build
    fi

    cd build
fi

cmake ..
make