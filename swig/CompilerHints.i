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


%{  // start Implementation


class CompilerHints 
{
  friend class Zorba;
  friend class StaticContext;

 private:
  Zorba_CompilerHints_t theCompilerHints;

 public:
  CompilerHints() {}
  CompilerHints(const CompilerHints& aCompilerHints) : 
    theCompilerHints(aCompilerHints.theCompilerHints) {}
  CompilerHints(Zorba_CompilerHints_t aCompilerHints) : 
    theCompilerHints(aCompilerHints) {}
    
  bool getLibModule()
  { return theCompilerHints.lib_module; }

  void setLibModule(bool aLibModule)
  { theCompilerHints.lib_module = aLibModule; }

  int getOptimizationLevel()
  { return theCompilerHints.opt_level; }

  void setOptimizationLevel(int aOptLevel)
  { 
    switch( aOptLevel )
    {
    case 0:
      theCompilerHints.opt_level = ZORBA_OPT_LEVEL_O0;
      break;
    case 1:
      theCompilerHints.opt_level = ZORBA_OPT_LEVEL_O1;
      break;
    default:
      return;
    }
  }
}; // class CompilerHints


%}  // end   Implementation

    // Interface

class CompilerHints
{
 private:
  Zorba_CompilerHints_t theCompilerHints;

 public:
  bool getLibModule();
  void setLibModule(bool aLibModule);

  int getOptimizationLevel();
  void setOptimizationLevel(int aOptLevel);
}; // class CompilerHints
