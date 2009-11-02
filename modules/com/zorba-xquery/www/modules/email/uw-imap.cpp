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
#include <sstream>
#include <cstdio>
#include <vector>

// #include <signal.h>

#include "uw-imap.h"
#include "c-client.h"

#include <zorba/store_consts.h>
#include <zorba/item_factory.h>
#include <zorba/item.h>
#include <zorba/zorbastring.h>
#include <zorba/iterator.h>

char *SMTPUsername, *SMTPPassword;

namespace zorba {
  namespace smtpmodule
  {

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
    body->contents.text.data = (unsigned char *) fs_get (8*MAILTMPLEN);   //message body
    sprintf ((char*)body->contents.text.data,"%s\015\012",message);
    body->contents.text.size = strlen ((const char*)body->contents.text.data);
  }

  void freeEnvelope(ENVELOPE* msg);
  void freeBody(BODY* body);

  zorba::String get_nodename(const Item element);
  bool get_text_value(const Item element, zorba::String& value);
  bool set_content_type_value(BODY* body, zorba::String& value);

  void parse_multipart(BODY* body, const Item itemMultipart);
  void parse_content(BODY* body, const Item itemContent);

  zorba::String
  get_nodename(const Item element)
  {
    Item lNodeName;
    element.getNodeName(lNodeName);
    return lNodeName.getStringValue();
  }

