#include <bits/stdc++.h>
using namespace std;
struct Mytype
{
	int x,y;
};

//Stack code
vector< Mytype > stak(1000,{0,0});
int top=-1;
void push(Mytype val)
{
	top=top+1;
	stak[top]=val;
}
void pop()
{
	top=top-1;
}
Mytype topp()
{
	return stak[top];
}

//Checks if queen can be safely placed in this box
bool check(vector<vector<int>> &grid,Mytype indices,int n)
{
	int row,col,i,j;
	row=indices.x,col=indices.y;

	//Checks top column
	for(i=row-1;i>=0;i--)
	{
		if(grid[i][col]==1)
			return false;
	}
	//Checks top right diagnol
	for(i=row-1,j=col+1;i>=0 && j<n;i--,j++)
	{
		if(grid[i][j]==1)
			return false;
	}
	//Checks top left diagnol
	for(i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
	{
		if(grid[i][j]==1)
			return false;
	}
	return true;
}
int main()
{
	int t,i,j,n,ans=0;
	cout<<"Enter size of grid n: ";
	cin>>n;
	vector<int> roww(n,0);
	Mytype indices;	// x and y coordinates
	vector<vector<int>> grid(n,roww);	// Stores location of queen
	push({0,0});
	grid[0][0]=1;
	// We keep checking till we place n queens or we fail to place them
	while(top<n and (top!=-1))
	{
		int row,col;
		indices=topp();
		row=indices.x,col=indices.y;

		if(col>(n-1)) // If queen is placed outside the grid
		{
			pop();
			if(top==-1)
				break;
			indices=topp();
			row=indices.x,col=indices.y;
			pop();
			grid[row][col]=0;
			push({row,col+1});
			grid[row][col+1]=1;
			continue;
		}
		// Checks if it is safe to place in (row,col)
		if(check(grid,indices,n)==true)
		{	
			if(row==(n-1))
			{
				ans=1; // Solution found
				break;
			}
			push({row+1,0});
			grid[row+1][0]=1;
		}
		// If it is not safe, change the location of previous queen
		else
		{
			pop();
			grid[row][col]=0;
			push({row,col+1});
			grid[row][col+1]=1;
		}
	}
	// Solution not found
	if(ans==0)
		cout<<"Solution doesn't exist"<<endl;
	else
	{
		// Print the grid with "q" as queen and "_" as empty space
		cout<<"The grid with 'q' as queen and '_' as empty space"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(grid[i][j]==0)
					cout<<"_"<<" ";
				else
					cout<<"q"<<" ";
			}
			cout<<endl;
		}
	}
}