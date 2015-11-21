#!/usr/bin/env bash
set -e

mkdir -p /zorba/build
cd /zorba/build
cmake ..
make -j4
echo "Starting Zorba Server"
nginx -c /zorba/src/server/tests/nginx/nginx.conf
spawn-fcgi -p 8000 -n /zorba/build/src/server/zorba-server
