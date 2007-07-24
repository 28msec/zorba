# Microsoft Developer Studio Project File - Name="zorba" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=zorba - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "zorba.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "zorba.mak" CFG="zorba - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "zorba - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "zorba - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "zorba - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "zorba - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I ".\\" /I "..\\" /I "values\\" /I "..\win_pthread" /D "_DEBUG" /D "WIN32" /D "_CONSOLE" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "zorba - Win32 Release"
# Name "zorba - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\functions\Accessors.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\anyURI.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Binary.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Boolean.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Casting.cpp
# End Source File
# Begin Source File

SOURCE=.\store\collection_resolver.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Constructor.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Context.cpp
# End Source File
# Begin Source File

SOURCE=.\dom\dom_namepool.cpp
# End Source File
# Begin Source File

SOURCE=.\dom\dom_nodes.cpp
# End Source File
# Begin Source File

SOURCE=.\dom\dom_qname.cpp
# End Source File
# Begin Source File

SOURCE=.\dom\dom_xml_handler.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\DurationsDatesTimes.cpp
# End Source File
# Begin Source File

SOURCE=.\context\dynamic_context.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Error.cpp
# End Source File
# Begin Source File

SOURCE=.\listeners\error_handler.cpp
# End Source File
# Begin Source File

SOURCE=.\runtime\errors.cpp
# End Source File
# Begin Source File

SOURCE=.\exprtree\expr.cpp
# End Source File
# Begin Source File

SOURCE=.\util\file.cpp
# End Source File
# Begin Source File

SOURCE=.\exprtree\ft_expr.cpp
# End Source File
# Begin Source File

SOURCE=.\values\ft_options.cpp
# End Source File
# Begin Source File

SOURCE=.\values\ft_values.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\function.cpp
# End Source File
# Begin Source File

SOURCE=.\util\fxcharheap.cpp
# End Source File
# Begin Source File

SOURCE=.\runtime\item_iterator.cpp
# End Source File
# Begin Source File

SOURCE=.\store\itemstore.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\library.cpp
# End Source File
# Begin Source File

SOURCE=.\util\mmfile.cpp
# End Source File
# Begin Source File

SOURCE=.\store\module_resolver.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\noderep_iterator.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\nodereps.cpp
# End Source File
# Begin Source File

SOURCE=.\exprtree\normalize_visitor.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\NOTATION.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Numerics.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\NumericsImpl.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\parsenodes.cpp
# End Source File
# Begin Source File

SOURCE=.\runtime\plan_visitor.cpp
# End Source File
# Begin Source File

SOURCE=.\values\primitive_values.cpp
# End Source File
# Begin Source File

SOURCE=.\store\qname_cache.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\qnamerep.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\QNames.cpp
# End Source File
# Begin Source File

SOURCE=.\util\rwlock.cpp
# End Source File
# Begin Source File

SOURCE=.\store\scan_handler.cpp
# End Source File
# Begin Source File

SOURCE=.\store\schema_resolver.cpp
# End Source File
# Begin Source File

SOURCE=.\types\sequence_type.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Sequences.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\SequencesImpl.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\signature.cpp
# End Source File
# Begin Source File

SOURCE=.\store\source.cpp
# End Source File
# Begin Source File

SOURCE=.\context\static_context.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\stdlib.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Strings.cpp
# End Source File
# Begin Source File

SOURCE=.\svnheader.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\symbol_table.cpp
# End Source File
# Begin Source File

SOURCE=.\util\tokenbuf.cpp
# End Source File
# Begin Source File

SOURCE=.\functions\Trace.cpp
# End Source File
# Begin Source File

SOURCE=.\listeners\trace_handler.cpp
# End Source File
# Begin Source File

SOURCE=.\store\unicode_decompositions.cpp
# End Source File
# Begin Source File

SOURCE=.\exprtree\update_expr.cpp
# End Source File
# Begin Source File

SOURCE=.\values\update_values.cpp
# End Source File
# Begin Source File

SOURCE=.\util\URI.cpp
# End Source File
# Begin Source File

SOURCE=.\store\uri_resolver.cpp
# End Source File
# Begin Source File

SOURCE=.\util\utf8_encoder.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\valuereps.cpp
# End Source File
# Begin Source File

SOURCE=.\runtime\var_iterator.cpp
# End Source File
# Begin Source File

SOURCE=.\store\xml_handler.cpp
# End Source File
# Begin Source File

SOURCE=.\store\xml_scanner.cpp
# End Source File
# Begin Source File

SOURCE=.\store\xml_term.cpp
# End Source File
# Begin Source File

SOURCE=.\util\xqp_exception.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\xquery_driver.cpp
# End Source File
# Begin Source File

