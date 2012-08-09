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

public class ZorbaOutputWrapper extends ZorbaIOStream {
  private OutputStream output;
  
  public ZorbaOutputWrapper(OutputStream aOutput) {
      output = aOutput;
  }
  
  @Override
  public void write(byte[] stream){
        try {
            output.write(stream);
        } catch (IOException ex) {
            System.err.println("Error writing on output stream" + ex.getLocalizedMessage());
        }
      
  }
  
}
