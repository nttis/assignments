.486
option casemap:none

include \masm32\include\masm32rt.inc

.code
start:
        call main
        exit

main proc
        LOCAL num1:DWORD
        LOCAL num2:DWORD
        LOCAL num3:DWORD
        LOCAL sum:DWORD
        LOCAL avg:DWORD
        
        mov num1, sval(input("Enter num1: "))
        mov num2, sval(input("Enter num2: "))
        mov num3, sval(input("Enter num3: "))

        mov eax, num1 ; eax = num1
        add eax, num2 ; eax = eax + num2
        add eax, num3 ; eax = eax + num3
        mov sum, eax ; store eax into sum

        print chr$("The sum is: ")
        print str$(sum)
        print chr$(13, 10)

        mov eax, sum ; eax = sum
        cdq ; extend the rest of sum in edx
        mov ebx, 3
        div ebx
        mov avg, eax

        print chr$("The average is: ")
        print str$(avg)
        print chr$(13, 10)
        
        ret
main endp

end start
