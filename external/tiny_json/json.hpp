// json.hpp (Version 1.0.1)                                           (c)'2007-08 Thomas Jansen (thomas@beef.de)
//
// -------------------------------------------------------------------------------------------------------------
// Copyright 2007-2008, Thomas Jansen. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted provided  that
// the following conditions are met:
//   * Redistributions of source code must retain the above copyright notice, this list of  conditions  and  the
//     following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
//     following disclaimer in the documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT  SHALL
// THOMAS JANSEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  OR  CONSEQUENTIAL  DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  OR  PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  OF  THIS  SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// -------------------------------------------------------------------------------------------------------------

#ifndef	_JSON_HPP_
#define	_JSON_HPP_

#include	<boost/any.hpp>
#include	<boost/spirit/core.hpp>
#include	<boost/spirit/utility/loops.hpp>
#include	<boost/lexical_cast.hpp>

#include	<string>
#include	<stack>
#include	<utility>
#include	<deque>
#include	<map>


namespace json {

	// ---[ TYPEDEFINITIONS ]------------------------------------------------------------------------------------

	typedef	std::stack< boost::any >					stack;						//           a stack of json elements
	typedef	std::pair< std::string, boost::any >	pair;							//       a pair as it appears in json

	typedef	std::deque< boost::any >					array;						//            an array of json values
	typedef	std::map< std::string, boost::any >		object;						//          an object with json pairs


	// ==========================================================================================================
	// ===                                   T H E   J S O N   G R A M M A R                                  ===
	// ==========================================================================================================

	class grammar : public boost::spirit::grammar< grammar > {

	protected:

		// ---[ SEMANTIC ACTION: PUSH A STRING ON THE STACK (AND ENCODE AS UTF-8) ]-------------------------------

		struct push_string {

			stack & m_stack;
			push_string(stack & stack) : m_stack(stack) { }

			void operator() (char const * szStart, char const * szEnd) const
			{
				// 1: skip the quotes...

				++szStart;
				--szEnd;

				// 2: traverse through the original string and check for escape codes..

				std::string strString;

				while(szStart < szEnd) {

					// 2.1: if it's no escape code, just append to the resulting string...

					if(*szStart != '\\') {

						// 2.1.1: append the character...

						strString.push_back(*szStart);
					}
					else {

						// 2.1.2: otherwise, check the escape code...

						++szStart;

						switch(*szStart) {

							default:			strString.push_back(*szStart);		break;
							case 'b':		strString.push_back(    '\b');		break;
							case 'f':		strString.push_back(    '\f');		break;
							case 'n':		strString.push_back(    '\n');		break;
							case 'r':		strString.push_back(    '\r');		break;
							case 't':		strString.push_back(    '\t');		break;
							case 'u':
							{
								// 2.1.2.1: convert the following hex value into an int...

								int iUnicode;
								std::istringstream(std::string(&szStart[1], 4)) >> std::hex >> iUnicode;

								szStart += 4;

								// 2.1.2.2: append the unicode int into utf-8...

								if(iUnicode < 0x0080) {

									// 2.1.2.2.1: character 0x0000 - 0x007f...

									strString.push_back(0x00 | ((iUnicode & 0x007f) >> 0));
								}
								else if(iUnicode < 0x0800) {

									// 2.1.2.2.2: character 0x0080 - 0x07ff...

									strString.push_back(0xc0 | ((iUnicode & 0x07c0) >> 6));
									strString.push_back(0x80 | ((iUnicode & 0x003f) >> 0));
								}
								else {

									// 2.1.2.2.3: character 0x0800 - 0xffff...

									strString.push_back(0xe0 | ((iUnicode & 0x00f000) >> 12));
									strString.push_back(0x80 | ((iUnicode & 0x000fc0) >>  6));
									strString.push_back(0x80 | ((iUnicode & 0x00003f) >>  0));
								}
							}
						}
					}

					// 2.2: go on with the next character...

					++szStart;
				}

				// 3: finally, push the string on the stack...

				m_stack.push(strString);
			}
		};


		// ---[ SEMANTIC ACTION: PUSH A NUMBER (INT OR FLOAT) ON THE STACK ]--------------------------------------

		struct push_number {

