Name:    zorba
Version: 0.9.2
Release: 1%{?dist}
Summary: Zorba is a general purpose XQuery processor implementing in C++ the W3C family of specifications

Group: System Environment/Libraries
License: Apache v2
URL: http://www.zorba-xquery.com/
Source0: file://mirror.optus.net/sourceforge/z/zo/zorba/%{name}-%{version}.tar.gz
BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)


BuildRequires: cmake >= 2.4 libxml2 >= 2.2.16 icu >= 2.6 libicu
BuildRequires: boost >= 1.32 xerces-c >= 2.7


%description


%prep
%setup -q

%build
mkdir -p build
pushd build
cmake -D CMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug ..
make %{?_smp_mflags}
popd

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT INSTALL="install -p" -C build


%clean
rm -rf $RPM_BUILD_ROOT

%post 

/sbin/ldconfig
%postun 

/sbin/ldconfig


%files
%defattr(-,root,root,-)

%{_bindir}/%{name}
%{_includedir}/%{name}/%{name}/*.h
%{_libdir}/*.so.%{version}
%{_libdir}/*.so
%dir %{_datadir}/doc/%{name}-%{version}
%{_datadir}/doc/%{name}-%{version}/LICENSE.txt
%{_datadir}/doc/%{name}-%{version}/AUTHORS.txt
%{_datadir}/doc/%{name}-%{version}/NOTICE.txt
%{_datadir}/doc/%{name}-%{version}/README.txt
%{_datadir}/doc/%{name}-%{version}/examples/*.cpp
%{_datadir}/doc/%{name}-%{version}/examples/Makefile
%dir %{_datadir}/doc/%{name}-%{version}/html
%{_datadir}/doc/%{name}-%{version}/html/*.gif

%changelog
* Fri Jun 13 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.2-1
- removed patch for next release

* Thu May 29 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.1-1
- Add patch for gcc 4.3 under Fedora 9


* Mon May 19 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.1-1
- Initial 

