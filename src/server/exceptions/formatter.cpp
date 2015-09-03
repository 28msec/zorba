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
      aFormattedException.addField("source", "Zorba (query static error)");
      break;
    case diagnostic::XQUERY_DYNAMIC:
      aFormattedException.addField("source", "Zorba (query dynamic error)");
      break;
    case diagnostic::XQUERY_TYPE:
      aFormattedException.addField("source", "Zorba (query type error)");
      break;
    default:
      if (dynamic_cast<const zorba::XQueryException*>(&aZorbaException))
        aFormattedException.addField("source", "Zorba (query error)");
      else
        aFormattedException.addField("source", "Zorba (engine error)");
  }

  std::string lCode = (lDiag.qname().ns() == NULL ? "" : std::string(lDiag.qname().ns()) + ":") + lDiag.qname().localname();
  aFormattedException.addField("code", lCode);

  const zorba::XQueryException* lXQueryException =
      dynamic_cast<const zorba::XQueryException*>(&aZorbaException);
  if (lXQueryException)
  {
    if (!lXQueryException->query_trace().empty())
    {
      utils::JSONArray lStack;
      for(zorba::XQueryStackTrace::const_iterator lIt = lXQueryException->query_trace().begin();
          lIt != lXQueryException->query_trace().end();
          ++lIt)
      {
        utils::JSONObject lStackEntry;
        lStackEntry.addField("module", lIt->getFileName());

        lStackEntry.addField("functionNamespaceURI", lIt->getFnName().ns());
        lStackEntry.addField("functionNamespacePrefix", lIt->getFnName().prefix());
        lStackEntry.addField("functionLocalName", lIt->getFnName().localname());
        lStackEntry.addField("functionArity", (long)lIt->getFnArity());
        lStackEntry.addField("lineNumber", (long)lIt->getLine());
        lStackEntry.addField("columnNumber", (long)lIt->getLineEnd());
        lStackEntry.addField("lineNumberEnd", (long)lIt->getColumn());
        lStackEntry.addField("columnNumberEnd", (long)lIt->getColumnEnd());
        lStack.addMember(lStackEntry);
      }
      aFormattedException.addField("stackTrace", lStack);
    }

    if (lXQueryException->has_source())
    {
      utils::JSONObject lLocation;
      lLocation.addField("module", lXQueryException->source_uri());
      lLocation.addField("lineNumber", (long)lXQueryException->source_line());
      lLocation.addField("columnNumber", (long)lXQueryException->source_column());
      lLocation.addField("lineNumberEnd", (long)lXQueryException->source_line_end());
      lLocation.addField("columnNumberEnd", (long)lXQueryException->source_column_end());
      aFormattedException.addField("location", lLocation);
    }
  }

  aFormattedException.addField("message", aZorbaException.what());

  aStatusCode = 500;
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
