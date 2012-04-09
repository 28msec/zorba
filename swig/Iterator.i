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

%{  // start Implementation

  void Iterator::open()
  {
    if (theIterator)
      theIterator->open();
    theConsumed = false;
  }

  bool Iterator::isOpen()
  {
    if (theIterator)
      return theIterator->isOpen();
    else 
      return !theConsumed;
  }

  void Iterator::close()
  {
    if (theIterator)
      theIterator->close();
    theConsumed = true;
  }

  void Iterator::destroy()
  {
    theIterator = 0;
  }

  bool Iterator::next(Item& aItem)
  {
    if (theIterator)
    {
      return theIterator->next(aItem.theItem);
    }
    else
    {
      if (!theConsumed)
      {
        aItem = theItem;
        return true;
      }
      else
      {
        return false;
      }
    }
  }


%}  // end   Implementation

%include "Iterator.h"
