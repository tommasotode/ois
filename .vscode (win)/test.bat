@echo off
setlocal EnableDelayedExpansion
chcp 65001 > nul

if not "%1" == "c++" if not "%1" == "python" (
  echo Linguaggio sconosciuto: %1
  exit /B 2
)

if exist input.txt (
  echo input.txt già esistente^^!
  echo Eseguire il programma direttamente per testare solo quell'input,
  echo oppure rinominare input.txt per poter eseguire il test completo.
  exit /B 3
)

for /F "delims=" %%f in ('where g++') do (
  set diff=%%f
  set diff=!diff:~,-18!usr\bin\diff
)

for %%i in (*input*.txt) do (
  set input=%%i
  echo !input!:

  if "%1" == "c++" ( main < !input! > output.txt ) else python main.py < !input! > output.txt

  if !ERRORLEVEL! neq 0 (
    echo Il programma ha terminato con il codice di uscita !ERRORLEVEL!
    exit /B 1
  )

  set output=!input:input=output!
  "%diff%" output.txt !output! >nul 2>&1
  if errorlevel 1 (
    echo L'output non è corretto:

    for /F "tokens=2" %%c in ('mode con ^| findstr Col') do set COLUMNS=%%c
    set /A "hw=(COLUMNS - 10) / 2"
    set /A "hwl=(hw - 10) / 2"
    for /F "delims=:" %%n in ('"(echo !output! & echo .) | findstr /o ^^^^"') do set /A "hwr=(hw - %%n + 3) / 2"

    set line=
    call :repeat " " !hwl! line
    set line=!line!output.txt
    set /A hwlc=hwl + hw %% 2
    call :repeat " " !hwlc! line
    set "line=!line! | "
    call :repeat " " !hwr! line
    set line=!line!!output!
    echo !line!

    set line=
    set /A hwc=hw + 1
    call :repeat - !hwc! line
    set line=!line!+
    call :repeat - !hw! line
    echo !line!

    "%diff%" -yW!COLUMNS! --color output.txt !output!
    exit /B 1
  )

  echo L'output è corretto
)

del output.txt
exit /B

:repeat
set str=!%3!
for /L %%i in (1,1,%2) do set str=!str!%~1
set "%3=%str%"
exit /B
