#include "parser.h"

using namespace json;

#ifndef WIN32
		#include "itow.h"
		#define _wtoi64(x) wcstoll(x,NULL,10)
		#define _wtof(x) wcstod((x),NULL)
#endif

namespace json{
	
	//Whitespace = \u0009 \u000B \u000C \u0020 \u00A0 (Other Unicode cat Zs char)
	//EOL = \u000A \u000D \u2028 \u2029
	inline bool charIsWS(wchar_t test){
		static const wchar_t WS[21]={0x0009,0x000B,0x000C,0x0020,0x00A0,0x1680,0x180E,0x2000,0x2001,0x2002,0x2003,0x2004,0x2005,0x2006,0x2007,0x2008,0x2009,0x200A,0x202F,0x205F,0x3000};
		for (int i=0;i<21;++i){
			if (test==WS[i]){ return true; }
		}
		return false;
	}
	
	inline wchar_t ansiitouni(char in){
		static const wchar_t table[256]={0x0001,0x0002,0x0003,0x0004,0x0005,0x0006,0x0007,0x0008,0x0009,0x000A,0x000B,0x000C,0x000D,0x000E,0x000F,0x0010,0x0011,0x0012,0x0013,0x0014,0x0015,0x0016,0x0017,0x0018,0x0019,0x001A,0x001B,0x001C,0x001D,0x001E,0x001F,0x0020,0x0021,0x0022,0x0023,0x0024,0x0025,0x0026,0x0027,0x0028,0x0029,0x002A,0x002B,0x002C,0x002D,0x002E,0x002F,0x0030,0x0031,0x0032,0x0033,0x0034,0x0035,0x0036,0x0037,0x0038,0x0039,0x003A,0x003B,0x003C,0x003D,0x003E,0x003F,0x0040,0x0041,0x0042,0x0043,0x0044,0x0045,0x0046,0x0047,0x0048,0x0049,0x004A,0x004B,0x004C,0x004D,0x004E,0x004F,0x0050,0x0051,0x0052,0x0053,0x0054,0x0055,0x0056,0x0057,0x0058,0x0059,0x005A,0x005B,0x005C,0x005D,0x005E,0x005F,0x0060,0x0061,0x0062,0x0063,0x0064,0x0065,0x0066,0x0067,0x0068,0x0069,0x006A,0x006B,0x006C,0x006D,0x006E,0x006F,0x0070,0x0071,0x0072,0x0073,0x0074,0x0075,0x0076,0x0077,0x0078,0x0079,0x007A,0x007B,0x007C,0x007D,0x007E,0x007F,0x20AC,0x0081,0x201A,0x0192,0x201E,0x2026,0x2020,0x2021,0x02C6,0x2030,0x0160,0x2039,0x0152,0x008D,0x017D,0x008F,0x0090,0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,0x02DC,0x2122,0x0161,0x203A,0x0153,0x009D,0x017E,0x0178,0x00A0,0x00A1,0x00A2,0x00A3,0x00A4,0x00A5,0x00A6,0x00A7,0x00A8,0x00A9,0x00AA,0x00AB,0x00AC,0x00AD,0x00AE,0x00AF,0x00B0,0x00B1,0x00B2,0x00B3,0x00B4,0x00B5,0x00B6,0x00B7,0x00B8,0x00B9,0x00BA,0x00BB,0x00BC,0x00BD,0x00BE,0x00BF,0x00C0,0x00C1,0x00C2,0x00C3,0x00C4,0x00C5,0x00C6,0x00C7,0x00C8,0x00C9,0x00CA,0x00CB,0x00CC,0x00CD,0x00CE,0x00CF,0x00D0,0x00D1,0x00D2,0x00D3,0x00D4,0x00D5,0x00D6,0x00D7,0x00D8,0x00D9,0x00DA,0x00DB,0x00DC,0x00DD,0x00DE,0x00DF,0x00E0,0x00E1,0x00E2,0x00E3,0x00E4,0x00E5,0x00E6,0x00E7,0x00E8,0x00E9,0x00EA,0x00EB,0x00EC,0x00ED,0x00EE,0x00EF,0x00F0,0x00F1,0x00F2,0x00F3,0x00F4,0x00F5,0x00F6,0x00F7,0x00F8,0x00F9,0x00FA,0x00FB,0x00FC,0x00FD,0x00FE,0x00FF};
		return table[in-1];
	}

