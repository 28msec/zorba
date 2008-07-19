#include "value.h"

using namespace json;

namespace json{
	
	/* IMPORTED & MANGLED FROM WINUNI.H. */
	void UNI_NG_SEARCH_REPLACE(std::wstring &srcstr,wchar_t *search, wchar_t *replace){
		size_t searchlen=wcslen(search);
		size_t replacelen=wcslen(replace);
		size_t fnd=0;
		size_t schstart=0;
		while((fnd=srcstr.find(search,schstart))!=std::wstring::npos){
			srcstr.replace(fnd,searchlen,replace);
			schstart=fnd+replacelen;
		}
	}

	void quotestring(std::wstring *thestr){
		UNI_NG_SEARCH_REPLACE((*thestr),L"\\",L"\\\\");
		UNI_NG_SEARCH_REPLACE((*thestr),L"\"",L"\\\"");
		UNI_NG_SEARCH_REPLACE((*thestr),L"\n",L"\\n");
		UNI_NG_SEARCH_REPLACE((*thestr),L"\r",L"\\r");
		std::wstring tmpstr=(*thestr);
		(*thestr)=L"\"";
		(*thestr)+=tmpstr;
		(*thestr)+=L"\"";
	}

	void arraygetstring(std::wstring *thestr,array_list_t *theval,bool enquote=false,bool separate=false){
		(*thestr)+=L" [ ";
		array_list_t::iterator theiter;
		bool started=false;
		for (theiter=theval->begin();theiter!=theval->end();++theiter){
			if (started){ 
				(*thestr)+=L" , ";
				if (separate) (*thestr)+=L"\n";
			}else started=true;
			std::wstring *stra=(*theiter)->getstring(L"",enquote);
			(*thestr)+=(*stra);
				delete stra;
		}
		(*thestr)+=L" ] ";
	}
	void objectgetstring(std::wstring *thestr,object_list_t *theval,bool enquote=false,bool separate=false){
		(*thestr)+=L" { ";
		object_list_t::iterator theiter;
		bool started=false;
		for (theiter=theval->begin();theiter!=theval->end();++theiter){
			if (started){
				(*thestr)+=L" , ";
				if (separate) (*thestr)+=L"\n";
			}else started=true;
			std::wstring namestr=(*theiter).first;
			quotestring(&namestr);
			(*thestr)+=namestr;
			(*thestr)+=L" : ";
			std::wstring *stra=(*theiter).second->getstring(L"",enquote);
			(*thestr)+=(*stra);
				delete stra;
		}
		
		(*thestr)+=L" } ";
	}
	bool wstrCmp::operator()( const wchar_t* s1, const wchar_t* s2 ) const {
      return wcscmp( s1, s2 ) < 0;
	}

}




value::value():val(NULL),dt(datatype::_undefined),separatevalues(false)
{
}

value::value(wchar_t *nval):separatevalues(false){
	setstring(nval);
}

value::value(int nval):separatevalues(false){
	setnumber(nval);
}
value::value(float nval):separatevalues(false){
	setnumber(nval);
}
value::value(double nval):separatevalues(false){
	setnumber(nval);
}
value::value(long nval):separatevalues(false){
	setnumber((__int64)nval);
}
value::value(char *nval):separatevalues(false){
	setstring(nval);
}
value::value(std::wstring &nval):separatevalues(false){
	setstring(nval);
}
value::value(datatype::dt nval):separatevalues(false){
		switch(nval){
		case datatype::_unquoted_string:
		case datatype::_string:
			setstring("");
		break;
		case datatype::_number:
			setnumber((double)0);
		break;
		case datatype::_fixed_number:
			setnumber((__int64)0);
		break;
		case datatype::_literal:
			setliteral(literals::_null);
		break;
		case datatype::_array:
			setarray();
		break;
		case datatype::_object:
			setobject();
		break;
		case datatype::_undefined:
		default:	
			dt=datatype::_undefined;
		break; 
	}
}

/*value::value(value &oldv){
	d*/

value::~value(void)
{
	deletevalue();
}


/*bool value::setname(std::wstring &newname){
	name=newname;
	return true;
}

bool value::setname(wchar_t *newname){
	name=newname;
	return true;
}

std::wstring &value::getname(){
	return name;
}*/

