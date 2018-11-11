if [ -d "build" ]; then
    cd build
    rm -rf *
else
    ./build.sh
    return
fi

cmake ..
make