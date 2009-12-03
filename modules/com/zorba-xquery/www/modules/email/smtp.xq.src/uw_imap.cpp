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
#include <vector>
#include <cstdio>

#include <signal.h>

#include "uw_imap.h"
#include "mime_parser.h"

#include <zorba/store_consts.h>
#include <zorba/item_factory.h>
#include <zorba/item.h>
#include <zorba/zorbastring.h>
#include <zorba/iterator.h>

namespace zorba
{
  namespace email
  {
  void
  CClient::setSMTPUser(const char* aSMTPUser)
  {
    lSMTPUser = std::string(aSMTPUser);
  }

  void
  CClient::setSMTPPwd(const char* aSMTPPwd)
  {
    lSMTPPwd = std::string(aSMTPPwd);
  }

  std::string
  CClient::getSMTPUser()
  {
    return lSMTPUser;
  }

  std::string
  CClient::getSMTPPwd()
  {
    return lSMTPPwd;
  }

  bool
  CClient::send(const Item& aMessage,
    const char* aSMTPServer, const char* aSMTPUser, const char* aSMTPPwd,
    zorba::String& aDiagnostics)
  {
    setSMTPUser((char*)aSMTPUser);
    setSMTPPwd((char*)aSMTPPwd);

    std::stringstream out;
    char tmp[MAILTMPLEN];
    SENDSTREAM *smtp_stream = NIL;
    bool res = false;

    char *hostlist[2];
    hostlist[0] = (char*)aSMTPServer;
    hostlist[1] = NIL;

    #include "linkage.c"
    #if MACOS
    {
      size_t *base = (size_t *) 0x000908;
      // increase stack size on a Mac
      SetApplLimit ((Ptr) (*base - (size_t) 65535L));
    }
    #endif

    CClientMimeHandler lHandler;
    MimeParser lParser(&lHandler);
    bool lParseOK = lParser.parse(aMessage, aDiagnostics);
    bool lHasRecipient = (lHandler.getEnvelope()->to ||
                          lHandler.getEnvelope()->cc ||
                          lHandler.getEnvelope()->bcc);

    if( !lParseOK )
      out << "Message could not be parsed.\n";
    else if( !lHasRecipient )
      out << "Message has no recipient.\n";
    else
    {
      out << "Sending...\n";
      smtp_stream = smtp_open (hostlist,NIL);//1);
      if ( smtp_stream )
      {
        sprintf (tmp,"MAIL");
        if (smtp_mail ( smtp_stream, tmp, lHandler.getEnvelope(), lHandler.getBody() ))
        {
          res = true;
          out << "OK\n";
        }
        else
          out << smtp_stream->reply << '\n';
      }
    }

    aDiagnostics = zorba::String(out.str());
    return res;
  }


  }//namespace email
}//namespace zorba



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
  mm_log (string,errflg); /* just do mm_log action */
}

/* Log an event for the user to see
 * Accepts: string to log
 *          error flag
 */
void mm_log (char *string,long errflg)
{
    switch ((short) errflg) {
    case NIL:
            printf ("[%s]\n",string);
            break;
    case PARSE:
    case WARN:
            printf ("WARN:%%%s\n",string);
            break;
    case ERROR:
            printf ("ERROR:%s\n",string);
            break;
        }
}

/* Log an event to debugging telemetry
 * Accepts: string to log
 */
void mm_dlog (char *string)
{
  std::cout << string << '\n';
}

/* Get user name and password for this host
 * Accepts: parse of network mailbox name
 *          where to return user name
 *          where to return password
 *          trial count
 */
void mm_login (NETMBX *mb,char *user,char *pwd,long trial)
{
  char* lSMTPUser = (char*)zorba::email::CClient::Instance().getSMTPUser().c_str();
  char* lSMTPPwd = (char*)zorba::email::CClient::Instance().getSMTPPwd().c_str();

  strcpy(user, lSMTPUser);
  strcpy(pwd, lSMTPPwd);
}

/* Log a fatal error event
 * Accepts: string to log
 */
void mm_fatal (char *string)
{
  printf ("?%s\n",string);
}
/* Co-routines from MAIL library */


