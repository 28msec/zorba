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
#include <zorba/external_function.h>
#include <zorba/item.h>
#include <zorba/iterator.h>
#include <zorba/options.h>

#include <fstream>

namespace zorba { namespace filemodule {

  class FileModule;

  class FileFunction : public NonePureStatelessExternalFunction
  {
    private:

#ifdef WIN32
      static bool
      isValidDriveSegment(
          String& value);
#endif

    protected:
      const FileModule* theModule;

      static void
      throwError(
          const std::string errorMessage,
          const Error& errorType);

      static String
      getOneStringArg(
          const StatelessExternalFunction::Arguments_t& args,
          int pos);

      static bool
      getOneBooleanArg(
          const StatelessExternalFunction::Arguments_t& args,
          int pos);

      static String
      getFilePathString(
          const StatelessExternalFunction::Arguments_t& args,
          int pos);

      static String
      getEncodingArg(
          const StatelessExternalFunction::Arguments_t& args,
          unsigned int pos);

      static String
      pathSeparator();

      static String
      pathToFullOSPath(const String& path);

      static String
      pathToOSPath(const String& path);

      static String
      pathToUriString(const String& path);

    public:
      FileFunction(const FileModule* module);
      ~FileFunction();

      virtual String
      getURI() const;

  };

  class StreamableFileFunction : public FileFunction
  {
    public:

      StreamableFileFunction(const FileModule* module);

      ~StreamableFileFunction();

    protected:

      class StreamableItemSequence : public ItemSequence {

      public:
        class InternalIterator : public Iterator
        {
          private:
            StreamableItemSequence *theItemSequence;
            bool theIsOpen;
            bool theHasNext;

          public:
            InternalIterator(StreamableItemSequence* aItemSequence)
              : theItemSequence(aItemSequence),
                theIsOpen(false),
                theHasNext(true)
            { }

            virtual void open()
            {
              theIsOpen = true;
              theHasNext = true;
            }
            virtual void close()
            {
              theIsOpen = false;
            }
            virtual bool isOpen() const
            {
              return theIsOpen;
            }
            bool next(Item& aResult);
        };

        Item          theItem;
        std::ifstream* theStream;

        StreamableItemSequence() 
          : theStream(new std::ifstream()) {}

        static void
        streamDestroyer(std::istream& stream)
        {
          delete &stream;
        }

        Iterator_t  getIterator()
        {
          return new InternalIterator(this);
        }
      };
  };

  class WriterFileFunction : public FileFunction
  {
    public:

      WriterFileFunction(const FileModule* module);

      ~WriterFileFunction();

      virtual ItemSequence_t 
      evaluate(const StatelessExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

    protected:

      virtual bool
      isAppend() const = 0;

      virtual bool
      isBinary() const = 0;
  };

} /* namespace filemodule */
} /* namespace zorba */

#endif /* ZORBA_FILEMODULE_FILEFUNCTION_H */
