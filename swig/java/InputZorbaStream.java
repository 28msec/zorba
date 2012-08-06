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
import java.io.InputStream;
import org.zorbaxquery.api.intArray;

public class InputZorbaStream extends org.zorbaxquery.api.ZorbaIOStream {

  private InputStream input;
  private byte[] b = new byte[@ZORBA_STREAM_BUFFER_SIZE@];;
  
  public InputZorbaStream(InputStream aInput) {
      input= aInput;
  }
  
  @Override
  public void fillStreamCallback() {
      int total = 0;
      try {
        total = input.read(b, 0, @ZORBA_STREAM_BUFFER_SIZE@);
        if (total==-1) 
          total=0;
        setStream(b, total);
      } catch (IOException ex) {
        System.err.println("Unexpected exception trying to get bytes from InputZorbaStream: " + ex.getLocalizedMessage());
        ex.printStackTrace();
      }
  }
}
