Circular linked list
Functions used :-
1.newNode() : creates a new node and assigns the next and the prev NODE variables as NULL.
2.delete(list,n) : deletes a node containg n in its data by detaching its link from the list and returns head node.
3.insertSorted(list,n) : inserts a node at a suitable position in the list such that it remains sorted and returns head node.
4.updateSorted(list,o,n) : deletes the node containing yhe nnumber o and inserts the node with number n in suitable position such that the list is sorted and returns head node.
5.print(head) : accepts the head node and prints the data of all the node linked to head node in the list.

The user provide list elements in ascending order and the list remains sorted till the end.
**In case of updateSorted() , the user must enter the number present in the list and if more than two numbers in the node are same , it just updates the 1st element.
This program works very well even if you wish to insert or update a number at the beginning or end of the mode.


 