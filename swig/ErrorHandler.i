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


%{   // start Implementations

class ErrorHandler : public zorba::ErrorHandler 
{
 private:
  void error (const zorba::ZorbaException &ze) 
  { 
    if ( zorba::XQueryException const *xe = dynamic_cast<zorba::XQueryException const*>( &ze ) ) {
      const XQueryException xe2(xe);
      error(xe2); 
    }
    if ( zorba::UserException const *ue = dynamic_cast<zorba::UserException const*>( &ze ) ) {
      const UserException ue2(ue);
      error(ue2); 
    }
  }

 public:
  virtual ~ErrorHandler() {}
  virtual void error(const ZorbaException &ze) {}
 }; // class ErrorHandler


%}  // end Implementations

    // Interface

class ErrorHandler 
{
 public:
  virtual ~ErrorHandler();
  virtual void error(const ZorbaException &de); 
}; // class ErrorHandler

/* vim:set et sw=2 ts=2: */
