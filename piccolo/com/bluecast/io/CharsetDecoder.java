/*
 * $Id: CharsetDecoder.java,v 1.4 2004/07/08 08:01:29 yuvalo Exp $
 *
 * (C) Copyright 2002-2004 by Yuval Oren. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

package com.bluecast.io;

import java.io.CharConversionException;

/**
 * Converts bytes to characters.
 *
 * @author Yuval Oren
 * @version $Revision: 1.4 $
 *
 */
 public interface CharsetDecoder {

    /** Minimum number of characters produced per byte using
     *  this decoder.
     */
    public int minBytesPerChar();

    /** Minimum number of characters produced per byte using
     *  this decoder.
     */
    public int maxBytesPerChar();


    /**
     * Decodes an array of bytes into characters.
     *
     * @param in_buf    input byte buffer
     * @param in_off    starting byte buffer offset
     * @param in_len    max number of bytes to read
     * @param out_buf   output character buffer
     * @param out_off   char buffer offset at which to start writing
     * @param out_len   max number of chars to write
     * @param result    an array of size >= 2 where results are returned:
     *                  result[0] = number of bytes read.
     *                  result[1] = number of chars written
     */
    public void decode(byte[] in_buf, int in_off, int in_len,
                      char[] out_buf, int out_off, int out_len, int[] result)
    throws CharConversionException;

    public CharsetDecoder newCharsetDecoder();
    public void reset();
}
