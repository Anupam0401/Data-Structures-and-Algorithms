#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define max 50

int arr[max];

int **Convert2adjlist(int n,int (*M)[n]);
int **create2d(int n);
void readadjmat(int n,int (*Adjmat)[n],int m);

int main()
{
    int n,m;
    printf("Enter the size of adjacency matrix : ");
    scanf("%d",&n);
    int (*ADJMAT)[n] = create2d(n);
    // int ADJMAT[n][n];
    printf("\nEnter the number of edges : ");
    scanf("%d",&m);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            ADJMAT[i][j] = 0;
        }
    }
    printf("\n\n");

    readadjmat(n,ADJMAT,m);

/*           EXAMPLE
     ___ ___ ___ ___ ___ ___
    |   |v_0|v_1|v_2|v_3|v_4|
    |v_0| 0 | 1 | 0 | 1 | 1 |
    |v_1| 1 | 0 | 1 | 1 | 0 |
    |v_2| 1 | 1 | 0 | 1 | 1 |
    |v_3| 0 | 1 | 1 | 0 | 1 |
    |v_4| 1 | 1 | 0 | 1 | 0 |
*/

    printf("|   |");
    for(int i=0; i<n; i++)
    {
        printf("v_%d|",i);
    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        printf("|v_%d|",i);
        for(int j=0; j<n; j++)
        {
            printf(" %d |",ADJMAT[i][j]);
        }
        printf("\n");
    }

    int **list = Convert2adjlist(n,ADJMAT);

    printf("\n");
    // for(int i=0; i<n; i++)
    // {
    //     printf("\nNumber of edges from V_%d : %d",i,*(list+i));
    // }
    // printf("\n");

    for(int i=0; i<n; i++)
    {
        printf("Adjacency list of vertex %d :\t  ",i);
        for(int j=0; j<arr[i] ; j++)
        {
            printf("->  %d  ",list[i][j]);
        }
        printf("\n");
    }


    free(ADJMAT);
    free(list);

    return 0;
}


int **Convert2adjlist(int n,int (*M)[n])
{
    int **adjlist = (int *)calloc(n,sizeof(int));
    int count = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(M[i][j]==1)
                count = count + 1;
        }

        arr[i] = count;
        adjlist[i] = (int *)calloc(count,sizeof(int));

        int j=0,k=0;
        while(j<n && k<arr[i])
        {
            if(M[i][j]==1)
            {
                adjlist[i][k] = j;
                k++;
            }
            j++;
            // printf("%d\t",adjlist[i][j]);
        }
        count = 0;
    }

    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<arr[i]; j++)
    //     {
    //         if(M[i][j]==1)
    //             adjlist[i][j] = j;
    //         printf("%d\t",adjlist[i][j]);
    //     }
    // }

    return adjlist;
}

int **create2d(int n)
{
    int **M = (int*)calloc(n,sizeof(int));
    for(int i=0; i<n; i++)
    {
        M[i] = (int*)calloc(n,sizeof(int));
    }

    return M;
}

void readadjmat(int n,int (*Adjmat)[n],int m)
{
    printf("\nEnter the coordinates of the edges in the following manner (i,j)\n");
    int i = 0;
    while(i<m)
    {
        int k,l;
        scanf("%d%d",&k,&l);

        if(k==l)
        {
            i--;     //there can't be any edge at a single point
        }
        else if(Adjmat[k][l]==1)
        {
            printf("You already entered this coordinate.\n");
            i--;
        }
        else
            Adjmat[k][l] = 1;

        i++;
    }

    printf("\n\n");
}
