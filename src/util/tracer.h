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
#ifndef ZORBA_TRACER_H
#define ZORBA_TRACER_H

namespace zorba {


#if !defined WIN32 && !defined WINCE
#define TRACE __PRETTY_FUNCTION__<<" ("__FILE__<<':'<<std::dec<<__LINE__<<")"
#define LOCATION	(__oss.str(""), \
                   __oss<<__FILE__<<":"<<std::dec<<__LINE__<<"::"<<__PRETTY_FUNCTION__, \
									 __oss.str())
#elif defined WIN32
#define TRACE __FUNCSIG__<<" ("__FILE__<<':'<<std::dec<<__LINE__<<")"
#define LOCATION	(__oss.str(""), \
                   __oss<<__FILE__<<":"<<std::dec<<__LINE__<<"::"<<__FUNCTION__, \
									 __oss.str())
#else
#define TRACE __FILE__<<':'<<std::dec<<__LINE__<<"::"<<__FUNCTION__
#define LOCATION	(__oss.str(""), \
										__oss<<__FILE__<<":"<<std::dec<<__LINE__<<"::"<<__FUNCTION__, \
										__oss.str())
#endif


} /* namespace zorba */

#endif /* ZORBA_TRACER_H */
/* vim:set et sw=2 ts=2: */
