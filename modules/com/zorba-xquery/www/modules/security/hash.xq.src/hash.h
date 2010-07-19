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

#ifndef ZORBA_SECURITY_HASH_H
#define ZORBA_SECURITY_HASH_H

#include <map>

#include <zorba/zorba.h>
#include <zorba/external_module.h>
#include <zorba/external_function.h>

namespace zorba { namespace security {
	
	class HashModule : public ExternalModule
	{
    private:
		static ItemFactory* theFactory;
		
    protected:
		class ltstr
		{
        public:
			bool
			operator()(const String& s1, const String& s2) const
			{
				return s1.compare(s2) < 0;
			}
		};
		
		typedef std::map<String, StatelessExternalFunction*, ltstr> FuncMap_t;
		mutable FuncMap_t theFunctions;
		
    public:
		virtual ~HashModule();
		
		virtual String
		getURI() const { return "http://www.zorba-xquery.com/modules/security/hash"; }
		
		virtual StatelessExternalFunction*
		getExternalFunction(String aLocalname) const;
		
		virtual void
		destroy();
		
		static ItemFactory*
		getItemFactory()
		{
			if(!theFactory)
				theFactory = Zorba::getInstance(0)->getItemFactory();
			return theFactory;
		}
		
	};
	
	class HashSHA1Function : public PureStatelessExternalFunction
	{
    protected:
		const HashModule* theModule;
		
		static void
		throwError(
				   const std::string aErrorMessage,
				   const XQUERY_ERROR& aErrorType);
		
    private:
		
    public:
		HashSHA1Function(const HashModule* aModule): theModule(aModule){}
		~HashSHA1Function(){}
		
		virtual String
		getLocalName() const { return "sha1"; }
		
		virtual zorba::ItemSequence_t
		evaluate(const Arguments_t&) const;
		
		virtual String
		getURI() const;
		
	};
} /* namespace security */ } /* namespace zorba */

#endif

