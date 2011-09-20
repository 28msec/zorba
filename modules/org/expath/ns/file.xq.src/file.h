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
#ifndef ZORBA_FILEMODULE_FILE_H
#define ZORBA_FILEMODULE_FILE_H

#include "file_function.h"

namespace zorba { 
  
  class ItemFactory;

  namespace filemodule {

//*****************************************************************************

  class CreateDirectoryFunction : public FileFunction
  {
    public:
      CreateDirectoryFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "create-directory"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class DeleteFileImplFunction : public FileFunction
  {
    public:
      DeleteFileImplFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "delete-file-impl"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class CopyFileImplFunction : public FileFunction
  {
    public:
      CopyFileImplFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "copy-file-impl"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class ExistsFunction : public FileFunction
  {
    public:
      ExistsFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "exists"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class ListFunction : public FileFunction
  {
    public:
      ListFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "list"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
    private:
      class IteratorBackedItemSequence : public ItemSequence , public Iterator{

        public:
          IteratorBackedItemSequence(
              DirectoryIterator_t& aIter,
              zorba::ItemFactory* aFactory);

          virtual ~IteratorBackedItemSequence();

          //ItemSequence interface
          Iterator_t getIterator();

          //Iterator interface
          virtual void open();
          virtual bool next(Item& aItem);
          virtual void close();
          virtual bool isOpen() const;
        private:
          bool is_open;
          int  open_count;
          DirectoryIterator_t theIterator;
          ItemFactory* theItemFactory;
    };
  };

//*****************************************************************************

  class IsDirectoryFunction : public FileFunction
  {
    public:
      IsDirectoryFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "is-directory"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class IsFileFunction : public FileFunction
  {
    public:
      IsFileFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "is-file"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class LastModifiedFunction : public FileFunction
  {
    public:
      LastModifiedFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "last-modified"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  private:
      static int
      getGmtOffset();

  };

//*****************************************************************************

  class SizeFunction : public FileFunction
  {
    public:
      SizeFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "size"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;

  private:
      static int
      getGmtOffset();

  };

//*****************************************************************************

  class PathSeparator : public FileFunction
  {
    public:
      PathSeparator(const FileModule* aModule);

      virtual String
      getLocalName() const { return "path-separator"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class DirectorySeparator : public FileFunction
  {
    public:
      DirectorySeparator(const FileModule* aModule);

      virtual String
      getLocalName() const { return "directory-separator"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class ResolvePathFunction : public FileFunction
  {
    public:
      ResolvePathFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "resolve-path"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class PathToUriFunction : public FileFunction
  {
    public:
      PathToUriFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "path-to-uri"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class PathToNativeFunction : public FileFunction
  {
    public:
      PathToNativeFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "path-to-native"; }

      virtual ItemSequence_t
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aStctxCtx,
               const DynamicContext* aDznCtx) const;
  };

//*****************************************************************************

  class ReadBinaryFunction : public FileFunction
  {
    public:
      ReadBinaryFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "read-binary"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class ReadTextFunction : public StreamableFileFunction
  {
    public:
      ReadTextFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "read-text"; }
  
      virtual ItemSequence_t 
      evaluate(const ExternalFunction::Arguments_t& args,
               const StaticContext* aSctxCtx,
               const DynamicContext* aDynCtx) const;
  };

//*****************************************************************************

  class WriteTextFunction : public WriterFileFunction
  {
    public:
      WriteTextFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "write-text"; }
  
    protected:
      virtual bool
      isAppend() const;

      virtual bool
      isBinary() const;
  };

//*****************************************************************************

  class WriteBinaryFunction : public WriterFileFunction
  {
    public:
      WriteBinaryFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "write-binary"; }
  
    protected:
      virtual bool
      isAppend() const;

      virtual bool
      isBinary() const;
  };

//*****************************************************************************

  class AppendTextFunction : public WriterFileFunction
  {
    public:
      AppendTextFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "append-text"; }
  
    protected:
      virtual bool
      isAppend() const;

      virtual bool
      isBinary() const;
  };

//*****************************************************************************

  class AppendBinaryFunction : public WriterFileFunction
  {
    public:
      AppendBinaryFunction(const FileModule* aModule);

      virtual String
      getLocalName() const { return "append-binary"; }
  
    protected:
      virtual bool
      isAppend() const;

      virtual bool
      isBinary() const;
  };

//*****************************************************************************

} /* namespace filemodule */ } /* namespace zorba */

#endif /* ZORBA_FILEMODULE_FILE_H */
