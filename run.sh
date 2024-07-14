#!/bin/bash

INPUT=src/inputs/jpeg/sea-turtle.jpeg
OUTPUT=bin/path

while getopts "i:o:" arg; do
    case $arg in
        i) INPUT=$OPTARG;;
        o) OUTPUT=$OPTARG;;
    esac
done

make clean > /dev/null && make > /dev/null
bin/stif -t -i${INPUT} -o${OUTPUT}