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

import java.net.URI;
import javax.xml.namespace.QName;
import javax.xml.xquery.XQException;
import javax.xml.xquery.XQSequenceType;
import org.zorbaxquery.api.IdentTypes.Kind;
import org.zorbaxquery.api.Item;
import org.zorbaxquery.api.SequenceType;
import org.zorbaxquery.api.StaticContext;

/**
  * The ZorbaXQItemType class represents an item type as defined in XQuery 1.0: An XML Query language. 
  * The ZorbaXQItemType extends the XQSequenceType but restricts the occurrance indicator to be exactly one. This derivation allows passing an item type wherever a sequence type is expected, but not the other way. The ZorbaXQItemType interface contains methods to represent information about the following aspects of an item type:
  * 
  * - The kind of the item - one of XQITEMKIND_* constants
  * - The base type of the item - one of the XQBASETYPE_* constants. For atomic types this is the closest matching built-in XML Schema type, for element and attributes the closest matching built-in XML Schema type this node is based on.
  * - Name of the node, if any
  * - Type name, if any. If present, then also whether the typename is an anonymous type
  * - XML Schema URI associated with the type, if any
  * - The nillability characteristics, if any
  * 
  * An instance of the ZorbaXQItemType is a standalone object that is independant of the XQConnection and any XQuery static or dynamic context.
  */
public class ZorbaXQItemType implements javax.xml.xquery.XQItemType
{
    public static final int ZORBA_XQITEMKIND_ANY = 0;
    public static final int ZORBA_XQITEMKIND_DOCUMENT = 1;
    public static final int ZORBA_XQITEMKIND_ELEMENT = 2;
    public static final int ZORBA_XQITEMKIND_ATTRIBUTE = 3;
    public static final int ZORBA_XQITEMKIND_TEXT = 4;
    public static final int ZORBA_XQITEMKIND_PI = 5;
    public static final int ZORBA_XQITEMKIND_COMMENT = 6;

    private int itemKind = 0;
    private int baseType = 0;
    private QName nodeName = null;
    private QName typeName = null;
    private URI schemaURI = null;
    private boolean allowNill = false;
    private String piTarget = null;
    private StaticContext sctx;

    protected SequenceType getSequenceType() throws XQException
    {
        SequenceType result = null;
        switch (itemKind)
        {
        case XQITEMKIND_ITEM:
            result = SequenceType.createItemType();
            break;

        case XQITEMKIND_ATOMIC:
            result = SequenceType.createAtomicOrUnionType(sctx,
                                                          typeName.getNamespaceURI(),
                                                          typeName.getLocalPart());
            break;

        case XQITEMKIND_NODE:
            result = SequenceType.createAnyNodeType();
            break;

        case XQITEMKIND_DOCUMENT:
        case XQITEMKIND_DOCUMENT_ELEMENT:
        case XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT:
            result = SequenceType.createAnyNodeType();
            break;

        case XQITEMKIND_ELEMENT:
            result = SequenceType.createElementType(sctx,
                                                    nodeName.getNamespaceURI(),
                                                    nodeName.getLocalPart(),
                                                    typeName.getNamespaceURI(),
                                                    typeName.getLocalPart(),
                                                    allowNill);
            break;
        case XQITEMKIND_ATTRIBUTE:
            result = SequenceType.createAttributeType(sctx,
                                                      nodeName.getNamespaceURI(),
                                                      nodeName.getLocalPart(),
                                                      typeName.getNamespaceURI(),
                                                      typeName.getLocalPart());
            break;

        case XQITEMKIND_PI:
            result = SequenceType.createPIType();
            break;

        case XQITEMKIND_TEXT:
            result = SequenceType.createTextType();
            break;

        case XQITEMKIND_COMMENT:
            result = SequenceType.createCommentType();
            break;

        case XQITEMKIND_SCHEMA_ATTRIBUTE:
        case XQITEMKIND_SCHEMA_ELEMENT:
        default:
            throw new XQException("Item kind is not valid.");
            
        }
        return result;
    }
    
