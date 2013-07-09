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

#include <zorba/util/fs_util.h>

#include "file_function.h"

namespace zorba {

class ItemFactory;

namespace filemodule {

//*****************************************************************************

class BaseNameFunction : public FileFunction {
public:
  BaseNameFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class CopyFileImplFunction : public FileFunction {
public:
  CopyFileImplFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class CreateDirectoryFunction : public FileFunction {
public:
  CreateDirectoryFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class DeleteFileImplFunction : public FileFunction {
public:
  DeleteFileImplFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class DirNameFunction : public FileFunction {
public:
  DirNameFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class ExistsFunction : public FileFunction {
public:
  ExistsFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class ListFunction : public FileFunction {
public:
  ListFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
private:
  class IteratorBackedItemSequence : public ItemSequence, public Iterator {
  public:
    IteratorBackedItemSequence( String const &path, zorba::ItemFactory* );

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
    fs::iterator theIterator;
    ItemFactory* theItemFactory;
  };
};

//*****************************************************************************

class IsDirectoryFunction : public FileFunction {
public:
  IsDirectoryFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class IsFileFunction : public FileFunction {
public:
  IsFileFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class IsSymlinkFunction : public FileFunction {
public:
  IsSymlinkFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class LastModifiedFunction : public FileFunction {
public:
  LastModifiedFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;

private:
  static int getGmtOffset();
};

//*****************************************************************************

class SizeFunction : public FileFunction {
public:
  SizeFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;

private:
  static int getGmtOffset();
};

//*****************************************************************************

class PathSeparator : public FileFunction {
public:
  PathSeparator( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class DirectorySeparator : public FileFunction {
public:
  DirectorySeparator( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class ResolvePathFunction : public FileFunction {
public:
  ResolvePathFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class PathToUriFunction : public FileFunction {
public:
  PathToUriFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class PathToNativeFunction : public FileFunction {
public:
  PathToNativeFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class ReadBinaryFunction : public FileFunction {
public:
  ReadBinaryFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class ReadTextFunction : public FileFunction {
public:
  ReadTextFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;
};

//*****************************************************************************

class ReadTextLinesFunction : public FileFunction {
public:
  ReadTextLinesFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( const ExternalFunction::Arguments_t&,
            const StaticContext*,
            const DynamicContext* ) const;

protected:
  class LinesItemSequence : public ItemSequence {
  protected:
    String            theFile;
    String            theEncoding;
    const ReadTextLinesFunction* theFunc;

    class LinesIterator : public Iterator {
    protected:
      const String&     theFile;
      const String&     theEncoding;
      const ReadTextLinesFunction* theFunc;

      std::ifstream* theStream;

    public:
      LinesIterator(
          const String&,
          const String&,
          const ReadTextLinesFunction*);

      virtual ~LinesIterator();

      virtual void open();
      virtual bool next(Item&);
      virtual void close();
      virtual bool isOpen() const;
    };

  public:
    LinesItemSequence(
        const String& aFile,
        const String& aEncoding,
        const ReadTextLinesFunction*);

    Iterator_t getIterator();
  };
};

//*****************************************************************************

class WriteTextFunction : public WriterFileFunction {
public:
  WriteTextFunction( FileModule const* );

protected:
  virtual bool isAppend() const;
  virtual bool isBinary() const;
};

//*****************************************************************************

class WriteBinaryFunction : public WriterFileFunction {
public:
  WriteBinaryFunction( FileModule const* );

protected:
  virtual bool isAppend() const;
  virtual bool isBinary() const;
};

//*****************************************************************************

class AppendTextFunction : public WriterFileFunction {
public:
  AppendTextFunction( FileModule const* );

protected:
  virtual bool isAppend() const;
  virtual bool isBinary() const;
};

//*****************************************************************************

class AppendBinaryFunction : public WriterFileFunction {
public:
  AppendBinaryFunction( FileModule const* );

protected:
  virtual bool isAppend() const;
  virtual bool isBinary() const;
};

//*****************************************************************************

} // namespace filemodule
} // namespace zorba
#endif /* ZORBA_FILEMODULE_FILE_H */
/* vim:set et sw=2 ts=2: */
