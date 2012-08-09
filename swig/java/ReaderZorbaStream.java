/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

package org.zorbaxquery.api;

import java.io.Reader;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.nio.charset.CharsetEncoder;

public class ReaderZorbaStream extends org.zorbaxquery.api.ZorbaIOStream {

  private static final int BUFFER_SIZE = @ZORBA_STREAM_BUFFER_SIZE@;
  private static CharsetEncoder encoder = Charset.forName("UTF-8").newEncoder();
  private Reader reader;
  private char[] charsReaded = new char[BUFFER_SIZE];
  private byte[] bytesEncoded = new byte[BUFFER_SIZE];
  CharBuffer charBuffer;
  ByteBuffer byteBuffer;
  
  public ReaderZorbaStream(Reader aReader) {
      charBuffer = CharBuffer.allocate(BUFFER_SIZE);
      byteBuffer = ByteBuffer.allocate(BUFFER_SIZE*2);
      reader= aReader;
  }
  
  private int encode(char[] initialBuffer, int initialIndex, int initialLength, 
                     byte[] result,        int resultIndex,  int resultLength) {
      charBuffer = CharBuffer.wrap(initialBuffer, initialIndex, initialLength);
      byteBuffer.clear();
      encoder.encode(charBuffer, byteBuffer, false);
      byteBuffer.flip();
      resultLength = byteBuffer.limit()-byteBuffer.position();
      byteBuffer.get(result, resultIndex, resultLength);
      return resultLength;
  }

  @Override
  public void fillStreamCallback() {
      int total;
      try {
        total = reader.read(charsReaded, 0, BUFFER_SIZE);
        total = encode(charsReaded, 0, total, bytesEncoded, 0, total);
        setStream(bytesEncoded, total);
      } catch (Exception ex) {
        System.err.println("Unexpected exception trying to get bytes from ReaderZorbaStream: " + ex.getLocalizedMessage());
        ex.printStackTrace();
      }
  }
}