    public ZorbaXQItemType(SequenceType seqType)
    {
        switch (seqType.getKind())
        {
        case Kind.EMPTY_TYPE:
            // TODO: raise error
            break;
        case Kind.ITEM_TYPE:
            itemKind = XQITEMKIND_ITEM;
            break;
        case Kind.ATOMIC_OR_UNION_TYPE:
            itemKind = XQITEMKIND_ATOMIC;
            break;
        case Kind.FUNCTION_TYPE:
        case Kind.STRUCTURED_ITEM_TYPE:
            itemKind = XQITEMKIND_ITEM;
            break;
        case Kind.NODE_TYPE:
            itemKind = XQITEMKIND_NODE;
            break;
        case Kind.DOCUMENT_TYPE:
            itemKind = XQITEMKIND_DOCUMENT;
            break;
        case Kind.ELEMENT_TYPE:
            itemKind = XQITEMKIND_ELEMENT;
            break;
        case Kind.SCHEMA_ELEMENT_TYPE:
            itemKind = XQITEMKIND_SCHEMA_ELEMENT;
            break;
        case Kind.ATTRIBUTE_TYPE:
            itemKind = XQITEMKIND_ATTRIBUTE;
            break;
        case Kind.SCHEMA_ATTRIBUTE_TYPE:
            itemKind = XQITEMKIND_SCHEMA_ATTRIBUTE;
            break;
        case Kind.PI_TYPE:
            itemKind = XQITEMKIND_PI;
            break;
        case Kind.TEXT_TYPE:
            itemKind = XQITEMKIND_TEXT;
            break;
        case Kind.COMMENT_TYPE:
            itemKind = XQITEMKIND_COMMENT;
            break;
        case Kind.NAMESPACE_TYPE:
            itemKind = XQITEMKIND_NODE;
            break;
        case Kind.JSON_ITEM_TYPE:
            itemKind = XQITEMKIND_ITEM;
            break;
        case Kind.JSON_OBJECT_TYPE:
            itemKind = XQITEMKIND_ITEM;
            break;
        case Kind.JSON_ARRAY_TYPE:
            itemKind = XQITEMKIND_ITEM;
            break;
        case Kind.INVALID_TYPE:
        default:
            // TODO: raise error
            itemKind = XQITEMKIND_ITEM;
            break;
        }
        
        String type = seqType.getTypeLocalName();

        baseType = ZorbaXQItemType.XQBASETYPE_ANYTYPE;

        if (type.indexOf("anyAtomicType")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYATOMICTYPE;
        } else if (type.indexOf("anySimpleType")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyType")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyURI")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYURI;
        } else if (type.indexOf("base64Binary")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_BASE64BINARY;
        } else if (type.indexOf("boolean")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_BOOLEAN;
        } else if (type.indexOf("byte")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_BYTE;
        } else if (type.indexOf("dateTime")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DATETIME;
        } else if (type.indexOf("date")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DATE;
        } else if (type.indexOf("dayTimeDuration")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DAYTIMEDURATION;
        } else if (type.indexOf("decimal")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DECIMAL;
        } else if (type.indexOf("double")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DOUBLE;
        } else if (type.indexOf("duration")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DURATION;
        } else if (type.indexOf("ENTITIES")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ENTITIES;
        } else if (type.indexOf("ENTITY")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ENTITY;
        } else if (type.indexOf("float")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_FLOAT;
        } else if (type.indexOf("gDay")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GDAY;
        } else if (type.indexOf("gMonthDay")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GMONTHDAY;
        } else if (type.indexOf("gMonth")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GMONTH;
        } else if (type.indexOf("gYear")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GYEAR;
        } else if (type.indexOf("hexBinary")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_HEXBINARY;
        } else if (type.indexOf("IDREFS")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_IDREFS;
        } else if (type.indexOf("IDREF")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_IDREF;
        } else if (type.indexOf("ID")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ID;
        } else if (type.indexOf("integer")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_INTEGER;
        } else if (type.indexOf("int")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_INT;
        } else if (type.indexOf("language")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_LANGUAGE;
        } else if (type.indexOf("long")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_LONG;
        } else if (type.indexOf("QName")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_QNAME;
        } else if (type.indexOf("NCName")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NCNAME;
        } else if (type.indexOf("Name")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NAME;
        } else if (type.indexOf("negativeInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NEGATIVE_INTEGER;
        } else if (type.indexOf("NMTOKENS")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NMTOKENS;
        } else if (type.indexOf("NMTOKEN")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NMTOKEN;
        } else if (type.indexOf("nonNegativeInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NONNEGATIVE_INTEGER;
        } else if (type.indexOf("nonPositiveInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NONPOSITIVE_INTEGER;
        } else if (type.indexOf("normalizedString")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NORMALIZED_STRING;
        } else if (type.indexOf("NOTATION")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NOTATION;
        } else if (type.indexOf("positiveInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_POSITIVE_INTEGER;
        } else if (type.indexOf("short")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_SHORT;
        } else if (type.indexOf("string")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_STRING;
        } else if (type.indexOf("time")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_TIME;
        } else if (type.indexOf("token")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_TOKEN;
        } else if (type.indexOf("unsignedByte")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_BYTE;
        } else if (type.indexOf("unsignedInt")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_INT;
        } else if (type.indexOf("unsignedLong")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_LONG;
        } else if (type.indexOf("unsignedShort")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_SHORT;
        } else if (type.indexOf("untypedAtomic")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNTYPEDATOMIC;
        } else if (type.indexOf("untyped")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNTYPED;
        } else if (type.indexOf("yearMonthDuration")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_YEARMONTHDURATION;
        }

        generateTypeName();
    }


    public ZorbaXQItemType(Item zorbaItem)
    {     
        String type = "";
        if (zorbaItem.isNode()) {
            switch (zorbaItem.getNodeKind()) {
                case ZORBA_XQITEMKIND_ANY:
                    itemKind = XQITEMKIND_ELEMENT;
                    break;
                case ZORBA_XQITEMKIND_ATTRIBUTE:
                    itemKind = XQITEMKIND_ATTRIBUTE;
                    break;
                case ZORBA_XQITEMKIND_COMMENT:
                    itemKind = XQITEMKIND_COMMENT;
                    break;
                case ZORBA_XQITEMKIND_DOCUMENT:
                    itemKind = XQITEMKIND_DOCUMENT;
                    break;
                case ZORBA_XQITEMKIND_ELEMENT:
                    itemKind = XQITEMKIND_ELEMENT;
                    break;
                case ZORBA_XQITEMKIND_PI:
                    itemKind = XQITEMKIND_PI;
                    break;
                case ZORBA_XQITEMKIND_TEXT:
                    itemKind = XQITEMKIND_TEXT;
                    break;
                default:
                    itemKind = XQITEMKIND_ELEMENT;
                    break;
                  
            }
        } else if (zorbaItem.isAtomic()) {
            itemKind = XQITEMKIND_ATOMIC;
            type = zorbaItem.getType().getStringValue();
        }
        baseType = ZorbaXQItemType.XQBASETYPE_ANYTYPE;
        if (type.indexOf("anyAtomicType")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYATOMICTYPE;
        } else if (type.indexOf("anySimpleType")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyType")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyURI")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ANYURI;
        } else if (type.indexOf("base64Binary")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_BASE64BINARY;
        } else if (type.indexOf("boolean")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_BOOLEAN;
        } else if (type.indexOf("byte")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_BYTE;
        } else if (type.indexOf("dateTime")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DATETIME;
        } else if (type.indexOf("date")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DATE;
        } else if (type.indexOf("dayTimeDuration")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DAYTIMEDURATION;
        } else if (type.indexOf("decimal")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DECIMAL;
        } else if (type.indexOf("double")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DOUBLE;
        } else if (type.indexOf("duration")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_DURATION;
        } else if (type.indexOf("ENTITIES")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ENTITIES;
        } else if (type.indexOf("ENTITY")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ENTITY;
        } else if (type.indexOf("float")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_FLOAT;
        } else if (type.indexOf("gDay")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GDAY;
        } else if (type.indexOf("gMonthDay")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GMONTHDAY;
        } else if (type.indexOf("gMonth")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GMONTH;
        } else if (type.indexOf("gYear")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_GYEAR;
        } else if (type.indexOf("hexBinary")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_HEXBINARY;
        } else if (type.indexOf("IDREFS")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_IDREFS;
        } else if (type.indexOf("IDREF")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_IDREF;
        } else if (type.indexOf("ID")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_ID;
        } else if (type.indexOf("integer")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_INTEGER;
        } else if (type.indexOf("int")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_INT;
        } else if (type.indexOf("language")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_LANGUAGE;
        } else if (type.indexOf("long")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_LONG;
        } else if (type.indexOf("QName")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_QNAME;
        } else if (type.indexOf("NCName")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NCNAME;
        } else if (type.indexOf("Name")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NAME;
        } else if (type.indexOf("negativeInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NEGATIVE_INTEGER;
        } else if (type.indexOf("NMTOKENS")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NMTOKENS;
        } else if (type.indexOf("NMTOKEN")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NMTOKEN;
        } else if (type.indexOf("nonNegativeInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NONNEGATIVE_INTEGER;
        } else if (type.indexOf("nonPositiveInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NONPOSITIVE_INTEGER;
        } else if (type.indexOf("normalizedString")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NORMALIZED_STRING;
        } else if (type.indexOf("NOTATION")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_NOTATION;
        } else if (type.indexOf("positiveInteger")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_POSITIVE_INTEGER;
        } else if (type.indexOf("short")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_SHORT;
        } else if (type.indexOf("string")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_STRING;
        } else if (type.indexOf("time")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_TIME;
        } else if (type.indexOf("token")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_TOKEN;
        } else if (type.indexOf("unsignedByte")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_BYTE;
        } else if (type.indexOf("unsignedInt")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_INT;
        } else if (type.indexOf("unsignedLong")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_LONG;
        } else if (type.indexOf("unsignedShort")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNSIGNED_SHORT;
        } else if (type.indexOf("untypedAtomic")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNTYPEDATOMIC;
        } else if (type.indexOf("untyped")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_UNTYPED;
        } else if (type.indexOf("yearMonthDuration")>=0){
            baseType = ZorbaXQItemType.XQBASETYPE_YEARMONTHDURATION;
        }
        generateTypeName();
    }
    
    public ZorbaXQItemType(int itemkind, String piTarget) {
        this.itemKind = itemkind;
        this.piTarget = piTarget;
        generateTypeName();
    }


    public ZorbaXQItemType(int itemkind) {
        this.itemKind = itemkind;
        generateTypeName();
    }


    public ZorbaXQItemType(int itemkind, int basetype) {
        this.itemKind = itemkind;
        this.baseType = basetype;
        generateTypeName();
    }


    public ZorbaXQItemType(int itemkind, QName nodename, int basetype) {
        this.itemKind = itemkind;
        this.nodeName = nodename;
        this.baseType = basetype;
        generateTypeName();
    }


    public ZorbaXQItemType(int itemkind, QName nodename, int basetype, QName typename, URI schemaURI, boolean allowNill) throws XQException {
        this.itemKind = itemkind;
        this.nodeName = nodename;
        this.baseType = basetype;
        this.typeName = typename;
        this.schemaURI = schemaURI;
        this.allowNill = allowNill;
    }


    public ZorbaXQItemType(int itemkind, QName nodename, int basetype, URI schemaURI) throws XQException {
        this.itemKind = itemkind;
        this.nodeName = nodename;
        this.baseType = basetype;
        this.schemaURI = schemaURI;
        generateTypeName();
    }
    

    private void generateTypeName()
    {
        String namespaceURI = "http://www.w3.org/2001/XMLSchema";
        String localPart = "untyped";
        String prefix = "";
        
        switch (baseType)
        {
        case ZorbaXQItemType.XQBASETYPE_ANYATOMICTYPE:
            localPart = "anyAtomicType";
            break;
        case ZorbaXQItemType.XQBASETYPE_ANYSIMPLETYPE:
            localPart = "anySimpleType";
            break;
        case ZorbaXQItemType.XQBASETYPE_ANYTYPE:
            localPart = "anyType";
            break;
        case ZorbaXQItemType.XQBASETYPE_ANYURI:
            localPart = "anyURI";
            break;
        case ZorbaXQItemType.XQBASETYPE_BASE64BINARY:
            localPart = "base64Binary";
            break;
        case ZorbaXQItemType.XQBASETYPE_BOOLEAN:
            localPart = "boolean";
            break;
        case ZorbaXQItemType.XQBASETYPE_BYTE:
            localPart = "byte";
            break;
        case ZorbaXQItemType.XQBASETYPE_DATE:
            localPart = "date";
            break;
        case ZorbaXQItemType.XQBASETYPE_DATETIME:
            localPart = "dateTime";
            break;
        case ZorbaXQItemType.XQBASETYPE_DAYTIMEDURATION:
            localPart = "dayTimeDuration";
            break;
        case ZorbaXQItemType.XQBASETYPE_DECIMAL:
            localPart = "decimal";
            break;
        case ZorbaXQItemType.XQBASETYPE_DOUBLE:
            localPart = "double";
            break;
        case ZorbaXQItemType.XQBASETYPE_DURATION:
            localPart = "duration";
            break;
        case ZorbaXQItemType.XQBASETYPE_ENTITIES:
            localPart = "ENTITIES";
            break;
        case ZorbaXQItemType.XQBASETYPE_ENTITY:
            localPart = "ENTITY";
            break;
        case ZorbaXQItemType.XQBASETYPE_FLOAT:
            localPart = "float";
            break;
        case ZorbaXQItemType.XQBASETYPE_GDAY:
            localPart = "gDay";
            break;
        case ZorbaXQItemType.XQBASETYPE_GMONTH:
            localPart = "gMonth";
            break;
        case ZorbaXQItemType.XQBASETYPE_GMONTHDAY:
            localPart = "gMonthDay";
            break;
        case ZorbaXQItemType.XQBASETYPE_GYEAR:
            localPart = "gYear";
            break;
        case ZorbaXQItemType.XQBASETYPE_GYEARMONTH:
            localPart = "gYearMonth";
            break;
        case ZorbaXQItemType.XQBASETYPE_HEXBINARY:
            localPart = "hexBinary";
            break;
        case ZorbaXQItemType.XQBASETYPE_ID:
            localPart = "ID";
            break;
        case ZorbaXQItemType.XQBASETYPE_IDREF:
            localPart = "IDREF";
            break;
        case ZorbaXQItemType.XQBASETYPE_IDREFS:
            localPart = "IDREFS";
            break;
        case ZorbaXQItemType.XQBASETYPE_INT:
            localPart = "int";
            break;
        case ZorbaXQItemType.XQBASETYPE_INTEGER:
            localPart = "integer";
            break;
        case ZorbaXQItemType.XQBASETYPE_LANGUAGE:
            localPart = "language";
            break;
        case ZorbaXQItemType.XQBASETYPE_LONG:
            localPart = "long";
            break;
        case ZorbaXQItemType.XQBASETYPE_NAME:
            localPart = "Name";
            break;
        case ZorbaXQItemType.XQBASETYPE_NCNAME:
            localPart = "NCName";
            break;
        case ZorbaXQItemType.XQBASETYPE_NEGATIVE_INTEGER:
            localPart = "negativeInteger";
            break;
        case ZorbaXQItemType.XQBASETYPE_NMTOKEN:
            localPart = "NMTOKEN";
            break;
        case ZorbaXQItemType.XQBASETYPE_NMTOKENS:
            localPart = "NMTOKENS";
            break;
        case ZorbaXQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
            localPart = "nonNegativeInteger";
            break;
        case ZorbaXQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
            localPart = "nonPositiveInteger";
            break;
        case ZorbaXQItemType.XQBASETYPE_NORMALIZED_STRING:
            localPart = "normalizedString";
            break;
        case ZorbaXQItemType.XQBASETYPE_NOTATION:
            localPart = "NOTATION";
            break;
        case ZorbaXQItemType.XQBASETYPE_POSITIVE_INTEGER:
            localPart = "positiveInteger";
            break;
        case ZorbaXQItemType.XQBASETYPE_QNAME:
            localPart = "QName";
            break;
        case ZorbaXQItemType.XQBASETYPE_SHORT:
            localPart = "short";
            break;
        case ZorbaXQItemType.XQBASETYPE_STRING:
            localPart = "string";
            break;
        case ZorbaXQItemType.XQBASETYPE_TIME:
            localPart = "time";
            break;
        case ZorbaXQItemType.XQBASETYPE_TOKEN:
            localPart = "token";
            break;
        case ZorbaXQItemType.XQBASETYPE_UNSIGNED_BYTE:
            localPart = "unsignedByte";
            break;
        case ZorbaXQItemType.XQBASETYPE_UNSIGNED_INT:
            localPart = "unsignedInt";
            break;
        case ZorbaXQItemType.XQBASETYPE_UNSIGNED_LONG:
            localPart = "unsignedLong";
            break;
        case ZorbaXQItemType.XQBASETYPE_UNSIGNED_SHORT:
            localPart = "unsignedShort";
            break;
        case ZorbaXQItemType.XQBASETYPE_UNTYPED:
            localPart = "untyped";
            break;
        case ZorbaXQItemType.XQBASETYPE_UNTYPEDATOMIC:
            localPart = "untypedAtomic";
            break;
        case ZorbaXQItemType.XQBASETYPE_YEARMONTHDURATION:
            localPart = "yearMonthDuration";
            break;
        default:
            localPart = "untyped";
            break;
        }
        typeName = new QName(namespaceURI, localPart, prefix);
    }

  /** \brief Returns the base type of the item.
   * 
   * One of the XQBASETYPE_* constants. 
   * 
   * XQJ defines a constant for each of the built-in schema types defined in XML Schema. For atomic types this is the closest matching built-in XML Schema type, for element and attributes the closest matching built-in XML Schema type this node is based on.
   * 
   * @return int one of the XQBASETYPE_* constants indicating the basic type of the item
   * @throw XQException - if the item kind is not one of: XQITEMKIND_DOCUMENT_ELEMENT, XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT, XQITEMKIND_ELEMENT, XQITEMKIND_SCHEMA_ELEMENT, XQITEMKIND_ATTRIBUTE, XQITEMKIND_SCHEMA_ATTRIBUTE, or XQITEMKIND_ATOMIC
   */
    @Override
    public int getBaseType() throws XQException {
        if (!((itemKind==ZorbaXQItemType.XQITEMKIND_DOCUMENT_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_SCHEMA_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ATTRIBUTE) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ATOMIC))) {
            throw new XQException("Item kind is not valid for a Base Type.");
        }
        return baseType;
    }

  /** \brief Returns the kind of the item.
   * 
   * One of the XQITEMKIND_* constants.
   * 
   * @return int one of the XQITEMKIND_* constants indicating the basic kind of the item
   */
    @Override
    public int getItemKind() {
        return itemKind;
    }

  /** \brief Returns the occurrence indicator for the item type.
   * 
   * This method will always return the value XQSequenceType.OCC_EXACTLY_ONE.
   * 
   * @return int indicating the occurrence indicator
   */
    @Override
    public int getItemOccurrence() {
        return XQSequenceType.OCC_EXACTLY_ONE;
    }

  /** \brief Returns the name of the node.
   * 
   * Returns the name of the node in case the item kind is an XQITEMKIND_DOCUMENT_ELEMENT, XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT, XQITEMKIND_ELEMENT, XQITEMKIND_SCHEMA_ELEMENT, XQITEMKIND_ATTRIBUTE, or XQITEMKIND_SCHEMA_ATTRIBUTE. For example, in the case of a type for element "foo" this will return the QName foo. For wildcard entries a null value will be returned.
   * 
   * @return QName for the name of the element, attribute, or document element node. null if it is a wildcard
   * @throw XQException - if the item kind is not one of: XQITEMKIND_DOCUMENT_ELEMENT, XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT, XQITEMKIND_ELEMENT, XQITEMKIND_SCHEMA_ELEMENT, XQITEMKIND_ATTRIBUTE, or XQITEMKIND_SCHEMA_ATTRIBUTE
   */
    @Override
    public QName getNodeName() throws XQException {
        if (!((itemKind==ZorbaXQItemType.XQITEMKIND_DOCUMENT_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_SCHEMA_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ATTRIBUTE) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE))) {
            throw new XQException("Item kind is not valid for a Type Name.");
        }
        return nodeName;
    }

  /** \brief Returns the schema location URI of the schema that contains the item's element or type definition.
   * 
   * This method is implementation-definied and an implementation will return a null value if it does not support retrieving the schema location URI. If the item corresponds to a validated global element in a schema, the result will be the schema location URI to the XMLSchema containing the element definition. Otherwise if the item is a schema validated node, the result will be the schema location URI of the XMLSchema containing the type definition of that node. If the item is not schema validated, the result is null.
   * 
   * @return URI representing the schema location URI of the XMLSchema containing the global element definition or the type definition of the current item. null in case the item is not schema validated or if the implementation does not support retrieving the schema URI.
   */
    @Override
    public URI getSchemaURI() {
        return schemaURI;
    }

  /** \brief Represents a type name (global or local).
   * 
   * This can be used to represent specific type name such as, element foo of type hatsize. The schema type name is represented as a single QName. If the return type is an anonymous type, the actual QName value returned is implementation defined.
   * 
   * @return the QName of the schema type in case of a user defined or anonoymous types. For a built-in type, returns a predefined type name as QName (e.g.xs:anyType, xs:decimal, etc). Cannot be null.
   * @throw XQException - if the item kind is not one of: XQITEMKIND_DOCUMENT_ELEMENT, XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT, XQITEMKIND_ATOMIC, XQITEMKIND_ELEMENT, XQITEMKIND_SCHEMA_ELEMENT, XQITEMKIND_ATTRIBUTE, or XQITEMKIND_SCHEMA_ATTRIBUTE
   */
    @Override
    public QName getTypeName() throws XQException {
        if (!((itemKind==ZorbaXQItemType.XQITEMKIND_DOCUMENT_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ATOMIC) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_SCHEMA_ELEMENT) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_ATTRIBUTE) ||
              (itemKind==ZorbaXQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE))) {
            throw new XQException("Item kind is not valid for a Type Name.");
        }
        return typeName;
    }

  /** \brief Represents whether the item type is an anonymous type in the schema.
   * 
   * @return true if the item type is an anonymous type in the schema, false otherwise.
   */
    @Override
    public boolean isAnonymousType() {
        return (itemKind==0);
    }

  /** \brief Returns whether the element type is nillable or not.
   * 
   * @return true if the element type is nillable, false otherwise.
   */
    @Override
    public boolean isElementNillable() {
        return allowNill;
    }

  /** \brief Returns the name of the processing instruction type.
   * 
   * As such the item kind of this ZorbaXQItemType must be XQITEMKIND_PI.
   * 
   * @return the name of the processing instruction type. null if it is a wildcard.
   * @throw XQException - if the item kind is not XQITEMKIND_PI
   */
    @Override
    public String getPIName() throws XQException {
        if (itemKind!=ZorbaXQItemType.XQITEMKIND_PI) {
            throw new XQException("Item kind is not a PI.");
        }
        return piTarget;
    }

  /** \brief Returns the type of the item in the sequence type.
   * 
   * @return ZorbaXQItemType representing the item type in the sequence. null is returned in case of an empty sequence.
   */
    @Override
    public ZorbaXQItemType getItemType() {
        return this;
    }

  /** \brief Compares the specified object with this item type for equality.
   * 
   * The result is true only if the argument is an item type object which represents the same XQuery item type. 
   * 
   * In order to comply with the general contract of equals and hashCode across different implementations the following algorithm must be used. Return true if and only if both objects are ZorbaXQItemType and:
   * - getItemKind() is equal
   * - if getBaseType() is supported for the item kind, it must be equal
   * - if getNodeName() is supported for the item kind, it must be equal
   * - getSchemaURI() is equal
   * - if getTypeName() is supported for the item kind, it must be equal
   * - isAnonymousType() is equal
   * - isElementNillable() is equal
   * - if getPIName() is supported for the item kind, it must be equal
   * 
   * @param o - an ZorbaXQItemType object representing an XQuery item type
   * @return true if the input item type object represents the same XQuery item type, false otherwise
   */
    @Override
    public boolean equals(Object o) {
        boolean result = false;
        boolean supportBaseType = false;
        boolean supportNodeName = false;
        boolean supportTypeName = false;
        boolean supportPIName = false;
        if (o instanceof ZorbaXQItemType) {
            if ( (getItemKind()==((ZorbaXQItemType)o).getItemKind()) &&
                 (getSchemaURI()==((ZorbaXQItemType)o).getSchemaURI()) &&
                 (isAnonymousType()==((ZorbaXQItemType)o).isAnonymousType()) &&
                 (isElementNillable()==((ZorbaXQItemType)o).isElementNillable()) ) {
                try {
                    supportBaseType = getBaseType() == ((ZorbaXQItemType)o).getBaseType();
                } catch (Exception e) {
                    supportBaseType = true;  // Not supported
                }
                try {
                    supportNodeName = getNodeName() == ((ZorbaXQItemType)o).getNodeName();
                } catch (Exception e) {
                    supportNodeName = true; // Not supported
                }
                try {
                    supportTypeName = getTypeName().equals(((ZorbaXQItemType)o).getTypeName());
                } catch (Exception e) {
                    supportTypeName = true; // Not supported
                }
                try {
                    supportPIName = getPIName().equals(((ZorbaXQItemType)o).getPIName());
                } catch (Exception e) {
                    supportPIName = true; // Not supported
                }
                
                
                result = supportBaseType && supportNodeName && supportTypeName && supportPIName;
            }
        }
        return result;
    }

  /** \brief Returns a hash code consistent with the definition of the equals method. 
   * 
   * In order to comply with the general contract of equals and hashCode across different implementations the following algorithm must be used:
   * \code{.java}
   *   hashCode = this.getItemKind();
   *   if this.getSchemaURI != null
   *     hashCode = 31*hashCode + this.getSchemaURI().hashCode();
   *   if this.getBaseType() is supported for the item kind
   *     hashCode = 31*hashCode + this.getbaseType();
   *   if this.getNodeName () is supported for the item kind and
   *     this.getNodeName() != null
   *     hashCode = 31*hashCode + this.getNodeName().hashCode()
   *   if this.getTypeName () is supported for the item kind
   *     hashCode = 31*hashCode + this.getTypeName().hashCode();
   *   if this.getPIName () is supported for the item kind and
   *     this.getPIName () != null
   *     hashCode = 31*hashCode + this.getPIName().hashCode();
   * \endcode 
   * 
   * @return hash code for this item type
   */
    @Override
    public int hashCode() {
        int hashCode = 0;
        hashCode = this.getItemKind();
        if (this.getSchemaURI() != null) {
            hashCode = 31*hashCode + this.getSchemaURI().hashCode();
        }
        try {
          int basetype = this.getBaseType();
          hashCode = 31*hashCode + basetype;
        } catch (Exception e) {}
        try {
          QName nodename = this.getNodeName();
          if (nodename!=null) {
              hashCode = 31*hashCode + nodename.hashCode();
          }
        } catch (Exception e) {}
        try {
            QName typename = this.getTypeName();
            hashCode = 31*hashCode + typename.hashCode();
        } catch(Exception e) {}
        try {
            String piname = this.getPIName();
            if (piname != null) {
                hashCode = 31*hashCode + piname.hashCode();
            }
        } catch (Exception e) {}
        return hashCode;
    }

  /** \brief Returns a human-readable implementation-defined string representation of the item type.
   * 
   * @return String a string representation of the item type
   */
    @Override
    public String toString() {
        StringBuffer result = new StringBuffer();

        try {
            for (java.lang.reflect.Field field: ZorbaXQItemType.class.getFields()) {
                if (field.getName().startsWith("XQITEMKIND_")) {
                    if (field.getInt(this)==itemKind) {
                        result.append("Item Kind: ").append(field.getName().substring(11));
                    }
                }
                if (field.getName().startsWith("XQBASETYPE_")) {
                    if (field.getInt(this)==baseType) {
                        result.append("  Base Type: ").append(field.getName().substring(11));
                    }
                }
            }
        } catch (Exception e){
            result.append("Item Kind or Base Type error: ").append(e.getLocalizedMessage());
        }

        return result.toString();
    }
    
    
}
