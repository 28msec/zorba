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
#include <string>
#include <ostream>
#include <sstream>

#include <zorba/version.h>

namespace zorba {

  // the following vars will be replaced by cmake
  int Version::theMajorVersion = @ZORBA_MAJOR_NUMBER@;
  int Version::theMinorVersion = @ZORBA_MINOR_NUMBER@;
  int Version::thePatchVersion = @ZORBA_PATCH_NUMBER@;

  int
  Version::getMajorVersion() { return theMajorVersion; }

  int
  Version::getMinorVersion() { return theMinorVersion; }

  int
  Version::getPatchVersion() { return thePatchVersion; }

  std::string
  Version::getVersion() 
  {
    std::ostringstream lStream;
    lStream << getMajorVersion() << "." << getMinorVersion() << "." << getPatchVersion();
    return lStream.str();
  }


  std::ostream& operator<< (std::ostream& os, const Version& aVersion)
  {
    os << aVersion.getVersion();
    return os;
  }

} /* end namespace zorba */