bool value::clear(){
	array_list_t::iterator valaiter;
	object_list_t::iterator valoiter;
	switch(dt){
		case datatype::_unquoted_string:
		case datatype::_string:
			((std::wstring *)val)->assign(L"");
			break;
		case datatype::_number:
			(*(double *)val)=0;
			break;
		case datatype::_fixed_number:
			(*(__int64 *)val)=0;
			break;
		case datatype::_literal:
			(*(literals::literals *)val)=literals::_null;
			break;
		case datatype::_array:
			for (valaiter=((array_list_t *)val)->begin();valaiter!=((array_list_t *)val)->end();++valaiter){
				(*valaiter)->deletevalue();
			}
			((array_list_t *)val)->clear();
			break;
		case datatype::_object:
			for (valoiter=((object_list_t *)val)->begin();valoiter!=((object_list_t *)val)->end();++valoiter){
				delete [] (*valoiter).first;
				(*valoiter).second->deletevalue();
			}
			((object_list_t *)val)->clear();
			break;
		case datatype::_undefined:
		default:	
			return false;
	}
	return true;
}

bool value::deletevalue(){
	if (val==NULL) return true;

	switch(dt){
		case datatype::_unquoted_string:
		case datatype::_string:
			delete (std::wstring *)val;
		break;
		case datatype::_number:
			delete (double *)val;
		break;
		case datatype::_fixed_number:
			delete (__int64 *)val;
		break;
		case datatype::_literal:
			delete (literals::literals *)val;
		break;
		case datatype::_array:
			clear();
			delete (array_list_t *)val;
		break;
		case datatype::_object:
			clear();
			delete (object_list_t *)val;
			/*TODO::*///delete object data
		case datatype::_undefined:

		break;
		default:
			return false;
	}
	dt=datatype::_undefined;
	val=NULL;
	return true;
}


//Data Set Functions
bool value::setstring(const wchar_t *newval){
	if (val) deletevalue();
	dt=datatype::_string;
	val=(void *)new std::wstring;
	(*(std::wstring *)val)=newval;
	return true;
}

bool value::setstring(const char *nval){
	if (val) deletevalue();
	dt=datatype::_string;
	wchar_t *newval=new wchar_t[strlen(nval)+1];
	astr2wstr(newval,nval,strlen(nval)+1);

	val=(void *)new std::wstring;
	(*(std::wstring *)val)=newval;
	delete newval;
	return true;
}


bool value::setstring(std::wstring &newval){
	if (val) deletevalue();
	dt=datatype::_string;
	val=(void *)new std::wstring;
	(*(std::wstring *)val)=newval;
	return true;
}

bool value::setnumber(__int64 newval){
	if (val) deletevalue();
	dt=datatype::_fixed_number;
	val=(void *)new __int64;
	(*(__int64 *)val)=newval;
	return true;
}
bool value::setnumber(int newval){
	if (val) deletevalue();
	dt=datatype::_fixed_number;
	val=(void *)new __int64;
	(*(__int64 *)val)=newval;
	return true;
}

bool value::setnumber(double newval){
	if (val) deletevalue();
	dt=datatype::_number;
	val=(void *)new double;
	(*(double *)val)=newval;
	return true;
}

bool value::setliteral(literals::literals newval){
	if (val) deletevalue();
	dt=datatype::_literal;
	val=(void *)new literals::literals;
	(*(literals::literals *)val)=newval;
	return true;
}

bool value::setliteral(bool newval){
	if (val) deletevalue();
	dt=datatype::_literal;
	val=(void *)new literals::literals;
	if (newval==true) (*(literals::literals *)val)=literals::_true;
	else if (newval==false) (*(literals::literals *)val)=literals::_false;
	else (*(literals::literals *)val)=literals::_null;
	return true;
}

bool value::setarray(){
	if (val) deletevalue();
	dt=datatype::_array;
	val=(void *)new array_list_t;
	return true;
}

bool value::setobject(){
	if (val) deletevalue();
	dt=datatype::_object;
	val=(void *)new object_list_t;
	return true;
}

