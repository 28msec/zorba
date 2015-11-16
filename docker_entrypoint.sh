#!/usr/bin/env bash
set -e

mkdir -p /zorba/build
cd /zorba/build
cmake ..
make -j4
./zorba -q 1
