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
import java.io.Reader;
import org.zorbaxquery.api.intArray;

public class ReaderStreamWrapper extends org.zorbaxquery.api.BufferWrapperBase {

  private Reader reader;

  public ReaderStreamWrapper(Reader aReader) {
      reader= aReader;
  }

  @Override
  public void fillBufferCallback() {
      char[] b = new char[1024];
      int total = 0;
      try {
        total = reader.read(b, 0, 1024);
      } catch (IOException ex) {
      }
      if (total>0) {
        intArray lBuffer = new intArray(total);
        for (int i=0; i<total; i++) {
            lBuffer.setitem(i, b[i]);
        }
        setBuffer(lBuffer.cast(), total);
      }
      
  }
}
