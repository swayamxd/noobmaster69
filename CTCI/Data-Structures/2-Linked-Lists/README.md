# Interview Questions

### 2.1 Remove Dups:
#### Write code to remove duplicates from an unsorted linked list.
FOLLOW UP
#### How would you solve this problem if a temporary buffer is not allowed?
Hints:
```
#9: Have you tried a hash table? You should be able to do this in a single pass of the linked list.
#40: Without extra space, you'll need a (N2) time. Try using two pointers, where the second one searches ahead of the first one.
```
### 2.2 Return Kth to Last:
#### Implement an algorithm to find the kth to last element of a singly linked list.
Hints:
```
#8: What if you knew the linked list size? What is the difference between finding the Kth-tolast element and finding the Xth element?
#25: If you don't know the linked list size, can you compute it? How does this impact the runtime?
#41: Try implementing it recursively. If you could find the (K -l)th to last element, can you find the Kth element?
#67: You might find it useful to return multiple values. Some languages don't directly support this, but there are workarounds in essentially any language. What are some of those workarounds?
#126: Can you do it iteratively? Imagine if you had two pOinters pointing to adjacent nodes and they were moving at the same speed through the linked list. When one hits the end of the linked list, where will the other be?
```

### 2.3 Delete Middle Node:
#### Implement an algorithm to delete a node in the middle (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
EXAMPLE
```
Input: the node c from the linked list a - >b- >c - >d - >e- >f
Result: nothing is returned, but the new linked list looks like a - >b- >d - >e- >f
```
Hints:
```
#72: Picture the list 1- > 5 - >9 - > 12. Removing 9 would make it look like 1- > 5 - > 12. You only have access to the 9 node. Can you make it look like the correct answer?
```

### 2.4 Partition:
#### Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x. lf x is contained within the list, the values of x only need to be after the elements less than x (see below). The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.
EXAMPLE
```
Input: 3 -> 5 -> 8 -> 5 - > 10 -> 2 -> 1 [partition = 5)
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
```
Hints:
```
#3: There are many solutions to this problem, most of which are equally optimal in runtime. Some have shorter, cleaner code than others. Can you brainstorm different solutions?
#24: Consider that the elements don't have to stay in the same relative order. We only need to ensure that elements less than the pivot must be before elements greater than the pivot. Does that help you come up with more solutions?
```

### 2.5 Sum Lists:
#### You have two numbers represented by a linked list, where each node contains a singledigit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.
EXAMPLE
```
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.
```
FOLLOW UP
#### Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
```
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).Thatis,617 + 295.
Output: 9 -> 1 -> 2. That is, 912.
```
Hints:
```
#7: Of course, you could convert the linked lists to integers, compute the sum, and then convert it back to a new linked list. If you did this in an interview, your interviewer would likely accept the answer, and then see if you could do this without converting it to a number and back.
#30: Try recursion. Suppose you have two lists, A = 1- >5 - >9 (representing 951) and B 2 - > 3 - >6 - > 7 (representing 7632), and a function that operates on the remainder of the lists (5 - >9 and 3- >6 - > 7). Could you use this to create the sum method? What is the relationship between sum(1->5->9, 2->3->6->7) and sum(5->9, 3->6->7)?
#71: Make sure you have considered linked lists that are not the same length.
#95: Does your algorithm work on linked lists like 9->7->8 and 6->8->5? Double check that.
#109: For the follow-up question: The issue is that when the linked lists aren't the same length, the head of one linked list might represent the 1000's place while the other represents the 1 D's place. What if you made them the same length? Is there a way to modify the linked list to do that, without changing the value it represents?
```

### 2.6 Palindrome:
#### Implement a function to check if a linked list is a palindrome.
Hints:
```
#5: A palindrome is something which is the same when written forwards and backwards. What if you reversed the linked list?
#13: Try using a stack.
#29: Assume you have the length of the linked list. Can you implement this recursively?
#61: In the recursive approach (we have the length of the list), the middle is the base case: iSPermutation(middle) is true. The node x to the immediate left of the middle: What can that node do to check if x- >middle- >y forms a palindrome? Now suppose that checks out. What about the previous node a? If x- >middle- >y is a palindrome, how can it check that a - >x - >middle - >y- >b is a palindrome?
#101: Go back to the previous hint. Remember: There are ways to return multiple values. You can do this with a new class.
```

### 2.7 Intersection:
#### Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node. Note that the intersection is defined based on reference, not value. That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting.
Hints:
```
#20: You can do this in 0 (A+B) time and 0 (1) additional space. That is, you do not need a hash table (although you could do it with one).
#45: Examples will help you. Draw a picture of intersecting linked lists and two equivalent linked lists (by value) that do not intersect.
#55: Focus first on just identifying if there's an intersection.
#65: Observe that two intersecting linked lists will always have the same last node. Once they intersect, all the nodes after that will be equal.
#76: You can determine if two linked lists intersect by traversing to the end of each and comparing their tails.
#93: Now, you need to find where the linked lists intersect. Suppose the linked lists were the same length. How could you do this?
#111: If the two linked lists were the same length, you could traverse forward in each until you found an element in common. Now, how do you adjust this for lists of different lengths?
#120: Try using the difference between the lengths of the two linked lists.
#129: If you move a pointer in the longer linked list forward by the difference in lengths, you can then apply a similar approach to the scenario when the linked lists are equal.
```

### 2.8 Loop Detection:
#### Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
DEFINITION
#### Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
EXAMPLE
```
Input: A -) B -) C -) 0 -) E - ) C[thesameCasearlierl
Output: C
```
Hints
```
#50: There are really two parts to this problem. First, detect if the linked list has a loop. Second, figure out where the loop starts.
#69: To identify if there's a cycle, try the "runner" approach described on page 93. Have one pointer move faster than the other.
#83: You can use two pointers, one moving twice as fast as the other. If there is a cycle, the two pointers will collide. They will land at the same location at the same time. Where do they land? Why there?
#90: If you haven't identified the pattern of where the two pointers start, try this: Use the linked list 1->2->3->4->5->6->7->8->9->?, where the? links to another node. Try making the? the first node (that is, the 9 points to the 1 such that the entire linked list is a loop). Then make the? the node 2. Then the node 3. Then the node 4. What is the pattern? Can you explain why this happens?
```