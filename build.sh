#!/bin/bash

mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
for EXE in $(find $PWD -perm +111 -type f -a -name "*_test" | grep -v "CMakeFiles" | sort)
do
    echo "-----$EXE------"
    $EXE
done

