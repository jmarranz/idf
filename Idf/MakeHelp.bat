@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by Idf.HPJ. >"hlp\Idf.hm"
echo. >>"hlp\Idf.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Idf.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Idf.hm"
echo. >>"hlp\Idf.hm"
echo // Prompts (IDP_*) >>"hlp\Idf.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Idf.hm"
echo. >>"hlp\Idf.hm"
echo // Resources (IDR_*) >>"hlp\Idf.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Idf.hm"
echo. >>"hlp\Idf.hm"
echo // Dialogs (IDD_*) >>"hlp\Idf.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Idf.hm"
echo. >>"hlp\Idf.hm"
echo // Frame Controls (IDW_*) >>"hlp\Idf.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Idf.hm"
REM -- Make help for Project Idf


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\Idf.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\Idf.hlp" goto :Error
if not exist "hlp\Idf.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\Idf.hlp" Debug
if exist Debug\nul copy "hlp\Idf.cnt" Debug
if exist Release\nul copy "hlp\Idf.hlp" Release
if exist Release\nul copy "hlp\Idf.cnt" Release
echo.
goto :done

:Error
echo hlp\Idf.hpj(1) : error: Problem encountered creating help file

:done
echo.
