:ClrHome
:Input "A: ",A
:Input "B: ",B
:Input "C: ",C
:Disp "Factors: "
:For(X,-10,10)  // You can adjust the range of X based on the coefficients of your quadratic equation
:If fPart(A(X^2)+B(X)+C)=0
:Then
:Output(3,1,X
:Output(3,5,":"
:Output(3,6,A(X^2)+B(X)+C
:Output(3,10,","
:Output(3,11,(A
:Output(3,14,","
:Output(3,15,B
:Output(3,18,","
:Output(3,19,C
:Output(4,1,"---"
:End