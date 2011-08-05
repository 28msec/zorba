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

#ifndef ZORBA_XQUERY_STACK_TRACE_API_H
#define ZORBA_XQUERY_STACK_TRACE_API_H

#include <string>
#include <vector>

#include <zorba/internal/qname.h>

namespace zorba {

class XQueryStackTrace;

namespace serialization {
  class Archiver;
  void operator&( Archiver&, XQueryStackTrace& );
}

///////////////////////////////////////////////////////////////////////////////

class XQueryStackTrace {
public:
  typedef internal::VariableQName<std::string> fn_name_type;
  typedef unsigned short fn_arity_type;
  typedef unsigned line_type;
  typedef unsigned short column_type;

  class Entry {
  public:
    Entry( fn_name_type const &fn_name, fn_arity_type fn_arity,
           char const *file_name, line_type line, column_type column,
           line_type line_end, column_type column_end);

    fn_name_type const& getFnName() const {
      return fn_name_;
    }

    fn_arity_type const& getFnArity() const {
      return fn_arity_;
    }

    std::string const& getFileName() const {
      return filename_;
    }

    line_type getLine() const {
      return line_;
    }

    column_type getColumn() const {
      return col_;
    }

    line_type getLineEnd() const {
      return line_end_;
    }

    column_type getColumnEnd() const {
      return col_end_;
    }

    fn_name_type& getFnNameRef()  {
      return fn_name_;
    }

    fn_arity_type& getFnArityRef() {
      return fn_arity_;
    }

    std::string& getFileNameRef() {
      return filename_;
    }

    line_type& getLineRef() {
      return line_;
    }

    column_type& getColumnRef() {
      return col_;
    }

    line_type& getLineEndRef() {
      return line_end_;
    }

    column_type& getColumnEndRef() {
      return col_end_;
    }

  private:
    fn_name_type fn_name_;
    fn_arity_type fn_arity_;
    std::string filename_;
    line_type line_;
    column_type col_;
    line_type line_end_;
    column_type col_end_;
  public:
    // for plan serialization
    Entry();
  };

  typedef std::vector<Entry> trace_t;
  typedef trace_t::size_type size_type;
  typedef trace_t::const_iterator const_iterator;
  typedef trace_t::const_reverse_iterator const_reverse_iterator;

  bool empty() const {
    return trace_.empty();
  }

  const_iterator begin() const {
    return trace_.begin();
  }

  const_iterator end() const {
    return trace_.end();
  }

  const_reverse_iterator rbegin() const {
    return trace_.rbegin();
  }

  const_reverse_iterator rend() const {
    return trace_.rend();
  }

  void push( Entry const &entry );

  size_type size() const {
    return trace_.size();
  }

private:
  trace_t trace_;

  friend void serialization::operator&( serialization::Archiver&,
                                        XQueryStackTrace& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_XQUERY_STACK_TRACE_API_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
