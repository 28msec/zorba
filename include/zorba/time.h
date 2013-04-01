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

#ifndef ZORBA_TIME_API_H
#define ZORBA_TIME_API_H

namespace zorba {
namespace time {

///////////////////////////////////////////////////////////////////////////////

/**
 * XQuery 3.0 F&O: 9.8.4.3: The calendars listed below were known to be in use
 * during the last hundred years.
 */
namespace calendar {
  enum type {
    unknown,
    AD,   ///< Anno Domini (Christian Era)
    AH,   ///< Anno Hegirae (Muhammedan Era)
    AM,   ///< Anno Mundi (Jewish Calendar)
    AME,  ///< Mauludi Era (solar years since Mohammed's birth)
    AP,   ///< Anno Persici
    AS,   ///< Aji Saka Era (Java)
    BE,   ///< Buddhist Era
    CB,   ///< Cooch Behar Era
    CE,   ///< Common Era
    CL,   ///< Chinese Lunar Era
    CS,   ///< Chula Sakarat Era
    EE,   ///< Ethiopian Era
    FE,   ///< Fasli Era
    ISO,  ///< ISO 8601 calendar
    JE,   ///< Japanese Calendar
    KE,   ///< Khalsa Era (Sikh calendar)
    KY,   ///< Kali Yuga
    ME,   ///< Malabar Era
    MS,   ///< Monarchic Solar Era
    OS,   ///< Old Style (Julian Calendar)
    RS,   ///< Rattanakosin (Bangkok) Era
    SE,   ///< Saka Era
    SH,   ///< Mohammedan Solar Era (Iran)
    SS,   ///< Saka Samvat
    TE,   ///< Tripurabda Era
    VE,   ///< Vikrama Era
    VS    ///< Vikrama Samvat Era
  };

} // namespace calendar

///////////////////////////////////////////////////////////////////////////////

} // namespace time
} // namespace zorba
#endif /* ZORBA_TIME_API_H */
/* vim:set et sw=2 ts=2: */
