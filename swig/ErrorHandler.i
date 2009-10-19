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
  void dynamicError (const zorba::DynamicException &aError) 
  { 
    const DynamicException de(&aError);
    dynamicError(de); 
  }
  void serializationError (const zorba::SerializationException &aError) 
  {
    const SerializationException se(&aError);
    serializationError(se); 
  } 
  void staticError (const zorba::StaticException &aStaticError) 
  {
    const StaticException se(&aStaticError);
    staticError(se);     
  }
  void systemError (const zorba::SystemException &aSystemError) 
  {
    const SystemException se(&aSystemError);
    systemError(se);     
  }
  void typeError (const zorba::TypeException &aTypeError) 
  {
    const TypeException te(&aTypeError);
    typeError(te);     
  }
  void userError (const zorba::UserException &aUserError)
  {
    const UserException ue(&aUserError);
    userError(ue);     
  }

 public:
  virtual ~ErrorHandler() {}
  virtual void dynamicError(const DynamicException &de) {}
  virtual void serializationError (const SerializationException &asError) {} 
  virtual void staticError (const StaticException &aStaticError) {}
  virtual void systemError (const SystemException &aSystemError) {}
  virtual void typeError (const TypeException &aTypeError) {}
  virtual void userError (const UserException &aUserError) {}
 }; // class ErrorHandler


%}  // end Implementations

    // Interface

class ErrorHandler 
{
 public:
  virtual ~ErrorHandler();
  virtual void dynamicError(const DynamicException &de); 
  virtual void serializationError(const SerializationException &e);
  virtual void staticError(const StaticException &e);
  virtual void systemError(const SystemException &e);
  virtual void typeError(const TypeException &e);
  virtual void userError(const UserException &e);
}; // class ErrorHandler
