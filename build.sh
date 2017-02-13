#!/bin/bash

cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
find $PWD -perm +111 -type f | grep -v "3.7.2" | xargs -n 1 -J % echo %;%

