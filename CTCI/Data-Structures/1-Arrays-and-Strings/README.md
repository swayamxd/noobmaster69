# Interview Questions

### 1.1 Is Unique:
#### Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
Hints:
```
#44: Try a hash table.
#117: Could a bit vector be useful?
#132: Can you solve it in O(N log N) time? What might a solution like that look like?
```

### 1.2 Check Permutation:
#### Given two strings, write a method to decide if one is a permutation of the other.
Hints:
```
#1: Describe what it means for two strings to be permutations of each other. Now, look at that definition you provided. Can you check the strings against that definition?
#84: There is one solution that is 0 (N log N) time. Another solution uses some space, but isO(N) time.
#122: Could a hash table be useful?
#131: Two strings that are permutations should have the same characters, but in different orders. Can you make the orders the same?
```

### 1.3 URLify:
#### Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters, and that you are given the "true" length of the string.
(Note: If implementing in Java, please use a character array so that you can perform this operation in place.)

EXAMPLE
```
Input: "Mr John Smith", 13
Output: "Mr%20John%20Smith"
```
Hints:
```
#53: It's often easiest to modify strings by going from the end of the string to the beginning.
#178: If we knew the number of paths to each of the steps before step 100, could we compute the number of steps to 1OO?
```

### 1.4 Palindrome Permutation:
#### Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
EXAMPLE
```
Input: Tact Coa
Output: True (permutations: "taco cat". "atco cta". etc.)
```
Hints:
```
#106: You do not have to-and should not-generate all permutations. This would be very inefficient.
#121: What characteristics would a string that is a permutation of a palindrome have?
#134: Have you tried a hash table? You should be able to get this down to 0 (N) time.
#136: Can you reduce the space usage by using a bit vector?
```

### 1.5 One Away:
#### There are three types of edits that can be performed on strings: insert a character, remove a character, or replace a character. Given two strings, write a function to check if they are one edit (or zero edits) away.
EXAMPLE
```
pale, pIe -> true
pales. pale -> true
pale. bale -> true
pale. bake -> false
```
Hints:
```
#23: Start with the easy thing. Can you check each of the conditions separately?
#97: What is the relationship between the "insert character" option and the "remove character" option? Do these need to be two separate checks?
#130: Can you do all three checks in a single pass?
```

### 1.6 String Compression:
#### Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has only uppercase and lowercase letters (a - z).
Hints:
```
#92: Do the easy thing first. Compress the string, then compare the lengths.
#110: Be careful that you aren't repeatedly concatenating strings together. This can be very inefficient.
```

### 1.7 Rotate Matrix:
#### Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. (an you do this in place?
Hints:
```
#51: Try thinking about it layer by layer. Can you rotate a specific layer?
#100: Rotating a specific layer would just mean swapping the values in four arrays. If you were asked to swap the values in two arrays, could you do this? Can you then extend it to four arrays?
```

### 1.8 Zero Matrix:
#### Write an algorithm such that if an element in an MxN matrix is 0, its entire row and column are set to O.
Hints:
```
#17: If you just cleared the rows and columns as you found Os, you'd likely wind up clearing the whole matrix. Try finding the cells with zeros first before making any changes to the matrix.
#74: Can you use 0 (N) additional space instead of 0 (N2 )? What information do you really need from the list of cells that are zero?
#102: You probably need some data storage to maintain a list of the rows and columns that need to be zeroed. Can you reduce the additional space usage to a (1) by using the matrix itself for data storage?
```

### 1.9 String Rotation:
#### Assume you have a method isSubst ring which checks if one word is a substring of another. Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one call to isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
Hints:
```
#34: If a string is a rotation of another, then it's a rotation at a particular point. For example, a rotation of water bottle at character 3 means cutting waterbottle at character 3 and putting the right half (erbottle) before the left half (wat).
#88: We are essentially asking if there's a way of splitting the first string into two parts, x and y, such that the first string is xy and the second string is yx. For example, x = wat and y = erbottle. The first string is xy = waterbottle. The second string is yx = erbottlewat.
#104: Think about the earlier hint. Then think about what happens when you concatenate erbottlewat to itself. You get erbottlewaterbottlewat.
```