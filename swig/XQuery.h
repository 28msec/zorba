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
#ifndef API_XQUERY_H
#define API_XQUERY_H

class XQuery 
{
private:
  zorba::XQuery_t theQuery;
  bool closed;

public:
  XQuery(const XQuery& aXQuery) : theQuery(aXQuery.theQuery), closed(aXQuery.closed) {}
  XQuery(zorba::XQuery_t aQuery) : theQuery(aQuery), closed(false) {}

  std::string execute();
  std::string printPlanAsXML();
  std::string printPlanAsDOT();
  void compile (const std::string &aQuery);
  void compile (const std::string &aQuery, StaticContext &aStaticContext);
#ifdef SWIGPYTHON
  void executeSAX(SAX2ContentHandlerProxy* contentHandlerProxy);
#endif

  void destroy();
  Iterator iterator();
  DynamicContext getDynamicContext();
  StaticContext getStaticContext();
  StaticCollectionManager getStaticCollectionManager();
  void getExternalVariables(Iterator vars) const;
}; // class XQuery

#endif