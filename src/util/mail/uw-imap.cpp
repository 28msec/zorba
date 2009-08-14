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

#include <iostream>
#include <cstdio>
#include "system/globalenv.h"

#include <signal.h>

#include "util/mail/uw-imap.h"
#include "c-client.h"

char *SMTPUsername, *SMTPPassword;

namespace zorba {

  /*private methods*/
  PARAMETER * createParam(const char* attribute, const char * value, PARAMETER * previous = NIL)
  {
    PARAMETER *param;
    param = mail_newbody_parameter();
    param->attribute = cpystr (attribute);
    param->value = cpystr (value);

    if(previous)
      previous->next = param;

    return param;
  }

  void add_envelope(ENVELOPE* msg, const char* to, const char* cc,const char* bcc, const char* subject)
  {
    char line[MAILTMPLEN];

    if( to ) {
      //Parse RFC 2822 address list
      rfc822_parse_adrlist (&msg->to, (char*)to, NIL);
    }

    if( cc ) {
      //Parse RFC 2822 address list
      rfc822_parse_adrlist (&msg->cc, (char*)cc, NIL);
    }

    if( bcc ) {
      //Parse RFC 2822 address list
      rfc822_parse_adrlist (&msg->bcc, (char*)bcc, NIL);
    }

    msg->from = mail_newaddr ();
    msg->return_path = mail_newaddr ();

    msg->subject = cpystr (subject);

    //set the date from the client.
    //If this is not set it defaults to the date of the SMTP server.
    rfc822_date (line);
    msg->date = (unsigned char *) fs_get (1+strlen (line));
    strcpy ((char *)msg->date,line);
  }

  void set_text_body(BODY* body, const char* message)
  {
    body->contents.text.data = (unsigned char *) fs_get (8*MAILTMPLEN);   /*message body*/
    sprintf ((char*)body->contents.text.data,"%s\015\012",message);
    body->contents.text.size = strlen ((const char*)body->contents.text.data);
  }

  void freeEnvelope(ENVELOPE* msg);
  void freeBody(BODY* body);
  bool get_text_value(const store::Item* element, xqpStringStore_t& value);
  bool get_text_value(const store::Item* element, std::istream* result);
  bool set_content_type_value(BODY* body, xqpStringStore_t& value);


  void parse_multipart_soso(BODY* body, store::Item_t itemMultipart);
  void parse_content_soso(BODY* body, store::Item_t itemContent);

