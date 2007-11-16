/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file utf8/Unicode_util.cpp
 */

#include "util/utf8/Unicode_util.h"

 namespace xqp {

bool isUpper(uint32_t c){
  uint32_t i;
  for (i = 0; i < TABLE_SIZE (title_table); ++i)
    if (title_table[i][0] == c)
      return true;
  return false;
}

bool isLower(uint32_t c){
  uint32_t i;
  for (i = 0; i < TABLE_SIZE (title_table); ++i)
    if (title_table[0][i] == c)
      return true;
  return false;
}

uint32_t toUpper(uint32_t c){
  uint32_t i;
  for (i = 0; i < TABLE_SIZE (title_table); i++)
    if (title_table[i][1] == c)
      return title_table[i][0];
  return c;
}
  
uint32_t toLower(uint32_t c){
  uint32_t i;
  for (i = 0; i < TABLE_SIZE (title_table); i++)
    if (title_table[i][0] == c)
      return title_table[i][1];
  return c;
}

}/* namespace xqp */
