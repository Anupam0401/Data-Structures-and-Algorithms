Double linked list
Functions used :-
1.newNode() : creates a new node and assigns the next and the prev NODE variables as NULL.
2.isEmpty(list) : checks whether the node is empty or not and returns 1 if list is empty.
3.append(list,n) :  adds a node and links it to the end of the list and returns the head node.
4.delete(list,n) : deletes a node containg n in its data by detaching its link from the list and returns head node.
5.insertSorted(list,n) : inserts a node at a suitable position in the list such that it remains sorted and returns head node.
6.updateSorted(list,o,n) : deletes the node containing yhe nnumber o and inserts the node with number n in suitable position such that the list is sorted and returns head node.
7.print(head) : accepts the head node and prints the data of all the node linked to head node in the list.

The user provide list elements in ascending order and the list remains sorted till the end.
**In case of updateSorted() , the user must enter the number present in the list.
Also, this program works very well even if you wish to insert or update a number at the beginning or end of the mode.


 