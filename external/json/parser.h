#pragma once

#include <vector>
#include <cstring>
#include "value.h"

namespace json{
	
	void UNI_NG_SEARCH_REPLACE(std::wstring &srcstr,wchar_t *search, wchar_t *replace);
	namespace tt{
		enum tokens{
			_name,
			_unquoted,
			_object,
			_array,
			_comment,
			_string,
			_literal
		};
	}

	struct error{
		size_t row;
		size_t column;
		unsigned _errno;
	};
	
	extern const wchar_t *errstrings[8];

	struct inputdata{
			size_t col;
			size_t row;
			bool eof;
			const void *data;
			const void *buffer;
			const void *cursor;	
			size_t length;
			wchar_t (*next)(inputdata *);
			wchar_t (*prev)(inputdata *,int n);
	};

	class parser{
	private:
		int abortlevel;
		
		// Behaviour flags
		inputdata si;
		bool isescaped;

		wchar_t cursor;
		wchar_t curchar;

		datatype::dt findval();
		value *readvalue();

		void readnumber(value *val);
		void readstring(value *val);
		void readlit(value *val);
		void readarray(value *val);
		void readobject(value *val);

		std::wstring *readname();

		inline void next();
		inline void rewind(int n=1);
		void getnextchar(bool,bool,bool,bool nonext=false);

		inline int readhexquadaswchar();
		wchar_t escapechar();
		bool eatcomment();
		void adderror(int no);
		
	public:
		bool allow_unquoted_names;
		bool strictjson;
		int fail();
		std::wstring *printerrors();
		std::vector<error> errors;
		parser(void);
		
		value *parse(const wchar_t *ins,size_t length);
		value *parse(const char *ins,size_t length);
		value *parse(const char *ins);
		value *parse(std::istream &stream);
		value *parse(std::wistream &stream);
		~parser(void);
		
	private:

	};


}

