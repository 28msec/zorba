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
#pragma once
#ifndef ZORBA_CORE_LOCALE_H
#define ZORBA_CORE_LOCALE_H

#include <iostream>

#include <zorba/util/locale.h>

#include "util/string_util.h"
#include "zorbatypes/zstring.h"

namespace zorba {
  namespace locale {

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso3166_1 {
      /**
       * Maps an iso3166_1::type to a string.
       *
       * @param t The type to map.
       * @return Returns the corresponding string or "UNKNOWN".
       */
      char const* str( type t );

      /**
       * Emits an iso3166_1::type to an ostream.
       *
       * @param o The ostream to emit to.
       * @param t The type to emit.
       * @return Returns \a o.
       */
      inline std::ostream& operator<<( std::ostream &o, type t ) {
        return o << str( t );
      }

      /**
       * Finds the ISO 3166-1 country code enumeration from the given string.
       *
       * @param country An ISO 3166-1 country code.
       * @return Returns said enumeration or \c unknown.
       */
      type find( char const *country );

      //
      // Template version of find().
      //
      template<class StringType> inline
      typename std::enable_if<ZORBA_HAS_C_STR(StringType),type>::type
      find( StringType const &country ) {
        return find( country.c_str() );
      }

      /**
       * Gets the "default" country that speaks the given language.
       *
       * @param lang The language to get the default country for.
       * @return Returns said country or \c unknown.
       */
      type get_default( iso639_1::type lang );

    } // namespace iso3166_1

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso639_1 {
      /**
       * Maps an iso639_1::type to a string.
       *
       * @param t The type to map.
       * @return Returns the corresponding string or "UNKNOWN".
       */
      char const* str( type t );

      /**
       * Emits an iso639_1::type to an ostream.
       *
       * @param o The ostream to emit to.
       * @param t The type to emit.
       * @return Returns \a o.
       */
      inline std::ostream& operator<<( std::ostream &o, type t ) {
        return o << str( t );
      }

      /**
       * Finds the ISO 639-1 language code enumeration from the given string.
       *
       * @param lang An ISO 639-1 langauge code.
       * @return Returns said enumeration or \c unknown.
       */
      type find( char const *lang );

      //
      // Template version of find().
      //
      template<class StringType> inline
      typename std::enable_if<ZORBA_HAS_C_STR(StringType),type>::type
      find( StringType const &lang ) {
        return find( lang.c_str() );
      }
    } // namespace iso639_1

    /////////////////////////////////////////////////////////////////////////// 

