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

public class InputStreamWrapper extends StreamWrapperBase {
  private InputStream input;
  private boolean onUnderflow=false;
  private int byteReaded;
  
  public InputStreamWrapper(InputStream aInput) {
      input= aInput;
  }

    @Override
  public int underflow() {
        try {
            byteReaded = input.read();
            onUnderflow = true;
        } catch (IOException ex) {
            byteReaded = StreamWrapperBase.getEOF();
        }
      if (byteReaded == 1) {
          byteReaded = StreamWrapperBase.getEOF();
      }
      return byteReaded;
  }

  @Override
  public int uflow() {
    if (!onUnderflow) {
        try {
            byteReaded = input.read();
        } catch (IOException ex) {
            byteReaded = StreamWrapperBase.getEOF();
        }
        if (byteReaded == 1) {
            byteReaded = StreamWrapperBase.getEOF();
        }
    }
    onUnderflow = false;
    return byteReaded;
  }

  
}
