	#pragma once
#include <list>
#include <istream>
#include <map>
#include <string>

namespace json{
	
	#ifndef WIN32
	typedef long long __int64;
	#endif
	
	class value;
	struct wstrCmp {
	    bool operator()( const wchar_t* s1, const wchar_t* s2 ) const;
	};	
	size_t astr2wstr(wchar_t *dst,const char *src,size_t n);

	typedef std::list<value*> array_list_t;
	typedef std::map<wchar_t *,value*,wstrCmp> object_list_t;

	namespace literals{
		enum literals{
			_true,
			_false,
			_null
		};
	}

	namespace datatype{
		enum dt{
			_undefined,
			_string,
			_unquoted_string,
			_literal,

			_number,
			_fixed_number,
	
			_array,
			_object
		};
	}

	class value{
	public:
		static value global_object;
	private:
		value *parent;
		/*std::wstring name;*/
		datatype::dt dt;
		void *val;
	public:
		bool separatevalues;
		/*bool setname(std::wstring &newname);
		bool setname(wchar_t *newname);
		std::wstring &getname();*/

		datatype::dt getdatatype();
		bool setstring(const wchar_t *newval);
		bool setstring(std::wstring &newval);
		bool setstring(const char *nval);
		bool setnumber(__int64 newval);
		bool setnumber(int newval);
		bool setnumber(double newval);

		bool setliteral(literals::literals newval);
		bool setliteral(bool newval);
		bool setarray();
		bool setobject();

		value & operator=(int);
		value & operator=(long);
		value & operator=(float);
		value & operator=(double);
		value & operator=(const char *);
		value & operator=(const wchar_t*);
		value & operator=(std::wstring&);


		bool addarrayvalue(value &newval);
		bool addarrayvalue(value *newval);
		bool addobjectvalue(const std::wstring &newname,value &newval);
		bool addobjectvalue(const std::wstring &newname,value *newval);
		bool addobjectvalue(const wchar_t *newname,value &newval);
		bool addobjectvalue(const wchar_t *newname,value *newval);
		bool deletechild(value *val);	
		bool deletechildbyname(const wchar_t *name);
		bool clear();

		__int64 getinteger( __int64 _default=0);
		double getfloat(const double _default=0);
		std::wstring *getrawstring();
		std::wstring *getstring(const wchar_t *_default=L"",bool enquote=false);

		value *operator[](const wchar_t *name);
		value *operator[](const char *name);

		array_list_t *getarraylist();
		object_list_t *getobjectlist();

		bool deletevalue();
		
		bool clone(value &oldval);

		value();
		value(wchar_t *nval);
		value(int nval);
		value(float nval);
		value(double nval);
		value(long nval);
		value(char *nval);
		value(std::wstring &nval);
		value(datatype::dt);
		~value(void);
	};

}
	