SOURCE=.\parser\xquery_parser.tab.c
# End Source File
# Begin Source File

SOURCE=.\parser\xquery_scanner.yy.cpp
# End Source File
# Begin Source File

SOURCE=.\runtime\zorba.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_ft_values.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_nodes.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_qname.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_update_values.cpp
# End Source File
# Begin Source File

SOURCE=.\store\zorba_uri_resolver.cpp
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_value_factory.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\functions\Accessors.h
# End Source File
# Begin Source File

SOURCE=.\functions\anyURI.h
# End Source File
# Begin Source File

SOURCE=.\util\Assert.h
# End Source File
# Begin Source File

SOURCE=.\functions\Binary.h
# End Source File
# Begin Source File

SOURCE=.\functions\Boolean.h
# End Source File
# Begin Source File

SOURCE=.\functions\Casting.h
# End Source File
# Begin Source File

SOURCE=.\store\character_entities.h
# End Source File
# Begin Source File

SOURCE=.\types\collation.h
# End Source File
# Begin Source File

SOURCE=.\store\collation_resolver.h
# End Source File
# Begin Source File

SOURCE=.\store\collection_resolver.h
# End Source File
# Begin Source File

SOURCE=.\context\common.h
# End Source File
# Begin Source File

SOURCE=.\functions\Constructor.h
# End Source File
# Begin Source File

SOURCE=.\runtime\content_handler.h
# End Source File
# Begin Source File

SOURCE=.\context\context.h
# End Source File
# Begin Source File

SOURCE=.\functions\Context.h
# End Source File
# Begin Source File

SOURCE=.\store\data_manager.h
# End Source File
# Begin Source File

SOURCE=.\dom\dom_namepool.h
# End Source File
# Begin Source File

SOURCE=.\dom\dom_nodes.h
# End Source File
# Begin Source File

SOURCE=.\dom\dom_qname.h
# End Source File
# Begin Source File

SOURCE=.\dom\dom_xml_handler.h
# End Source File
# Begin Source File

SOURCE=.\functions\DurationsDatesTimes.h
# End Source File
# Begin Source File

SOURCE=.\context\dynamic_context.h
# End Source File
# Begin Source File

SOURCE=.\runtime\dynamic_context.h
# End Source File
# Begin Source File

SOURCE=.\functions\Error.h
# End Source File
# Begin Source File

SOURCE=.\listeners\error_handler.h
# End Source File
# Begin Source File

SOURCE=.\runtime\errors.h
# End Source File
# Begin Source File

SOURCE=.\exprtree\expr.h
# End Source File
# Begin Source File

SOURCE=.\runtime\expr_visitor.h
# End Source File
# Begin Source File

SOURCE=.\util\file.h
# End Source File
# Begin Source File

SOURCE=.\exprtree\ft_expr.h
# End Source File
# Begin Source File

SOURCE=.\values\ft_options.h
# End Source File
# Begin Source File

SOURCE=.\values\ft_selection.h
# End Source File
# Begin Source File

SOURCE=.\values\ft_values.h
# End Source File
# Begin Source File

SOURCE=.\functions\function.h
# End Source File
# Begin Source File

SOURCE=.\util\fxarray.h
# End Source File
# Begin Source File

SOURCE=.\util\fxcharheap.h
# End Source File
# Begin Source File

SOURCE=.\util\fxhashmap.h
# End Source File
# Begin Source File

SOURCE=.\util\fxvector.h
# End Source File
# Begin Source File

SOURCE=.\util\hashfun.h
# End Source File
# Begin Source File

SOURCE=.\util\hashmap.h
# End Source File
# Begin Source File

SOURCE=.\exprtree\indent.h
# End Source File
# Begin Source File

SOURCE=.\parser\indent.h
# End Source File
# Begin Source File

SOURCE=.\runtime\indent.h
# End Source File
# Begin Source File

SOURCE=.\runtime\item_iterator.h
# End Source File
# Begin Source File

SOURCE=.\values\itemid.h
# End Source File
# Begin Source File

SOURCE=.\store\itemstore.h
# End Source File
# Begin Source File

SOURCE=.\functions\library.h
# End Source File
# Begin Source File

SOURCE=.\util\list.h
# End Source File
# Begin Source File

SOURCE=.\util\mmfile.h
# End Source File
# Begin Source File

SOURCE=.\store\module_resolver.h
# End Source File
# Begin Source File

SOURCE=.\runtime\namespace.h
# End Source File
# Begin Source File

SOURCE=.\zorba\noderep_iterator.h
# End Source File
# Begin Source File

SOURCE=.\zorba\nodereps.h
# End Source File
# Begin Source File

SOURCE=.\values\nodes.h
# End Source File
# Begin Source File

SOURCE=.\exprtree\normalize_visitor.h
# End Source File
# Begin Source File

