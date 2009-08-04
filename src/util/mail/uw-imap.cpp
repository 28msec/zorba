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
#include <signal.h>

#include "util/mail/uw-imap.h"
#include "c-client.h"

char *SMTPUsername, *SMTPPassword;

namespace zorba {

  /*private methods*/
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

  void add_body(BODY *body, char* text, const char* message)
  {
    body->type = TYPETEXT;
    *text = '\0';
    strcat (text, message);
    strcat (text,"\015\012");
    body->contents.text.data = (unsigned char *) text;
    body->contents.text.size = strlen (text);
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
    char *text = (char *) fs_get (8*MAILTMPLEN);   /*message body*/
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

    add_body(body, text, message);

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
    else
      fs_give ((void **) &text);

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
//   switch ((short) errflg) {
//     case NIL:
//       printf ("[%s]\n",string);
//       break;
//     case PARSE:
//     case WARN:
//       printf ("WARN:%%%s\n",string);
//       break;
//     case ERROR:
//       printf ("ERROR:%s\n",string);
//       break;
//   }
}

/* Log an event to debugging telemetry
 * Accepts: string to log
 */
void mm_dlog (char *string)
{
//   puts (string);
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