			stack & m_stack;
			push_number(stack & stack) : m_stack(stack) { }

			void operator() (char const * szStart, char const * szEnd) const
			{
				// 1: check if the string contains a '.', an 'e' or an 'E', because in that case it's a "frac"...

				std::string strNumber(szStart, szEnd - szStart);

				if(strNumber.find_first_of(".eE") == std::string::npos) {

					// 1.1: it's an integer...

					m_stack.push(boost::lexical_cast< int >(strNumber));
				}
				else {

					// 1.2: it's a floating point...

					m_stack.push(boost::lexical_cast< float >(strNumber));
				}
			}
		};


		// ---[ SEMANTIC ACTION: PUSH A BOOLEAN ON THE STACK ]----------------------------------------------------

		struct push_boolean {

			stack & m_stack;
			push_boolean(stack & stack) : m_stack(stack) { }

			void operator() (char const * szStart, char const * /* szEnd */ ) const
			{
				// 1: push a boolean that is "true" if the string starts with 't' and "false" otherwise...

				m_stack.push((bool) (*szStart == 't'));
			}
		};


		// ---[ SEMANTIC ACTION: PUSH A NULL VALUE ON THE STACK ]-------------------------------------------------

		struct push_null {

			stack & m_stack;
			push_null(stack & stack) : m_stack(stack) { }

			void operator() (char const * szStart, char const * /* szEnd */ ) const
			{
				m_stack.push(boost::any());
			}
		};


		// ---[ SEMANTIC ACTION: CREATE A "JSON PAIR" ON THE STACK ]----------------------------------------------

		struct create_pair {

			stack & m_stack;
			create_pair(stack & stack) : m_stack(stack) { }

			void operator() (char const * /* szStart */, char const * /* szEnd */ ) const
			{
				// 1: get the value from the stack...

				boost::any baValue = m_stack.top();
				m_stack.pop();

				// 2: get the name from the stack...

				std::string strName;

				try {

					strName = boost::any_cast< std::string >(m_stack.top());
				}
				catch(boost::bad_any_cast &) { /* NOTHING */ }

				m_stack.pop();

				// 3: push a pair of both on the stack...

				m_stack.push(pair(strName, baValue));
			}
		};


		// ---[ SEMANTIC ACTION: BEGIN AN ARRAY ]-----------------------------------------------------------------

		class	array_delimiter { /* EMPTY CLASS */ };

		struct begin_array {

			stack & m_stack;
			begin_array(stack & stack) : m_stack(stack) { }

			void operator() (char /* cCharacter */) const
			{
				m_stack.push( array_delimiter() );
			}
		};


		// ---[ SEMANTIC ACTION: CREATE AN ARRAY FROM THE VALUES ON THE STACK ]-----------------------------------

		struct end_array {

			stack & m_stack;
			end_array(stack & stack) : m_stack(stack) { }

			// - -[ functional operator ] - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			void operator() (char /* cCharacter */) const
			{
				// 1: create an array object and push everything in it, that's on the stack...

				array arr;

				while(!m_stack.empty()) {

					// 1.1: get the top most value of the stack...

					boost::any variant = m_stack.top();
					m_stack.pop();

					// 1.2: is it the end of the array? if yes => break the loop...

					if(boost::any_cast< array_delimiter >(&variant) != NULL) {

						break;
					}

					// 1.3: otherwise, add to the array...

					arr.push_front(variant);
				}

				// 2: finally, push the array at the end of the stack...

				m_stack.push(arr);
			}
		};


		// ---[ SEMANTIC ACTION: BEGIN AN OBJECT ]----------------------------------------------------------------

		class	object_delimiter { /* EMPTY CLASS */ };

		struct begin_object {

			stack & m_stack;
			begin_object(stack & stack) : m_stack(stack) { }

			void operator() (char /* cCharacter */) const
			{
				m_stack.push( object_delimiter() );
			}
		};


		// ---[ SEMANTIC ACTION: CREATE AN OBJECT FROM THE VALUES ON THE STACK ]----------------------------------

		struct end_object {

			stack & m_stack;
			end_object(stack & stack) : m_stack(stack) { }

