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
import org.zorbaxquery.api.TypeIdentifier;

public class XQItemType implements javax.xml.xquery.XQItemType {
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

    protected TypeIdentifier getTypeIdentifier() throws XQException {
        TypeIdentifier result = null;
        switch (itemKind) {
            case XQITEMKIND_ATOMIC:
                result = TypeIdentifier.createEmptyType();
                break;
            case XQITEMKIND_ATTRIBUTE:
                // TODO: fix uriWildcard, localNameWildcard
                result = TypeIdentifier.createAttributeType(schemaURI.toString(), true, nodeName.getLocalPart(), true, TypeIdentifier.createAnyNodeType());
                break;
            case XQITEMKIND_COMMENT:
                result = TypeIdentifier.createCommentType();
                break;
            case XQITEMKIND_DOCUMENT:
            case XQITEMKIND_DOCUMENT_ELEMENT:
            case XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT:
                result = TypeIdentifier.createDocumentType(TypeIdentifier.createAnyNodeType());
                break;
            case XQITEMKIND_ELEMENT:
                // TODO: fix uriWildcard, localNameWildcard
                result = TypeIdentifier.createElementType(schemaURI.toString(), true, nodeName.getLocalPart(), true, TypeIdentifier.createAnyNodeType());
                break;
            case XQITEMKIND_ITEM:
                result = TypeIdentifier.createItemType();
                break;
            case XQITEMKIND_NODE:
                result = TypeIdentifier.createAnyNodeType();
                break;
            case XQITEMKIND_PI:
                result = TypeIdentifier.createPIType();
                break;
            case XQITEMKIND_TEXT:
                result = TypeIdentifier.createTextType();
                break;
            case XQITEMKIND_SCHEMA_ATTRIBUTE:
            case XQITEMKIND_SCHEMA_ELEMENT:
            default:
                throw new XQException("Item kind is not valid.");
              
        }
        return result;
    }
    
