#!/bin/bash

cp start.sh build/start.sh
rm -r build/*
cp start.sh build/start.sh
cd build
bash start.sh
cd ..
cd install 
cd bin
./MainLib