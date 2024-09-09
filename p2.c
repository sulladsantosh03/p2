#include<stdio.h>
#include<time.h>
int n,a[50][50],i,j,count=0,reach[50],pos[50];
int main()
{
        int v;
        double clk;
        clock_t starttime,endtime;
        printf("\n\t\t\t DEPTH FIRST SEARCH \n");
        printf("\n Enter number of Lands to be surveyed:");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
       {	
          	pos[i]=0;
       }
        read_matrix();
        printf("\n Enter the starting Land number:");
        scanf("%d",&v);
        starttime=clock();
        dfs(v);
        endtime=clock();
        clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
        printf("\n Vertices reached from the given vertex are...\n");
       for(i=1;i<=count;i++)
       {
	printf("%d\t",reach[i]);
       }
        printf("\nThe run time is %f\n",clk);
}

read_matrix()
{
	printf("\n Enter the adjacency matrix (Enter 0/1)\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(i!=j)
	{
		printf("(%d,%d):",i,j);
		scanf("%d",&a[i][j]);
	}
}

dfs(int v)
{
	int u;
	reach[++count]=v;
	u=adjacent(v);
	while(u)
	{
		if(checkreach(u)==0) dfs(u);
		u=adjacent(v);
	}
}
adjacent(int i)
{
	for(j=pos[i]+1;j<=n;j++)
	if(a[i][j]==1)
	{
		pos[i]=j;
		return j;
	}
	pos[i]=n+1;
	return 0;
}
checkreach(int u)
{
	for(i=1;i<=count;i++)
	if(reach[i]==u)
		return 1;
	return 0;
}
/*
DEPTH FIRST SEARCH
	Enter number of Lands to be surveyed:  5
	Enter the starting Land number: 1
	Enter the adjacency matrix: 

	0 1 1 1 0
0 0 0 0 1
0 0 0 0 0 
0 0 0 0 0  
0 0 0 0 0 

	Vertices reached from the given vertex are...
	1  2
2  5
1  3
1  4
*/
