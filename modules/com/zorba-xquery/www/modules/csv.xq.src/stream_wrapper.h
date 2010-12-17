#ifndef ZORBA_PROCESSMODULE_PROCESS_H
#define ZORBA_PROCESSMODULE_PROCESS_H

#include <zorba/zorba.h>
#include <zorba/smart_ptr.h>

namespace zorba {
namespace csv {

class CharStreamBase : public SmartObject
{
public:
  virtual ~CharStreamBase() {}

  virtual bool is_end() = 0;

  virtual unsigned int get_utf8_sequence_length() = 0;
  virtual const char *get_utf8_seq() = 0;
  virtual bool compare(std::string &other) = 0;
  virtual void skip(unsigned int nr_chars) = 0;
};

class StreamWrapper : public CharStreamBase
{
public:
	std::istream *csv_is;
  char *tempstr;
  char *start_str;
  char *end_str;
  unsigned int temp_buf_size;
  unsigned int utf8_len;

  StreamWrapper(Item string_item, unsigned int temp_buf_size);
  virtual ~StreamWrapper();

  virtual bool is_end();

  virtual unsigned int get_utf8_sequence_length();
  virtual const char *get_utf8_seq();
  virtual bool compare(std::string &other);
  virtual void skip(unsigned int nr_chars);
private:
  void read_buf();
};

class CharPtrStream : public CharStreamBase
{
public:
  Item string_item;
  zorba::String csv_string;
  const char *str;

  CharPtrStream(Item string_item);
  virtual ~CharPtrStream();
  
  virtual bool is_end();

  virtual unsigned int get_utf8_sequence_length();
  virtual const char *get_utf8_seq();
  virtual bool compare(std::string &other);
  virtual void skip(unsigned int nr_chars);
};

}}

#endif