	size_t astr2wstr(wchar_t *dst,const char *src,size_t n){
		size_t slen=strlen(src);
		if (n<(slen+1)){
			slen=(n-1);
		}
		size_t i=0;
		for (i=0;i<slen;++i){
			dst[i]=ansiitouni(src[i]);
		}
		dst[i]=L'\0';
		return i;
	}

	inline bool charIsEOL(wchar_t test){
		if (test==0x000A) return true;
		if (test==0x000D) return true;
		if (test==0x2028) return true;
		if (test==0x2029) return true;
		return false;
	}

	inline bool charInNumber(wchar_t test){
		if (test>=L'0' && test<=L'9'){ return true; }
		if (test==L'-' || test==L'+') return true;
		if (test==L'.') return true;
		if (test==L'e') return true;
		if (test==L'E') return true;
		return false;
	}
	inline bool charStartsNumber(wchar_t test){
		if (test>=L'0' && test<=L'9'){ return true; }
		if (test==L'-') return true;
		return false;
	}

	int hextoint(wchar_t hexchar){
		if ((hexchar >= L'0' && hexchar <= L'9')){
			return hexchar-L'0';
		}
		if (hexchar >= L'a' && hexchar <= L'f'){
			return 10+(hexchar-L'a');
		}
		if (hexchar >= L'A' && hexchar <= L'F'){
			return 10+(hexchar-L'A');
		}
		return -1;
	}
}

parser::parser(void) {
	cursor=0;
	allow_unquoted_names=true;
	strictjson=false;
}

parser::~parser(void){

}

void parser::adderror(int no){
	error tmperr;
	tmperr._errno=no;
	tmperr.column=si.col;
	tmperr.row=si.row;
	errors.push_back(tmperr);
}

int parser::fail(){
	return (int)errors.size();
}

std::wstring * parser::printerrors(){
	std::vector<error>::iterator iter;
	std::wstring *errstr=new std::wstring;
	wchar_t lnum[50];
	if (errors.size()==0){	return errstr;	}
	for (iter=errors.begin();iter!=errors.end();++iter){
		if (iter!=errors.begin())(*errstr)+=L"\n";
		std::wstring tmperr=errstrings[(*iter)._errno];
		tmperr+=L" on line ";
		_itow((int)(*iter).row,lnum,10);
		tmperr+=lnum;
		tmperr+=L", column ";
		_itow((int)(*iter).column,lnum,10);
		tmperr+=lnum;
		tmperr+=L".";
		(*errstr)+=tmperr;
	}
	return errstr;
}

#include "readers.h"

void parser::next(){
	if (si.eof){
		adderror(1);
		return;
	}
	cursor=si.next(&si);
}

void parser::rewind(int n){
	cursor=si.prev(&si,n);
}	


bool parser::eatcomment(){
	if (cursor!=L'/') return false;
	next();
	switch (cursor){
		case L'/':
			while (!charIsEOL(cursor)){
				next();  //Eat up to the newline
			}
			while (charIsEOL(cursor))next();  //And eat that too.
			return true;  //Tell us that we're full
		break;
		case L'*':
			while ((cursor)!=L'/'){  //Wait for ending /
				while ((cursor)!=L'*')next(); //only when preceeded by a *
				if ((cursor)==0){ return false; }
				next();
			}
			next(); //the eat the trailing /
			return true;
		break;
		default:
			rewind();
			return false;
	}
	return false;
}

int parser::readhexquadaswchar(){  //returns -1 on fail.
	int a=hextoint(cursor);
	if (a<0) return -1;
	next();
	int b=hextoint(cursor);
	if (b<0){ rewind(); return -1;}
	next();
	int c=hextoint(cursor);
	if (c<0){ rewind(2); return -1;}
	next();
	int d=hextoint(cursor);
	if (d<0){ rewind(3); return -1;}
	return (d+(c<<4)+(b<<8)+(a<<12));
}

