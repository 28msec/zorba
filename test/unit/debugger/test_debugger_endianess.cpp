#include "debugger/debugger_protocol.h"

using namespace zorba;

int test_debugger_endianess( int argc, char * argv[] )
{
  uint32_t  lWord = 0;
  uint32_t  lRevertedWord = 16777216;
  uint16_t  lShortWord = 767;
  uint16_t  lRevertedShortWord = 2;
  
  if ( is_little_endian() )
  {
    std::cerr << uint_swap( lRevertedWord ) << std::endl;
    assert( lRevertedWord == uint_swap( lWord ) ); 
  } else {
    assert( lWord == uint_swap( lWord ) );
  }
  
  if ( is_little_endian() )
  {
    std::cerr << uint_swap( lRevertedShortWord ) << std::endl;
    assert( lRevertedShortWord == uint_swap( lShortWord ) );
  } else {
    assert( lShortWord == uint_swap( lShortWord ) );
  }
  return 0;
}

