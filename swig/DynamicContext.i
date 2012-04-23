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

  bool DynamicContext::getContextItem (Item& aItem) {
    return theContext->getContextItem(aItem.theItem);
  }
  Item DynamicContext::getCurrentDateTime (){
    return Item(theContext->getCurrentDateTime());
  }
  Item DynamicContext::getDefaultCollection () {
    return Item(theContext->getDefaultCollection());
  }
  int 	DynamicContext::getImplicitTimezone (){
    return theContext->getImplicitTimezone();
  }
  bool 	DynamicContext::getVariable (const std::string& aNamespace, const std::string& aLocalname, Item& aItem, Iterator& aIterator) {
    return theContext->getVariable(aNamespace, aLocalname, aItem.theItem, aIterator.theIterator);
  }

  bool DynamicContext::setContextItem (Item& aItem) {
    return theContext->setContextItem(aItem.theItem);
  }
  bool DynamicContext::setCurrentDateTime (Item& aDateTimeItem) {
    return theContext->setCurrentDateTime(aDateTimeItem.theItem);
  }
  bool DynamicContext::setDefaultCollection (Item& aCollectionUri) {
    return theContext->setDefaultCollection(aCollectionUri.theItem);
  }
  bool DynamicContext::setImplicitTimezone (int aTimezone) {
    return theContext->setImplicitTimezone(aTimezone);
  }
  bool DynamicContext::setVariable(const std::string& aNamespace, const std::string& aLocalname, Iterator& aIter) {
    return theContext->setVariable(aNamespace, aLocalname, aIter.theIterator);
  }
  bool DynamicContext::setVariable (const std::string& aQName, Item& aItem) {
    return theContext->setVariable (aQName, aItem.theItem);
  }
  bool DynamicContext::setVariable (const std::string& aQName, Iterator& aIterator) {
    return theContext->setVariable (aQName, aIterator.theIterator);
  }

%}  // end   Implementation

%include "DynamicContext.h"
