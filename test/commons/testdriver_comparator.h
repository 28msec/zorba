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
#ifndef TEST_TESTDRIVER_COMPARATOR
#define TEST_TESTDRIVER_COMPARATOR

#include <zorba/zorba.h>
#include <iostream>

namespace zorba {

bool
fileEquals(const char* aRefFile, const char* aResFile, int& aLine, int& aCol, std::string& aRefLine, std::string& aResLine, std::ostream& = std::cout);

int
canonicalizeAndCompare(const std::string& aComparisonMethod,
                       const char* aRefFile,
                       const char* aResultFile,
                       const std::string& aRBKTBinDir,
                       std::ostream& = std::cout);

void
printFile(std::ostream& os, const std::string &aInFile);

void
printPart(std::ostream& os, const std::string &aInFile, int aStartPos, int aLen);

void
trim(std::string& str);

} /* namespace zorba */
#endif
