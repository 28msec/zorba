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
#ifndef ZORBA_PARSENODE_BASE_H
#define ZORBA_PARSENODE_BASE_H

#include "compiler/parser/parse_constants.h"
#include "compiler/parser/query_loc.h"

#include "store/api/update_consts.h"

namespace zorba {

class parsenode_visitor;


/*
**  base class: syntax-only nodes
*/
class parsenode : public SimpleRCObject
{
protected:
	QueryLoc loc;

    friend class ParseNodePrintXMLVisitor;

public:
	parsenode(const QueryLoc& loc_) : loc(loc_) { }
  virtual ~parsenode() {}

public:
	const QueryLoc& get_location() const { return loc; }

  virtual void accept(parsenode_visitor&) const = 0;

};

/*
**  exprnode:  nodes with values.
*/
class exprnode : public parsenode
{
public:
	exprnode(const QueryLoc& loc) : parsenode(loc) { }

public:

	virtual void accept(parsenode_visitor&) const = 0;

};

class ParseErrorNode : public parsenode {
public:
  std::string msg;
  ParseErrorNode (const QueryLoc& loc_, std::string msg_)
    : parsenode (loc_), msg (msg_)
  {}

public:
	void accept(parsenode_visitor&) const {}
};


}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
