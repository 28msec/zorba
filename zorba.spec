Name:    zorba
Version: 0.9.21
Release: 2%{?dist}
Summary: General purpose XQuery processor implementing in C++

Group: System Environment/Libraries
License: ASL 2.0
URL: http://www.zorba-xquery.com/
Source0: file://mirror.optus.net/sourceforge/z/zo/zorba/%{name}-%{version}.tar.gz

%{!?python_sitelib: %define python_sitelib %(%{__python} -c "from distutils.sysconfig import get_python_lib; print get_python_lib(0)")}

%{!?ruby_sitelib: %define ruby_sitelib %( ruby -r rbconfig -e "print Config::CONFIG['sitearchdir']")}

BuildRoot: %{_tmppath}/%{name}-%{version}-%{release}-root-%(%{__id_u} -n)


BuildRequires: cmake >= 2.4 libxml2 >= 2.2.16 icu >= 2.6 libicu-devel
BuildRequires: boost >= 1.32 xerces-c-devel >= 2.7
BuildRequires: ruby-devel
%description
Zorba is a general purpose XQuery processor implementing in C++ the
W3C family of specifications. It is not an XML database. The query
processor has been designed to be embeddable in a variety of
environments such as other programming languages extended with XML
processing capabilities, browsers, database servers, XML message
dispatchers, or smartphones. Its architecture employes a modular
design, which allows customizing the Zorba query processor to the
environment's needs. In particular the architecture of the query
processor allows a pluggable XML store (e.g. main memory, DOM stores,
persistent disk-based large stores, S3 stores).

%package devel
Summary: Header files for %{name}
Group: Development/Libraries
Requires: %{name} = %{version}-%{release}

%description devel
The %{name}-devel package contains headerss for building applications
that use %{zorba}.

%package devel-docs
Summary: Class library documentaton
Group: Documentation


%description devel-docs
This package contains the html documentation files for the %{name}
class library.  User documentation is part of the main package.

%package python
Summary: %{name} Python module
Group: Development/Languages
BuildRequires: swig

%description python
Summary: %{name} python module
Provides Python module to use %{name} API

%package ruby
Summary: %{name} Ruby module
Group: Development/Languages
BuildRequires: swig
Requires: %{name} = %{version}-%{release}

%description ruby
Provides ruby module to use %{name} API


%prep
%setup -q

%build
mkdir -p build
pushd build
cmake -D CMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Debug --debug-output -DCMAKE_SKIP_BUILD_RPATH=1  ..
make %{?_smp_mflags}
make doc
popd

%install
rm -rf $RPM_BUILD_ROOT
make install DESTDIR=$RPM_BUILD_ROOT INSTALL="install -p" -C build


%clean
# rm -rf $RPM_BUILD_ROOT

%post 

/sbin/ldconfig
%postun 

/sbin/ldconfig


%files
%defattr(-,root,root,-)

