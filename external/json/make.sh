#!/bin/bash

COMPILER=g++
COMPILEFLAG=-c
OUTPUTFLAG=-o
CFLAGS=""

ALLFILES=( itow.h parser.h readers.h value.h errstrings.cpp itow.cpp parser.cpp test.cpp value.cpp )
SRCFILES=( errstrings itow parser test value );

crtail(){
	if ! [ -e "$1" ]; then
		echo -e "\e[33m"CRTail, must supply a valid filename as first argument"\e[0m"
		exit
	fi

	if [ "$(tail -n 1 $1)" != "" ]; then
		echo -e "\e[34m"Adding newline to end of: "\e[33m"$1 "\e[0m"
		echo -e "\n" >> $1
	fi
}

if ! [ -e "obj/" ]; then
	mkdir "obj/"
fi

echo -e "\e[1m"Checking Newlines:"\e[0m"
for i in $(seq 1 ${#ALLFILES[@]}); do
	j=$(( i - 1 ))  ## arrays are zeo-indexed.
	crtail ${ALLFILES[j]}	
done

linklist=""
echo -e "\e[1m"Building:"\e[0m"
for i in $(seq 1 ${#SRCFILES[@]}); do
	j=$(( i - 1 ))  ## arrays are zeo-indexed.
	ofile="obj/"$(basename ${SRCFILES[j]})".o"
	echo ${SRCFILES[j]}.cpp" => "$ofile
	$COMPILER $CFLAGS $COMPILEFLAG ${SRCFILES[j]}.cpp $OUTPUTFLAG $ofile
	linklist+=" "$ofile
done;

echo -e "\e[1m"Linking test program:"\e[0m"
$COMPILER $CFLAGS $linklist $OUTPUTFLAG test
echo $linklist

echo -e "\e[1m"Making Shared Library:"\e[0m"
ar rc libJSON.a obj/errstrings.o obj/itow.o obj/parser.o obj/value.o
echo $linklist

echo -e "\e[1m"Removing Object Directory:"\e[0m"
rm -r obj

