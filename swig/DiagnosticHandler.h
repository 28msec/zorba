/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#ifndef API_DIAGNOSTIC_HANDLER_H
#define API_DIAGNOSTIC_HANDLER_H

/**
 * When registered with an XQuery object, a %DiagnosticHandler handles all
 * exceptions that otherwise would have been thrown or reported.
 */
class DiagnosticHandler : public zorba::DiagnosticHandler 
{
 private:
  void error (const zorba::ZorbaException &ze);
  void warning (const zorba::XQueryException &xw);
 public:
  DiagnosticHandler() {};
  virtual ~DiagnosticHandler();

  /**
   * This function is called for all exceptions.
   *
   * @param ze The exception.
   */
 virtual void error(const ZorbaException &ze); 
  //virtual void warning(const XQueryWarning &xw); 
}; // class DiagnosticHandler

#endif
