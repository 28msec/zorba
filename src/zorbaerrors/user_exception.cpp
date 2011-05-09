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

#include <zorba/item_sequence.h>
#include <zorba/iterator.h>

#include "user_exception.h"
#include "zorbamisc/ns_consts.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

UserException::UserException( char const *ns, char const *prefix,
                              char const *localname, char const *throw_file,
                              line_type throw_line, char const *description,
                              error_object_type *error_object ) :
  XQueryException(
    *(new UserError( ns, prefix, localname )), throw_file, throw_line,
    description
  )
{
  if ( error_object )
    error_object->swap( error_object_ );
}

UserException::UserException(zorba::serialization::Archiver &ar) : XQueryException(ar)
{
}

UserException::~UserException() throw() {
  // out-of-line since it's virtual
}

auto_ptr<ZorbaException> UserException::clone() const {
  return auto_ptr<ZorbaException>( new UserException( *this ) );
}

void UserException::polymorphic_throw() const {
  throw *this;
}

///////////////////////////////////////////////////////////////////////////////

namespace internal {

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line ) {
  Item empty;
  return make_user_exception( throw_file, throw_line, empty );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   Item const &error ) {
  String empty;
  return make_user_exception( throw_file, throw_line, error, empty );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   Item const &error,
                                   String const &description ) {
  ItemSequence_t empty_seq;
  return make_user_exception(
    throw_file, throw_line, error, description, empty_seq
  );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   Item const &error,
                                   String const &description,
                                   ItemSequence_t const &error_item_seq ) {
  UserException::error_object_type error_object;
  if ( error_item_seq.get() ) {
    if ( Iterator_t i = error_item_seq->getIterator() ) {
      i->open();
      Item item;
      while ( i->next( item ) )
        error_object.push_back( item );
      i->close();
    }
  }
  return make_user_exception(
    throw_file, throw_line, error, description.c_str(), QueryLoc::null,
    &error_object
  );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   Item const &qname,
                                   char const *description,
                                   QueryLoc const &loc,
                                   error_object_type *error_object ) {
  store::Item_t store_qname;
  if ( !qname.isNull() )
    store_qname = Unmarshaller::getInternalItem( qname );

  return make_user_exception(
    throw_file, throw_line, store_qname, description, loc, error_object
  );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   store::Item_t const &qname,
                                   char const *description,
                                   QueryLoc const &loc,
                                   error_object_type *error_object ) {
  char const *ns, *prefix, *localname;
  if ( qname.isNull() ) {
    ns = XQUERY_ERR_NS;
    prefix = "err";
    localname = "FOER0000";
  } else {
    ns = qname->getNamespace().c_str();
    prefix = qname->getPrefix().c_str();
    localname = qname->getLocalName().c_str();
  }

  return make_user_exception(
    throw_file, throw_line, ns, prefix, localname, description, loc,
    error_object
  );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   Error const &error,
                                   err::parameters const &params,
                                   err::location const &loc,
                                   UserException::error_object_type
                                    *error_object ) {
  err::parameters::value_type message( error.message() );
  params.substitute( &message );
  zorba::err::QName const &qname = error.qname();
  return make_user_exception(
    throw_file, throw_line, qname.ns(), qname.prefix(), qname.localname(),
    message.c_str(), loc, error_object
  );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   char const *ns, char const *prefix,
                                   char const *localname,
                                   char const *description, QueryLoc const &loc,
                                   error_object_type *error_object ) {
  err::location const eloc(
    loc.getFilename(), loc.getLineno(), loc.getColumnBegin() 
  );
  return make_user_exception(
    throw_file, throw_line, ns, prefix, localname, description, eloc,
    error_object
  );
}

UserException make_user_exception( char const *throw_file,
                                   ZorbaException::line_type throw_line,
                                   char const *ns, char const *prefix,
                                   char const *localname,
                                   char const *description,
                                   err::location const &loc,
                                   UserException::error_object_type
                                    *error_object ) {
  UserException ue(
    ns, prefix, localname, throw_file, throw_line, description, error_object
  );
  if ( loc )
    ue.set_source( loc.file(), loc.line(), loc.column() );
  return ue;
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
