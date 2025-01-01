@echo off
REM Batch script to compile C code into DataProcessor.exe

REM Set the compiler and flags
set COMPILER=gcc
set FLAGS=-Wall -o DataProcessor.exe

REM Compile the code
%COMPILER% %FLAGS% vaka.c

REM Check if the compilation was successful
if exist DataProcessor.exe (
    echo Compilation successful. Executable is DataProcessor.exe
) else (
    echo Compilation failed.
)

REM Run the executable (DataProcessor.exe) and keep the terminal open
echo Running DataProcessor.exe...
DataProcessor.exe

REM Pause to keep the terminal open
pause
