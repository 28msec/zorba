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

#include <iostream>
#include <fstream>
#include <sstream>

#include <zorba/zorba.h>
#include <simplestore/simplestore.h>


using namespace zorba;

/**
 * Example to show the use mail function.
 */
bool
email_example_1(Zorba* aZorba)
{
  StaticContext_t lStaticContext = aZorba->createStaticContext();

  XQuery_t lQuery = aZorba->compileQuery("import module namespace ze = 'http://www.zorba-xquery.com/modules/email/smtp'; declare namespace op = 'http://www.zorba-xquery.org/options'; declare option op:SMTPServer 'smtp.gmail.com:587/tls/novalidate-cert'; declare option op:SMTPUser 'username'; declare option op:SMTPPwd 'zorbaisgreat'; ze:mail('userTo@domain.com','','','this is a test email','it works!')",
          lStaticContext);

  try {

    std::cout << lQuery << std::endl;

  } catch (SystemException &e) {
    std::cerr << e << std::endl;
    return true;
  }

  return false;
}

int 
email(int argc, char* argv[])
{
  simplestore::SimpleStore* lStore = simplestore::SimpleStoreManager::getStore();

  Zorba* lZorba = Zorba::getInstance(lStore);
  bool res = false;

  std::cout << "executing example 1" << std::endl;
  res = email_example_1(lZorba);
  if (!res) return 1;
  std::cout << std::endl;

  lZorba->shutdown();
  simplestore::SimpleStoreManager::shutdownStore(lStore);
  return 0;
}