%{_bindir}/%{name}
%{_libdir}/*.so.%{version}
%{_libdir}/*.so
%dir %{_datadir}/doc/%{name}-%{version}
%{_datadir}/doc/%{name}-%{version}/LICENSE.txt
%{_datadir}/doc/%{name}-%{version}/AUTHORS.txt
%{_datadir}/doc/%{name}-%{version}/NOTICE.txt
%{_datadir}/doc/%{name}-%{version}/README.txt
%{_datadir}/doc/%{name}-%{version}/c/examples/*.c
%{_datadir}/doc/%{name}-%{version}/c/html/*.gif
%{_datadir}/doc/%{name}-%{version}/cxx/examples/*.cpp
%{_datadir}/doc/%{name}-%{version}/cxx/examples/Makefile
%{_datadir}/doc/%{name}-%{version}/cxx/html/*.gif
%{_datadir}/doc/%{name}-%{version}/zorba/html/*.gif

%files devel
%{_includedir}/%{name}/%{name}/*.h
%{_includedir}/%{name}/simplestore/*.h

%files devel-docs
%{_datadir}/doc/%{name}-%{version}/c/html/*.html
%{_datadir}/doc/%{name}-%{version}/c/html/%{name}.TAGFILE
%{_datadir}/doc/%{name}-%{version}/c/html/*.css
%{_datadir}/doc/%{name}-%{version}/c/html/*.png
%{_datadir}/doc/%{name}-%{version}/c/html/index.*
%{_datadir}/doc/%{name}-%{version}/c/html/installdox
%{_datadir}/doc/%{name}-%{version}/c/html/search.*
%{_datadir}/doc/%{name}-%{version}/cxx/html/*.html
%{_datadir}/doc/%{name}-%{version}/cxx/html/%{name}.TAGFILE
%{_datadir}/doc/%{name}-%{version}/cxx/html/*.css
%{_datadir}/doc/%{name}-%{version}/cxx/html/*.png
%{_datadir}/doc/%{name}-%{version}/cxx/html/index.*
%{_datadir}/doc/%{name}-%{version}/cxx/html/installdox
%{_datadir}/doc/%{name}-%{version}/cxx/html/search.*
%{_datadir}/doc/%{name}-%{version}/python/html/*.css
%{_datadir}/doc/%{name}-%{version}/python/html/*.html
%{_datadir}/doc/%{name}-%{version}/python/html/doxygen.png
%{_datadir}/doc/%{name}-%{version}/python/html/index.*
%{_datadir}/doc/%{name}-%{version}/python/html/installdox
%{_datadir}/doc/%{name}-%{version}/python/html/search.*
%{_datadir}/doc/%{name}-%{version}/python/html/%{name}.TAGFILE
%{_datadir}/doc/%{name}-%{version}/ruby/html/*.html
%{_datadir}/doc/%{name}-%{version}/ruby/html/*.css
%{_datadir}/doc/%{name}-%{version}/ruby/html/index.*
%{_datadir}/doc/%{name}-%{version}/ruby/html/doxygen.png
%{_datadir}/doc/%{name}-%{version}/ruby/html/index.*
%{_datadir}/doc/%{name}-%{version}/ruby/html/installdox
%{_datadir}/doc/%{name}-%{version}/ruby/html/search.*
%{_datadir}/doc/%{name}-%{version}/ruby/html/%{name}.TAGFILE
%{_datadir}/doc/%{name}-%{version}/%{name}/html/index.*
%{_datadir}/doc/%{name}-%{version}/%{name}/html/*.css
%{_datadir}/doc/%{name}-%{version}/%{name}/html/*.html
%{_datadir}/doc/%{name}-%{version}/%{name}/html/doxygen.png
%{_datadir}/doc/%{name}-%{version}/%{name}/html/installdox
%{_datadir}/doc/%{name}-%{version}/%{name}/html/search.*
%{_datadir}/doc/%{name}-%{version}/%{name}/html/%{name}.TAGFILE


%files python

%dir %{python_sitelib}/_zorba_api.so
%dir %{python_sitelib}/zorba_api.*
%{_datadir}/doc/%{name}-%{version}/python/examples/*.py
%{_datadir}/doc/%{name}-%{version}/python/examples/*.pyc
%{_datadir}/doc/%{name}-%{version}/python/examples/*.pyo
%{_datadir}/doc/%{name}-%{version}/python/html/*.gif

%files ruby

%dir %{ruby_sitelib}/zorba_api.so
%{_datadir}/doc/%{name}-%{version}/ruby/examples/*.rb
%{_datadir}/doc/%{name}-%{version}/ruby/html/*.gif

%changelog
* Mon Jul 28 2008 Paul Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.21-2
- remove rpath in build
- added documentation
- added devel package
- remove non utf8 character
- fix license entry
- fix description line


* Sun Jun 29 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.21-1
- Update to 0.9.21

* Fri Jun 27 2008 Paul Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.2-2
- Added required -devel packages for build


* Sun Jun 22 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.2-2
- Added correct install of ruby and python modules

* Fri Jun 20 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.2-1
- update to version 0.9.2

* Mon Jun 16 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.2541-1
- added python and ruby subpackages

* Fri Jun 13 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.2-1
- removed patch for next release

* Thu May 29 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.1-1
- Add patch for gcc 4.3 under Fedora 9


* Mon May 19 2008 Paul F. Kunz <Paul_Kunz@slac.stanford.edu> - 0.9.1-1
- Initial 

