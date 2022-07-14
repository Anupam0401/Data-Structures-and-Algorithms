#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;

// stores the detils of the node : min represents left child , max represents right child
struct NodeDetails
{
	int data;
	int min, max;
};

int main()
{
	cout<<"Enter the number of elements"<<endl;
    int n;
    cin>>n;
	int arr[n] ={0};
    cout<<"\nEnter the elements in level order of a perfect BST"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }	
    if (n == 0){ //empty BST case
		cout << "Valid BST"<<endl;
        return 0;
    }
	
	// queue to store NodeDetails
	queue<NodeDetails> q;
	
	// index variable to access array elements
	int i=0;
	
	// root of the BST
	NodeDetails newNode;
	newNode.data = arr[i++];
	newNode.min = INT_MIN;
	newNode.max = INT_MAX;
	q.push(newNode);
	
	//executes till arr is empty or queue is empty
	while (i != n && !q.empty())		
	{
		NodeDetails temp = q.front();
		q.pop();
		
		if (i < n && (arr[i] < temp.data && arr[i] > temp.min))
		{
			//add the newNode to queue
			newNode.data = arr[i++];
			newNode.min = temp.min;
			newNode.max = temp.data;
			q.push(newNode);				
		}
		
		if (i < n && (arr[i] > temp.data && arr[i] < temp.max))
		{
			//add the newNode to the queue
			newNode.data = arr[i++];
			newNode.min = temp.data;
			newNode.max = temp.max;
			q.push(newNode);			
		}
	}
	
	if (i == n){
		cout << "Valid BST"<<endl;
        return 0;
    }
		
	cout << "Invalid BST"<<endl;			
	return 0;	
}