    public XQItemType(TypeIdentifier typeIdentifier) {
        switch (typeIdentifier.getKind()) {
            case Kind.ANY_NODE_TYPE:
                itemKind = XQITEMKIND_NODE;
                break;
            case Kind.ATTRIBUTE_TYPE:
                itemKind = XQITEMKIND_ATTRIBUTE;
                break;
            case Kind.COMMENT_TYPE:
                itemKind = XQITEMKIND_COMMENT;
                break;
            case Kind.DOCUMENT_TYPE:
                itemKind = XQITEMKIND_DOCUMENT;
                break;
            case Kind.ELEMENT_TYPE:
                itemKind = XQITEMKIND_ELEMENT;
                break;
            case Kind.EMPTY_TYPE:
            case Kind.INVALID_TYPE:
            case Kind.ITEM_TYPE:
            case Kind.NAMED_TYPE:
                itemKind = XQITEMKIND_ITEM;
                break;
            case Kind.PI_TYPE:
                itemKind = XQITEMKIND_PI;
                break;
            case Kind.TEXT_TYPE:
                itemKind = XQITEMKIND_TEXT;
                break;
        }
        
        String type = typeIdentifier.getLocalName();
        baseType = XQItemType.XQBASETYPE_ANYTYPE;
        if (type.indexOf("anyAtomicType")>=0){
            baseType = XQItemType.XQBASETYPE_ANYATOMICTYPE;
        } else if (type.indexOf("anySimpleType")>=0){
            baseType = XQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyType")>=0){
            baseType = XQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyURI")>=0){
            baseType = XQItemType.XQBASETYPE_ANYURI;
        } else if (type.indexOf("base64Binary")>=0){
            baseType = XQItemType.XQBASETYPE_BASE64BINARY;
        } else if (type.indexOf("boolean")>=0){
            baseType = XQItemType.XQBASETYPE_BOOLEAN;
        } else if (type.indexOf("byte")>=0){
            baseType = XQItemType.XQBASETYPE_BYTE;
        } else if (type.indexOf("dateTime")>=0){
            baseType = XQItemType.XQBASETYPE_DATETIME;
        } else if (type.indexOf("date")>=0){
            baseType = XQItemType.XQBASETYPE_DATE;
        } else if (type.indexOf("dayTimeDuration")>=0){
            baseType = XQItemType.XQBASETYPE_DAYTIMEDURATION;
        } else if (type.indexOf("decimal")>=0){
            baseType = XQItemType.XQBASETYPE_DECIMAL;
        } else if (type.indexOf("double")>=0){
            baseType = XQItemType.XQBASETYPE_DOUBLE;
        } else if (type.indexOf("duration")>=0){
            baseType = XQItemType.XQBASETYPE_DURATION;
        } else if (type.indexOf("ENTITIES")>=0){
            baseType = XQItemType.XQBASETYPE_ENTITIES;
        } else if (type.indexOf("ENTITY")>=0){
            baseType = XQItemType.XQBASETYPE_ENTITY;
        } else if (type.indexOf("float")>=0){
            baseType = XQItemType.XQBASETYPE_FLOAT;
        } else if (type.indexOf("gDay")>=0){
            baseType = XQItemType.XQBASETYPE_GDAY;
        } else if (type.indexOf("gMonthDay")>=0){
            baseType = XQItemType.XQBASETYPE_GMONTHDAY;
        } else if (type.indexOf("gMonth")>=0){
            baseType = XQItemType.XQBASETYPE_GMONTH;
        } else if (type.indexOf("gYear")>=0){
            baseType = XQItemType.XQBASETYPE_GYEAR;
        } else if (type.indexOf("hexBinary")>=0){
            baseType = XQItemType.XQBASETYPE_HEXBINARY;
        } else if (type.indexOf("IDREFS")>=0){
            baseType = XQItemType.XQBASETYPE_IDREFS;
        } else if (type.indexOf("IDREF")>=0){
            baseType = XQItemType.XQBASETYPE_IDREF;
        } else if (type.indexOf("ID")>=0){
            baseType = XQItemType.XQBASETYPE_ID;
        } else if (type.indexOf("integer")>=0){
            baseType = XQItemType.XQBASETYPE_INTEGER;
        } else if (type.indexOf("int")>=0){
            baseType = XQItemType.XQBASETYPE_INT;
        } else if (type.indexOf("language")>=0){
            baseType = XQItemType.XQBASETYPE_LANGUAGE;
        } else if (type.indexOf("long")>=0){
            baseType = XQItemType.XQBASETYPE_LONG;
        } else if (type.indexOf("QName")>=0){
            baseType = XQItemType.XQBASETYPE_QNAME;
        } else if (type.indexOf("NCName")>=0){
            baseType = XQItemType.XQBASETYPE_NCNAME;
        } else if (type.indexOf("Name")>=0){
            baseType = XQItemType.XQBASETYPE_NAME;
        } else if (type.indexOf("negativeInteger")>=0){
            baseType = XQItemType.XQBASETYPE_NEGATIVE_INTEGER;
        } else if (type.indexOf("NMTOKENS")>=0){
            baseType = XQItemType.XQBASETYPE_NMTOKENS;
        } else if (type.indexOf("NMTOKEN")>=0){
            baseType = XQItemType.XQBASETYPE_NMTOKEN;
        } else if (type.indexOf("nonNegativeInteger")>=0){
            baseType = XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER;
        } else if (type.indexOf("nonPositiveInteger")>=0){
            baseType = XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER;
        } else if (type.indexOf("normalizedString")>=0){
            baseType = XQItemType.XQBASETYPE_NORMALIZED_STRING;
        } else if (type.indexOf("NOTATION")>=0){
            baseType = XQItemType.XQBASETYPE_NOTATION;
        } else if (type.indexOf("positiveInteger")>=0){
            baseType = XQItemType.XQBASETYPE_POSITIVE_INTEGER;
        } else if (type.indexOf("short")>=0){
            baseType = XQItemType.XQBASETYPE_SHORT;
        } else if (type.indexOf("string")>=0){
            baseType = XQItemType.XQBASETYPE_STRING;
        } else if (type.indexOf("time")>=0){
            baseType = XQItemType.XQBASETYPE_TIME;
        } else if (type.indexOf("token")>=0){
            baseType = XQItemType.XQBASETYPE_TOKEN;
        } else if (type.indexOf("unsignedByte")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_BYTE;
        } else if (type.indexOf("unsignedInt")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_INT;
        } else if (type.indexOf("unsignedLong")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_LONG;
        } else if (type.indexOf("unsignedShort")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_SHORT;
        } else if (type.indexOf("untypedAtomic")>=0){
            baseType = XQItemType.XQBASETYPE_UNTYPEDATOMIC;
        } else if (type.indexOf("untyped")>=0){
            baseType = XQItemType.XQBASETYPE_UNTYPED;
        } else if (type.indexOf("yearMonthDuration")>=0){
            baseType = XQItemType.XQBASETYPE_YEARMONTHDURATION;
        }
        generateTypeName();
    }
    public XQItemType(Item zorbaItem) {
        
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
            }
        } else if (zorbaItem.isAtomic()) {
            itemKind = XQITEMKIND_ATOMIC;
            type = zorbaItem.getType().getStringValue();
        }
        baseType = XQItemType.XQBASETYPE_ANYTYPE;
        if (type.indexOf("anyAtomicType")>=0){
            baseType = XQItemType.XQBASETYPE_ANYATOMICTYPE;
        } else if (type.indexOf("anySimpleType")>=0){
            baseType = XQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyType")>=0){
            baseType = XQItemType.XQBASETYPE_ANYTYPE;
        } else if (type.indexOf("anyURI")>=0){
            baseType = XQItemType.XQBASETYPE_ANYURI;
        } else if (type.indexOf("base64Binary")>=0){
            baseType = XQItemType.XQBASETYPE_BASE64BINARY;
        } else if (type.indexOf("boolean")>=0){
            baseType = XQItemType.XQBASETYPE_BOOLEAN;
        } else if (type.indexOf("byte")>=0){
            baseType = XQItemType.XQBASETYPE_BYTE;
        } else if (type.indexOf("dateTime")>=0){
            baseType = XQItemType.XQBASETYPE_DATETIME;
        } else if (type.indexOf("date")>=0){
            baseType = XQItemType.XQBASETYPE_DATE;
        } else if (type.indexOf("dayTimeDuration")>=0){
            baseType = XQItemType.XQBASETYPE_DAYTIMEDURATION;
        } else if (type.indexOf("decimal")>=0){
            baseType = XQItemType.XQBASETYPE_DECIMAL;
        } else if (type.indexOf("double")>=0){
            baseType = XQItemType.XQBASETYPE_DOUBLE;
        } else if (type.indexOf("duration")>=0){
            baseType = XQItemType.XQBASETYPE_DURATION;
        } else if (type.indexOf("ENTITIES")>=0){
            baseType = XQItemType.XQBASETYPE_ENTITIES;
        } else if (type.indexOf("ENTITY")>=0){
            baseType = XQItemType.XQBASETYPE_ENTITY;
        } else if (type.indexOf("float")>=0){
            baseType = XQItemType.XQBASETYPE_FLOAT;
        } else if (type.indexOf("gDay")>=0){
            baseType = XQItemType.XQBASETYPE_GDAY;
        } else if (type.indexOf("gMonthDay")>=0){
            baseType = XQItemType.XQBASETYPE_GMONTHDAY;
        } else if (type.indexOf("gMonth")>=0){
            baseType = XQItemType.XQBASETYPE_GMONTH;
        } else if (type.indexOf("gYear")>=0){
            baseType = XQItemType.XQBASETYPE_GYEAR;
        } else if (type.indexOf("hexBinary")>=0){
            baseType = XQItemType.XQBASETYPE_HEXBINARY;
        } else if (type.indexOf("IDREFS")>=0){
            baseType = XQItemType.XQBASETYPE_IDREFS;
        } else if (type.indexOf("IDREF")>=0){
            baseType = XQItemType.XQBASETYPE_IDREF;
        } else if (type.indexOf("ID")>=0){
            baseType = XQItemType.XQBASETYPE_ID;
        } else if (type.indexOf("integer")>=0){
            baseType = XQItemType.XQBASETYPE_INTEGER;
        } else if (type.indexOf("int")>=0){
            baseType = XQItemType.XQBASETYPE_INT;
        } else if (type.indexOf("language")>=0){
            baseType = XQItemType.XQBASETYPE_LANGUAGE;
        } else if (type.indexOf("long")>=0){
            baseType = XQItemType.XQBASETYPE_LONG;
        } else if (type.indexOf("QName")>=0){
            baseType = XQItemType.XQBASETYPE_QNAME;
        } else if (type.indexOf("NCName")>=0){
            baseType = XQItemType.XQBASETYPE_NCNAME;
        } else if (type.indexOf("Name")>=0){
            baseType = XQItemType.XQBASETYPE_NAME;
        } else if (type.indexOf("negativeInteger")>=0){
            baseType = XQItemType.XQBASETYPE_NEGATIVE_INTEGER;
        } else if (type.indexOf("NMTOKENS")>=0){
            baseType = XQItemType.XQBASETYPE_NMTOKENS;
        } else if (type.indexOf("NMTOKEN")>=0){
            baseType = XQItemType.XQBASETYPE_NMTOKEN;
        } else if (type.indexOf("nonNegativeInteger")>=0){
            baseType = XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER;
        } else if (type.indexOf("nonPositiveInteger")>=0){
            baseType = XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER;
        } else if (type.indexOf("normalizedString")>=0){
            baseType = XQItemType.XQBASETYPE_NORMALIZED_STRING;
        } else if (type.indexOf("NOTATION")>=0){
            baseType = XQItemType.XQBASETYPE_NOTATION;
        } else if (type.indexOf("positiveInteger")>=0){
            baseType = XQItemType.XQBASETYPE_POSITIVE_INTEGER;
        } else if (type.indexOf("short")>=0){
            baseType = XQItemType.XQBASETYPE_SHORT;
        } else if (type.indexOf("string")>=0){
            baseType = XQItemType.XQBASETYPE_STRING;
        } else if (type.indexOf("time")>=0){
            baseType = XQItemType.XQBASETYPE_TIME;
        } else if (type.indexOf("token")>=0){
            baseType = XQItemType.XQBASETYPE_TOKEN;
        } else if (type.indexOf("unsignedByte")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_BYTE;
        } else if (type.indexOf("unsignedInt")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_INT;
        } else if (type.indexOf("unsignedLong")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_LONG;
        } else if (type.indexOf("unsignedShort")>=0){
            baseType = XQItemType.XQBASETYPE_UNSIGNED_SHORT;
        } else if (type.indexOf("untypedAtomic")>=0){
            baseType = XQItemType.XQBASETYPE_UNTYPEDATOMIC;
        } else if (type.indexOf("untyped")>=0){
            baseType = XQItemType.XQBASETYPE_UNTYPED;
        } else if (type.indexOf("yearMonthDuration")>=0){
            baseType = XQItemType.XQBASETYPE_YEARMONTHDURATION;
        }
        generateTypeName();
    }
    
    public XQItemType(int itemkind, String piTarget) {
        this.itemKind = itemkind;
        this.piTarget = piTarget;
        generateTypeName();
    }
    public XQItemType(int itemkind) {
        this.itemKind = itemkind;
        generateTypeName();
    }
    public XQItemType(int itemkind, int basetype) {
        this.itemKind = itemkind;
        this.baseType = basetype;
        generateTypeName();
    }
    public XQItemType(int itemkind, QName nodename, int basetype) {
        this.itemKind = itemkind;
        this.nodeName = nodename;
        this.baseType = basetype;
        generateTypeName();
    }
    public XQItemType(int itemkind, QName nodename, int basetype, QName typename, URI schemaURI, boolean allowNill) throws XQException {
        this.itemKind = itemkind;
        this.nodeName = nodename;
        this.baseType = basetype;
        this.typeName = typename;
        this.schemaURI = schemaURI;
        this.allowNill = allowNill;
    }
    public XQItemType(int itemkind, QName nodename, int basetype, URI schemaURI) throws XQException {
        this.itemKind = itemkind;
        this.nodeName = nodename;
        this.baseType = basetype;
        this.schemaURI = schemaURI;
        generateTypeName();
    }
    
    
    private void generateTypeName() {
        String namespaceURI = "http://www.w3.org/2001/XMLSchema";
        String localPart = "untyped";
        String prefix = "";
        
        switch (baseType) {
            case XQItemType.XQBASETYPE_ANYATOMICTYPE:
                localPart = "anyAtomicType";
                break;
            case XQItemType.XQBASETYPE_ANYSIMPLETYPE:
                localPart = "anySimpleType";
                break;
            case XQItemType.XQBASETYPE_ANYTYPE:
                localPart = "anyType";
                break;
            case XQItemType.XQBASETYPE_ANYURI:
                localPart = "anyURI";
                break;
            case XQItemType.XQBASETYPE_BASE64BINARY:
                localPart = "base64Binary";
                break;
            case XQItemType.XQBASETYPE_BOOLEAN:
                localPart = "boolean";
                break;
            case XQItemType.XQBASETYPE_BYTE:
                localPart = "byte";
                break;
            case XQItemType.XQBASETYPE_DATE:
                localPart = "date";
                break;
            case XQItemType.XQBASETYPE_DATETIME:
                localPart = "dateTime";
                break;
            case XQItemType.XQBASETYPE_DAYTIMEDURATION:
                localPart = "dayTimeDuration";
                break;
            case XQItemType.XQBASETYPE_DECIMAL:
                localPart = "decimal";
                break;
            case XQItemType.XQBASETYPE_DOUBLE:
                localPart = "double";
                break;
            case XQItemType.XQBASETYPE_DURATION:
                localPart = "duration";
                break;
            case XQItemType.XQBASETYPE_ENTITIES:
                localPart = "ENTITIES";
                break;
            case XQItemType.XQBASETYPE_ENTITY:
                localPart = "ENTITY";
                break;
            case XQItemType.XQBASETYPE_FLOAT:
                localPart = "float";
                break;
            case XQItemType.XQBASETYPE_GDAY:
                localPart = "gDay";
                break;
            case XQItemType.XQBASETYPE_GMONTH:
                localPart = "gMonth";
                break;
            case XQItemType.XQBASETYPE_GMONTHDAY:
                localPart = "gMonthDay";
                break;
            case XQItemType.XQBASETYPE_GYEAR:
                localPart = "gYear";
                break;
            case XQItemType.XQBASETYPE_GYEARMONTH:
                localPart = "gYearMonth";
                break;
            case XQItemType.XQBASETYPE_HEXBINARY:
                localPart = "hexBinary";
                break;
            case XQItemType.XQBASETYPE_ID:
                localPart = "ID";
                break;
            case XQItemType.XQBASETYPE_IDREF:
                localPart = "IDREF";
                break;
            case XQItemType.XQBASETYPE_IDREFS:
                localPart = "IDREFS";
                break;
            case XQItemType.XQBASETYPE_INT:
                localPart = "int";
                break;
            case XQItemType.XQBASETYPE_INTEGER:
                localPart = "integer";
                break;
            case XQItemType.XQBASETYPE_LANGUAGE:
                localPart = "language";
                break;
            case XQItemType.XQBASETYPE_LONG:
                localPart = "long";
                break;
            case XQItemType.XQBASETYPE_NAME:
                localPart = "Name";
                break;
            case XQItemType.XQBASETYPE_NCNAME:
                localPart = "NCName";
                break;
            case XQItemType.XQBASETYPE_NEGATIVE_INTEGER:
                localPart = "negativeInteger";
                break;
            case XQItemType.XQBASETYPE_NMTOKEN:
                localPart = "NMTOKEN";
                break;
            case XQItemType.XQBASETYPE_NMTOKENS:
                localPart = "NMTOKENS";
                break;
            case XQItemType.XQBASETYPE_NONNEGATIVE_INTEGER:
                localPart = "nonNegativeInteger";
                break;
            case XQItemType.XQBASETYPE_NONPOSITIVE_INTEGER:
                localPart = "nonPositiveInteger";
                break;
            case XQItemType.XQBASETYPE_NORMALIZED_STRING:
                localPart = "normalizedString";
                break;
            case XQItemType.XQBASETYPE_NOTATION:
                localPart = "NOTATION";
                break;
            case XQItemType.XQBASETYPE_POSITIVE_INTEGER:
                localPart = "positiveInteger";
                break;
            case XQItemType.XQBASETYPE_QNAME:
                localPart = "QName";
                break;
            case XQItemType.XQBASETYPE_SHORT:
                localPart = "short";
                break;
            case XQItemType.XQBASETYPE_STRING:
                localPart = "string";
                break;
            case XQItemType.XQBASETYPE_TIME:
                localPart = "time";
                break;
            case XQItemType.XQBASETYPE_TOKEN:
                localPart = "token";
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_BYTE:
                localPart = "unsignedByte";
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_INT:
                localPart = "unsignedInt";
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_LONG:
                localPart = "unsignedLong";
                break;
            case XQItemType.XQBASETYPE_UNSIGNED_SHORT:
                localPart = "unsignedShort";
                break;
            case XQItemType.XQBASETYPE_UNTYPED:
                localPart = "untyped";
                break;
            case XQItemType.XQBASETYPE_UNTYPEDATOMIC:
                localPart = "untypedAtomic";
                break;
            case XQItemType.XQBASETYPE_YEARMONTHDURATION:
                localPart = "yearMonthDuration";
                break;
            default:
                localPart = "untyped";
                break;
       }
        typeName = new QName(namespaceURI, localPart, prefix);
    }
    
    
    
    
    @Override
    public int getBaseType() throws XQException {
        if (!((itemKind==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_SCHEMA_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_ATTRIBUTE) ||
              (itemKind==XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE) ||
              (itemKind==XQItemType.XQITEMKIND_ATOMIC))) {
            throw new XQException("Item kind is not valid for a Base Type.");
        }
        return baseType;
    }

    @Override
    public int getItemKind() {
        return itemKind;
    }

    @Override
    public int getItemOccurrence() {
        return XQSequenceType.OCC_EXACTLY_ONE;
    }

    @Override
    public QName getNodeName() throws XQException {
        if (!((itemKind==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_SCHEMA_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_ATTRIBUTE) ||
              (itemKind==XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE))) {
            throw new XQException("Item kind is not valid for a Type Name.");
        }
        return nodeName;
    }

    @Override
    public URI getSchemaURI() {
        return schemaURI;
    }

    @Override
    public QName getTypeName() throws XQException {
        if (!((itemKind==XQItemType.XQITEMKIND_DOCUMENT_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_DOCUMENT_SCHEMA_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_ATOMIC) ||
              (itemKind==XQItemType.XQITEMKIND_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_SCHEMA_ELEMENT) ||
              (itemKind==XQItemType.XQITEMKIND_ATTRIBUTE) ||
              (itemKind==XQItemType.XQITEMKIND_SCHEMA_ATTRIBUTE))) {
            throw new XQException("Item kind is not valid for a Type Name.");
        }
        return typeName;
    }

    @Override
    public boolean isAnonymousType() {
        return (itemKind==0);
    }

    @Override
    public boolean isElementNillable() {
        return allowNill;
    }

    @Override
    public String getPIName() throws XQException {
        if (itemKind!=XQItemType.XQITEMKIND_PI) {
            throw new XQException("Item kind is not a PI.");
        }
        return piTarget;
    }

    @Override
    public XQItemType getItemType() {
        return this;
    }
    
    @Override
    public boolean equals(Object o) {
        boolean result = false;
        boolean supportBaseType = false;
        boolean supportNodeName = false;
        boolean supportTypeName = false;
        boolean supportPIName = false;
        if (o instanceof XQItemType) {
            if ( (getItemKind()==((XQItemType)o).getItemKind()) &&
                 (getSchemaURI()==((XQItemType)o).getSchemaURI()) &&
                 (isAnonymousType()==((XQItemType)o).isAnonymousType()) &&
                 (isElementNillable()==((XQItemType)o).isElementNillable()) ) {
                try {
                    supportBaseType = getBaseType() == ((XQItemType)o).getBaseType();
                } catch (Exception e) {
                    supportBaseType = true;  // Not supported
                }
                try {
                    supportNodeName = getNodeName() == ((XQItemType)o).getNodeName();
                } catch (Exception e) {
                    supportNodeName = true; // Not supported
                }
                try {
                    supportTypeName = getTypeName().equals(((XQItemType)o).getTypeName());
                } catch (Exception e) {
                    supportTypeName = true; // Not supported
                }
                try {
                    supportPIName = getPIName().equals(((XQItemType)o).getPIName());
                } catch (Exception e) {
                    supportPIName = true; // Not supported
                }
                
                
                result = supportBaseType && supportNodeName && supportTypeName && supportPIName;
            }
        }
        return result;
    }

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

    @Override
    public String toString() {
        StringBuffer result = new StringBuffer();

        try {
            for (java.lang.reflect.Field field: XQItemType.class.getFields()) {
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
