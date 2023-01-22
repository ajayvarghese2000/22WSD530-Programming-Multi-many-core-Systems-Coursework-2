#!/bin/bash
# since Bash v4
for i in {1..100}
do
    ./bin/original.exe
done
for i in {1..100}
do
    ./bin/fast.exe
done
for i in {1..100}
do
    ./bin/slow.exe
done