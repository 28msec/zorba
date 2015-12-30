#!/bin/bash
set -e

if [ "$#" -ne 1 ]
then
  echo "No version specified, use for instance: ./build.sh precise"
  exit 1
fi

FOLDER=$1
NAME=zorba-test-$FOLDER
BUILD_FOLDER=build
(
  rm -rf $BUILD_FOLDER
  mkdir $BUILD_FOLDER
  cp docker-entrypoint.sh $BUILD_FOLDER/docker-entrypoint.sh
  cp $FOLDER/Dockerfile $BUILD_FOLDER/Dockerfile
  cd $BUILD_FOLDER

  set +e
  docker stop "$NAME" > /dev/null 2>&1
  docker rm "$NAME" > /dev/null 2>&1
  set -e

  docker build -t "$NAME" .
)
