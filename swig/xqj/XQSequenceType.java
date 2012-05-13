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

  /** 
   * The XQSequenceType interface represents a sequence type as XQuery 1.0: An XML Query language. The XQSequenceType is the base interface for the XQItemType interface and contains an occurence indicator.
   * 
   */
public class XQSequenceType implements javax.xml.xquery.XQSequenceType {

    XQItemType type;
    int occurence;

    public XQSequenceType(XQItemType type, int occurence) {
        this.type = type;
        this.occurence = occurence;
    }

  /** \brief Returns the type of the item in the sequence type.
   * 
   * Returns the type of the item in the sequence type.
   * 
   * @return XQItemType representing the item type in the sequence. null is returned in case of an empty sequence.
   */
    @Override
    public XQItemType getItemType() {
        return type;
    }

  /** \brief Returns the occurrence indicator for the sequence type.
   * 
   * Returns the occurrence indicator for the sequence type. One of:
   * Description	Value
   * Zero or one	OCC_ZERO_OR_ONE
   * Exactly one	OCC_EXACTLY_ONE
   * Zero or more	OCC_ZERO_OR_MORE
   * One or more	OCC_ONE_OR_MORE
   * Empty	      OCC_EMPTY
   * 
   * @return int indicating the occurrence indicator
   */
    @Override
    public int getItemOccurrence() {
        return occurence;
    }

  /** \brief Returns a human-readable implementation-defined string representation of the sequence type.
   * 
   * Returns a human-readable implementation-defined string representation of the sequence type.
   * 
   * @return a String representation of the sequence type
   */
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

  /** \brief Compares the specified object with this sequence type for equality.
   * 
   * Compares the specified object with this sequence type for equality. The result is true only if the argument is a sequence type object which represents the same XQuery sequence type. 
   * 
   * In order to comply with the general contract of equals and hashCode across different implementations the following algorithm must be used. Return true if and only if both objects are XQsequenceType and:
   * - getItemOccurrence() is equal
   * - if not OCC_EMPTY, getItemType() is equal
   * 
   * @param o - an XQItemType object representing an XQuery sequence type
   * @return true if the input item type object represents the same XQuery sequence type, false otherwise
   */
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

  /** \brief Returns a hash code consistent with the definition of the equals method.
   * 
   * Returns a hash code consistent with the definition of the equals method.
   * 
   * In order to comply with the general contract of equals and hashCode across different implementations the following algorithm must be used:
   * \code{.java}
   *   int hashCode;
   *   if (getItemOccurrence() == XQSequenceType.OCC_EMPTY)
   *   {
   *     hashCode = 1; 
   *   }
   *   else
   *   {
   *     hashCode = getItemOccurrence()*31 + getItemType().hashCode();
   *   }
   * \endcode
   * 
   * @return hash code for this item type
   */
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