  bool parse_message(ENVELOPE* envelope, BODY* body, const Item& itemDoc, std::iostream& result)
  {
    Iterator_t        childrenIt;
    Item              child, itemMessage;
    bool              res = false, parseOk = false;
    zorba::String     value, mimeVersion, nonMime;

    char line[MAILTMPLEN];

    body->type = TYPEOTHER;

    //set the date from the client.
    //If this is not set it defaults to the date of the SMTP server.
    rfc822_date (line);
    envelope->date = (unsigned char *) fs_get (1+strlen (line));
    strcpy ((char *)envelope->date,line);

    childrenIt = itemDoc.getChildren();
    if(childrenIt->next(itemMessage))
      if (itemMessage.getNodeKind() == store::StoreConsts::elementNode)
        if(!get_nodename(itemMessage).lowercase().equals("message"))
          return false;

    childrenIt = itemMessage.getChildren();
    while (childrenIt->next(child))
    {
      if (child.getNodeKind() == store::StoreConsts::elementNode)
      {
        res = get_text_value(child, value);
        if(get_nodename(child).lowercase().equals("date")) {
          envelope->date = (unsigned char *) value.c_str();
        }
        else if(get_nodename(child).lowercase().equals("from")) {
          envelope->from = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->from, (char*)value.c_str(), NIL);
        }
        else if(get_nodename(child).lowercase().equals("sender")) {
          envelope->sender = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->sender, (char*)value.c_str(), NIL);
        }
        else if(get_nodename(child).lowercase().equals("replyto")) {
          envelope->reply_to = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->reply_to, (char*)value.c_str(), NIL);
        }
        else if(get_nodename(child).lowercase().equals("subject")) {
          envelope->subject = cpystr ((char*)value.c_str());
        }
        else if(get_nodename(child).lowercase().equals("to")) {
          envelope->to = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->to, (char*)value.c_str(), NIL);
        }
        else if(get_nodename(child).lowercase().equals("cc")) {
          envelope->cc = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->cc, (char*)value.c_str(), NIL);
        }
        else if(get_nodename(child).lowercase().equals("bcc")) {
          envelope->bcc = mail_newaddr ();
          rfc822_parse_adrlist (&envelope->bcc, (char*)value.c_str(), NIL);
        }
        else if(get_nodename(child).lowercase().equals("mimeversion")) {
          mimeVersion = value;
        }
        else if(get_nodename(child).lowercase().equals("nonmime")) {
          nonMime = value;
        }
        else if(get_nodename(child).lowercase().equals("content")) {
          parseOk = true;
          parse_content(body, child);
        }
        else if(get_nodename(child).lowercase().equals("multipart")) {
          parseOk = true;
          //nu fac nimik cu PART-ul returnat?
          parse_multipart(body, child);
        }
      }
    }

    if(!parseOk)
      result << "The message structure is not correct: neither 'content' nor 'multipart' nodes were found.\n";

    return (res && parseOk);
  }

  bool mail(const char* to, const char* cc,const char* bcc,
            const char* subject, const char* message,
            const char* SMTPServer, const char* SMTPUser, const char* SMTPPwd,
            zorba::String& diagnostics)
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

    diagnostics = zorba::String(out.str());
    return res;
  }

  bool mail(const Item& itemMessage,
            const char* SMTPServer, const char* SMTPUser, const char* SMTPPwd,
            zorba::String& diagnostics)
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

    diagnostics = zorba::String(out->str());
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

  bool get_text_value(const Item element, zorba::String& value)
  {
    Iterator_t  childrenIt;
    Item        child;
    bool        res = false;

    childrenIt = element.getChildren();
    while (childrenIt->next(child))
    {
      if (child.getNodeKind() == store::StoreConsts::textNode)
        value = child.getStringValue();
      else
        value = String();

      res = true;
    }
    return res;
  }

  bool set_content_type_value(BODY* body, zorba::String& value)
  {
    // the list of subtypes of each type is available at
    // http://www.iana.org/assignments/media-types/
    zorba::String subtype;
    bool          res = true;
    int           pos = value.indexOf("/");

    //set the message type
    zorba::String tmp = value.substring(0,pos);
    if(tmp.lowercase().equals("text"))
      body->type = TYPETEXT;
    else if(tmp.lowercase().equals("multipart"))
      body->type = TYPEMULTIPART;
    else if(tmp.lowercase().equals("message"))
      body->type = TYPEMESSAGE;
    else if(tmp.lowercase().equals("application"))
      body->type = TYPEAPPLICATION;
    else if(tmp.lowercase().equals("image"))
      body->type = TYPEIMAGE;
    else if(tmp.lowercase().equals("audio"))
      body->type = TYPEAUDIO;
    else if(tmp.lowercase().equals("video"))
      body->type = TYPEVIDEO;
    else
    {
      body->type = TYPEOTHER;
      res = false;
    }
    if( res ) {
      //set the message subtype
      subtype = value.substring(pos + 1,value.length() - pos);
      body->subtype = cpystr((char*) subtype.uppercase().c_str());
    }

    return res;
  }

  void parse_multipart(BODY* body, const Item itemMultipart)
  {
    Iterator_t    childrenIt;
    Item          child;
    zorba::String value;
    PART*         partRoot = NIL;
    PART*         partPrev = NIL;

    childrenIt = itemMultipart.getChildren();
    while (childrenIt->next(child)) {
      if (child.getNodeKind() == store::StoreConsts::elementNode) {
        if(get_nodename(child).lowercase().equals("contenttype")) {
          get_text_value(child, value);
          if(body->type == TYPEOTHER)
            set_content_type_value(body, value);
        }
        else if(body->type == TYPEMULTIPART) {
          PART* part;
          part = NIL;
          part = mail_newbody_part();
          part->body.type = TYPEOTHER;

          parse_multipart(&part->body,child);

          if(partPrev)
            partPrev->next = part;
          else
            partRoot = part;

          partPrev = part;
        }
        else if((body->type != TYPEOTHER) &&
                (body->type != TYPEMULTIPART))
        {
          parse_content(body, itemMultipart);
          break;
        }
      }
    }

    if(partRoot)
      body->nested.part = partRoot;
  }

  void  parse_content(BODY* body, const Item itemContent)
  {
    Iterator_t    childrenIt;
    Item          child;
    zorba::String name, value;
    bool res = false;

    PARAMETER* root = NIL;
    PARAMETER* pPrev = NIL;

    childrenIt = itemContent.getChildren();
    while (childrenIt->next(child)) {
      if (child.getNodeKind() == store::StoreConsts::elementNode) {
        name = get_nodename(child);
        res = get_text_value(child, value);
        if(name.lowercase().equals("contenttype")) {
          if(body->type == TYPEOTHER)
            set_content_type_value(body, value);
        }
        else if(name.lowercase().equals("charset")) {
          root = createParam((char*)name.c_str(), (char*)value.uppercase().c_str(), NIL);
          pPrev = root;
        }
        else if(name.lowercase().equals("contenttransferencoding")) {
          if(value.uppercase().equals("ENC7BIT"))
            body->encoding = ENC7BIT;
          else if (value.uppercase().equals("ENC8BIT"))
            body->encoding = ENC8BIT;
          else if (value.uppercase().equals("ENCBINARY"))
            body->encoding = ENCBINARY;
          else if (value.uppercase().equals("ENCBASE64"))
            body->encoding = ENCBASE64;
          else if (value.uppercase().equals("ENCQUOTEDPRINTABLE"))
            body->encoding = ENCQUOTEDPRINTABLE;
          else
            body->encoding = ENCOTHER;
        }
        //also parse the serialization attribute
        else if(name.lowercase().equals("body")) {
          set_text_body(body, value.c_str());
        }
        else {
          if( name.lowercase().equals("contentdisposition"))
            name = zorba::String("Content-Disposition");

          PARAMETER* temp;
          temp = createParam((char*)name.c_str(), (char*)value.lowercase().c_str(), pPrev);

          if(pPrev)
            pPrev->next = temp;
          else
            root = temp;

          pPrev = temp;
        }
      }
    }

    if(root && root->value)
      body->parameter = root;
  }
  }//namespace smtpmodule
} //namespace Zorba

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
