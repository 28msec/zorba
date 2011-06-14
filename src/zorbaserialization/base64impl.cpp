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
#include "stdafx.h"

#include "zorbaserialization/base64impl.h"


namespace zorba{
  namespace serialization{

////Base64

const char Base64Impl::base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/*
	Transform each 6 bits into a character

  dataout len must be 8/6*datalen+2
  return dataoutlen
*/
size_t
Base64Impl::Encode(const unsigned char *datain, size_t datalen,
			  char *dataout)///pre-allocated at the right size
{
	unsigned char	rembits6;
	unsigned char	rembits8;
	unsigned char	temp6;
	unsigned char	temp8;
	unsigned int	index;
	char	*orig_dataout = dataout;

	temp6 = 0;
	rembits6 = 6;
	rembits8 = 8;
	index = 0;
	temp8 = datain[0];

	while(index < datalen)
	{
		temp6 <<= 1;
		if(temp8 & 0x80)
			temp6 |= 1;
		temp8 <<= 1;
		rembits8--;
		if(rembits8 == 0)
		{
			rembits8 = 8;
			datain++;
			temp8 = datain[0];
			index++;
		}
		rembits6--;
		if(rembits6 == 0)
		{
			rembits6 = 6;
			dataout[0] = base64chars[temp6];
			dataout++;
			temp6 = 0;
		}
	}
	if(rembits6 != 6)
	{
		temp6 <<= rembits6;
		rembits6 = 0;
		dataout[0] = base64chars[temp6];
		dataout++;
	}
	if((datalen%3) == 1)
	{
		///add two more 6bit bytes
		dataout[0] = dataout[1] = '=';
		dataout += 2;
	}
	if((datalen%3) == 2)
	{
		///add two more 6bit bytes
		dataout[0] = '=';
		dataout++;
	}
  dataout[0] = 0;

	return dataout - orig_dataout;
}

//static const char base64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
unsigned char
Base64Impl::getChar6BitIndex(char c)
{
	if((c >= 'A') && (c <= 'Z'))
		return c-'A';
	if((c >= 'a') && (c <= 'z'))
		return c-'a' + 'Z' - 'A' + 1;
	if((c >= '0') && (c <= '9'))
		return c-'0' + 'Z' - 'A' + 1 + 'z' - 'a' + 1;
	if(c == '+')
		return 62;
	if(c == '/')
		return 63;
	return 0xFF;///special case for '='
}

/*
	dataout must be pre-allocated for 6/8*datalen
return dataoutlen
*/
size_t
Base64Impl::Decode(const unsigned char *datain, size_t datalen,
			  unsigned char *dataout)
{
	unsigned char	*orig_dataout = dataout;
	unsigned char	rembits6;
	unsigned char	rembits8;
	unsigned char	temp8;
	unsigned char	temp6;

	rembits6 = 6;
	rembits8 = 8;
	temp8 = 0;
	temp6 = getChar6BitIndex(datain[0]);

	while(datalen)
	{
		temp8 <<= 1;
		if(temp6 & 0x20)
			temp8 |= 1;
		temp6 <<= 1;
		rembits8--;
		if(rembits8 == 0)
		{
			dataout[0] = temp8;
			dataout++;
			rembits8 = 8;
			temp8 = 0;
		}
		rembits6--;
		if(rembits6 == 0)
		{
			do{
				datain++;
				datalen--;
			}while(((datain[0] == '\r')||(datain[0] == '\n'))&&datalen);
			if(!datalen)
				break;
			if(datain[0] == '=')
				break;
			temp6 = getChar6BitIndex(datain[0]);
			if(temp6 > 0x40)
				break;
			rembits6 = 6;
		}
	}

	if(rembits8 != 8)
	{
		///something wrong here, but ignore partially written last byte at returning len
	}

	return dataout - orig_dataout;

}

}}
/* vim:set et sw=2 ts=2: */
