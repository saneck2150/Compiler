
#################################### 
VER: 1.0
####################################

This is a student-made simple compiler based on C++

The grammar of the compiler is very simple:

<program> ::= <statement>
<statement> ::= "if" <paren-expr> <statement> |
                 "if" <paren-expr> <statement> "else" <statement> |
                 "while" <paren-expr> <statement> |
                 "{" { <statement> } "}" |
                 <expr> ";" |
                 ";"
<paren-expr> ::= "(" <expr> ")"
<expr> ::= <test> | <id> "=" <expr>
<test> ::= <sum> | <sum> "<" <sum>
<sum>  ::= <term> | <sum> "+" <term> | <sum> "-" <term>
<term> ::= <id> | <int> | <paren-expr>
<var>   ::= "a" | "b" | ... | "z"

For variables suported only 1 uppercase letter A to Z
For numbers - 0 to 9;

Example of code:

int a;
int b = 1;
a = 2;
if(a < b)
{
    a = b;
}
else
{
    while(b < a)
    {
      b = b + 1;
    }
}