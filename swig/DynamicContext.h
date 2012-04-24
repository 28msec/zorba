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
#ifndef API_DYNAMIC_CONTEXT_H
#define API_DYNAMIC_CONTEXT_H

class DynamicContext
{
private:
  zorba::DynamicContext* theContext;
public:

  DynamicContext():theContext(0) {}
  DynamicContext(const DynamicContext& aCtx):theContext(aCtx.theContext) {}
  DynamicContext(zorba::DynamicContext* aCtx):theContext(aCtx) {}

  bool 	getContextItem (Item& aItem);
  Item 	getCurrentDateTime ();
  Item 	getDefaultCollection ();
  int 	getImplicitTimezone ();
  bool 	getVariable (const std::string& aNamespace, const std::string& aLocalname, Item& aItem, Iterator& aIterator);
  
  bool setContextItem (Item& aItem);
  bool setCurrentDateTime (Item& aDateTimeItem);
  bool setDefaultCollection (Item& aCollectionUri);
  bool setImplicitTimezone (int aTimezone);
  bool setVariable (const std::string& aNamespace, const std::string& aLocalname, Iterator& aIter);
  bool setVariable (const std::string& aQName, Item& aItem);
  bool setVariable (const std::string& aQName, Iterator& aIterator);

};

#endif