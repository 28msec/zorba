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

#ifndef ZORBA_FILEMODULE_FILEFUNCTION_H
#define ZORBA_FILEMODULE_FILEFUNCTION_H

#include <zorba/error.h>
#include <zorba/function.h>
#include <zorba/item.h>
#include <zorba/iterator.h>
#include <zorba/options.h>

#include <fstream>

namespace zorba {
namespace filemodule {

///////////////////////////////////////////////////////////////////////////////

class FileModule;

class FileFunction : public ContextualExternalFunction {
private:

#ifdef WIN32
  static bool
  isValidDriveSegment(
      String& value);
#endif

protected:
  char const *const local_name_;
  const FileModule* theModule;

  int
  raiseFileError(
      char const *qName,
      char const *message,
      const String& path) const;

  /**
   * Gets the argument on position pos as a normalised file system path.
   * pos must point to a file function argument. No checks are made.
   */
  String
  getPathArg(
    const ExternalFunction::Arguments_t& args,
    unsigned int pos) const;

  String
  getEncodingArg(
    const ExternalFunction::Arguments_t& args,
    unsigned int pos) const;

  String
  getStringArg(
    const ExternalFunction::Arguments_t& args,
    unsigned int pos) const;

  String pathToFullOSPath(const String& path) const;
  String pathToOSPath(const String& path) const;
  String pathToUriString(const String& path) const;

public:
  FileFunction( FileModule const *module, char const *local_name );

  virtual String getLocalName() const;
  virtual String getURI() const;
};

///////////////////////////////////////////////////////////////////////////////

class StreamableFileFunction : public FileFunction {
public:
  StreamableFileFunction( FileModule const*, char const *local_name );

protected:
  class StreamableItemSequence : public ItemSequence {
  public:
    class InternalIterator : public Iterator {
    private:
      StreamableItemSequence *theItemSequence;
      bool theIsOpen;
      bool theHasNext;

    public:
      InternalIterator(StreamableItemSequence* aItemSequence) :
        theItemSequence(aItemSequence),
        theIsOpen(false),
        theHasNext(true)
      { }

      void open();
      void close();
      bool isOpen() const;
      bool next( Item &aResult );
    };

    Item                 theItem;
    std::ifstream*       theStream;

    StreamableItemSequence() : theStream( new std::ifstream() ) { }

    Iterator_t getIterator() {
      return new InternalIterator( this );
    }
  };
};

///////////////////////////////////////////////////////////////////////////////

class WriterFileFunction : public FileFunction {
public:
  WriterFileFunction( FileModule const*, char const *local_name );

  virtual ItemSequence_t 
  evaluate(const ExternalFunction::Arguments_t& args,
            const StaticContext* aSctxCtx,
            const DynamicContext* aDynCtx) const;

protected:
  virtual bool isAppend() const = 0;
  virtual bool isBinary() const = 0;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace filemodule
} // namespace zorba

#endif /* ZORBA_FILEMODULE_FILEFUNCTION_H */
/* vim:set et sw=2 ts=2: */
