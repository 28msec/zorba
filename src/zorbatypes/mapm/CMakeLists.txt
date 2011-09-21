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

SET(MAPM_SRCS
    mapm5sin.c
    mapm_add.c
    mapm_cpi.c
    mapm_div.c
    mapm_exp.c
    mapm_fam.c
    mapm_fft.c
    mapm_flr.c
    mapm_fpf.c
    mapm_gcd.c
    mapm_lg2.c
    mapm_lg3.c
    mapm_lg4.c
    mapm_log.c
    mapm_mul.c
    mapm_pow.c
    mapm_rcp.c
    mapm_rnd.c
    mapm_set.c
    mapm_sin.c
    mapmasin.c
    mapmasn0.c
    mapmcbrt.c
    mapmcnst.c
    mapmfact.c
    mapmfmul.c
    mapmgues.c
    mapmhasn.c
    mapmhsin.c
    mapmipwr.c
    mapmistr.c
    mapmpwr2.c
    mapmrsin.c
    mapmsqrt.c
    mapmstck.c
    mapmutil.c
    mapmutl1.c
    mapmutl2.c)
  
# disable warning "assuming signed overflow does not occur when assuming that (X + c) < X is always false."
# no signed overflow may occur in these parts of mapm
IF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  INCLUDE (CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG (-Wstrict-overflow _works)
  IF (_works)
    FOREACH(MAPM_SRC ${MAPM_SRCS})
      SET_SOURCE_FILES_PROPERTIES(${CMAKE_SOURCE_DIR}/src/zorbatypes/mapm/${MAPM_SRC} PROPERTIES COMPILE_FLAGS "-Wstrict-overflow=0")
    ENDFOREACH(MAPM_SRC)
  ENDIF (_works)
ENDIF (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
