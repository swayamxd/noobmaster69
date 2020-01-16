# DAY-1
##### Max. Marks: 100
#### Joe has recently got his new collection of sci-fi novels. He arranges all books in a shelf. Because of his crazy rules, he only reads book from one of the ends of the shelf. Thus, each book Joe reads is either leftmost or rightmost book from the shelf. Joe cannot read a book if it has more than K chapters, again a crazy rule. When Joe has read a book, he removes it from the shelf. Joe stops when he is unable to read any book from any end of the shelf. How many books are still present in the shelf?

#### Input:

The first line of the input contains two integers N, the total number of books and K, the maximum number of chapters in a book which Joe can read.

The next  N lines denote the number of chapters in the ith book.

#### Output:

Print the number of books left in the shelf, when Joe stops reading.


#### Constraints:
1 <= N <= 10^5
1 <= K <= 10^9

| SAMPLE INPUT                                	| SAMPLE OUTPUT 	|
|---------------------------------------------	|---------------	|
| 8 4<br>4<br>3<br>4<br>2<br>5<br>1<br>6<br>4 	| 3             	|

#### Explanation
Joe can read books in the following order: [4,3,4,2,5,1,6 4]→[3,4,2,5,1,6 4]→[3,4,2,5,1,6]→[4,2,5,1,6]→[2,5,1,6]→[5,1,6]

So the number of books left in the shelf will be 3.

```console
Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded if any testcase passes.
Allowed Languages: C, C++, C++14, C#, Java, Java 8, Python, Python 3
```