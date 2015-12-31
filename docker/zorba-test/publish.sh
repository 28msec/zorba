#!/bin/bash
set -e

if [ "$#" -ne 1 ]
then
  echo "No version specified, use for instance: ./publish.sh precise"
  exit 1
fi

NAME=zorba-test-$1
FULL_NAME=fcavalieri/$NAME
docker tag -f $NAME $FULL_NAME
docker push $FULL_NAME
