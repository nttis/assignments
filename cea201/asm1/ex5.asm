.486
option casemap:none

include \masm32\include\masm32rt.inc

.code
start:
        call main
        exit

main proc
        LOCAL v1:DWORD
        LOCAL v2:DWORD
        LOCAL temp:DWORD
        
        mov v1, sval(input("Enter the first number (v1): "))
        mov v2, sval(input("Enter the second number (v2): "))

        ; v1 + v2
        mov eax, v1
        add eax, v2
        mov temp, eax

        print chr$("v1 + v2 = ")
        print str$(temp)
        print chr$(13, 10)

        ; v1 - v2
        mov eax, v1
        sub eax, v2
        mov temp, eax

        print chr$("v1 - v2 = ")
        print str$(temp)
        print chr$(13, 10)

        ; v1 * v2
        mov eax, v1
        mul v2 ; mul implicitly stores the result in eax
        mov temp, eax

        print chr$("v1 * v2 = ")
        print str$(temp)
        print chr$(13, 10)

        ; v1 / v2
        cmp v2, 0
        je div_by_0_error

        mov eax, v1
        cdq
        mov ebx, v2
        div ebx ; divide edx:eax by ebx
        mov temp, eax
        
        print chr$("v1 / v2 = ")
        print str$(temp)
        print chr$(13, 10)

        ret
main endp

div_by_0_error proc
        print chr$("Cannot divide by zero")
div_by_0_error endp

end start