bool value::clone(value &oldval){
	array_list_t::iterator valaiter;
	object_list_t::iterator valoiter;
	switch(oldval.dt){
		case datatype::_unquoted_string:
		case datatype::_string:
			setstring((*(std::wstring*)oldval.val));
			break;
		case datatype::_number:
			setnumber((*(double *)oldval.val));
			break;
		case datatype::_fixed_number:
			setnumber((*(__int64 *)oldval.val));
			break;
		case datatype::_literal:
			setliteral((*(literals::literals*)oldval.val));
			break;
		case datatype::_array:
			setarray();
			for (valaiter=((array_list_t*)oldval.val)->begin();valaiter!=((array_list_t*)oldval.val)->end();++valaiter){
				addarrayvalue((*(*valaiter)));
			}
			break;
		case datatype::_object:
			setobject();
			for (valoiter=((object_list_t*)oldval.val)->begin();valoiter!=((object_list_t*)oldval.val)->end();++valoiter){
				addobjectvalue((*valoiter).first,(*(*valoiter).second));
			}
			break;
		case datatype::_undefined:
		default:	
			return false;
	}
	return true;
	
}

bool value::addarrayvalue(value &oldval){
	if (dt!=datatype::_array) return false;
	value *newval=new value;
	newval->clone(oldval);
	((array_list_t *)val)->push_back(newval);
	return true;		
}

bool value::addarrayvalue(value *newval){
	if (dt!=datatype::_array) return false;
	((array_list_t *)val)->push_back(newval);
	return true;		
}

bool value::addobjectvalue(const std::wstring &oldname,value &oldval){
	if (dt!=datatype::_object) return false;
	if (((object_list_t *)val)->find((wchar_t * const)oldname.c_str())==((object_list_t *)val)->end()){
		value *newval=new value;
		wchar_t *newname =new wchar_t[oldname.length()+1];
		wcscpy(newname,oldname.c_str());
		newval->clone(oldval);

		((object_list_t *)val)->insert(std::pair<wchar_t *,value*>(newname,newval));
		return true;		
	}else{
		return false;
	}
}

bool value::addobjectvalue(const std::wstring &oldname,value *newval){
	if (dt!=datatype::_object) return false;
	object_list_t::iterator tmp;
	tmp=((object_list_t *)val)->find((wchar_t * const)oldname.c_str());
	if (tmp==((object_list_t *)val)->end()){
		wchar_t *newname =new wchar_t[oldname.length()+1];
		wcscpy(newname,oldname.c_str());
 		((object_list_t *)val)->insert(std::pair<wchar_t *,value*>(newname,newval));
		return true;		
	}else{
		return false;
	}
}

bool value::addobjectvalue(const wchar_t *oldname,value &oldval){
	if (dt!=datatype::_object) return false;
	if (((object_list_t *)val)->find((wchar_t *const)oldname)==((object_list_t *)val)->end()){
		value *newval=new value;
		wchar_t *newname =new wchar_t[wcslen(oldname)+1];
		wcscpy(newname,oldname);
		newval->clone(oldval);

		((object_list_t *)val)->insert(std::pair<wchar_t *,value*>(newname,newval));
		return true;		
	}else{
		return false;
	}
}

bool value::addobjectvalue(const wchar_t *oldname,value *newval){
	if (dt!=datatype::_object) return false;
	if (((object_list_t *)val)->find((wchar_t *const)oldname)==((object_list_t *)val)->end()){
		wchar_t *newname =new wchar_t[wcslen(oldname)+1];
		wcscpy(newname,oldname);
 		((object_list_t *)val)->insert(std::pair<wchar_t *,value*>(newname,newval));
		return true;		
	}else{
		return false;
	}
}

//Data Access Functions
std::wstring *value::getstring( const wchar_t *_default,bool enquote){
	std::wstring *retval=new std::wstring;
	wchar_t strnum[32];
	switch(dt){
		case datatype::_unquoted_string:
		case datatype::_string:
			(*retval)=(*(std::wstring *)val);
			if (enquote)quotestring(retval);
			break;
		case datatype::_fixed_number:
			swprintf(strnum,31,L"%.1lld",(*(__int64 *)val));
			(*retval)=strnum;
			break;
		case datatype::_number:
			swprintf(strnum,31,L"%lG",(*(double *)val));
			(*retval)=strnum;
			break;
		case datatype::_literal:
			switch(*(literals::literals *)val){
				case literals::_false:(*retval)=L"false";break;
				case literals::_true:(*retval)=L"true";break;
				case literals::_null:(*retval)=L"null";break;
				default: (*retval)=_default;
			}
			break;
		case datatype::_array:
			arraygetstring(retval,(array_list_t *)this->val,enquote,separatevalues);
			break;
		case datatype::_object:
			objectgetstring(retval,(object_list_t *)this->val,enquote,separatevalues);
			break;
		case datatype::_undefined:
		default:	
			(*retval)=_default;
	}
	return retval;
}

