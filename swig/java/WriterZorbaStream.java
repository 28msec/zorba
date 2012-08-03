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
import java.io.Writer;

public class WriterZorbaStream extends org.zorbaxquery.api.ZorbaStream {
  private Writer writer;
  
  public WriterZorbaStream(Writer aWriter) {
      writer = aWriter;
  }
  
  @Override
  public void write(String string, long l){
        try {
            writer.append(string);
        } catch (IOException ex) {
            System.out.println("Error writing on output stream" + ex.getLocalizedMessage());
        }
      
  }
  
}
