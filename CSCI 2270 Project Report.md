

Zachary Colleran

CSCI 2270

Asa Ashraf

7/19/2022

CSCI 2270 Project Report

We were tasked to store a list of 10,000 IDs 3 different ways; Using a Double

Linked List, Hash Table with BST Chaining, and Hash Table with Double Hashing. To

check the time complexity, we calculated the time it takes to insert and search for IDs

stored in each data structure. We did this by:

**Inserting 200 IDs -> Searching 200 IDs -> Repeat (50 times)**

This way we could evaluate the time complexity of each data structure as the number of

IDs stored increased. We also check the number of collisions the Hash Tables have as

the # of IDs stored increases.





**Double Linked List**

Inserting 200 IDs into a Double Linked List 50 times

160

140

120

100

80

60

40

20

0

0

10

20

30

40

50

60

Iteration

Searching for 200 IDs in a Double Linked List 50 times

20000

18000

16000

14000

12000

10000

8000

6000

4000

2000

0

0

10

20

30

40

50

60

Iteration





**Hash Table with Double Hashing**

Inserting 200 IDs into a Hash Table with Double Hashing

300

250

200

150

100

50

0

0

10

20

30

40

50

60

Iteration

Searching for 200 IDs in a Hash Table with Double Hashing

200

180

160

140

120

100

80

60

40

20

0

0

10

20

30

40

50

60

Iteration





**Double Hashing Collisions**

\# of Collisions when Inserting 200 IDs into a Hash Table

with Double Hashing

120

100

80

60

40

20

0

0

10

20

30

40

50

60

Iteration

\# of Collions when Searching for 200 IDs into a Hash Table

with Double Hashing

90

80

70

60

50

40

30

20

10

0

0

10

20

30

40

50

60

Iteration





**Hash Table with BST Chaining**

Inserting 200 IDs into a Hash Table with BST Chaining

250

200

150

100

50

0

0

10

20

30

40

50

60

Iteration

Searching for 200 IDs in a Hash Table with BST Chaining

180

160

140

120

100

80

60

40

20

0

0

10

20

30

40

50

60

Iteration





**BST Chaining Collisions**

\# of Collisions when Inserting 200 IDs into a Hash Table

with BST Chaining

120

100

80

60

40

20

0

0

10

20

30

40

50

60

Iteration

\# of Collisions when searching for 200 IDs in a Hash Table

with BST Chaining

80

70

60

50

40

30

20

10

0

0

10

20

30

40

50

60

Iterations





**Comparing Double Linked List and Hash Table with BST Chaining**

Inserting 200 IDs Comparing Double LL and Hashing with

BST Chaining

250

200

150

100

50

0

0

10

20

30

40

50

60

Iterations

Double LL

HashBST

Searching 200 IDs Comparing Double LL and Hashing with

BST Chaining

20000

18000

16000

14000

12000

10000

8000

6000

4000

2000

0

0

10

20

30

40

50

60

Iterations

Double LL

HashBST





**Conclusion**

From the comparison we can see that inserting into a Hash Table and a Double

Linked List is very similar with the Double Linked List having a slight edge. Looking at

the search comparison however, we can see the Hash Table with BST Chaining is

immensely quicker than a Double Linked List. This conclusion makes sense because

inserting into a Linked List and a Hash Table has the same time complexity O(1). On

the other hand, searching in a Linked list has a time complexity of O(n) while a Hash

Table is O(1).


