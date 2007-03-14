// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __com_bluecast_io_CharsetDecoder__
#define __com_bluecast_io_CharsetDecoder__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace com
  {
    namespace bluecast
    {
      namespace io
      {
        class CharsetDecoder;
      }
    }
  }
}

class com::bluecast::io::CharsetDecoder : public ::java::lang::Object
{
public:
  virtual jint minBytesPerChar () = 0;
  virtual jint maxBytesPerChar () = 0;
  virtual void decode (jbyteArray, jint, jint, jcharArray, jint, jint, jintArray) = 0;
  virtual ::com::bluecast::io::CharsetDecoder *newCharsetDecoder () = 0;
  virtual void reset () = 0;

  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif /* __com_bluecast_io_CharsetDecoder__ */
