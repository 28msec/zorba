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
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

#include "zorbautils/runnable.h"

#ifdef WIN32
#define sleep(n) Sleep(100*n)
#endif // WIN32

class MyThread : public zorba::Runnable {

  public:
    virtual void
    run()
    {
      std::cout << __FUNCTION__ << " suspending" << std::endl;
      suspend();
      std::cout << __FUNCTION__ << " hicks" << std::endl;
    }

    
    virtual void
    finish()
    {
      std::cout << __FUNCTION__ << std::endl;
    }
}; 

int
runnable(int argc, char* argv[])
{
  {
    MyThread lThread1;
    MyThread lThread2;
    {
      lThread1.start();
      lThread2.start();

      sleep(2);

      lThread1.terminate();
      lThread2.terminate();
    }
  }
  {
    MyThread lThread;
    {
      lThread.start();

      sleep(2);

      lThread.resume();
      lThread.join();
    }
  }
  return 0;

}

