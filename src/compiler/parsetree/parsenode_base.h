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
	parsenode(const QueryLoc& _loc) : loc(_loc) { }
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
  ParseErrorNode (const QueryLoc& loc, std::string msg_)
    : parsenode (loc), msg (msg_)
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
