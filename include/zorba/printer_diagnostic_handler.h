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

#ifndef ZORBA_PRINTER_ERROR_HANDLER_API_H
#define ZORBA_PRINTER_ERROR_HANDLER_API_H

#include <zorba/config.h>
#include <zorba/diagnostic_handler.h>

namespace zorba {

class PrinterDiagnosticHandler : public DiagnosticHandler
{
public:
  PrinterDiagnosticHandler(std::ostream&, bool aPrintAsXml = false, bool aIndenXml = false);

  virtual ~PrinterDiagnosticHandler();

  virtual void error( ZorbaException const &exception );

protected:
  std::ostream& theOStream;
  bool          thePrintAsXml;
  bool          theIndent;
};

} // namespace zorba

#endif /* ZORBA_PRINTER_ERROR_HANDLER_API_H */
/* vim:set et sw=2 ts=2: */
