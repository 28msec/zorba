/*
  100% free public domain implementation of the HMAC-SHA1 algorithm
  by Chien-Chung, Chung (Jim Chung) <jimchung1221@gmail.com>
*/


#ifndef ZORBA_HMAC_SHA1_H
#define ZORBA_HMAC_SHA1_H

#include "sha1.h"

namespace zorba { namespace securitymodule {

class CHMAC_SHA1 : public CSHA1
{
    private:
    unsigned char m_ipad[64];
    unsigned char m_opad[64];

    char * szReport ;
    char * SHA1_Key ;
    char * AppendBuf1 ;
    char * AppendBuf2 ;


  public:
    
    enum {
      SHA1_DIGEST_LENGTH  = 20,
      SHA1_BLOCK_SIZE    = 64,
      HMAC_BUF_LEN    = 4096
    } ;

    CHMAC_SHA1()
      :szReport(new char[HMAC_BUF_LEN]),
             SHA1_Key(new char[HMAC_BUF_LEN]),
             AppendBuf1(new char[HMAC_BUF_LEN]),
             AppendBuf2(new char[HMAC_BUF_LEN])
    {}

        ~CHMAC_SHA1()
        {
            delete[] szReport ;
            delete[] AppendBuf1 ;
            delete[] AppendBuf2 ;
            delete[] SHA1_Key ;
        }

        void HMAC_SHA1(unsigned char *text, 
                       int text_len, 
                       unsigned char *key, 
                       int key_len, 
                       unsigned char *digest);
};

}}

#endif /* ZORBA_HMAC_SHA1_H */

