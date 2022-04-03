#!/bin/bash

cmake -DTOOLCHAIN=~/Desktop/toolchain/bin -DCMAKE_INSTALL_PREFIX=~/task3/TP/task3/install ..
make
make install