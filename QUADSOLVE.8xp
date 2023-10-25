:"QUADSOLVE"
:Prompt A,B,C
:ClrHome
:Disp "VERTEX FORM:"
:Output(3,1,"Y=A(X-H)²+K
:Output(4,1,"VERTEX: (H,K)
:Output(6,1,"Y-INTERCEPT:"
:(0,0→L₁
:For(X,0,10,1)
:A(X→Y₁
:B(X²→Y₂
:C→Y₃
:Y₁+Y₂+Y₃→L₁(X
:End
:DelVar Y₁
:DelVar Y₂
:DelVar Y₃
:SortA(L₁,L₁
:1→dim(L₁
:Output(5,1,"(",L₁(1),",0)"
:Output(3,10,"Y=",A,"(X-",L₁(1),")²+",C-L₁(1)²A