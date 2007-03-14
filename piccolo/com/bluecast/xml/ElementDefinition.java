/*
 * $Id: ElementDefinition.java,v 1.3 2004/07/08 08:03:04 yuvalo Exp $
 *
 * (C) Copyright 2002-2004 by Yuval Oren. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


package  com.bluecast.xml;

import  com.bluecast.util.*;
import  java.util.*;


/**
 * A class to hold information about an element defined
 * within an XML document type declaration.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.3 $
 */
final public class ElementDefinition {
    String name;
    AttributeDefinition[] attributes;
    Map attributeMap;
    int size = 0;

    public ElementDefinition () {
        this(null);
    }

    public ElementDefinition (String name) {
        this.name = name;
        attributes = new AttributeDefinition[4];
        attributeMap = new HashMap();
        size = 0;
    }

    final public String getName () {
        return  name;
    }

    final public void setName (String name) {
        this.name = name;
    }

    final public AttributeDefinition[] getAttributes () {
        return  attributes;
    }

    final public int getAttributeCount () {
        return  size;
    }

    final public IndexedObject getIndexedAttribute (String name) {
        return  (IndexedObject)attributeMap.get(name);
    }

    final public AttributeDefinition getAttribute (int index) {
        return  attributes[index];
    }

    final public void addAttribute (AttributeDefinition attrib) throws DuplicateKeyException {
        Object newObj = new IndexedObjectImpl(size, attrib);
        Object oldObj = attributeMap.put(attrib.getQName(), newObj);
        // If there was already an attribute with this name, put the original back
        // and throw an exception.
        if (oldObj != null) {
            attributeMap.put(attrib.getQName(), oldObj);
            throw  new DuplicateKeyException("attribute '" + attrib.getQName()
                    + "' is already defined for element '" + name + "'.");
        }
        else {
            if (size >= attributes.length) {
                AttributeDefinition[] newAttributes = new AttributeDefinition[size*2];
                System.arraycopy(attributes, 0, newAttributes, 0, size);
                attributes = newAttributes;
            }
            attributes[size++] = attrib;
        }
    }
}



