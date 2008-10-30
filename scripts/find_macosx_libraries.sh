#!/bin/bash

file=$1
while [ -L $file ]
do
  currentdir=$(dirname $file)
  file=$( readlink "$file" )
done
echo ";$(cd "${currentdir}";pwd)/$(basename "$file")"
