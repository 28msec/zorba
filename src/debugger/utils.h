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

#ifndef ZORBA_DEBUGGER_UTILS
#define ZORBA_DEBUGGER_UTILS
namespace zorba
{
  template<class T>
  class ZorbaArrayAutoPointer
  {
    private:
      T* thePtr;
  
    public:
      ZorbaArrayAutoPointer(): thePtr(0){}
      ZorbaArrayAutoPointer(T *aPtr): thePtr(aPtr){}
  
      ~ZorbaArrayAutoPointer()
      {
        delete[] thePtr;
      }
  
      void reset(T *aPtr)
      {
        T* lPtr = thePtr;
        thePtr = aPtr;
        delete[] lPtr;
      }
  
      T* get()
      {
        return thePtr;
      }

      T* release()
      {
        T* lPtr = thePtr;
        thePtr = 0;
        return lPtr;
      }
  };
}//end of namespace
#endif
