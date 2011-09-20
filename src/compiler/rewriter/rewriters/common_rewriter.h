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
#ifndef ZORBA_COMMON_REWRITER
#define ZORBA_COMMON_REWRITER

#define ADD_DRIVER( d ) \
m_childRewriters.push_back(rewriter_ptr_t (new d))

#define ADD_SINGLETON_DRIVER(rule) \
m_childRewriters.push_back(rewriter_ptr_t(new SingletonRuleMajorDriver<rule>))

#define ADD_ONCE_DRIVER(rule) \
m_childRewriters.push_back(rewriter_ptr_t(new RuleOnceDriver<rule>))

#define ADD_RULE( rule ) \
m_rules.push_back (rule_ptr_t (new rule))

#endif /* ZORBA_COMMON_REWRITER */
/* vim:set et sw=2 ts=2: */
