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
SET(COMPILER_SRCS)
SET(COMPILER_BUILD_SRCS)

ADD_SRC_SUBFOLDER(COMPILER_SRCS parser PARSER_SRCS)

FOREACH (SRCS ${PARSER_BUILD_SRCS})
    LIST(APPEND COMPILER_BUILD_SRCS ${SRCS})
ENDFOREACH (SRCS)

ADD_SRC_SUBFOLDER(COMPILER_SRCS parsetree PARSETREE_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS translator TRANSLATOR_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS normalizer NORMALIZER_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS codegen CODEGEN_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS expression EXPRESSION_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS rewriter REWRITER_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS semantic_annotations SEMANTIC_ANNOTATIONS_SRCS)
ADD_SRC_SUBFOLDER(COMPILER_SRCS api COMPILER_API_SRCS)
