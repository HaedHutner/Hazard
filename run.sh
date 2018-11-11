if [ ! -d "bin" ]; then
    mkdir bin
fi

if [ ! -f "bin/Hazard" ]; then
    sudo ./build.sh $1
fi

if [ -f "bin/Hazard" ]; then
    chmod 777 /bin/Hazard
    ./Hazard
fi