  bool parse_message(ENVELOPE* envelope, BODY* body, store::Item_t itemDoc, std::iostream& result)
  {
    store::Iterator_t childrenIt;
    store::Item_t     child, itemMessage;
    bool              res = false, parseOk = false;
    xqpStringStore_t  value, mimeVersion, nonMime;

    char line[MAILTMPLEN];

    body->type = TYPEOTHER;

    //set the date from the client.
    //If this is not set it defaults to the date of the SMTP server.
    rfc822_date (line);
    envelope->date = (unsigned char *) fs_get (1+strlen (line));
    strcpy ((char *)envelope->date,line);

    childrenIt = itemDoc->getChildren();
    childrenIt->open();
    if(childrenIt->next(itemMessage))
      if (itemMessage->getNodeKind() == store::StoreConsts::elementNode)
        if(itemMessage->getNodeName()->getStringValue()->lowercase()->byteCompare("message") != 0)
          return false;
    childrenIt->close();

    childrenIt = itemMessage->getChildren();
    childrenIt->open();
    while (childrenIt->next(child))
    {
      if (child->getNodeKind() == store::StoreConsts::elementNode)
      {
        res = get_text_value(child, value);
        if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("date") == 0) {
          envelope->date = (unsigned char *) value->c_str();
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("from") == 0) {
          envelope->from = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->from, (char*)value->c_str(), NIL);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("sender") == 0) {
          envelope->sender = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->sender, (char*)value->c_str(), NIL);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("replyto") == 0) {
          envelope->reply_to = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->reply_to, (char*)value->c_str(), NIL);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("subject") == 0) {
          envelope->subject = cpystr ((char*)value->c_str());
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("to") == 0) {
          envelope->to = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->to, (char*)value->c_str(), NIL);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("cc") == 0) {
          envelope->cc = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->cc, (char*)value->c_str(), NIL);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("bcc") == 0) {
          envelope->bcc = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->bcc, (char*)value->c_str(), NIL);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("mimeversion") == 0) {
          mimeVersion = value;
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("nonmime") == 0) {
          nonMime = value;
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("content") == 0) {
          parseOk = true;
          parse_content_soso(body, child);
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("multipart") == 0) {
          parseOk = true;
          //nu fac nimik cu PART-ul returnat?
          parse_multipart_soso(body, child);
        }
      }
    }
    childrenIt->close();

    if(!parseOk)
      result << "The message structure is not correct: neither 'content' nor 'multipart' nodes were found.\n";

    return (res && parseOk);
  }

  bool mail(const char* to, const char* cc,const char* bcc,
            const char* subject, const char* message,
            const char* SMTPServer, const char* SMTPUser, const char* SMTPPwd,
            xqp_string& diagnostics)
  {
    std::stringstream out;

    char *hostlist[2];
    hostlist[0] = (char*) SMTPServer;
    hostlist[1] = NIL;

    SMTPUsername = (char*)SMTPUser;
    SMTPPassword = (char*)SMTPPwd;

    char tmp[MAILTMPLEN];
    bool res = false;
    SENDSTREAM *smtp_stream = NIL;
    ENVELOPE *msg = mail_newenvelope ();
    BODY *body = mail_newbody ();
    mail_initbody(body);

#include "linkage.c"
#if MACOS
  {
    size_t *base = (size_t *) 0x000908;
    /* increase stack size on a Mac */
    SetApplLimit ((Ptr) (*base - (size_t) 65535L));
  }
#endif

    add_envelope(msg, to, cc, bcc, subject);

    body->type = TYPETEXT;
    set_text_body(body, message);

    if ( msg->to ||
         msg->cc ||
         msg->bcc ) {
      out << "Sending..." << std::endl;
      smtp_stream = smtp_open (hostlist,NIL);
      if (smtp_stream){
        sprintf (tmp,"MAIL");
        if (smtp_mail (smtp_stream,tmp,msg,body))
        {
          res = true;
          out << "OK" << std::endl;
        }
        else
          out << smtp_stream->reply << std::endl;
      }
    }

    if (smtp_stream)
        smtp_close (smtp_stream);
    else
      out << "Can't open connection to given SMTP server {" << SMTPServer << "}" << std::endl;

    if(msg)
      mail_free_envelope(&msg);
    if(body)
      mail_free_body(&body);

    out.seekg (0, std::ios::end);
    uint size = out.tellg();
    out.seekg (0, std::ios::beg);

    diagnostics = new xqpStringStore(out.str().c_str(), size);
    return res;
  }

  bool mail(store::Item_t itemMessage,
            const char* SMTPServer, const char* SMTPUser, const char* SMTPPwd,
            xqp_string& diagnostics)
  {
    std::auto_ptr<std::stringstream> out(new std::stringstream());

    char *hostlist[2];
    hostlist[0] = (char*) SMTPServer;
    hostlist[1] = NIL;

    SMTPUsername = (char*)SMTPUser;
    SMTPPassword = (char*)SMTPPwd;

    char tmp[MAILTMPLEN];
    bool res = false;
    SENDSTREAM *smtp_stream = NIL;
    ENVELOPE *envelope = mail_newenvelope ();
    BODY *body = mail_newbody ();
    mail_initbody(body);

#include "linkage.c"
#if MACOS
    {
      size_t *base = (size_t *) 0x000908;
// increase stack size on a Mac
      SetApplLimit ((Ptr) (*base - (size_t) 65535L));
    }
#endif

    //parse the message item and fill in the envelope and body structures
    bool parseOk = parse_message(envelope, body, itemMessage, *out);

    bool hasRecipient = (envelope->to || envelope->cc || envelope->bcc);

    if( parseOk )
    {
      if ( hasRecipient )
      {
        *out << "Sending...\n";
        smtp_stream = smtp_open (hostlist,NIL);//1);
        if ( smtp_stream ){
          sprintf (tmp,"MAIL");
          if (smtp_mail ( smtp_stream, tmp, envelope, body ))
          {
            res = true;
            *out << "OK\n";
          }
          else
            *out << smtp_stream->reply << '\n';
        }
      }
      else {
        *out << "Message has no recipient.\n";
      }

      if ( smtp_stream )
        smtp_close (smtp_stream);
      else
        *out << "Can't open connection to given SMTP server {" << SMTPServer << "}\n";
    }

    if( envelope )
      freeEnvelope( envelope );
    if( body )
      freeBody( body );

    out->seekg (0, std::ios::end);
    uint size = out->tellg();
    out->seekg (0, std::ios::beg);

    diagnostics = new xqpStringStore(out->str().c_str(), size);
    return res;

  }

  void freeEnvelope(ENVELOPE* envelope)
  {
    if( envelope )
      mail_free_envelope( &envelope );
  }

  void freeBody(BODY* body)
  {
    switch (body->type) {
      case TYPEMULTIPART:
        if(body->nested.part->body.parameter)
          mail_free_body_parameter(&body->nested.part->body.parameter);

        mail_free_body_part (&body->nested.part);
        break;
      default:
        break;
    }

    if(body->parameter)
      mail_free_body_parameter(&body->parameter);

    mail_free_body(&body);
  }

  bool get_text_value(const store::Item* element, xqpStringStore_t& value)
  {
    store::Iterator_t childrenIt;
    store::Item_t     child;
    bool              res = false;

    childrenIt = element->getChildren();
    childrenIt->open();
    while (childrenIt->next(child))
    {
      if (child->getNodeKind() == store::StoreConsts::textNode)
        value = child->getStringValue();
      else
        value = new xqpStringStore();

      res = true;
    }
    childrenIt->close();
    return res;
  }

  bool get_text_value(const store::Item* element, std::istream* result)
  {
    store::Iterator_t childrenIt;
    store::Item_t     child;
    bool              res = false;

    childrenIt = element->getChildren();
    childrenIt->open();
    while (childrenIt->next(child))
    {
      if (child->getNodeKind() == store::StoreConsts::textNode)
      {
        result = new std::istringstream(child->getStringValue()->c_str());
        res = true;
      }
    }
    childrenIt->close();
    return res;
  }

  bool set_content_type_value(BODY* body, xqpStringStore_t& value)
  {
    // the list of subtypes of each type is available at
    // http://www.iana.org/assignments/media-types/
    xqpStringStore_t  subtype;
    bool              res = true;
    int32_t           pos = value->indexOf("/");

    //set the message type
    xqpStringStore_t tmp = value->substr(0,pos);
    if(tmp->lowercase()->byteCompare("text") == 0)
      body->type = TYPETEXT;
    else if(tmp->lowercase()->byteCompare("multipart") == 0)
      body->type = TYPEMULTIPART;
    else if(tmp->lowercase()->byteCompare("message") == 0)
      body->type = TYPEMESSAGE;
    else if(tmp->lowercase()->byteCompare("application") == 0)
      body->type = TYPEAPPLICATION;
    else if(tmp->lowercase()->byteCompare("image") == 0)
      body->type = TYPEIMAGE;
    else if(tmp->lowercase()->byteCompare("audio") == 0)
      body->type = TYPEAUDIO;
    else if(tmp->lowercase()->byteCompare("video") == 0)
      body->type = TYPEVIDEO;
    else
    {
      body->type = TYPEOTHER;
      res = false;
    }
    if( res ) {
      //set the message subtype
      subtype = value->substr(pos + 1,value->size() - pos);
      body->subtype = cpystr((char*) subtype->uppercase()->c_str());
    }

    return res;
  }

  void parse_multipart_soso(BODY* body, store::Item_t itemMultipart)
  {
    store::Iterator_t childrenIt;
    store::Item_t     child;
    xqpStringStore_t  value, name;
    PART*             partRoot = NIL;
    PART*             partPrev = NIL;

    childrenIt = itemMultipart->getChildren();
    childrenIt->open();
    while (childrenIt->next(child)) {
      if (child->getNodeKind() == store::StoreConsts::elementNode) {
        name = child->getNodeName()->getStringValue()->lowercase();
        if(name->byteCompare("contenttype") == 0) {
          get_text_value(child, value);
          if(body->type == TYPEOTHER)
            set_content_type_value(body, value);
        }
        else if(body->type == TYPEMULTIPART) {
          PART* part;
          part = NIL;
          part = mail_newbody_part();
          part->body.type = TYPEOTHER;

          parse_multipart_soso(&part->body,child);

          if(partPrev)
            partPrev->next = part;
          else
            partRoot = part;

          partPrev = part;
        }
        else if((body->type != TYPEOTHER) &&
                (body->type != TYPEMULTIPART))
        {
          parse_content_soso(body, itemMultipart);
          break;
        }
      }
    }
    childrenIt->close();

    if(partRoot)
      body->nested.part = partRoot;
  }

  void  parse_content_soso(BODY* body, store::Item_t itemContent)
  {
    store::Iterator_t childrenIt;
    store::Item_t     child;
    xqpStringStore_t  name, value;
    bool res = false;

    PARAMETER* root = NIL;
    PARAMETER* pPrev = NIL;

    childrenIt = itemContent->getChildren();
    childrenIt->open();
    while (childrenIt->next(child)) {
      if (child->getNodeKind() == store::StoreConsts::elementNode) {
        name = child->getNodeName()->getStringValue();
        res = get_text_value(child, value);
        if(name->lowercase()->byteCompare("contenttype") == 0) {
          if(body->type == TYPEOTHER)
            set_content_type_value(body, value);
        }
        else if(name->lowercase()->byteCompare("charset") == 0) {
          root = createParam((char*)name->c_str(), (char*)value->uppercase()->c_str(), NIL);
          pPrev = root;
        }
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("contenttransferencoding") == 0) {
          if(value->uppercase()->byteCompare("ENC7BIT") == 0)
            body->encoding = ENC7BIT;
          else if (value->uppercase()->byteCompare("ENC8BIT") == 0)
            body->encoding = ENC8BIT;
          else if (value->uppercase()->byteCompare("ENCBINARY") == 0)
            body->encoding = ENCBINARY;
          else if (value->uppercase()->byteCompare("ENCBASE64") == 0)
            body->encoding = ENCBASE64;
          else if (value->uppercase()->byteCompare("ENCQUOTEDPRINTABLE") == 0)
            body->encoding = ENCQUOTEDPRINTABLE;
          else
            body->encoding = ENCOTHER;
        }
        //also parse the serialization attribute
        else if(child->getNodeName()->getStringValue()->lowercase()->byteCompare("body") == 0) {
          set_text_body(body, value->c_str());
        }
        else {
          if( name->lowercase()->byteCompare("contentdisposition") == 0 )
            name = new xqpStringStore("Content-Disposition");

          PARAMETER* temp;
          temp = createParam((char*)name->c_str(), (char*)value->lowercase()->c_str(), pPrev);

          if(pPrev)
            pPrev->next = temp;
          else
            root = temp;

          pPrev = temp;
        }
      }
    }
    childrenIt->close();

    if(root && root->value)
      body->parameter = root;
  }
} /*namespace Zorba */