wchar_t parser::escapechar(){
	if (cursor!=L'\\') return 0;
	next();
	int ec=-1;
	switch(cursor){
		case L'\\':	ec=L'\\';	break;
		case L'/':	ec=L'/';	break;
		case L'"':	ec=L'"';	break;
		case L'b':	ec=0x0008;	break;
		case L't':	ec=0x0009;	break;
		case L'n':	ec=0x000A;	break;	
		case L'v':	if (strictjson==false)ec=0x000B;	break;	
		case L'f':	ec=0x000C;	break;	
		case L'r':	ec=0x000D;	break;	
		case L'u':
			next();
			ec=readhexquadaswchar();
			if (ec==-1){
				adderror(0);
				rewind(2);
				ec=L'\\';
			}
		break;
	}
	if (ec>-1){
		//next();  //Skip over the escaped char so when we resume, we'll read the next bit
		return ec;
	}
	rewind(); //Not an escaped sequence, so rewind to allow reading.
	return 0;
}

void parser::getnextchar(bool skipWS, bool doBS,bool doC,bool nonext){
	if (!nonext)next();
	isescaped=false;
	bool again=true;
	while (again){
		again=false;  //Assume we won't meet resistance
		if (skipWS && (charIsWS(cursor) || charIsEOL(cursor))){next(); again=true; continue;}
		if (doC && eatcomment()){ again=true; continue;}
		if (doBS && cursor==L'\\'){wchar_t ech=escapechar(); if (ech!=0){isescaped=true; curchar=ech; return;}}
	}
	curchar=cursor;
}



datatype::dt parser::findval(){	
	getnextchar(true,false,true);
	if (isescaped) return datatype::_undefined;//No datatypes should start with escaped chars.
	switch(curchar){
	case L'{':
		return datatype::_object;
	case L'[':	
		return datatype::_array;
	case L'"':
		return datatype::_string;
	case L',':
	case L':':
		return datatype::_undefined;
	}
	if (charStartsNumber(curchar)) return datatype::_number;
	if (curchar==L't' || curchar==L'f' || curchar==L'n') return datatype::_literal;
	return datatype::_undefined;
}
void parser::readnumber(value *val){
	//This is a bit of a hack, but it works
	std::wstring number;
	bool isint=true;
	while (charInNumber(curchar)){
		if (curchar==L'.' || curchar==L'e' || curchar==L'E'){
			isint=false;
		}
		number+=curchar;
		getnextchar(false,true,false);
	}
	if (isint==false){
		val->setnumber(_wtof(number.c_str()));
	}else{
			
		__int64 a=_wtoi64(number.c_str());
		val->setnumber(a);
	}
	getnextchar(true,true,true,true);
}

void parser::readstring(value *val){
	getnextchar(false,true,false); //We should start on the opening ", so get the next char
	std::wstring str;
	while (isescaped || (curchar!=L'"' && curchar!=L'\0')){
		str+=curchar;
		getnextchar(false,true,false);
	}
	getnextchar(true,true,true); //This should skip over the closing "
	val->setstring(str);
}

void parser::readlit(value *val){

	literals::literals destval;
	wchar_t *deststr;
	int destlen;
	switch(curchar){
	case 't':
		destval=literals::_true;
		deststr=L"rue";
		destlen=3;
	break;	
	case 'f':
		destval=literals::_false;
		deststr=L"alse";
		destlen=4;
	break;
	case 'n':
		destval=literals::_null;
		deststr=L"ull";
		destlen=3;
	break;
	default: return;
	}
	for (int i=0;i<destlen;++i){
		getnextchar(false,true,true);
		if (curchar != deststr[i]){
			adderror(7);
			return;
		}
	}
	getnextchar(true,true,true);  //Get the next char after the last letter
	val->setliteral(destval);
	return;
}

void parser::readarray(value *val){
	val->setarray();
	while (!si.eof){
		value *tmpval=readvalue();
		if (tmpval->getdatatype()!=datatype::_undefined){
			val->addarrayvalue(tmpval);
		}else{
			adderror(6);
		}
		if (curchar!=L','){
 			if (curchar!=L']'){
				adderror(2);
			}else{
				getnextchar(true,true,true);  //Ignore the ]
			}
			return;
		}
	}
	getnextchar(true,true,true);
}

