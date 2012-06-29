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
SET(EXPRESSION_SRCS
    expr_consts.cpp
    expr_base.cpp
    expr_iter.cpp
    expr_type.cpp
    expr.cpp
    expr_put.cpp
    expr_utils.cpp
    json_exprs.cpp
    var_expr.cpp
    path_expr.cpp
    flwor_expr.cpp
    fo_expr.cpp
    script_exprs.cpp
    update_exprs.cpp
    function_item_expr.cpp
    pragma.cpp)

IF (NOT ZORBA_NO_FULL_TEXT)
  LIST(APPEND EXPRESSION_SRCS
    ft_expr.cpp
    ftnode.cpp
    ftnode_visitor.cpp)
ENDIF (NOT ZORBA_NO_FULL_TEXT)
