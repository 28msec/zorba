/*
 * Copyright 2015 Federico Cavalieri.
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
#include "formatter.h"

namespace zorba
{
namespace server
{
namespace exceptions
{

void Formatter::formatException(const std::exception& aException,
                                zorba::Item& aFormattedException,
                                int& aStatusCode)
{
  utils::JSONObject lFormattedException;

  if (const zorba::ZorbaException* lZorbaException =
        dynamic_cast<const zorba::ZorbaException*>(&aException))
  {
    Formatter::formatZorbaException(*lZorbaException, lFormattedException, aStatusCode);

  }
  else if (const exceptions::ServerException* lSException =
        dynamic_cast<const exceptions::ServerException*>(&aException))
  {
    Formatter::formatServerException(*lSException, lFormattedException, aStatusCode);
  }
  else
  {
    lFormattedException.addField("source", "Internal Error");
    lFormattedException.addField("code", "INT0001");
    lFormattedException.addField("message", aException.what());
    aStatusCode = 500;
  }

  aFormattedException = lFormattedException.getAsItem();
}

void Formatter::formatZorbaException(const zorba::ZorbaException& aZorbaException,
                                     utils::JSONObject& aFormattedException,
                                     int& aStatusCode)
{

  const zorba::Diagnostic& lDiag = aZorbaException.diagnostic();

  switch (lDiag.kind())
  {
    case diagnostic::XQUERY_STATIC:
      aFormattedException.addField("source", "Query (static error)");
      break;
    case diagnostic::XQUERY_DYNAMIC:
      aFormattedException.addField("source", "Query (dynamic error)");
      break;
    case diagnostic::XQUERY_TYPE:
      aFormattedException.addField("source", "Query (type error)");
      break;
    default:
      if (dynamic_cast<const zorba::XQueryException*>(&aZorbaException))
        aFormattedException.addField("source", "Query");
      else
        aFormattedException.addField("source", "Zorba (engine error)");
  }

  std::string lCode = (lDiag.qname().ns() == NULL ?
                         "" :
                         std::string(lDiag.qname().ns()) + ":") + lDiag.qname().localname();
  aFormattedException.addField("code", lCode);
  aFormattedException.addField("message", aZorbaException.what());

  const zorba::XQueryException* lXQueryException =
      dynamic_cast<const zorba::XQueryException*>(&aZorbaException);
  if (lXQueryException)
    addStackTrace(*lXQueryException, aFormattedException);

  aStatusCode = 500;
}

void Formatter::addStackTrace(const zorba::XQueryException& aXQueryException,
                              utils::JSONObject& aFormattedException)
{
  if (aXQueryException.has_source())
  {
    utils::JSONArray lStack;

    utils::JSONObject lLocation;
    lLocation.addField("module", aXQueryException.source_uri());
    lLocation.addField("lineNumber", (long)aXQueryException.source_line());
    lLocation.addField("columnNumber", (long)aXQueryException.source_column());
    lLocation.addField("lineNumberEnd", (long)aXQueryException.source_line_end());
    lLocation.addField("columnNumberEnd", (long)aXQueryException.source_column_end());
    lStack.addMember(lLocation);

    if (!aXQueryException.query_trace().empty())
    {
      for(zorba::XQueryStackTrace::const_iterator lIt = aXQueryException.query_trace().begin();
          lIt != aXQueryException.query_trace().end();
          ++lIt)
      {
        addStackTraceEntry(*lIt, lStack);
      }
    }
    aFormattedException.addField("stackTrace", lStack);
  }
}

void Formatter::addStackTraceEntry(const XQueryStackTrace::Entry& aEntry,
                                   utils::JSONArray& aStack)
{
  utils::JSONObject lStackEntry;
  lStackEntry.addField("module", aEntry.getFileName());
  lStackEntry.addField("lineNumber", (long)aEntry.getLine());
  lStackEntry.addField("columnNumber", (long)aEntry.getColumn());
  lStackEntry.addField("lineNumberEnd", (long)aEntry.getLineEnd());
  lStackEntry.addField("columnNumberEnd", (long)aEntry.getColumnEnd());

  utils::JSONObject lFunction;
  lFunction.addField("namespaceURI", aEntry.getFnName().ns());
  lFunction.addField("namespacePrefix", aEntry.getFnName().prefix());
  lFunction.addField("localName", aEntry.getFnName().localname());
  lFunction.addField("arity", (long)aEntry.getFnArity());
  lStackEntry.addField("function", lFunction);

  aStack.addMember(lStackEntry);
}

void Formatter::formatServerException(const exceptions::ServerException& aServerException,
                                      utils::JSONObject& aFormattedException,
                                      int& aStatusCode)
{
  aFormattedException.addField("source", "Server API");
  aFormattedException.addField("message", aServerException.what());

  aStatusCode = aServerException.getStatusCode();
}

}
}
}
