.486
option casemap:none

include \masm32\include\masm32rt.inc

.code
start:
        call main
        exit

main proc
        LOCAL curr_count: DWORD ; Store the current iteration count
        LOCAL original_count: DWORD ; Store the original iteration count, will not change
        
        LOCAL n1: DWORD ; The first number
        LOCAL n2: DWORD ; The second number
        LOCAL sum: DWORD ; Temporary storage for the sum of the 2 numbers

        ; Assign user input into both curr_count and original_count
        mov curr_count, sval(input("Enter the number of times to compute the sum: n = "))
        mov eax, curr_count
        mov original_count, eax
        
        print chr$("Time", 13, 10)

contd:
        ; Jump to end_loop if curr_count is 0
        cmp curr_count, 0
        je end_loop

        ; Compute a number to display to the screen
        ; This number counts UP from 1
        mov eax, original_count ; eax = original_cout
        sub eax, curr_count ; eax = eax - curr_count
        add eax, 1 ; eax = eax + 1 (to make it start from 1)
        print str$(eax)
        print chr$(13, 10)

        mov n1, sval(input("Enter number 1: "))
        mov n2, sval(input("Enter number 2: "))

        mov eax, n1
        add eax, n2
        mov sum, eax ; store sum in sum

        print chr$("Sum of them: ")
        print str$(sum)
        print chr$(13, 10)
        
        dec curr_count ; decrement curr_count
        jmp contd ; jump back to the start

end_loop:
        ret

main endp

end start
