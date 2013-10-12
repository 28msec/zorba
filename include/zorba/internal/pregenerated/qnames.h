/**
 * Copyright 2006-2013 The FLWOR Foundation.
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
 
 /*
  * THIS FILE IS GENERATED.
  * PLEASE DO NOT EDIT.
  */


#ifndef ZORBA_INTERNAL_QNAMES_H
#define ZORBA_INTERNAL_QNAMES_H

namespace zorba {
namespace internal {

class ZORBA_DLL_PUBLIC XQueryErrorQName :
  public FixedQName<XQueryErrorQName,char const*>
{
  typedef FixedQName<XQueryErrorQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];
  XQueryErrorQName( char const *localname ) : base_type( localname ) { }
  zorba::diagnostic::kind kind() const;
};

class ZORBA_DLL_PUBLIC JSONiqErrorQName :
  public FixedQName<JSONiqErrorQName,char const*>
{
  typedef FixedQName<JSONiqErrorQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];
  JSONiqErrorQName( char const *localname ) : base_type( localname ) { }
  zorba::diagnostic::kind kind() const;
};

class ZORBA_DLL_PUBLIC ZorbaErrorQName :
  public FixedQName<ZorbaErrorQName,char const*>
{
  typedef FixedQName<ZorbaErrorQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];
  ZorbaErrorQName( char const *localname ) : base_type( localname ) { }
  zorba::diagnostic::kind kind() const;
};

class ZORBA_DLL_PUBLIC ZorbaWarningQName :
  public FixedQName<ZorbaWarningQName,char const*>
{
  typedef FixedQName<ZorbaWarningQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];
  ZorbaWarningQName( char const *localname ) : base_type( localname ) { }
  zorba::diagnostic::kind kind() const;
};

class ZORBA_DLL_PUBLIC ZorbaCSVErrorQName :
  public FixedQName<ZorbaCSVErrorQName,char const*>
{
  typedef FixedQName<ZorbaCSVErrorQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];
  ZorbaCSVErrorQName( char const *localname ) : base_type( localname ) { }
  zorba::diagnostic::kind kind() const;
};

class ZORBA_DLL_PUBLIC ZorbaDateTimeErrorQName :
  public FixedQName<ZorbaDateTimeErrorQName,char const*>
{
  typedef FixedQName<ZorbaDateTimeErrorQName,char const*> base_type;
public:
  static char const NAMESPACE[];
  static char const PREFIX[];
  ZorbaDateTimeErrorQName( char const *localname ) : base_type( localname ) { }
  zorba::diagnostic::kind kind() const;
};

} // namespace internal

typedef internal::SystemDiagnostic<internal::XQueryErrorQName> XQueryErrorCode;
typedef internal::SystemDiagnostic<internal::JSONiqErrorQName> JSONiqErrorCode;
typedef internal::SystemDiagnostic<internal::ZorbaErrorQName> ZorbaErrorCode;
typedef internal::SystemDiagnostic<internal::ZorbaWarningQName> ZorbaWarningCode;
typedef internal::SystemDiagnostic<internal::ZorbaCSVErrorQName> ZorbaCSVErrorCode;
typedef internal::SystemDiagnostic<internal::ZorbaDateTimeErrorQName> ZorbaDateTimeErrorCode;

} // namespace zorba
#endif /* ZORBA_INTERNAL_QNAMES_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
