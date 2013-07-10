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
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class CopyFileImplFunction : public FileFunction {
public:
  CopyFileImplFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class CreateDirectoryFunction : public FileFunction {
public:
  CreateDirectoryFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class DeleteFileImplFunction : public FileFunction {
public:
  DeleteFileImplFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class DirNameFunction : public FileFunction {
public:
  DirNameFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class ExistsFunction : public FileFunction {
public:
  ExistsFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class ListFunction : public FileFunction {
public:
  ListFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
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
    ItemFactory *theItemFactory;
  };
};

//*****************************************************************************

class IsDirectoryFunction : public FileFunction {
public:
  IsDirectoryFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class IsFileFunction : public FileFunction {
public:
  IsFileFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class IsSymlinkFunction : public FileFunction {
public:
  IsSymlinkFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class LastModifiedFunction : public FileFunction {
public:
  LastModifiedFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;

private:
  static int getGmtOffset();
};

//*****************************************************************************

class SizeFunction : public FileFunction {
public:
  SizeFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;

private:
  static int getGmtOffset();
};

//*****************************************************************************

class PathSeparator : public FileFunction {
public:
  PathSeparator( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class DirectorySeparator : public FileFunction {
public:
  DirectorySeparator( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class ResolvePathFunction : public FileFunction {
public:
  ResolvePathFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class PathToUriFunction : public FileFunction {
public:
  PathToUriFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class PathToNativeFunction : public FileFunction {
public:
  PathToNativeFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class ReadBinaryFunction : public FileFunction {
public:
  ReadBinaryFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class ReadTextFunction : public FileFunction {
public:
  ReadTextFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;
};

//*****************************************************************************

class ReadTextLinesFunction : public FileFunction {
public:
  ReadTextLinesFunction( FileModule const* );

  virtual ItemSequence_t
  evaluate( ExternalFunction::Arguments_t const&,
            StaticContext const*,
            DynamicContext const* ) const;

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

class WriteTextFunction : public WriteTextFunctionImpl {
public:
  WriteTextFunction( FileModule const* );
};

//*****************************************************************************

class WriteBinaryFunction : public WriteBinaryFunctionImpl {
public:
  WriteBinaryFunction( FileModule const* );
};

//*****************************************************************************

class AppendTextFunction : public WriteTextFunctionImpl {
public:
  AppendTextFunction( FileModule const* );
};

//*****************************************************************************

class AppendBinaryFunction : public WriteBinaryFunctionImpl {
public:
  AppendBinaryFunction( FileModule const* );
};

//*****************************************************************************

} // namespace filemodule
} // namespace zorba
#endif /* ZORBA_FILEMODULE_FILE_H */
/* vim:set et sw=2 ts=2: */
