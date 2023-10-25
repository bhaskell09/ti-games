PROGRAM:GCDCALC
:ClrHome
:Input "First number: ", A
:Input "Second number: ", B
:While B!=0
:If A>B
:A-AB/int(A/B)*B->A
:Else
:B-BB/int(B/A)*A->B
:EndWhile
:Disp "GCD is ", A