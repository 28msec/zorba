namespace json{
	namespace readers{

//UNICODE Buffer
wchar_t unicode_next(inputdata *si){
	if (si->eof) return 0;
	if (si->cursor==0){
		si->cursor=si->data;
		si->row=1;
		si->col=0;
	}else{
		if ((*(wchar_t *)si->cursor)==L'\n'){
			++si->row;
			si->col=0;
		}
		si->cursor=(wchar_t *)si->cursor+1;
		++si->col;
	}
	if (si->cursor > (((wchar_t *)si->data)+si->length)){
		si->eof=true;
		return 0;
	}

	return (*(wchar_t*)si->cursor);
}
wchar_t unicode_rewind(inputdata *si,int n){
	if (n>0) si->eof=false;

	si->cursor=((wchar_t *)si->cursor)-n;
	si->col-=n;
	if (si->col==0){
		si->col=1;
		--si->row;
	}
	if (si->cursor<si->data){
		return 0;
		si->cursor=si->data;
	}else{
		return (*(wchar_t*)si->cursor);
	}
}


//ANSI Buffer
wchar_t ansi_next(inputdata *si){
	if (si->eof) return 0;
	if (si->cursor==0){
		si->cursor=si->data;
		si->row=1;
		si->col=0;
	}else{
		if ((*(char *)si->cursor)==L'\n'){
			++si->row;
			si->col=0;
		}
		si->cursor=(char*)si->cursor+1;
		++si->col;
	}
	if (si->cursor > (((char*)si->data)+si->length)){
		si->eof=true;
		return 0;
	}

	wchar_t rtn=ansiitouni(*(char*)si->cursor);
	return rtn;
}

wchar_t ansi_rewind(inputdata *si,int n){
	if (n>0) si->eof=false;

	si->cursor=((char *)si->cursor)-n;
	si->col-=n;
	if (si->col==0){
		si->col=1;
		--si->row;
	}
	if (si->cursor<si->data){
		return 0;
		si->cursor=si->data;
	}else{
		wchar_t rtn=(wchar_t)(*(char*)si->cursor);
		return rtn;
	}
}


//ANSI Stream
wchar_t ansi_stream_next(inputdata *si){
	static char a=0;
	if (si->eof) return 0;

	if (a=='\n'){ ++si->row;	si->col=0;	}

	a=((std::istream *)si->data)->get();
	++si->col;
	if (((std::istream *)si->data)->fail()!=false){
		si->eof=true;
		return 0;
	}
	wchar_t rtn=ansiitouni(a);
	return rtn;
}

wchar_t ansi_stream_rewind(inputdata *si,int n){
	if (n>0) si->eof=false;
	((std::istream *)si->data)->seekg(-(n+1),std::ios_base::cur);
	return ansi_stream_next(si);
}

//Unicode Stream
wchar_t uni_stream_next(inputdata *si){
	static wchar_t a=0;
	if (si->eof) return 0;

	if (a==L'\n'){ ++si->row;si->col=0; }

	a=((std::wistream *)si->data)->get();

	++si->col;
	if (((std::wistream *)si->data)->fail()!=false){
		si->eof=true;
		return 0;
	}
	return a;
}

wchar_t uni_stream_rewind(inputdata *si,int n){
	if (n>0) si->eof=false;
	((std::wistream *)si->data)->seekg(-(n+1),std::ios_base::cur);
	return ansi_stream_next(si);
}


//End namespaces
}
}

