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
#include "stdafx.h"

#include <zorba/diagnostic_list.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>

#include "user_exception.h"
#include "zorbamisc/ns_consts.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

UserException::UserException( char const *ns, char const *prefix,
                              char const *localname, char const *raise_file,
                              line_type raise_line, char const *description,
                              error_object_type *error_object ) :
  XQueryException(
    UserError( ns, prefix, localname ), raise_file, raise_line,
    description
  )
{
  if ( error_object )
    error_object->swap( error_object_ );
}

UserException::UserException( Error const &error, char const *raise_file,
                              line_type raise_line, char const *description,
                              error_object_type *error_object ) :
  XQueryException( error, raise_file, raise_line, description )
{
  if ( error_object )
    error_object->swap( error_object_ );
}

UserException::UserException( UserException const &from ) :
  XQueryException( from ),
  error_object_( from.error_object_ )
{
  // This copy constructor isn't necessary: the compiler-generated default copy
  // constructor would work just fine.  It is defined explicitly, however, so
  // as to future-proof the code and keep ABI compatibility.
}

UserException::UserException( serialization::Archiver &ar ) :
  XQueryException( ar )
{
}

UserException::~UserException() throw() {
  // out-of-line since it's virtual
}

UserException& UserException::operator=( UserException const &from ) {
  //
  // This assignment operator isn't necessary: the compiler-generated default
  // assignment operator would work just fine.  It is defined explicitly,
  // however, so as to future-proof the code and keep ABI compatibility.
  //
  if ( &from != this ) {
    XQueryException::operator=( from );
    error_object_ = from.error_object_;
  }
  return *this;
}

auto_ptr<ZorbaException> UserException::clone() const {
  return auto_ptr<ZorbaException>( new UserException( *this ) );
}

void UserException::polymorphic_throw() const {
  throw *this;
}

///////////////////////////////////////////////////////////////////////////////

namespace internal {

// MAKE_USER_EXCEPTION_CC_LT_4CC_EL_EOT_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   char const *ns, char const *prefix,
                                   char const *localname,
                                   char const *description,
                                   diagnostic::location const &loc,
                                   error_object_type *error_object ) {
  UserException ue(
    ns, prefix, localname, raise_file, raise_line, description, error_object
  );
  if ( loc )
    ue.set_source( loc.file(), loc.line(), loc.column() );
  return ue;
}

// MAKE_USER_EXCEPTION_CC_LT_E_CC_EL_EOT_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Error const &error, char const *description,
                                   diagnostic::location const &loc,
                                   error_object_type *error_object ) {
  UserException ue( error, raise_file, raise_line, description, error_object );
  if ( loc )
    ue.set_source( loc.file(), loc.line(), loc.column() );
  return ue;
}

// MAKE_USER_EXCEPTION_CC_LT_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line ) {
  Item no_item;
  return make_user_exception( raise_file, raise_line, no_item );
}

// MAKE_USER_EXCEPTION_CC_LT_I_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Item const &error ) {
  String no_description;
  return make_user_exception( raise_file, raise_line, error, no_description );
}

// MAKE_USER_EXCEPTION_CC_LT_E_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Error const &error ) {
  String no_description;
  return make_user_exception( raise_file, raise_line, error, no_description );
}

// MAKE_USER_EXCEPTION_CC_LT_I_S_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Item const &error,
                                   String const &description ) {
  ItemSequence_t empty_seq;
  return make_user_exception(
    raise_file, raise_line, error, description, empty_seq
  );
}

// MAKE_USER_EXCEPTION_CC_LT_I_S_IS_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
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
    raise_file, raise_line, error, description.c_str(),
    diagnostic::location::empty, &error_object
  );
}

// MAKE_USER_EXCEPTION_CC_LT_E_S_IS_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Error const &error,
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
    raise_file, raise_line, error, description.c_str(), &error_object
  );
}

// MAKE_USER_EXCEPTION_CC_LT_E_S_EOT_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Error const &error,
                                   String const &description,
                                   error_object_type *error_object ) {
  return make_user_exception(
    raise_file, raise_line, error, description.c_str(),
    diagnostic::location::empty, error_object
  );
}

// MAKE_USER_EXCEPTION_CC_LT_SI_CC_EL_EOT_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   store::Item_t const &qname,
                                   char const *description,
                                   diagnostic::location const &loc,
                                   error_object_type *error_object ) {
  if ( qname.isNull() )
    return make_user_exception(
      raise_file, raise_line, zorba::err::FOER0000, description, loc,
      error_object
    );

  return make_user_exception(
    raise_file, raise_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    description, loc, error_object
  );
}

// MAKE_USER_EXCEPTION_CC_LT_I_CC_EL_EOT_X
UserException make_user_exception( char const *raise_file,
                                   ZorbaException::line_type raise_line,
                                   Item const &qname,
                                   char const *description,
                                   diagnostic::location const &loc,
                                   error_object_type *error_object ) {
  store::Item_t store_qname;
  if ( !qname.isNull() )
    store_qname = Unmarshaller::getInternalItem( qname );

  return make_user_exception(
    raise_file, raise_line, store_qname, description, loc, error_object
  );
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
