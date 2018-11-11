#!/bin/bash

if [ "$1" != "" ]; then
    if [ "$1" == "clean" ]
        if [ -d "build" ]; then
            cd build
            rm -rf *
        else
            mkdir build
        fi
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