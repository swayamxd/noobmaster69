# DAY 3
##### Max. Marks: 100
#### Saksham is shopping in a super market which provides a superb offer. If a customer purchases exactly (but not necessarily distinct) n items such that the total cost is divisible by m, a massive cashback is provided. There are l different categories of products with every category having an infinite amount of products. Saksham being a geek, wonders how many possible ways are there to purchase items in such a way that he could get the cashback. Help him find the number of ways possible to make the purchase. As this number can be large, you need to print the answer modulo 10^9 + 7.

#### Input
The first line of input contains three space separated integers n, m and l.
The second line of the input contains l space separated integers denoting the cost of each product type.

#### Output
You have to print one line, the number of different ways to purchase the items in order to get the cashback, modulo 10^9 + 7.

#### Constraints
1<= n <=10^5
1<= m <=10
1<= l <=10^5
1<= li <=10^9

#### Explanation
Saksham can buy two products of type 3, i.e (3,3) then the total price will be divisible by 3
Also, he can buy one product of type 1 and 1 product of type 2 in two ways, i.e, (1,2) and (2,1)
So, in total there are 3 possible ways.

```console
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded if any testcase passes.
Allowed Languages:	Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
```