#!/usr/bin/env bash
set -e

mkdir -p /zorba/build
cd /zorba/build

if [ $# -eq 0 ]
  then
    cmake ..
    make -j4
fi

if [ $# -gt 0 ]
  then
    ./bin/zorba $@
fi
