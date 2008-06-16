#include <vector>

#include "debugger/debugger_protocol.h"

using namespace zorba;

int test_debugger_endianness( int argc, char * argv[] )
{
  //We only perform the test on little endian systems
  if ( ! is_little_endian() )
  {
    return 0;
  }
 
  {
    std::vector< uint32_t > l1;
    std::vector< uint32_t > l2;
    l1.push_back( 0x0 );
    l2.push_back( 0x0 );
    l1.push_back( 0xffffffff );
    l2.push_back( 0xffffffff );
    l1.push_back( 0x0d0c0b0a );
    l2.push_back( 0x0a0b0c0d ); 
  
    for ( unsigned int i = 0; i < l1.size(); i++ )
    {
        assert( l1.at( i ) == uint_swap( l2.at( i ) ) );
    }
  }
  
  {
    std::vector< uint16_t > l1;
    std::vector< uint16_t > l2;
    l1.push_back( 0x0 );
    l2.push_back( 0x0 );
    l1.push_back( 0xffff );
    l2.push_back( 0xffff );
    l1.push_back( 0x0a0b );
    l2.push_back( 0x0b0a ); 
  
    for ( unsigned int i = 0; i < l1.size(); i++ )
    {
        assert( l1.at( i ) == uint_swap( l2.at( i ) ) );
    } 
  }

  return 0;
}