    namespace iso639_2 {
      enum type {
        unknown,
        aar,  ///< Afar
        abk,  ///< Abkhazian
        afr,  ///< Afrikaans
        aka,  ///< Akan
        alb,  ///< Albanian
        amh,  ///< Amharic
        ara,  ///< Arabic
        arg,  ///< Aragonese
        arm,  ///< Armenian
        asm_, ///< Assamese [without '_', it's a C++ keyword]
        ava,  ///< Avaric
        ave,  ///< Avestan
        aym,  ///< Aymara
        aze,  ///< Azerbaijani
        bak,  ///< Bashkir
        bam,  ///< Bambara
        baq,  ///< Basque
        bel,  ///< Belarusian
        ben,  ///< Bengali
        bih,  ///< Bihari
        bis,  ///< Bislama
        bos,  ///< Bosnian
        bre,  ///< Breton
        bul,  ///< Bulgarian
        bur,  ///< Burmese
        cat,  ///< Catalan
        cha,  ///< Chamorro
        che,  ///< Chechen
        chi,  ///< Chinese
        chu,  ///< Church Slavic; Old Slavonic; Church Slavonic
        cym,  ///< Welsh
        dan,  ///< Danish
        deu,  ///< German (T)
        div,  ///< Divehi; Dhivehi; Maldivian
        dut,  ///< Dutch (B)
        dzo,  ///< Dzongkha
        ell,  ///< Modern Greek
        eng,  ///< English
        epo,  ///< Esperanto
        est,  ///< Estonian
        ewe,  ///< Ewe
        fao,  ///< Faroese
        fij,  ///< Fijian
        fin,  ///< Finnish
        fra,  ///< French (T)
        fre,  ///< French (B)
        fry,  ///< Western Frisian
        ful,  ///< Fulah
        geo,  ///< Georgian
        ger,  ///< German (B)
        gla,  ///< Scottish Gaelic; Gaelic
        gle,  ///< Irish
        glg,  ///< Galician
        glv,  ///< Manx
        gre,  ///< Modern Greek
        grn,  ///< Guarani
        guj,  ///< Gujarati
        hat,  ///< Haitian Creole; Haitian
        hau,  ///< Hausa
        heb,  ///< Hebrew
        her,  ///< Herero
        hin,  ///< Hindi
        hmo,  ///< Hiri Motu
        hrv,  ///< Croatian
        hun,  ///< Hungarian
        ibo,  ///< Igbo
        ice,  ///< Icelandic
        ido,  ///< Ido
        iku,  ///< Inuktitut
        ile,  ///< Interlingue; Occidental
        ina,  ///< Interlingua
        ind,  ///< Indonesian
        ipk,  ///< Inupiaq
        isl,  ///< Icelandic
        ita,  ///< Italian
        jav,  ///< Javanese
        jpn,  ///< Japanese
        kal,  ///< Kalaallisut; Greenlandic
        kan,  ///< Kannada
        kas,  ///< Kashmiri
        kat,  ///< Georgian
        kau,  ///< Kanuri
        kaz,  ///< Kazakh
        khm,  ///< Central Khmer
        kik,  ///< Kikuyu; Gikuyu
        kin,  ///< Kinyarwanda
        kir,  ///< Kirghiz; Kyrgyz
        kom,  ///< Komi
        kon,  ///< Kongo
        kor,  ///< Korean
        kua,  ///< Kuanyama; Kwanyama
        kur,  ///< Kurdish
        lao,  ///< Lao
        lat,  ///< Latin
        lav,  ///< Latvian
        lim,  ///< Limburgan; Limburger; Limburgish
        lin,  ///< Lingala
        lit,  ///< Lithuanian
        ltz,  ///< Luxembourgish; Letzeburgesch
        lub,  ///< Luba-Katanga
        mya,  ///< Burmese
        nld,  ///< Dutch (T)
        nor,  ///< Norwegian
        nya,  ///< Chichewa; Chewa; Nyanja
        por,  ///< Portuguese
        ron,  ///< Romanian (T)
        rum,  ///< Romanian (B)
        rus,  ///< Russian
        spa,  ///< Spanish
        swe,  ///< Swedish
        tur,  ///< Turkish
        ven,  ///< Venda
        vie,  ///< Vietnamese
        vol,  ///< Volapuk
        wel,  ///< Welsh
        wln,  ///< Walloon
        wol,  ///< Wolof
        xho,  ///< Xhosa
        yid,  ///< Yiddish
        yor,  ///< Yoruba
        zha,  ///< Zhuang; Chuang
        zho,  ///< Chinese
        zul,  ///< Zulu
        NUM_ENTRIES
      };

      /**
       * Maps an iso639_2::type to a string.
       *
       * @param t The type to map.
       * @return Returns the corresponding string or "UNKNOWN".
       */
      char const* str( type t );

      /**
       * Emits an iso639_2::type to an ostream.
       *
       * @param o The ostream to emit to.
       * @param t The type to emit.
       * @return Returns \a o.
       */
      inline std::ostream& operator<<( std::ostream &o, type t ) {
        return o << str( t );
      }

      /**
       * Finds the ISO 639-2 language code enumeration from the given string.
       *
       * @param lang An ISO 639-2 langauge code.
       * @return Returns said enumeration or \c unknown.
       */
      type find( char const *lang );

      //
      // Template version of find().
      //
      template<class StringType> inline
      typename std::enable_if<ZORBA_HAS_C_STR(StringType),type>::type
      find( StringType const &lang ) {
        return find( lang.c_str() );
      }
    } // namespace iso639_2

    /////////////////////////////////////////////////////////////////////////// 

    /**
     * Finds the ISO 639-1 language code enumeration from the given string.
     *
     * @param lang Either an ISO 639-1 or an ISO 639-2 langauge code.
     * @return Returns said enumeration or \c unknown.
     */
    iso639_1::type find_lang( char const *lang );

    //
    // Template version of find_lang().
    //
    template<class StringType> inline
    typename std::enable_if<ZORBA_HAS_C_STR(StringType),iso639_1::type>::type
    find_lang( StringType const &lang ) {
      return find_lang( lang.c_str() );
    }

    /**
     * Gets the date format in the locale specified by the given language and
     * country.  The format is that used by \c strptime(3).
     *
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said date format.
     */
    zstring get_date_format( iso639_1::type lang = iso639_1::unknown,
                             iso3166_1::type country = iso3166_1::unknown );

