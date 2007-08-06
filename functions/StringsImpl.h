			/**
 * @file StringsImpl.h
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @copyright 2006-2007 FLWOR Foundation (flworfound.org)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef XQP_STRINGS_IMPL_H
#define XQP_STRINGS_IMPL_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/item_iterator.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

namespace xqp {

class zorba;


/*______________________________________________________________________
|
| 7.2 Functions to Assemble and Disassemble Strings
|_______________________________________________________________________*/


// 7.2.1 fn:codepoints-to-string
// --------------------

class fn_codepoints_to_string_iterator : public BasicIterator
{
private:
	iterator_t arg;
	document_node* doc_node;

public:// ctor,dtor
	fn_codepoints_to_string_iterator( yy::location loc, iterator_t);
	fn_codepoints_to_string_iterator(const fn_codepoints_to_string_iterator&);
	virtual ~fn_codepoints_to_string_iterator() {}

public:
	fn_codepoints_to_string_iterator& operator=(const fn_codepoints_to_string_iterator& it);

public:	// iterator interface
	virtual void _open();
	virtual void _close();
	virtual std::ostream&  _show(std::ostream&) const;
	virtual item_t _next();
	virtual bool done() const;
};


// 7.2.2 fn:string-to-codepoints
// --------------------

class fn_string_to_codepoints_iterator : public BasicIterator
{
private:
	iterator_t arg;
	document_node* doc_node;

public:// ctor,dtor
	fn_string_to_codepoints_iterator( yy::location loc, iterator_t);
	fn_string_to_codepoints_iterator(const fn_string_to_codepoints_iterator&);
	virtual ~fn_string_to_codepoints_iterator() {}

public:
	fn_string_to_codepoints_iterator& operator=(const fn_string_to_codepoints_iterator& it);

public:	// iterator interface
	virtual void _open();
	virtual void _close();
	virtual std::ostream&  _show(std::ostream&) const;
	virtual item_t _next();
	virtual bool done() const;
};

}/*namespace xqp*/
#endif /* XQP_STRINGS_IMPL_H */
