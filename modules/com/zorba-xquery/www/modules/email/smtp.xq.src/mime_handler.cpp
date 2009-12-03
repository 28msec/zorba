/*
 * Copyright 2006-2008 The FLWOR Foundation.
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
#include <vector>
#include <cstdio>

#include "mime_handler.h"

#include <zorba/zorbastring.h>
#include <zorba/iterator.h>
#include <zorba/item_factory.h>
#include <zorba/store_consts.h>

namespace zorba
{
  namespace email
  {
  //helper function for retrieving the NodeName of an Item
  static zorba::String
  get_nodename(const Item aElement)
  {
    Item lNodeName;
    aElement.getNodeName(lNodeName);
    return lNodeName.getStringValue();
  }

  //helper function for retrieving the string value of a Text Node
  static void
  get_text_value(const Item aElement,
                  zorba::String& aValue)
  {
    Iterator_t lChildrenIt;
    Item       lChild;

    aValue = String();

    lChildrenIt = aElement.getChildren();
    lChildrenIt->open();
    while (lChildrenIt->next(lChild))
      if (lChild.getNodeKind() == store::StoreConsts::textNode)
        aValue = lChild.getStringValue();

    lChildrenIt->close();
  }

  void CClientMimeHandler::begin(const Item& aMimeItem)
  {
    Iterator_t    childrenIt;

    //initialize ENVELOPE
    theEnvelope = mail_newenvelope ();

    //initialize BODY
    theBody = mail_newbody ();
    mail_initbody(theBody);

    //set theMessageItem
    childrenIt = aMimeItem.getChildren();
    childrenIt->open();
    if(childrenIt->next(theMessageItem))
      if (theMessageItem.getNodeKind() == store::StoreConsts::elementNode)
        if(!get_nodename(theMessageItem).lowercase().equals("message"))
          theMessageItem = zorba::Item();

    childrenIt->close();
  }

  bool
  CClientMimeHandler::envelope
      (zorba::String& aDiagnostics)
  {
    Iterator_t    lChildrenIt;
    zorba::Item   lChild;
    char line[MAILTMPLEN];
    bool          lRes = true;
    zorba::String lValue;

    if( theMessageItem.isNull() )
    {
      aDiagnostics = "The message could not be parsed.";
      return false;
    }

    //set the date from the client.
    //If this is not set it defaults to the date of the SMTP server.
    rfc822_date (line);
    theEnvelope->date = (unsigned char *) fs_get (1+strlen (line));
    strcpy ((char *)theEnvelope->date,line);

    lChildrenIt = theMessageItem.getChildren();
    lChildrenIt->open();
    while (lChildrenIt->next(lChild) && lRes)
    {
      if (lChild.getNodeKind() == store::StoreConsts::elementNode)
      {
        get_text_value(lChild, lValue);

        if(!lValue.empty())
        {
          zorba::String lLowerNodeName = get_nodename(lChild).lowercase();
          if(lLowerNodeName.equals("date"))
            theEnvelope->date = (unsigned char *) lValue.c_str();
          else if(lLowerNodeName.equals("from"))
          {
            theEnvelope->from = mail_newaddr ();
            rfc822_parse_adrlist (&theEnvelope->from, (char*)lValue.c_str(), NIL);
          }
          else if(lLowerNodeName.equals("sender"))
          {
            theEnvelope->sender = mail_newaddr ();
            rfc822_parse_adrlist (&theEnvelope->sender, (char*)lValue.c_str(), NIL);
          }
          else if(lLowerNodeName.equals("replyto"))
          {
            theEnvelope->reply_to = mail_newaddr ();
            rfc822_parse_adrlist (&theEnvelope->reply_to, (char*)lValue.c_str(), NIL);
          }
          else if(lLowerNodeName.equals("subject"))
            theEnvelope->subject = cpystr ((char*)lValue.c_str());
          else if(lLowerNodeName.equals("to"))
          {
            theEnvelope->to = mail_newaddr ();
            rfc822_parse_adrlist (&theEnvelope->to, (char*)lValue.c_str(), NIL);
          }
          else if(lLowerNodeName.equals("cc"))
          {
            theEnvelope->cc = mail_newaddr ();
            rfc822_parse_adrlist (&theEnvelope->cc, (char*)lValue.c_str(), NIL);
          }
          else if(lLowerNodeName.equals("bcc"))
          {
            theEnvelope->bcc = mail_newaddr ();
            rfc822_parse_adrlist (&theEnvelope->bcc, (char*)lValue.c_str(), NIL);
          }
        }
      }
    }
    lChildrenIt->close();

    return lRes;
  }

  bool
  CClientMimeHandler::body
      (zorba::String& aDiagnostics)
  {
    Iterator_t    lChildrenIt;
    zorba::Item   lChild;
    bool          lRes = true;
    zorba::String lValue;

    theBody->type = TYPEOTHER;

    lChildrenIt = theMessageItem.getChildren();
    lChildrenIt->open();
    while (lChildrenIt->next(lChild))
    {
      if (lChild.getNodeKind() == store::StoreConsts::elementNode)
      {
        get_text_value(lChild, lValue);

        if(get_nodename(lChild).lowercase().equals("content"))
          parse_content(theBody, lChild);
        else if(get_nodename(lChild).lowercase().equals("multipart"))
          lRes = parse_multipart(theBody, lChild);
      }
    }
    lChildrenIt->close();

    return lRes;
  }

  void
  CClientMimeHandler::set_text_body
      (BODY* aBody,
       const char* aMessage)
  {
    aBody->contents.text.data = (unsigned char *) fs_get (8*MAILTMPLEN);   //message body
    sprintf ((char*)aBody->contents.text.data,"%s\015\012",aMessage);
    aBody->contents.text.size = strlen ((const char*)aBody->contents.text.data);
  }

  PARAMETER *
  CClientMimeHandler::create_param
      (const char* aAttribute,
       const char * aValue,
       PARAMETER * aPrevious)
  {
    PARAMETER *lParam;
    lParam = mail_newbody_parameter();
    lParam->attribute = cpystr (aAttribute);
    lParam->value = cpystr (aValue);

    if(aPrevious)
      aPrevious->next = lParam;

    return lParam;
  }

  void
  CClientMimeHandler::set_encoding
      (BODY* aBody,
       zorba::String& aEncoding)
  {
    //all encodings should start with ENC so we only check the rest of the string
    zorba::String lUpperEncSuffix = aEncoding.uppercase().substring(3);

    if(lUpperEncSuffix.equals("7BIT"))
      aBody->encoding = ENC7BIT;
    else if (lUpperEncSuffix.equals("8BIT"))
      aBody->encoding = ENC8BIT;
    else if (lUpperEncSuffix.equals("BINARY"))
      aBody->encoding = ENCBINARY;
    else if (lUpperEncSuffix.equals("BASE64"))
      aBody->encoding = ENCBASE64;
    else if (lUpperEncSuffix.equals("QUOTEDPRINTABLE"))
      aBody->encoding = ENCQUOTEDPRINTABLE;
    else
      aBody->encoding = ENCOTHER;
  }

  bool
  CClientMimeHandler::set_content_type_value
      (BODY* aBody,
       zorba::String& aValue)
  {
    bool          lRes = true;
    int           lPos = aValue.indexOf("/");
    zorba::String lLowerType = aValue.substring(0, lPos).lowercase();

    //set the BODY content type
    if(lLowerType.equals("text"))
      aBody->type = TYPETEXT;
    else if(lLowerType.equals("multipart"))
      aBody->type = TYPEMULTIPART;
    else if(lLowerType.equals("message"))
      aBody->type = TYPEMESSAGE;
    else if(lLowerType.equals("application"))
      aBody->type = TYPEAPPLICATION;
    else if(lLowerType.equals("image"))
      aBody->type = TYPEIMAGE;
    else if(lLowerType.equals("audio"))
      aBody->type = TYPEAUDIO;
    else if(lLowerType.equals("video"))
      aBody->type = TYPEVIDEO;
    else
    {
      aBody->type = TYPEOTHER;
      lRes = false;
    }
    if(lRes) //set the BODY content subtype
    {
      // the list of subtypes of each type is available at
      // http://www.iana.org/assignments/media-types/
      zorba::String lSubtype = aValue.substring(lPos + 1,aValue.length() - lPos);
      aBody->subtype = cpystr((char*) lSubtype.uppercase().c_str());
    }

    return lRes;
  }

  bool
  CClientMimeHandler::parse_content
      (BODY* aBody,
       const Item aItemContent)
  {
    Iterator_t    lChildrenIt;
    Item          lChild;
    zorba::String lNname, lValue;
    bool          lRes = true;

    PARAMETER* lRoot = NIL;
    PARAMETER* lPrev = NIL;

    lChildrenIt = aItemContent.getChildren();
    lChildrenIt->open();
    while (lChildrenIt->next(lChild) && lRes)
    {
      if (lChild.getNodeKind() == store::StoreConsts::elementNode)
      {
        lNname = get_nodename(lChild);
        get_text_value(lChild, lValue);
        if(lNname.lowercase().equals("contenttype"))
        {
          if(aBody->type == TYPEOTHER)
            lRes = set_content_type_value(aBody, lValue);
        }
        else if(lNname.lowercase().equals("charset") ||
                lNname.lowercase().equals("name"))
        {
          lRoot = create_param((char*)lNname.c_str(), (char*)lValue.uppercase().c_str(), NIL);
          lPrev = lRoot;
        }
        else if(lNname.lowercase().equals("contenttransferencoding"))
          set_encoding(aBody, lValue);
        else if(lNname.lowercase().equals("body"))
          set_text_body(aBody, lValue.c_str());
        else if(lNname.lowercase().equals("content-id"))
          aBody->id = cpystr((char*)lValue.lowercase().c_str());
        else if(lNname.lowercase().equals("content-disposition"))
          //defined at http://tools.ietf.org/html/rfc2183 ,only FILENAME is parsed
          aBody->disposition.type = cpystr((char*)lValue.uppercase().c_str());
        else if(lNname.lowercase().equals("filename"))
        {
          PARAMETER* lfilename = NIL;
          lfilename = create_param((char*)lNname.c_str(), (char*)lValue.c_str(), NIL);
          aBody->disposition.parameter = lfilename;
        }
        else
        {
          PARAMETER* lParam = NIL;
          lParam = create_param((char*)lNname.c_str(), (char*)lValue.lowercase().c_str(), lPrev);

          if(lPrev)
            lPrev->next = lParam;
          else
            lRoot = lParam;

          lPrev = lParam;
        }
      }
    }
    lChildrenIt->close();

    if(lRes && lRoot && lRoot->value)
      aBody->parameter = lRoot;

    return lRes;
  }

  bool
  CClientMimeHandler::parse_multipart
      (BODY* aBody,
       const Item aItemMultipart)
  {
    Iterator_t    lChildrenIt;
    Item          lChild;
    zorba::String lValue;
    bool          lRes = true;
    PART*         partRoot = NIL;
    PART*         partPrev = NIL;

    lChildrenIt = aItemMultipart.getChildren();
    lChildrenIt->open();
    while (lChildrenIt->next(lChild) && lRes)
    {
      if (lChild.getNodeKind() == store::StoreConsts::elementNode)
      {
        if(get_nodename(lChild).lowercase().equals("contenttype"))
        {
          get_text_value(lChild, lValue);
          if(aBody->type == TYPEOTHER)
            lRes = set_content_type_value(aBody, lValue);
        }
        else if(aBody->type == TYPEMULTIPART)
        {
          PART* part;
          part = NIL;
          part = mail_newbody_part();
          part->body.type = TYPEOTHER;

          lRes = parse_multipart(&part->body,lChild);

          if(partPrev)
            partPrev->next = part;
          else
            partRoot = part;

          partPrev = part;
        }
        else if((aBody->type != TYPEOTHER) &&
                (aBody->type != TYPEMULTIPART))
        {
          parse_content(aBody, aItemMultipart);
          break;
        }
      }
    }
    lChildrenIt->close();

    if(lRes && partRoot)
      aBody->nested.part = partRoot;

    return lRes;
  }

  //destroy theBody and theEnvelope
  void CClientMimeHandler::end()
  {
  }

  void
  CClientMimeHandler::CClientEnvelope
      (char* aFrom,
       char* aTo,
       char* aCc,
       char* aBcc,
       char* aSubject,
       char* aDate)
  {
    char line[MAILTMPLEN];

    theEnvelope->from = mail_newaddr ();
    theEnvelope->return_path = mail_newaddr ();

    if( aFrom )
      rfc822_parse_adrlist (&theEnvelope->from, (char*)aFrom, NIL);

    if( aTo )
      //Parse RFC 2822 address list
      rfc822_parse_adrlist (&theEnvelope->to, (char*)aTo, NIL);

    if( aCc )
      //Parse RFC 2822 address list
      rfc822_parse_adrlist (&theEnvelope->cc, (char*)aCc, NIL);

    if( aBcc )
      //Parse RFC 2822 address list
      rfc822_parse_adrlist (&theEnvelope->bcc, (char*)aBcc, NIL);

    if( aSubject )
      theEnvelope->subject = cpystr (aSubject);

    //set the date from the client.
    //if this is not set it defaults to the date of the SMTP server.
    if(aDate)
      theEnvelope->date = (unsigned char *)cpystr (aDate);
    else
    {
      rfc822_date (line);
      theEnvelope->date = (unsigned char *) fs_get (1+strlen (line));
      strcpy ((char *)theEnvelope->date,line);
    }
  }

  CClientMimeHandler::~CClientMimeHandler()
  {
    if( theEnvelope )
      mail_free_envelope( &theEnvelope );

    mail_free_body(&theBody);
  }

  }//namespace email
}//namespace zorba