    /**
     * Gets the date and time format in the locale specified by the given
     * language and country.  The format is that used by \c strptime(3).
     *
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said date format.
     */
    zstring get_date_time_format( iso639_1::type lang = iso639_1::unknown,
                                  iso3166_1::type country = iso3166_1::unknown);

    /**
     * Gets the ISO 3166-1 country code enumeration for the host system.
     *
     * @return Returns said enumeration or \c unknown.
     */
    iso3166_1::type get_host_country();

    /**
     * Gets the ISO 639-1 language code enumeration for the host system.
     *
     * @return Returns said enumeration defaulting to \c en.
     */
    iso639_1::type get_host_lang();

    /**
     * Gets a month's abbreviation in the locale specified by the given
     * language and country.
     *
     * @param month_index The index of the month to get in the range 0-11.
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said abbreviation.
     */
    zstring get_month_abbr( unsigned month_index,
                            iso639_1::type lang = iso639_1::unknown,
                            iso3166_1::type country = iso3166_1::unknown );

    /**
     * Gets a month's full name in the locale specified by the given language
     * and country.
     *
     * @param month_index The index of the month to get in the range 0-11.
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said full name.
     */
    zstring get_month_name( unsigned month_index,
                            iso639_1::type lang = iso639_1::unknown,
                            iso3166_1::type country = iso3166_1::unknown );

    /**
     * Gets the time AM or PM string in the locale specified by the given
     * language and country.
     *
     * @param pm If \c true, gets the PM string; else the AM string.
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said string.
     */
    zstring get_time_ampm( bool pm, iso639_1::type lang = iso639_1::unknown,
                           iso3166_1::type country = iso3166_1::unknown );

    /**
     * Gets the time format in the locale specified by the given language and
     * country.  The format is that used by \c strptime(3).
     *
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said time format.
     */
    zstring get_time_format( iso639_1::type lang = iso639_1::unknown,
                             iso3166_1::type country = iso3166_1::unknown );

    /**
     * Gets a weekday's abbreviation in the locale specified by the given
     * language and country.
     *
     * @param day_index The index of the weekday to get in the range 0-6.
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said abbreviation.
     */
    zstring get_weekday_abbr( unsigned day_index,
                              iso639_1::type lang = iso639_1::unknown,
                              iso3166_1::type country = iso3166_1::unknown );

    /**
     * Gets a weekday's full name in the locale specified by the given language
     * and country.
     *
     * @param day_index The index of the month to get in the range 0-6.
     * @param lang The language to use.  Defaults to host language.
     * @param country The country to use.  Defaults to host country.
     * @return Returns said full name.
     */
    zstring get_weekday_name( unsigned day_index,
                              iso639_1::type lang = iso639_1::unknown,
                              iso3166_1::type country = iso3166_1::unknown );

    /**
     * Checks if the locale specified by the given language and country is
     * supported by the OS.
     *
     * @param lang The language to use.
     * @param country The country to use.  Defaults to none.
     * @return Returns \a true only if the given locale is supported by the OS.
     */
    bool is_supported( iso639_1::type lang,
                       iso3166_1::type country = iso3166_1::unknown );

    /**
     * Parses a locale string.
     *
     * @param locale_str A locale string of the form \c ll{-_}CC[.enc] where
     * \c ll is a 2 letter ISO 639-1 (or 3 letter 639-2) language code, \c CC
     * is a 2 letter ISO 3166-1 country code, and \c enc is an optional
     * encoding (which is ignored).
     * @param lang A pointer to receive the language, if any.
     * @param country A pointer to receive the country, if any.
     * @return Returns \c true if at least a language is parsed.
     */
    bool parse( char const *locale_str, iso639_1::type *lang = nullptr,
                iso3166_1::type *country = nullptr );

    //
    // Template version of parse().
    //
    template<class StringType> inline
    typename std::enable_if<ZORBA_HAS_C_STR(StringType),bool>::type
    parse( StringType const &locale_str, iso639_1::type *lang = nullptr,
           iso3166_1::type *country = nullptr ) {
      return parse( locale_str.c_str(), lang, country );
    }

    ///////////////////////////////////////////////////////////////////////////

  } // namespace locale
} // namespace zorba

#endif  /* ZORBA_CORE_LOCALE_H */
/* vim:set et sw=2 ts=2: */