SOURCE=.\functions\NOTATION.h
# End Source File
# Begin Source File

SOURCE=.\functions\Numerics.h
# End Source File
# Begin Source File

SOURCE=.\functions\NumericsImpl.h
# End Source File
# Begin Source File

SOURCE=.\parser\parse_constants.h
# End Source File
# Begin Source File

SOURCE=.\exprtree\parsenode_visitor.h
# End Source File
# Begin Source File

SOURCE=.\parser\parsenodes.h
# End Source File
# Begin Source File

SOURCE=.\runtime\plan_visitor.h
# End Source File
# Begin Source File

SOURCE=.\values\primitive_values.h
# End Source File
# Begin Source File

SOURCE=.\values\qname.h
# End Source File
# Begin Source File

SOURCE=.\store\qname_cache.h
# End Source File
# Begin Source File

SOURCE=.\zorba\qnamerep.h
# End Source File
# Begin Source File

SOURCE=.\functions\QNames.h
# End Source File
# Begin Source File

SOURCE=.\util\rchandle.h
# End Source File
# Begin Source File

SOURCE=.\types\representations.h
# End Source File
# Begin Source File

SOURCE=.\util\rwlock.h
# End Source File
# Begin Source File

SOURCE=.\sax\sax_interface.h
# End Source File
# Begin Source File

SOURCE=.\store\scan_handler.h
# End Source File
# Begin Source File

SOURCE=.\store\schema_resolver.h
# End Source File
# Begin Source File

SOURCE=.\types\sequence_type.h
# End Source File
# Begin Source File

SOURCE=.\functions\Sequences.h
# End Source File
# Begin Source File

SOURCE=.\functions\SequencesImpl.h
# End Source File
# Begin Source File

SOURCE=.\functions\signature.h
# End Source File
# Begin Source File

SOURCE=.\runtime\singleton_iterators.h
# End Source File
# Begin Source File

SOURCE=.\util\sorter.h
# End Source File
# Begin Source File

SOURCE=.\store\source.h
# End Source File
# Begin Source File

SOURCE=.\context\static_context.h
# End Source File
# Begin Source File

SOURCE=.\store\store.h
# End Source File
# Begin Source File

SOURCE=.\store\store_common.h
# End Source File
# Begin Source File

SOURCE=.\functions\Strings.h
# End Source File
# Begin Source File

SOURCE=.\svnheader.h
# End Source File
# Begin Source File

SOURCE=.\parser\symbol_table.h
# End Source File
# Begin Source File

SOURCE=.\util\tokenbuf.h
# End Source File
# Begin Source File

SOURCE=.\functions\Trace.h
# End Source File
# Begin Source File

SOURCE=.\listeners\trace_handler.h
# End Source File
# Begin Source File

SOURCE=.\util\tracer.h
# End Source File
# Begin Source File

SOURCE=.\util\triple.h
# End Source File
# Begin Source File

SOURCE=.\types\typecodes.h
# End Source File
# Begin Source File

SOURCE=.\store\unicode_decompositions.h
# End Source File
# Begin Source File

SOURCE=.\exprtree\update_expr.h
# End Source File
# Begin Source File

SOURCE=.\values\update_values.h
# End Source File
# Begin Source File

SOURCE=.\util\URI.h
# End Source File
# Begin Source File

SOURCE=.\store\uri_resolver.h
# End Source File
# Begin Source File

SOURCE=.\util\utf8_encoder.h
# End Source File
# Begin Source File

SOURCE=.\values\value_factory.h
# End Source File
# Begin Source File

SOURCE=.\zorba\valuereps.h
# End Source File
# Begin Source File

SOURCE=.\values\values.h
# End Source File
# Begin Source File

SOURCE=.\runtime\var_iterator.h
# End Source File
# Begin Source File

SOURCE=.\store\xml_handler.h
# End Source File
# Begin Source File

SOURCE=.\store\xml_scanner.h
# End Source File
# Begin Source File

SOURCE=.\store\xml_term.h
# End Source File
# Begin Source File

SOURCE=.\util\xqp_exception.h
# End Source File
# Begin Source File

SOURCE=.\parser\xquery_driver.h
# End Source File
# Begin Source File

SOURCE=.\parser\xquery_parser.tab.h
# End Source File
# Begin Source File

SOURCE=.\values\xs_primitive_values.h
# End Source File
# Begin Source File

SOURCE=.\runtime\zorba.h
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_ft_values.h
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_nodes.h
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_qname.h
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_update_values.h
# End Source File
# Begin Source File

SOURCE=.\store\zorba_uri_resolver.h
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_value_factory.h
# End Source File
# Begin Source File

SOURCE=.\zorba\zorba_values.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
