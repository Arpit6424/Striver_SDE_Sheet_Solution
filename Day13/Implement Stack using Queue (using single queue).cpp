
 





















Stack using queue
Difficulty: MEDIUM
Contributed By
Amandeep Kaur
|
Level 1
Avg. time to solve
25 min
Success Rate
65%
Problem Statement
Implement a Stack Data Structure specifically to store integer data using two Queues.
There should be two data members, both being Queues to store the data internally. You may use the inbuilt Queue.
Implement the following public functions :
1. Constructor:
It initializes the data members(queues) as required.

2. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

3. pop() :
It pops the element from the top of the stack and, in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.

4. top :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.

5. size() :
It returns the size of the stack at any given instance of time.

6. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.
Operations Performed On The Stack:
Query-1(Denoted by an integer 1): Pushes an integer data to the stack. (push function)

Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack and returns it to the caller. (pop function)

Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack but doesn't remove it, unlike the pop function. (top function)

Query-4(Denoted by an integer 4): Returns the current size of the stack. (size function)

Query-5(Denoted by an integer 5): Returns a boolean value denoting whether the stack is empty or not. (isEmpty function)
Input Format:
The first line contains an integer 'Q’, which denotes the number of queries to be run against each operation in the stack. 

The next 'Q' lines represent an operation that needs to be performed.

For the push operation, the input line will contain two integers separated by a single space, representing the type of the operation in integer and the integer data being pushed into the stack.

For the rest of the operations on the stack, the input line will contain only one integer value, representing the query being performed on the stack.
Output Format:
For Query-1, you do not need to return anything.

For Query-2, prints the data being popped from the stack.

For Query-3, print the data kept on the top of the stack.

For Query-4, print the current size of the stack.

For Query-5, print 'true' or 'false'(without quotes).

Output for every query will be printed in a separate line.
Note:
You are not required to print anything explicitly. It has already been taken care of. Just implement the function.
Constraints:
1 <= Q <= 1000
1 <= query type <= 5
-10^9 <= data <= 10^9 and data != -1

Where 'Q' is the total number of queries being performed on the stack and data represents the integer pushed into the stack. 

Time Limit: 1 second
Sample Input 1:
6
1 13
1 47
4
5
2
3
Sample Output 1:
2
false
47
13
Explanation Of The Sample Input 1:
Here we have six queries in total.

Query 1: Integer 1 represents the push function. Hence we push element ‘13’ onto the stack.

Query 2: Integer 1 represents the push function. Hence we push element ‘47’ onto the stack.

Query 3: Integer 4 represents the size function. Hence we print the size of the stack that is 2.

Query 4: Integer 5 represents the isEmpty function. Hence here, we print false because the stack is not empty.

Query 5: Integer 2 represents the pop function. The stack contains element ‘47’ at the top. We remove/pop ‘47’ from the stack and print ‘47’ on the new line.

Query 6: Integer 3 represents the top function. Because we have element ‘13’ at the top of the stack, we print ‘13’ on the new line.
Previous
Next
 
1
#include<bits/stdc++.h>
2
class Stack {
3
    // Define the data members.
4
      queue<int> q;
5
   public:
6
    Stack() {
7
        // Implement the Constructor.
8
    }
9
​
10
    /*----------------- Public Functions of Stack -----------------*/
11
​
12
    int getSize() {
13
       return  q.size();
14
    }
15
​
16
    bool isEmpty() {
17
        return q.empty();
18
    }
19
​
20
    void push(int element) {
21
        int size = q.size();
22
        q.push(element);
23
        while(size--){
24
            q.push(q.front());
25
            q.pop();
26
        }
27
    }
28
​
29
    int pop() {
30
        if(q.empty())return -1;
31
        int element = q.front();
32
        q.pop();
33
        return element;
34
    }
35
​
36
    int top() {
37
        if(q.empty())return -1;
38
        return q.front();
39
    }
40
};
Saving Code...
