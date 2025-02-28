.486
.model flat, stdcall
option casemap:none

include \masm32\include\windows.inc
include \masm32\macros\macros.asm

include \masm32\include\masm32.inc
include \masm32\include\gdi32.inc
include \masm32\include\user32.inc
include \masm32\include\kernel32.inc

includelib \masm32\lib\masm32.lib
includelib \masm32\lib\gdi32.lib
includelib \masm32\lib\user32.lib
includelib \masm32\lib\kernel32.lib

.code
start:
        call main
        exit

main proc
        print chr$("Song co xanh tuoi gon toi troi", 13, 10)
        print chr$("Bao co thon nu hat tren doi", 13, 10)
        print chr$("Ngay mai trong dam xuan xanh ay", 13, 10)
        print chr$("Co ke theo chong bo cuoc choi", 13, 10)
        ret
main endp

end start
