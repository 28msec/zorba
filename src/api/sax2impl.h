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
#ifndef ZORBA_SAX2_IMPL_HPP
#define ZORBA_SAX2_IMPL_HPP

#include <zorba/sax2.h>
#include <zorba/item.h>

#include "zorbatypes/representations.h"
#include "store/api/item.h"

namespace zorba{

class SAX2AttributesImpl: public SAX2_Attributes
{
  typedef struct
  {
    xqp_string    uri;
    xqp_string    localname;
    xqp_string    qname;
    xqp_string    value;
    xqp_string    type;
  }SAX2_XmlAttribute;
  //list of pairs localname/prefix/URI/valueBegin/valueEnd
  std::vector<SAX2_XmlAttribute>   attrs;
  //bool  own_data;
public:
  SAX2AttributesImpl( store::Item *item);
  SAX2AttributesImpl( SAX2AttributesImpl * orig);

  /** Destructor */
  virtual ~SAX2AttributesImpl();

  unsigned int getLength() const;

  const String getURI(const unsigned int index) const;

  const String getLocalName(const unsigned int index) const;

  const String getQName(const unsigned int index) const;

  const String getType(const unsigned int index) const;

  const String getValue(const unsigned int index) const;

  int getIndex(const String & uri, const String & localPart ) const;

  int getIndex(const String & qName ) const;

  const String getType(const String & uri, const String & localPart ) const;

  const String getType(const String & qName) const;

  const String getValue(const String & uri, const String & localPart ) const;

  const String getValue(const String & qName) const;
};
}//end of namespace
#endif

