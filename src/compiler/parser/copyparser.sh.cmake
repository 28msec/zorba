#
# Copyright 2006-2008 The FLWOR Foundation.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
# http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#/
#!/bin/bash

BINARY_DIR=@CMAKE_CURRENT_BINARY_DIR@
SOURCE_DIR=@CMAKE_CURRENT_SOURCE_DIR@

cp $BINARY_DIR/compiler/parser/xquery_parser.hpp $SOURCE_DIR/compiler/parser
cp $BINARY_DIR/compiler/parser/xquery_parser.cpp $SOURCE_DIR/compiler/parser
cp /usr/include/FlexLexer.h $SOURCE_DIR/compiler/parser/FlexLexer.h
sed -e 's|^#include <FlexLexer.h>|#include "compiler/parser/FlexLexer.h"|g' $BINARY_DIR/compiler/parser/xquery_scanner.cpp > $SOURCE_DIR/compiler/parser/xquery_scanner.cpp
