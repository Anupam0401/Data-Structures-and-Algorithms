#include <bits/stdc++.h>
using namespace std;

//queue code
vector<char> que(1000,' ');
int front=-1,rear=-1;
void enqueue(char val)
{
	if(front==-1)
		front++;

	rear++;
	que[rear]=val;
}
void dequeue()
{
	front++;
}
char frontt()
{
	return que[front];
}


int main()
{
	int n,i;
	cout<<"Enter size of input n: ";
	cin>>n;
	vector<char> array(n,' '); // stores input
	vector<int> freq(26,0); //stores frequency of characters 
	cout<<"Enter n space separated characters"<<endl;
	for(i=0;i<n;i++)
	{
		cin>>array[i]; //Takes input
	}
	if(n>0) // Checks if size of input is not 0
	{
		cout<<"Output is:"<<endl;
		cout<<array[0]<<" ";
		freq[array[0]-'a']=1;
		enqueue(array[0]);
	}
	for(i=1;i<n;i++)
	{
		if(freq[array[i]-'a']==0) //Element is found for the first time
		{
			enqueue(array[i]);
			cout<<frontt()<<" ";
			freq[array[i]-'a']++;
		}
		else
		{
			freq[array[i]-'a']++;
			if(freq[frontt()-'a']>1) //Element is found more then once
				dequeue();
			if(front>rear) // Queue size is empty
				cout<<"- ";
			else
				cout<<frontt()<<" ";
		}
	}
}