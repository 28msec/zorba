/*
 * $Id: AttributeDefinition.java,v 1.4 2004/07/11 09:37:37 yuvalo Exp $
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


/**
 * A class to hold information about an attribute defined
 * within an XML document type declaration.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.4 $
 */
final public class AttributeDefinition {
    // Attribute Defaults
    static public final int IMPLIED = 1;
    static public final int REQUIRED = 2;
    static public final int FIXED = 3;
    // Attribute Value Types
    static public final int ENUMERATION = 1;
    static public final int NOTATION = 2;
    static public final int CDATA = 3;
    static public final int ID = 4;
    static public final int IDREF = 5;
    static public final int IDREFS = 6;
    static public final int ENTITY = 7;
    static public final int ENTITIES = 8;
    static public final int NMTOKEN = 9;
    static public final int NMTOKENS = 10;
    static private final String[] valueTypeStrings =  {
        null, "NMTOKEN", "NOTATION", "CDATA", "ID", "IDREF", "IDREFS", "ENTITY",
                "ENTITIES", "NMTOKEN", "NMTOKENS"
    };
    static private final String[] defaultTypeStrings = {
        null, "#IMPLIED","#REQUIRED","#FIXED"
    };

    String prefix, localName, qName;
    int valueType;
    int defaultType;
    String defaultValue;
    String[] possibleValues;

    public AttributeDefinition (String prefix, String localName, String qName,
            int valueType, String[] possibleValues, int defaultType, String defaultValue) {
        this.prefix = prefix;
        this.localName = localName;
        this.qName = qName;
        this.valueType = valueType;
        this.possibleValues = possibleValues;
        this.defaultType = defaultType;
        this.defaultValue = defaultValue;
    }

    public String getPrefix () {
        return  prefix;
    }

    public String getLocalName () {
        return  localName;
    }

    public String getQName () {
        return  qName;
    }

    public int getValueType () {
        return  valueType;
    }

    public String getValueTypeString () {
        return  getValueTypeString(valueType);
    }

    static public String getValueTypeString (int valueType) {
        return  valueTypeStrings[valueType];
    }

    public int getDefaultType () {
        return  defaultType;
    }

    public String getDefaultTypeString () {
        return getDefaultTypeString(defaultType);
    }

    static public String getDefaultTypeString (int defaultType) {
        return defaultTypeStrings[defaultType];
    }

    public String getDefaultValue () {
        return  defaultValue;
    }

    public String[] getPossibleValues () {
        return  possibleValues;
    }
}



