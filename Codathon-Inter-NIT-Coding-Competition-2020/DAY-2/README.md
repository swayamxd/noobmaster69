# DAY 2
##### Max. Marks: 100
#### You are given a N x N matrix and have to perform Q queries on it. Queries are of 2 types:
a) 1 a b c : For each element eij (a<=i<=b) and (1<=j<=N) in the matrix, eij = eij (exor) c
b) 2 a b c : For each element eij (1<=i<=N) and (a<=j<=b) in the matrix, eij = eij (exor) c
After these queries are performed, print the sum of the diagonal (top left to bottom right) elements.

#### Input:
The first line contains an integer denoting N
The next N lines contains N space separated integers
The next line contains an integer denoting Q
The next Q lines contain 4 space separated integers depending on the type of query

#### Output:
A single line denoting the sum of diagonal elements of the final matrix

#### Constraints:
1 <= N <= 10^5
1 <= K <= 10^9

#### NOTE: Use fast I/O.

| SAMPLE INPUT                                 	| SAMPLE OUTPUT 	|
|----------------------------------------------	|---------------	|
| 3<br>2 3 1<br>3 2 1<br>4 3 2<br>1<br>1 2 3 2 	| 2             	|


```console
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded if any testcase passes.
Allowed Languages:	Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
```