			void operator() (char /* cCharacter */) const
			{
				// 1: create an array object and push everything in it, that's on the stack...

				object obj;

				while(!m_stack.empty()) {

					// 1.1: get the top most value of the stack...

					boost::any variant = m_stack.top();
					m_stack.pop();

					// 1.2: is it the end of the array? if yes => break the loop...
					
					if(boost::any_cast< object_delimiter >(&variant) != NULL) {

						break;
					}

					// 1.3: if this is not a pair, we have a problem...

					pair * pPair = boost::any_cast< pair >(&variant);
					if(!pPair) {

						/* BIG PROBLEM!! */

						continue;
					}

					// 1.4: set the child of this object...

					obj[pPair->first] = pPair->second;
				}

				// 2: finally, push the array at the end of the stack...

				m_stack.push(obj);
			}
		};

	public:

		stack & m_stack;
		grammar(stack & stack) : m_stack(stack) { }

		// ---[ THE ACTUAL GRAMMAR DEFINITION ]-------------------------------------------------------------------

		template <typename SCANNER>
		class definition {

			boost::spirit::rule< SCANNER > m_object;

			boost::spirit::rule< SCANNER > m_array;
			boost::spirit::rule< SCANNER > m_pair;
			boost::spirit::rule< SCANNER > m_value;
			boost::spirit::rule< SCANNER > m_string;
			boost::spirit::rule< SCANNER > m_number;
			boost::spirit::rule< SCANNER > m_boolean;
			boost::spirit::rule< SCANNER > m_null;

		public:

			boost::spirit::rule< SCANNER > const & start() const { return m_object; }

			// - -[ create the definition ] - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

			definition(grammar const & self)
			{
				using namespace boost::spirit;

				// 1: an object is an unordered set of pairs (seperated by commas)...

				m_object
					= ch_p('{') [ begin_object(self.m_stack) ] >>
					  !(m_pair >> *(ch_p(',') >> m_pair)) >>
					  ch_p('}') [ end_object  (self.m_stack) ];

				// 2: an array is an ordered collection of values (seperated by commas)...

				m_array
					= ch_p('[')	[ begin_array(self.m_stack) ] >>
					  !(m_value >> *(ch_p(',') >> m_value)) >>
					  ch_p(']')	[ end_array  (self.m_stack) ];

				// 3: a pair is given by a name and a value...

				m_pair
					= ( m_string >> ch_p(':') >> m_value )
					  [ create_pair(self.m_stack) ]
					;

				// 4: a value can be a string in double quotes, a number, a boolean, an object or an array.

				m_value
					= m_string
					| m_number
					| m_object
					| m_array
					| m_boolean
					| m_null
					;

				// 5: a string is a collection of zero or more unicode characters, wrapped in double quotes...

				m_string
					= lexeme_d
						[
							( ch_p('"') >> *(
								( (anychar_p - (ch_p('"') | ch_p('\\')))
								| ch_p('\\') >>
									( ch_p('\"')
									| ch_p('\\')
									| ch_p('/')
									| ch_p('b')
									| ch_p('f')
									| ch_p('n')
									| ch_p('r')
									| ch_p('t')
									| (ch_p('u') >> repeat_p(4)[ xdigit_p ])
									)
								)) >> ch_p('"') 
							)
							[ push_string(self.m_stack) ]
						]
					;

				// 6: a number is very much like a C or java number...

				m_number
					= lexeme_d
						[
							( !ch_p('-') >> ('0' | (digit_p - '0') >> *digit_p)
											 >> !(ch_p('.') >> +digit_p)
											 >> !((ch_p('e') | ch_p('E')) >> !(ch_p('+') | ch_p('-')) >> +digit_p)
							)
							[ push_number(self.m_stack) ]
						]
					;

				// 7: a boolean can be "true" or "false"...

				m_boolean
					= ( str_p("true")
					  | str_p("false")
					  )
					  [ push_boolean(self.m_stack) ]
					;

				// 8: finally, a value also can be a 'null', i.e. an empty item...

				m_null
					= str_p("null")
					  [ push_null(self.m_stack) ]
					;
			}
		};
	};


	// ==========================================================================================================
	// ===                          T H E   F I N A L   P A R S I N G   R O U T I N E                         ===
	// ==========================================================================================================

	boost::any parse(char const * szFirst, char const * szEnd);
};


#endif	// _JSON_HPP_
