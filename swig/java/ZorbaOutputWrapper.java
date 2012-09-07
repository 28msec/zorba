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

import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.nio.charset.CharsetDecoder;
import java.nio.charset.CharsetEncoder;

public class ZorbaOutputWrapper extends ZorbaIOStream {
  private OutputStream output;
  private static final int BUFFER_SIZE = @ZORBA_STREAM_BUFFER_SIZE@;
  private static CharsetDecoder decoder = Charset.forName("UTF-8").newDecoder();
  CharBuffer charBuffer;
  ByteBuffer byteBuffer;
  ByteBuffer byteBufferFinal;
  
  public ZorbaOutputWrapper(OutputStream aOutput) {
      try {
        output = aOutput;
      } catch (Exception e) {
        System.out.println("Error creating OutputStreamWriter" + e.getLocalizedMessage());
      }
      charBuffer = CharBuffer.allocate(BUFFER_SIZE);
      byteBuffer = ByteBuffer.allocate(BUFFER_SIZE*2);
      byteBufferFinal = ByteBuffer.allocate(BUFFER_SIZE*2);
  }
  
  @Override
  public void write(byte[] stream, long aLen){
        try {
            int offset = 0;
            int bufferLength = 0;
            while (aLen>offset) {
                byteBuffer.clear();
                bufferLength = BUFFER_SIZE;
                if ((offset+BUFFER_SIZE)>aLen) {
                    bufferLength = (int)aLen-offset;
                }
                offset += BUFFER_SIZE;
                byteBuffer.put(stream, 0, bufferLength);
                byteBuffer.flip();
                charBuffer.clear();
                decoder.decode(byteBuffer, charBuffer, false);
                charBuffer.flip();
            }
            ByteBuffer result = Charset.forName("UTF-8").encode(charBuffer);
            output.write(result.array());
        } catch (IOException ex) {
            System.err.println("Error writing on output stream" + ex.getLocalizedMessage());
        }
      
  }
  
}
