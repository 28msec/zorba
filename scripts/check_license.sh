#!/bin/bash
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
#

FILES=`find $1 -type f -name "*.cpp" -or -name "*.h" -or -name "*.cmake" -or -name "*.txt" \
        | grep -v build | grep -v external | grep -v m_apm | grep -v ZorbaCOMApi \
        | grep -v zorbatest | grep -v xqc.h | grep -v CMakeUseDoxygen.cmake \
        | grep -v FindBoost.cmake | grep -v FindJNI.cmake | grep -v stdint.h | grep -v properties.txt \
        | grep -v ./KNOWN_ISSUES.txt | grep -v ./LICENSE.txt | grep -v ./NOTICE.txt | grep -v ./README.txt \
        | grep -v parser/FlexLexer.h | grep -v parser/xquery_parser.cpp | grep -v singleton.h | grep -v threads.h  \
        | grep -v StackWalker.* | grep -v dpl.txt | grep -v ME_1_2008_v08.txt | grep -v pusum02a.txt | grep -v tri_2008_NH_v08.txt`

for i in $FILES
do
  grep -q "Copyright 2006.*The FLWOR Foundation." "$i" || echo "does not contain license $i"
done
