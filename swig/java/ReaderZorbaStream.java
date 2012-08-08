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

package org.zorbaxquery.api2;

import java.io.Reader;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.nio.charset.CharsetEncoder;

public class ReaderZorbaStream extends org.zorbaxquery.api.ZorbaIOStream {

  private Reader reader;
  private char[] charsReaded = new char[@ZORBA_STREAM_BUFFER_SIZE@];
  private byte[] bytesEncoded = new byte[@ZORBA_STREAM_BUFFER_SIZE@];
  CharBuffer charBuffer;
  ByteBuffer byteBuffer;
  CharsetEncoder encoder;
  
  public ReaderZorbaStream(Reader aReader) {
      charBuffer = CharBuffer.allocate(@ZORBA_STREAM_BUFFER_SIZE@);
      byteBuffer = ByteBuffer.allocate(@ZORBA_STREAM_BUFFER_SIZE@*2);
      encoder = Charset.forName("UTF-8").newEncoder();
      reader= aReader;
  }
  
  private int encode(char[] initialBuffer, int initialIndex, int initialLength, byte[] result, int resultIndex, int resultLength) {
      charBuffer.clear();
      charBuffer.put(initialBuffer, initialIndex, initialLength);
      charBuffer.flip();
      
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
        total = reader.read(charsReaded, 0, @ZORBA_STREAM_BUFFER_SIZE@);
        total = encode(charsReaded, 0, total, bytesEncoded, 0, @ZORBA_STREAM_BUFFER_SIZE@);
        setStream(bytesEncoded, total);
      } catch (Exception ex) {
        System.err.println("Unexpected exception trying to get bytes from ReaderZorbaStream: " + ex.getLocalizedMessage());
        ex.printStackTrace();
      }
  }
}
