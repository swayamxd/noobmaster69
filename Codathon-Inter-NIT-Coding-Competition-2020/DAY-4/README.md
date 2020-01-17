# DAY 4
##### Max. Marks: 100
#### Jatin is a geek and is often called the “X guy” in the college because of his obsession with the number X as he never spends more than Rs. X on any single occasion. Jatin plans to visit “La La State” during the vacations. He searched to know the physical distribution of the state and found that the state consists of N cities. Being a geek, he observed closely and came to know that the state is nothing but a tree having exactly N-1 roads between the cities but the ingenious government aware of the popularity of the state, imposed taxes to travel on any of these roads. Being a friend of Jatin, give the number of possible pairs of cities he can travel on his trip. A pair containing 2 cities say (A, B) means that Jatin can travel from city A to city B via some path in the state.

##### Note - Single occasion refers to any single moment. For this trip, an occasion will be any toll tax he passes through i.e. for any particular road he won’t give more than Rs. X.

#### Input
- The first line of input contains a single positive integer N denoting the number of cities
- Each of the next N-1 lines contains 3 space-separated integers U, V and W denoting that there is a road between the city U and city V with the imposed tax of Rs. W i.e. to travel on the road a tax of Rs W needs to be paid
- The next line of input contains a single positive integer Q denoting the number of queries.
- Each of the next Q lines contains X for the query

#### Output
For each query, print the single integer answer for the query i.e. For query’s given 'X', print number of possible pairs of cities he can travel on his trip as described in the statement above

#### Constraints

1<= N <= 10^5
1<= W <= 10^9
1<= Q <= 10^5
1<= X <= 10^9

| SAMPLE INPUT                                                  	| SAMPLE OUTPUT 	|
|---------------------------------------------------------------	|---------------	|
| 6<br>1 2 2<br>2 3 4<br>3 4 3<br>3 5 5<br>3 6 4<br>2<br>3<br>4 	|    2<br>10    	|

#### Explanation
For X=3,  Possible pairs Jatin can travel is (1,2),(3,4)
For X=4,  Possible pairs Jatin can travel is (1,2),(2,3),(3,4),(3,6),(1,3),(2,4),(2,6),(6,4),(1,4),(1,6)

```
Time Limit:	0.5 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded if any testcase passes.
Allowed Languages:	Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic
```