#!/bin/bash

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
for EXE in $(find $PWD -perm +111 -type f | grep -v "CMakeFiles")
do
    echo "-----$EXE------"
    $EXE
done

