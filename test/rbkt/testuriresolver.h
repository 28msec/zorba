/* -*- mode:c++ -*-
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
#include <zorba/uri_resolvers.h>

#include <map>
#include <vector>

namespace zorba {
class TestSchemaURIResolverResult : public SchemaURIResolverResult
{
public:

  virtual ~TestSchemaURIResolverResult();
  virtual Item getSchema () const;
protected:
  friend class TestSchemaURIResolver;
  Item theSchema;

};

class TestSchemaURIResolver : public SchemaURIResolver 
{
private:

  const char * map_file;
  std::map< String, String > uri_map;

  void initialize ();

public:

  TestSchemaURIResolver ( const char * file);
  virtual ~TestSchemaURIResolver();

  virtual std::auto_ptr<SchemaURIResolverResult>
  resolve ( const Item & aURI,
	    const std::vector <Item> & aLocationHint,
	    StaticContext * aStaticContext );
};

} // namespace zorba
