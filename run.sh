if [ ! -d "bin" ]; then
    mkdir bin
fi

if [ ! -f "bin/Hazard" ]; then
    ./build.sh $1
fi

if [ -f "bin/Hazard" ]; then
    chmod 777 bin/Hazard
    ./bin/Hazard
fi