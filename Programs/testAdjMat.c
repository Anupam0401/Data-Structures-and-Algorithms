#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int **Convert2adjlist(int **M,int n);
int **create2d(int n);
void readadjmat(int **Adjmat,int m);

int main()
{
	int n,m;
	printf("Enter the size of adjacency matrix : ");
	scanf("%d",&n);
	int **ADJMAT = create2d(n);
	printf("\nEnter the number of edges : ");
	scanf("%d",&m);
	readadjmat(ADJMAT,m);

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			printf("%d\t",*(*(ADJMAT+i)+j));
		}
		printf("\n");
	}

	int **list = Convert2adjlist(ADJMAT,n);

	printf("\n");
	for(int i=0; i<n; i++)
	{
	    printf("\nEdges from V_%d are:",i);
	    for(int j=0;j<(int)sizeof(list[i])/sizeof(list[0]);j++)
        {
           //printf("%d\n",(int)(sizeof(list[i])/sizeof(list[0])));
            printf("%d , ",*(*(list+i)+j));
        }
	}
	printf("\b\b.\n\n");

	return 0;
}


int **Convert2adjlist(int **M,int n)
{
	int **adjlist;//= (int **)malloc(n*sizeof(int*));
	adjlist=(int**)calloc(n,sizeof(int*));
	int count = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(M[i][j]==1)
            {
				count = count + 1;
            }
		}
		adjlist[i] = (int*)calloc(count,sizeof(int));
		for(int j=0; j<n; j++)
		{
		    int k=0;
		    if(M[i][j]==1)
            {
                //printf("%d\n",j);
                adjlist[i][k]=j;
                k++;
               // printf("%d\n",*(*(adjlist+i)+j));
            }
		}
		count = 0;
	}
	return adjlist;
}

int **create2d(int n)
{
	int **M = (int *)calloc(n,sizeof(int));
	for(int i=0; i<n; i++)
	{
		M[i] = (int *)calloc(n,sizeof(int));
	}

	return M;
}

void readadjmat(int **Adjmat,int m)
{
	printf("\nEnter the coordinates of the edges in the following manner (i,j)");
	for(int i=0; i<m; i++)
	{
		int k,l;
		scanf("%d%d",&k,&l);
		if(k==l)
		{
			i = i-1;     //there can't be any edge at a single point
		}
		else
			Adjmat[k][l] = 1;
	}

	printf("\n\n");
}
