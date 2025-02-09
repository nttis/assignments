#set page(
  paper: "a4",
  number-align: center,
)

#set text(font: "Libertinus Serif")
#set heading(numbering: "1.1. ")

= Exercise 1

Because 37.26#sub[10] is a real number with a fractional part, we convert the integral part and the fractional parts separately.

== To hexadecimal
=== Integral part

We take the source, divide it by 16 and make the quotient the new source.
The remainder is added to the left of the destination.
This process repeats until the quotient becomes 0.

#align(center, table(
  columns: (1fr, 1fr, 1fr, 1fr, 1fr),

  [*Iteration*], [*Source*], [*Quotient*], [*Remainder*], [*Destination*],
  [1], [37], [2], [5], [5],
  [2], [2], [0], [2], [25],
))

Therefore, the integral part in hexadecimal is *25#sub[16]*.

=== Fractional part

We take the fractional part as the source, multiply it by 16, and make the fractional part of the result become the new source.
Insert the integral part of the result to the right of the destination.
Repeat until fraction is 0 or we have enough digits.

#align(center, table(
  columns: (0.7fr, 1fr, 1fr, 1fr, 1fr, 1fr),

  [*Iteration*], [*Source*], [*Result*], [*Integral part of result*], [*Fractional part of result*], [*Destination*],
  [1], [0.26], [4.16], [4], [0.16], [4],
  [2], [0.16], [2.56], [2], [0.56], [42],
  [3], [0.56], [8.96], [8], [0.96], [428],
  [4], [0.96], [15.36], [15#sub[10] = F#sub[16]], [0.36], [428F],
  [5], [0.36], [5.76], [5], [0.76], [428F5],
  [6], [0.76], [12.16], [12#sub[10] = C#sub[16]], [0.16], [428F5C],
))

The fractions begin to repeat after the 6th iteration, so we stop there.

Therefore, the fractional part in hexadecimal is *428F5C#sub[16]*.

=== Result

*37.26#sub[10]* is equal to *25.428F5C#sub[16]*.

== To binary

=== The integral part

The process is similar, except we divide by 2 instead of 16.

#align(center, table(
  columns: (1fr, 1fr, 1fr, 1fr, 1fr),

  [*Iteration*], [*Source*], [*Quotient*], [*Remainder*], [*Destination*],
  [1], [37], [18], [1], [1],
  [2], [18], [9], [0], [01],
  [3], [9], [4], [1], [101],
  [4], [4], [2], [0], [0101],
  [5], [2], [1], [0], [00101],
  [6], [1], [0], [1], [100101],
))

The integral part is *100101#sub[2]*.

=== The fractional part

The process is similar, except we multiply by 2 instead of 16.

#align(center, table(
  columns: (0.7fr, 1fr, 1fr, 1fr, 1fr, 1fr),

  [*Iteration*], [*Source*], [*Result*], [*Integral part of result*], [*Fractional part of result*], [*Destination*],
  [1], [0.26], [0.52], [0], [0.52], [0],
  [2], [0.52], [1.04], [1], [0.04], [01],
  [3], [0.04], [0.08], [0], [0.08], [010],
  [4], [0.08], [0.16], [0], [0.16], [0100],
  [5], [0.16], [0.32], [0], [0.32], [01000],
  [6], [0.32], [0.64], [0], [0.64], [010000],
  [..], [..], [..], [..], [..], [..],
))

It goes on forever, so I have stopped at 6 iterations.

The fractional part in binary is *010000#sub[2]*.

== Result

*37.26#sub[10]* is _approximately_ *100101.010000#sub[2]*.

#pagebreak()

= Exercise 2

== The sign bit
*37.26#sub[10]* is positive #sym.arrow the sign bit is *0*.

== The exponent
*37.26#sub[10]* when transformed into binary is *100101.010000#sub[2]*.

Normalizing the binary representation gives us: *100101.010000#sub[2]* = *1.00101010000#sub[2] $#sym.times 2^5$*.

Therefore, the exponent is *5*. In Excess_127, the exponent is *5 + 127 = 132#sub[10] = 10000100#sub[2]*.

== The mantissa

We have the normalized binary representation as *1.00101010000#sub[2] $#sym.times 2^5$* #sym.arrow the mantissa is *00101010000#sub[2]*.

The mantissa is currently 11 bits long, so we add 12 more bits to the right to make it 23 bits long.

This gives us the final mantissa: *00101010000000000000000#sub[2]*.

== Result

Assembling the parts together, the Excess_127 representation of 37.26#sub[10] is *01000010000101010000000000000000#sub[2]*.

#table(
  columns: (1fr, 1fr, 3fr),

  [*Sign*], [*Exponent*], [*Mantissa*],
  [0], [10000100], [00101010000000000000000],
)

#pagebreak()

= Exercise 3

Normalizing: *101.1010000#sub[2] #sym.arrow 1.011010000#sub[2] $#sym.times 2^2$*.

The shifter: *2*.

The mantissa: *011010000*.

#pagebreak()

= Exercise 4

We have:
- 32#sub[10] = 100000#sub[2]
- 25#sub[10] = 011001#sub[2] (padded with 1 zero to be 6 bits)

To subtract 25 from 32, we *add* 32 to the two's complement of 25.

To obtain the two's complement of 25, we add 1 to its one's complement.

#table(
  columns: (2fr, 1fr, 1fr, 1fr, 1fr, 1fr, 1fr),
  stroke: none,

  [*Original*], [#table.vline()], [0], [1], [1], [0], [0], [1],
  [*One's complement*], [1], [0], [0], [1], [1], [0],
  [*1#sub[10]*], [0], [0], [0], [0], [0], [1],
  
  [#table.hline()],
  
  [*Two's complement*], [1], [0], [0], [1], [1], [1]
)

The following table shows the *32 - 25* operation:

#table(
  columns: (2.5fr, 1fr, 1fr, 1fr, 1fr, 1fr, 1fr),
  stroke: none,

  [*Carry*], [#table.vline()], [1], [], [], [], [], [],
  [*32#sub[10]*], [1], [0], [0], [0], [0], [0],
  [*25#sub[10] (two's complement)*], [1], [0], [0], [1], [1], [1],
  [#table.hline()],
  [*Sum*], [0], [0], [0], [1], [1], [1],
)

The last carry is discarded. Thus, *32#sub[10] - 25#sub[10] = 7#sub[10] = 000111#sub[2]*.

#pagebreak()

= Exercise 5

The XOR operation returns *0* if both inputs are the same and *1* if both inputs are different.

#table(
  columns: (1fr, 1fr, 1fr, 1fr, 1fr, 1fr, 1fr, 1fr, 1fr),
  stroke: none,

  [*Input 1*], [#table.vline()], [1], [0], [0], [0], [1], [1], [1], [0],
  [*Input 2*], [1], [0], [1], [1], [1], [0], [0], [1],
  [#table.hline()],
  [*Result*], [0], [0], [1], [1], [0], [1], [1], [1],  
)

Thus, *10001110#sub[2] #sym.xor 10111001#sub[2] = 00110111#sub[2]*.
