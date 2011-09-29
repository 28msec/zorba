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

SET(FULLTEXT_SRCS
    ft_match.cpp
    ft_query_item.cpp
    ft_single_token_iterator.cpp
    ft_stop_words_set.cpp
    ft_token_seq_iterator.cpp
    ft_wildcard.cpp
    ft_token_matcher.cpp
    apply.cpp
    ftcontains_visitor.cpp
    full_text.cpp
    full_text_impl.cpp
    stemmer.cpp
    stop_words/stop_words_da.cpp
    stop_words/stop_words_de.cpp
    stop_words/stop_words_en.cpp
    stop_words/stop_words_es.cpp
    stop_words/stop_words_fi.cpp
    stop_words/stop_words_fr.cpp
    stop_words/stop_words_hu.cpp
    stop_words/stop_words_it.cpp
    stop_words/stop_words_nl.cpp
    stop_words/stop_words_no.cpp
    stop_words/stop_words_pt.cpp
    stop_words/stop_words_sv.cpp
    thesaurus.cpp
    tokenizer.cpp
    default_tokenizer.cpp
    ft_module.cpp
    )

IF (ZORBA_NO_UNICODE)
  LIST(APPEND FULLTEXT_SRCS latin_tokenizer.cpp)
ELSE (ZORBA_NO_UNICODE)
  LIST(APPEND FULLTEXT_SRCS icu_tokenizer.cpp)
ENDIF (ZORBA_NO_UNICODE)

ADD_SRC_SUBFOLDER(FULLTEXT_SRCS stemmer LIBSTEMMER_SRCS)

IF (ZORBA_WITH_FILE_ACCESS)
  ADD_SRC_SUBFOLDER(FULLTEXT_SRCS thesauri THESAURUS_SRCS)
ENDIF (ZORBA_WITH_FILE_ACCESS)
