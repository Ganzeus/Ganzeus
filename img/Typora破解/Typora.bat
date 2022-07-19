@echo off
for /f "delims= " %%d in ('echo %date%') do (set "now=%%d")
date 2019/1/1
echo changing date:2019/1/1
start D:\Typora\Typora.exe
echo starting Typora ......
choice /t 1 /d y /n >nul
date %now%
echo reset time