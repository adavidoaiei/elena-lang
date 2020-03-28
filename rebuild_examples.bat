bin\elc examples\console\helloworld\helloworld.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\helloworld\vm_helloworld.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\sum\intsum.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\sum\realsum.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\words\words.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\pi\pi.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\bsort\bsort.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\files\textfile\textfile.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\binary\binary.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\replace\replace.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\goods\goods.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\datetime\dtcalculator.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\random\random.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\trans\tanslit.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\matrix\matrix.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\console\pi2\pi2.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\files\textdb\textdb.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\db\sqlite\sqlite_test.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\script\interpreter\interpreter.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\script\calculator\calc.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\script\calculator\calc_static.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\script\js\vmconsole.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\script\js\fibonacci_static.prj 
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\gui\agenda\agenda.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\gui\graphs\graphs.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

bin\elc examples\gui\c_a_g\c_area_gui.prj
@echo off 
if %ERRORLEVEL% EQU -2 GOTO CompilerError
@echo on

rem bin\elc examples\gui\notepad\notepad.prj

@echo off 
goto:eof
@echo on

:CompilerError
echo ELC returns error %ERRORLEVEL%
@echo off
goto:eof
@echo on
