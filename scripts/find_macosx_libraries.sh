#!/bin/bash

file=$1
echo $file
while [ -L $file ]
do
  currentdir=$(dirname $file)
  file=$( readlink "$file" )
  echo ";$(cd "${currentdir}";pwd)/$(basename "$file");"
done

