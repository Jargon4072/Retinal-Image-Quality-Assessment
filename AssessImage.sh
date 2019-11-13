#!/bin/bash
if [[ $# -eq 1 ]]; then
echo "$1";
for files in "$1"/*
do
  echo "$files"
  ./featur "$files"
  ./res theta.txt feature.txt
done
fi
