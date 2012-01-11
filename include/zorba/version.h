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
#ifndef ZORBA_VERSION_API_H
#define ZORBA_VERSION_API_H

#include <string>

#include <zorba/config.h>

namespace zorba {

  /**
   * Provide access to the version of %Zorba that is used
   */
  class ZORBA_DLL_PUBLIC Version
  { 
    protected:
      static int theMajorVersion;
      static int theMinorVersion;
      static int thePatchVersion;

    public:
      /** \brief Get the major version
       */
      static int 
      getMajorVersion();

      /** \brief Get the minor version
       */
      static int 
      getMinorVersion();

      /** \brief Get the patch version
       */
      static int 
      getPatchVersion();

      /** \brief Get the %Zorba version as std::string
       *
       * Form: MajorVersion.MinorVersion.PatchVersion
       */
      static std::string
      getVersion();

  };

  /** \brief Write the result of calling aVersiongetVersion() to the given
   *         output stream.
   */
  ZORBA_DLL_PUBLIC
  std::ostream& 
  operator<< (std::ostream& os, const Version& aVersion);


} /* end namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
