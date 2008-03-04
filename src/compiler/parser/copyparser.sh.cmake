#!/bin/bash

BINARY_DIR=@CMAKE_CURRENT_BINARY_DIR@
SOURCE_DIR=@CMAKE_CURRENT_SOURCE_DIR@

cp $BINARY_DIR/compiler/parser/xquery_parser.hpp $SOURCE_DIR/compiler/parser
cp $BINARY_DIR/compiler/parser/xquery_parser.cpp $SOURCE_DIR/compiler/parser
sed -e 's|^#include <FlexLexer.h>|#include "compiler/parser/FlexLexer.h"|g' $BINARY_DIR/compiler/parser/xquery_scanner.cpp > $SOURCE_DIR/compiler/parser/xquery_scanner.cpp