/* Co-routines from MAIL library */
void mm_searched (MAILSTREAM *stream,unsigned long msgno) {}
void mm_exists (MAILSTREAM *stream,unsigned long number) {}
void mm_expunged (MAILSTREAM *stream,unsigned long number) {}
void mm_flags (MAILSTREAM *stream,unsigned long number) {}
void mm_list (MAILSTREAM *stream,int delimiter,char *mailbox,long attributes) {}
void mm_lsub (MAILSTREAM *stream,int delimiter,char *mailbox,long attributes) {}
void mm_status (MAILSTREAM *stream,char *mailbox,MAILSTATUS *status) {}
void mm_critical (MAILSTREAM *stream) {}
void mm_nocritical (MAILSTREAM *stream) {}
long mm_diskerror (MAILSTREAM *stream,long errcode,long serious) {return NIL;}

/* Notification event
 * Accepts: MAIL stream
 *          string to log
 *          error flag
 */
void mm_notify (MAILSTREAM *stream,char *string,long errflg)
{
//   mm_log (string,errflg); /* just do mm_log action */
}

/* Log an event for the user to see
 * Accepts: string to log
 *          error flag
 */
void mm_log (char *string,long errflg)
{
//     switch ((short) errflg) {
//     case NIL:
//             printf ("[%s]\n",string);
//             break;
//     case PARSE:
//     case WARN:
//             printf ("WARN:%%%s\n",string);
//             break;
//     case ERROR:
//             printf ("ERROR:%s\n",string);
//             break;
//         }
}

/* Log an event to debugging telemetry
 * Accepts: string to log
 */
void mm_dlog (char *string)
{
//   std::cout << string << '\n';
}

/* Get user name and password for this host
 * Accepts: parse of network mailbox name
 *          where to return user name
 *          where to return password
 *          trial count
 */
void mm_login (NETMBX *mb,char *user,char *pwd,long trial)
{
  strcpy(user, SMTPUsername);
  strcpy(pwd, SMTPPassword);
}

/* Log a fatal error event
 * Accepts: string to log
 */
void mm_fatal (char *string)
{
//   printf ("?%s\n",string);
}
/* Co-routines from MAIL library */
