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
package org.zorbaxquery.api.xqj;

import javax.xml.xquery.XQItemType;


public class XQSequenceType implements javax.xml.xquery.XQSequenceType {

    XQItemType type;
    int occurence;
    
    public XQSequenceType(XQItemType type, int occurence) {
        this.type = type;
        this.occurence = occurence;
    }
    
    @Override
    public XQItemType getItemType() {
        return type;
    }

    @Override
    public int getItemOccurrence() {
        return occurence;
    }
    
    @Override
    public String toString() {
        StringBuffer result = new StringBuffer();

        try {

            result.append(type.toString());
            
            for (java.lang.reflect.Field field: XQSequenceType.class.getFields()) {
                if (field.getName().startsWith("OCC_")) {
                    if (field.getInt(this)==occurence) {
                        result.append("Ocurrence: ").append(field.getName().substring(4));
                    }
                }
            }
        } catch (Exception e){
            result.append("Sequence Type error: ").append(e.getLocalizedMessage());
        }

        return result.toString();
    }

    @Override
    public boolean equals(Object o) {
        boolean result = false;
        if (o instanceof XQSequenceType) {
            result = (occurence != XQSequenceType.OCC_EMPTY) && 
                     (type.equals(((XQSequenceType)o).getItemType())) && 
                     (occurence == ((XQSequenceType)o).getItemOccurrence());
        }
        return result;
    }

    @Override
    public int hashCode() {
        int hashCode;
        if (occurence == XQSequenceType.OCC_EMPTY) {
            hashCode = 1; 
        } else {
            hashCode = occurence * 31 + type.hashCode();
        }
        return hashCode;
    }

}
