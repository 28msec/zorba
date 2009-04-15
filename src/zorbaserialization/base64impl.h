
#ifndef ZORBA_BASE64_IMPLEMENTATION
#define ZORBA_BASE64_IMPLEMENTATION

namespace zorba{
  namespace serialization{

class Base64Impl
{
public:
  static const char base64chars[];
public:
  static unsigned int Encode(const unsigned char *datain, unsigned int datalen,
			    char *dataout);///pre-allocated at the right size
  static unsigned int  Decode(const unsigned char *datain, unsigned int datalen,
			  unsigned char *dataout);
protected:
  static unsigned char getChar6BitIndex(char c);
};

}}
#endif
