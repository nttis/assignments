.486
option casemap:none

include \masm32\include\masm32rt.inc

.code
start:
        call main
        exit

main proc
        LOCAL a:DWORD
        LOCAL b:DWORD
        LOCAL x:DWORD
        
        mov a, sval(input("Enter the coefficient a: "))
        mov b, sval(input("Enter the coefficient b: "))

        ; Jump to error if a = 0
        cmp a, 0
        je error

        ; Calculate x = -b/a
        mov eax, b
        neg eax ; negate b
        cdq

        mov ebx, a
        idiv ebx
        mov x, eax

        print chr$("The solution x is: ")
        print str$(x)
        print chr$(13, 10)

        ret
main endp

error proc
        print chr$("a cannot be zero", 13, 10)
error endp

end start

