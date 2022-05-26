#include <bits/stdc++.h>
using namespace std;
struct Mytype
{
	int x,y,direction;
};
//Stack code
// Stack stores { x-cord,y-cord,Direction of knight }
vector< Mytype > stak(1000,{0,0,0});
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

int main()
{
	int n,i,j,k;
	cout<<"Enter size of grid n: ";
	cin>>n;
	vector<int> row(n,0);
	Mytype ind;
	vector<vector<int>> grid(n,row); // To mark visited boxes
	push({0,0,0});
	grid[0][0]=1;
	// The 8 possible directions of movements of knight
	vector<pair<int,int>> iteration{ {-1,-2} , {-1,2} , {1,-2} , {1,2} , {-2,-1} , {-2,1} , {2,-1} , {2,1} };
	
	while(top!=-1) //Stack not empty
	{
		int row,col,ROW,COL;
		ind=topp();
		row=(ind.x),col=(ind.y);
		int check=0;
		// Checks 8 possible directions on movement
		for(i=ind.direction;i<8;i++)
		{
			ROW=row+(iteration[i].first),COL=col+(iteration[i].second);
			if((ROW>=0 and ROW <n)and(COL>=0 and COL <n)) // Box is inside the grid
			{
				if(grid[ROW][COL]==0) // Box is not visited
				{
					pop();
					push({row,col,i+1}); // This knight checked i/8 directons
					push({ROW,COL,0});
					grid[ROW][COL]=1;
					check=1; // Atleast 1 direction is valid
					break;
				}
			}
		}
		if((top+1)==(n*n)) // We found a solution as all boxes are visited
			break;
		if(check==0) // This knight has nowhere to move
		{
			if(top==-1) // Solution doesn't exist
				break;

			ind=topp();
			row=(ind.x),col=(ind.y);
			// Clear the previously visited box
			pop();
			grid[row][col]=0;
		}
	}

	if(top==-1) // Stack is empty
		cout<<"Solution doesn't exist"<<endl;
	else
	{
		vector<Mytype> answer(n*n,{0,0,0});
		i=(n*n);
		//Stores coordinates of steps
		while(top!=-1)
		{
			i--;
			ind=topp();
			pop();
			answer[i].x=(ind.x);
			answer[i].y=(ind.y);
		}
		// Prints the sequence of steps of knight tour
		cout<<"The sequence of steps are:"<<endl;
		for(i=0,k=0;i<n;i++)
		{
			for(j=0;j<n;j++,k++)
			{
				cout<<"("<<answer[k].x<<","<<answer[k].y<<")";
				if(k!=(n*n-1))
					cout<<" -> ";
			}
			cout<<endl;
		}
	}
}