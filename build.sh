#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

cd build

if [ "$1" != "" ] && [ "$1" == "clean" ]; then
    rm -rf *
fi

cmake -DCMAKE_BUILD_TYPE=$2 ..
make