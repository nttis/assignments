.486
option casemap:none

include \masm32\include\masm32rt.inc

factorial PROTO: DWORD

.code
start:
        call main
        exit

main proc
        LOCAL N: DWORD ; N given by user

        mov N, sval(input("n = "))
        invoke factorial, N
main endp

factorial proc n: DWORD
        LOCAL result: DWORD ; final factorial
        LOCAL count: DWORD ; loop iteration counter

        mov result, 1 ; minimum result is 1
        mov count, 1

        print chr$("n! = ")

contd:
        ; MUL multiplies eax by src (ebx in this case)
        ; and store the result in eax
        mov eax, result
        mul count
        mov result, eax

        print str$(count)

        ; Skip printing the last * symbol and exit the loop
        mov eax, n
        cmp count, eax
        je end_loop

        print chr$(" * ")

        inc count ; increment count by 1
        jmp contd ; jump back to start of loop

end_loop:
        print chr$(13, 10, " => ")
        print str$(result)
        exit

factorial endp

end start

