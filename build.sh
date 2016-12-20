#!/bin/bash

cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
find $PWD -perm +111 -type f | xargs -n 1 -J % %

