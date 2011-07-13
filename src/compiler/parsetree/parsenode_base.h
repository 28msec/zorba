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
#ifndef ZORBA_PARSENODE_BASE_H
#define ZORBA_PARSENODE_BASE_H

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>

#include "compiler/parser/parse_constants.h"
#include "compiler/parser/query_loc.h"
#include "compiler/parser/xqdoc_comment.h"
#include "zorbatypes/rchandle.h"

#include "store/api/update_consts.h"
#include "zorbatypes/zstring.h"

namespace zorba {

class parsenode_visitor;


/*
**  base class: syntax-only nodes
*/
// exported for unit testing only
class ZORBA_DLL_PUBLIC parsenode : public SimpleRCObject
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

/**
 * XQDocumentable: nodes with XQDoc comments attached
 */
class XQDocumentable: public parsenode
{
  private:
    zstring theStringComment;
    mutable const XQDocComment* theComment;

  public:
    XQDocumentable(const QueryLoc& loc): parsenode(loc), theComment(0){}
    ~XQDocumentable(){ delete theComment; }

    XQDocumentable* setComment(const zstring& aComment)
    {
      theStringComment = aComment;
      return this;
    }

    const XQDocComment* getComment() const
    {
      if(theComment == 0)
      {
        theComment = new XQDocComment(theStringComment);
      }
      return theComment;
    }

    zstring getCommentString() const { return theStringComment; }
};


/**
 * exprnode:  nodes with values.
 */
class exprnode : public parsenode
{
public:
  exprnode(const QueryLoc& loc) : parsenode(loc) { }

public:
  virtual void accept(parsenode_visitor&) const = 0;

};


class ZORBA_DLL_PUBLIC ParseErrorNode : public parsenode 
{
public:
  Error const &err;
  zstring const msg;
  bool const useParam;   // if true, msg is a parameter for the ZORBA_ERROR_LOC_PARAM() macro

  ParseErrorNode(const QueryLoc& loc_, Error const &err_ = err::XPST0003, zstring msg_ = "", bool useParam_ = false)
    :
    parsenode (loc_), err(err_), msg(msg_), useParam(useParam_)
  {}

  void accept(parsenode_visitor&) const {}
};


} // namespace zorba

#endif /* ZORBA_PARSENODE_BASE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
