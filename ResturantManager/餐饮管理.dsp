# Microsoft Developer Studio Project File - Name="餐饮管理" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=餐饮管理 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "餐饮管理.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "餐饮管理.mak" CFG="餐饮管理 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "餐饮管理 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "餐饮管理 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "餐饮管理 - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "餐饮管理 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "餐饮管理 - Win32 Release"
# Name "餐饮管理 - Win32 Debug"
# Begin Source File

SOURCE=.\res\142.ico
# End Source File
# Begin Source File

SOURCE=.\res\167.ico
# End Source File
# Begin Source File

SOURCE=.\res\2.ico
# End Source File
# Begin Source File

SOURCE=.\res\33.ico
# End Source File
# Begin Source File

SOURCE=.\res\42.ico
# End Source File
# Begin Source File

SOURCE=.\res\57.ico
# End Source File
# Begin Source File

SOURCE=.\res\61.ico
# End Source File
# Begin Source File

SOURCE=.\res\66.ico
# End Source File
# Begin Source File

SOURCE=.\res\71.ico
# End Source File
# Begin Source File

SOURCE=.\res\82.ico
# End Source File
# Begin Source File

SOURCE=.\res\91.ico
# End Source File
# Begin Source File

SOURCE=.\res\background1.bmp
# End Source File
# Begin Source File

SOURCE=.\Copydlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Copydlg.h
# End Source File
# Begin Source File

SOURCE=.\CPdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CPdlg.h
# End Source File
# Begin Source File

SOURCE=.\Diancaidlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Diancaidlg.h
# End Source File
# Begin Source File

SOURCE=.\JHselect.cpp
# End Source File
# Begin Source File

SOURCE=.\JHselect.h
# End Source File
# Begin Source File

SOURCE=.\Jiacaidlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Jiacaidlg.h
# End Source File
# Begin Source File

SOURCE=.\Jiacaidlg1.cpp
# End Source File
# Begin Source File

SOURCE=.\Jiacaidlg1.h
# End Source File
# Begin Source File

SOURCE=.\Jiezhangdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Jiezhangdlg.h
# End Source File
# Begin Source File

SOURCE=.\Jinhuodlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Jinhuodlg.h
# End Source File
# Begin Source File

SOURCE=.\Jinhuoselect.cpp
# End Source File
# Begin Source File

SOURCE=.\Jinhuoselect.h
# End Source File
# Begin Source File

SOURCE=.\Kaitaidlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Kaitaidlg.h
# End Source File
# Begin Source File

SOURCE=.\res\login.bmp
# End Source File
# Begin Source File

SOURCE=.\Login1.cpp
# End Source File
# Begin Source File

SOURCE=.\Login1.h
# End Source File
# Begin Source File

SOURCE=.\Logindlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Logindlg.h
# End Source File
# Begin Source File

SOURCE=.\msado15.tlh
# End Source File
# Begin Source File

SOURCE=.\msado15.tli
# End Source File
# Begin Source File

SOURCE=.\Quanxiandlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Quanxiandlg.h
# End Source File
# Begin Source File

SOURCE=.\Rcxdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Rcxdlg.h
# End Source File
# Begin Source File

SOURCE=.\resource.h
# End Source File
# Begin Source File

SOURCE=.\Returndlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Returndlg.h
# End Source File
# Begin Source File

SOURCE=.\Shuliangdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Shuliangdlg.h
# End Source File
# Begin Source File

SOURCE=.\SLdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SLdlg.h
# End Source File
# Begin Source File

SOURCE=.\SpInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\SpInfo.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\Ycxdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Ycxdlg.h
# End Source File
# Begin Source File

SOURCE=.\Zhucedlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Zhucedlg.h
# End Source File
# Begin Source File

SOURCE=".\餐饮管理.cpp"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理.h"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理.rc"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理Dlg.cpp"
# End Source File
# Begin Source File

SOURCE=".\餐饮管理Dlg.h"
# End Source File
# End Target
# End Project
