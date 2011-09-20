/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef ZORBA_FTNODE_CLASSES_H
#define ZORBA_FTNODE_CLASSES_H

#include "zorbatypes/rchandle.h"

namespace zorba {

class ftnode;
typedef rchandle<ftnode> ftnode_t;

class ftnode_visitor;
class pass_thru_expr_visitor;

namespace ft_visit_result {
  enum type {
    proceed,
    no_children = 0x01,
    no_end      = 0x02,
    neither     = no_children | no_end
  };
}

class ftand;
class ftcase_option;
class ftcontent_filter;
class ftdiacritics_option;
class ftdistance_filter;
class ftextension_option;
class ftextension_selection;
class ftlanguage_option;
class ftmatch_option;
class ftmatch_options;
class ftmild_not;
class ftorder_filter;
class ftor;
class ftpos_filter;
class ftprimary;
class ftprimary_with_options;
class ftrange;
class ftscope_filter;
class ftselection;
class ftstem_option;
class ftstop_word_option;
class ftstop_words;
class ftthesaurus_id;
class ftthesaurus_option;
class ftunary_not;
class ftweight;
class ftwild_card_option;
class ftwindow_filter;
class ftwords;
class ftwords_times;

} // namespace zorba
#endif /* ZORBA_FTNODE_CLASSES_H */
/* vim:set et sw=2 ts=2: */