array_list_t *value::getarraylist(){
	if (dt!=datatype::_array) return 0;
	return (array_list_t*)val;
}

object_list_t *value::getobjectlist(){
	if (dt!=datatype::_object) return 0;
	return (object_list_t*)val;
}

__int64 value::getinteger( __int64 _default){
	switch(dt){
		case datatype::_unquoted_string:
		case datatype::_string:
			return _default;
		case datatype::_number:
			return (__int64)(*(double*)val);
		case datatype::_fixed_number:
			return (__int64)(*(__int64*)val);
		case datatype::_literal:
			switch(*(literals::literals *)val){
			case literals::_true:	return 1;
			case literals::_false:	
			case literals::_null:	return 0;
			default: return _default;
			}
		case datatype::_array:
		case datatype::_object:
		case datatype::_undefined:
		default:	return _default;
	}
}



double value::getfloat( double _default){
	switch(dt){
		case datatype::_unquoted_string:
		case datatype::_string:
			return _default;
		case datatype::_number:
			return (double)(*(double*)val);
		case datatype::_fixed_number:
			return (double)(*(__int64*)val);
		case datatype::_literal:
		case datatype::_array:
		case datatype::_object:
		case datatype::_undefined:
		default:	return _default;
	}
}

std::wstring *value::getrawstring(){
	if (dt!=datatype::_string){	return 0;}
	return ((std::wstring*)val);
}

value *value::operator[](const wchar_t *name){
	if (dt!=datatype::_object){	return 0;}
	object_list_t::iterator dstval=((object_list_t *)val)->find((wchar_t *const)name);
	if (dstval==((object_list_t *)val)->end()){
		value *nval=new value;
		addobjectvalue(name,nval);
		return nval;
	}else{
		return (*dstval).second;
	}
}

value *value::operator[](const char *name){
	if (dt!=datatype::_object){	return 0;}
	wchar_t *wname=new wchar_t[strlen(name)+1];
	astr2wstr(wname,name,strlen(name)+1);
	object_list_t::iterator dstval=((object_list_t *)val)->find((wchar_t *const)wname);
	if (dstval==((object_list_t *)val)->end()){
		value *nval=new value;
		addobjectvalue(wname,nval);
		delete [] wname;
		return nval;
	}else{
		delete [] wname;
		return (*dstval).second;
	}
}


//Overloaded assignment operators
value & value::operator=(int nv){
	setnumber(nv);
	return *this;
}

value & value::operator=(long nv){
	setnumber((__int64)nv);
	return *this;
}
value & value::operator=(float nv){
	setnumber(nv);
	return *this;
}
value & value::operator=(double nv){
	setnumber(nv);
	return *this;
}
value & value::operator=(const char *nv){
	setstring(nv);
	return *this;
}
value & value::operator=(const wchar_t*nv){
	setstring(nv);
	return *this;
}
value & value::operator=(std::wstring& nv){
	setstring(nv);
	return *this;
}


datatype::dt value::getdatatype(){
	return dt;
}

bool value::deletechildbyname(const wchar_t *name){
	if (dt!=datatype::_object) return false;
	object_list_t::iterator dstval=((object_list_t *)val)->find((wchar_t *const)name);
	if (dstval==((object_list_t *)val)->end()){
		return false;
	}else{
		delete (*dstval).second;
		((object_list_t *)val)->erase(dstval);
		return true;
	}
}



//The global parent
value value::global_object;



/*
switch(dt){
		case datatype::_unquoted_string:
		case datatype::_string:
		case datatype::_number:
		case datatype::_fixed_number:
		case datatype::_literal:
		case datatype::_array:
		case datatype::_object:
		case datatype::_undefined:
		default:	
	}
*/