std::wstring *parser::readname(){
	int quoted=0; //This becomes true if the string is quoted.
	std::wstring *newname=new std::wstring(L"");
	
	if (curchar==L'"'){
		quoted=1;
		getnextchar(false,true,false);
	}else if(curchar==L'\''){
		quoted=2;
		getnextchar(false,true,false);
	}else{
		if (!allow_unquoted_names){
			adderror(3);
		}
	}
	
	//Try to find reasons to STOP getting the name	
	while (!si.eof){
		if (isescaped!=true){
			if (quoted==1 && curchar==L'"'){
				getnextchar(true,true,true);
				return newname;
			}else if (quoted==2 && curchar==L'\''){
				getnextchar(true,true,true);
				return(newname);
			}else if(quoted==0 && curchar==L':'){
				return(newname);
			}else if(quoted==0 && iswspace(curchar)){
				getnextchar(true,true,true);
				return(newname);
			}
		}
		(*newname)+=curchar;
		getnextchar(false,true,false);	
	}
	return(newname);
}

void parser::readobject(value *val){
	val->setobject();
	while (!si.eof){
		getnextchar(true,true,true);
		if (curchar==L'}'){
			getnextchar(true,true,true);
			return;
		}
		std::wstring *name=readname();
		if (curchar!=L':'){adderror(4); delete name; return;}
		value *tmpval=readvalue();
		bool rv=val->addobjectvalue((*name),tmpval);
		delete name;
		if (rv==false){
			delete tmpval;	
			adderror(8);
		}
		if (curchar!=L','){
			if (curchar!=L'}'){
				adderror(5);
			}
			getnextchar(true,true,true);
			return;
		}
	}
}

value *parser::readvalue(){
	datatype::dt obdt=findval();
	if (obdt==datatype::_undefined){
		adderror(6);
	}
	value *nval=new value;
	switch (obdt){
		case datatype::_number:
			readnumber(nval);
			break;
		case datatype::_string:
			readstring(nval);
		break;
		case datatype::_literal:
			readlit(nval);
		break;
		case datatype::_array:
			readarray(nval);
		break;
		case datatype::_object:
			readobject(nval);
		break;
	}
	return nval;
}

value *parser::parse(const wchar_t *ins, size_t length){
	si.length=length;
	si.data=ins;

	si.cursor=0;

	cursor=0;
	curchar=0;
	si.eof=false; //cursor has been set, so clear any eof mark.
	si.next=readers::unicode_next;
	si.prev=readers::unicode_rewind;

//Look for a value
	value *newval=readvalue();
	return newval;
}

value *parser::parse(const char *ins, size_t length){
	si.length=length;
	si.data=ins;

	si.cursor=0;

	cursor=0;
	curchar=0;
	si.eof=false; //cursor has been set, so clear any eof mark.
	si.next=readers::ansi_next;
	si.prev=readers::ansi_rewind;

//Look for a value
	value *newval=readvalue();
	return newval;
}

value *parser::parse(const char *ins){
	return parse(ins,strlen(ins));
}

value *parser::parse(std::istream &stream){
	//si.length=0;  NOT USED
	si.data=&stream;
	si.cursor=0;
	si.col=0;
	si.row=1;

	cursor=0;
	curchar=0;
	si.eof=false; //cursor has been set, so clear any eof mark.
	si.next=readers::ansi_stream_next;
	si.prev=readers::ansi_stream_rewind;

//Look for a value
	value *newval=readvalue();
	return newval;
}

value *parser::parse(std::wistream &stream){
	//si.length=0;  NOT USED
	si.data=&stream;
	si.cursor=0;
	si.col=0;
	si.row=1;

	cursor=0;
	curchar=0;
	si.eof=false; //cursor has been set, so clear any eof mark.
	si.next=readers::uni_stream_next;
	si.prev=readers::uni_stream_rewind;

//Look for a value
	value *newval=readvalue();
	return newval;
}

