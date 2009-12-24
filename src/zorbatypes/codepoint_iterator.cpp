
#include "codepoint_iterator.h"
#include "zorbatypes/utf8.h"

namespace zorba{

string_codepoints_iterator& string_codepoints_iterator::operator++()
{
#ifndef ZORBA_NO_UNICODE
  this->last_seq_len = sequence_length(str+pos);
#else
  this->last_seq_len = 1;
#endif
  pos += last_seq_len;
  return *this;
}
void string_codepoints_iterator::unread_last_codepoint()
{
  pos -= last_seq_len;
}
uint32_t string_codepoints_iterator::operator*() const
{
  const char  *str_pos = str+pos;
#ifndef ZORBA_NO_UNICODE
  return UTF8Decode(str_pos);
#else
  return *str_pos;
#endif
}
/*
unsigned int string_codepoints_iterator::compare_cp(checked_vector<uint32_t> &cp)
{
  const char *strtemp = str+pos;
  unsigned int i;
  for(i=0;i<cp.size(); i++)
  {
    if(UTF8Decode(strtemp) != cp[i])
      break;
    operator++();
  }
  return i;
}
*/


ifstream_codepoints_iterator::ifstream_codepoints_iterator(std::ifstream *ifs) 
{
  this->ifs = ifs; 
  cp[0] = read_cp();
  this->write_pos = 1;
  this->read_pos = 0;
}

uint32_t  ifstream_codepoints_iterator::read_cp()
{
  char  c[4];
  ifs->read(c, 1);
  if(ifs->gcount() < 1)
    return 0;
#ifndef ZORBA_NO_UNICODE
  int  seq_len = sequence_length(c);
#else
  int seq_len = 1;
#endif
  if(seq_len > 1)
  {
    ifs->read(c+1, seq_len-1);
    if(ifs->gcount() < (seq_len-1))
      return 0;
  }
  char *pc = c;
#ifndef ZORBA_NO_UNICODE
  return UTF8Decode(pc);
#else
  return *pc;
#endif
}
unicode_codepoint_iterator& ifstream_codepoints_iterator::operator++()
{
  read_pos++;
  if(read_pos == write_pos)
  {
    if(write_pos == 2)
    {
      cp[0] = cp[1];
      read_pos--;
    }
    else
      write_pos++;
    cp[1] = read_cp();
  }
  return *(unicode_codepoint_iterator*)this;
}
void ifstream_codepoints_iterator::unread_last_codepoint()
{
  read_pos--;
  assert(read_pos >= 0);
}
//bool operator!=(unicode_codepoint_iterator &other) {return (str!=other.str)||(pos!=other.pos);}
uint32_t ifstream_codepoints_iterator::operator*() const
{
  return cp[read_pos];
}
bool ifstream_codepoints_iterator::is_end()
{
  return !cp[read_pos];
}
unsigned int unicode_codepoint_iterator::compare_cp(checked_vector<uint32_t> &cp)
{
  unsigned int len = 0;
  
  for(len=0;len < cp.size(); len++)
  {
    if((**this) != cp[len])
      break;
    ++(*this);
  }
  return len;
}

}