.486
option casemap:none

include \masm32\include\masm32rt.inc

.code
start:
        call main
        exit

main proc
        LOCAL count: DWORD ; iteration count
        LOCAL N: DWORD ; Fibonacci number input by user

        LOCAL t1: DWORD
        LOCAL t2: DWORD
        LOCAL result: DWORD

        mov N, sval(input("Enter the Fibonacci number to calculate (N): "))

        ; Jump to short_circuit if N = 1 or N = 2
        ; the result is 1 in these cases
        cmp N, 1
        je short_circuit

        cmp N, 2
        je short_circuit

        ; Prepare to calculate
        mov t1, 1
        mov t2, 1

        ; We only loop N - 2 times
        mov edx, N
        sub edx, 2
        mov count, edx

contd:
        ; Jump to end_loop if count is 0
        cmp count, 0
        je end_loop

        ; eax = t1 + t2
        mov eax, t1
        add eax, t2

        mov edx, t2
        mov t1, edx ; t1 = t2 (edx)
        mov t2, eax ; t2 = eax

        dec count; decrement count
        jmp contd ; jump back to the start of the loop

end_loop:
        ; When the loop ends, eax contains the result
        mov result, eax
        jmp end_program

short_circuit:
        mov result, 1
        jmp end_program

end_program:
        print chr$("Fibonacci: ")
        print str$(result)
        exit

main endp

end start

