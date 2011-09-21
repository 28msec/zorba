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

SET(LIBSTEMMER_SRCS
    libstemmer/libstemmer_utf8.c
    runtime/api.c
    runtime/utilities.c
    src_c/stem_UTF_8_danish.c
    src_c/stem_UTF_8_dutch.c
    src_c/stem_UTF_8_english.c
    src_c/stem_UTF_8_finnish.c
    src_c/stem_UTF_8_french.c
    src_c/stem_UTF_8_german.c
    src_c/stem_UTF_8_hungarian.c
    src_c/stem_UTF_8_italian.c
    src_c/stem_UTF_8_norwegian.c
    src_c/stem_UTF_8_portuguese.c
    src_c/stem_UTF_8_romanian.c
    src_c/stem_UTF_8_russian.c
    src_c/stem_UTF_8_spanish.c
    src_c/stem_UTF_8_swedish.c
    src_c/stem_UTF_8_turkish.c
    sb_stemmer.cpp
    )
