#ifndef ZORBATYPES_UNICODE_CODEPOINT_ITERATOR
#define ZORBATYPES_UNICODE_CODEPOINT_ITERATOR

#include <zorba/config.h>
#include "zorbautils/checked_vector.h"
#include <fstream>

namespace zorba{

/*abstract class, see specializations for xqpString and ifstream*/
class unicode_codepoint_iterator
{
public:
  virtual ~unicode_codepoint_iterator() {}
  virtual unicode_codepoint_iterator& operator++() = 0;
  virtual void unread_last_codepoint() = 0;
  virtual uint32_t operator*() const = 0;
  virtual bool is_end() = 0;
  unsigned int compare_cp(checked_vector<uint32_t> &cp);
};

class string_codepoints_iterator : public unicode_codepoint_iterator
{
  const char  *str;
  int   pos;
  int   last_seq_len;
  public:
    string_codepoints_iterator() {str=NULL;pos=0;last_seq_len=0;}
    string_codepoints_iterator(const char *str) {this->str = str; this->pos = 0;this->last_seq_len=0;}
    string_codepoints_iterator& operator++();
    void unread_last_codepoint();
    //bool operator!=(codepoints_iterator &other) {return (str!=other.str)||(pos!=other.pos);}
    uint32_t operator*() const;
    bool is_end() {return !str[pos];}
};

class ifstream_codepoints_iterator : public unicode_codepoint_iterator
{
  std::ifstream    *ifs;
  uint32_t  cp[2];
  int       write_pos;
  int       read_pos;
public:
  ifstream_codepoints_iterator() {ifs=NULL;}
  ifstream_codepoints_iterator(std::ifstream *ifs);
  unicode_codepoint_iterator& operator++();
  void unread_last_codepoint();
  //bool operator!=(unicode_codepoint_iterator &other) {return (str!=other.str)||(pos!=other.pos);}
  uint32_t operator*() const;
  bool is_end();
private:
  uint32_t  read_cp();
};

}
#endif
