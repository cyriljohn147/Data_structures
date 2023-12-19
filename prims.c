//PRIMS ALGORITHM IMPLEMENTATION

#include<stdio.h>
#include<stdlib.h>
#define infinity 9999
#define MAX 20

int G[MAX][MAX],spanning[MAX][MAX],n;

int prims()
{
  int u,v,i,j,min_distance,min_cost,no_of_edges;
  int cost[MAX][MAX],distance[MAX],visited[MAX],from[MAX];


  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
      if(G[i][j]==0)
      cost[i][j]=infinity;

      else
        cost[i][j]=G[i][j];
      
      spanning[i][j]=0;
    }//initialise visited[],distance[] and from[]

  distance[0]=0;
  visited[0]=1;

  for(i=1;i<n;i++)
  {
    distance[i]=cost[0][i];
    from[i]=0;
    visited[i]=0;
  }

  min_cost=0; //cost of spanning tree
  no_of_edges=n-1; //no. of edges to be added

  while(no_of_edges>0)
  {
    //find the vertex at minimum distance from the tree
    min_distance=infinity;
    
    for(i=1;i<n;i++)
      if(visited[i]==0&&distance[i]<min_distance)
      {
        v=i;
        min_distance=distance[i];
      }
    u=from[v];
    
    //insert the edge in spanning tree
    spanning[u][v]=distance[v];
    spanning[v][u]=distance[v];
    no_of_edges--;
    visited[v]=1;

    //updated the distance[] array
    for(i=1;i<n;i++)
      if(visited[i]==0&&cost[i][v]<distance[i])
      {
        distance[i]=cost[i][v];
        from[i]=v;
      }
    min_cost=min_cost+cost[u][v];
  }

  return(min_cost);
}

int main()
{
  int i,j,total_cost;
  printf("Enter no. of vertices:");
  scanf("%d",&n);
  printf("\nEnter the adjacency matrix:\n");

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d",&G[i][j]);

  total_cost=prims();
  printf("\nspanning tree matrix:\n");

  for(i=0;i<n;i++)
  {
    printf("\n");
    
    for(j=0;j<n;j++)
      printf("%d\t",spanning[i][j]);
  }

  printf("\n\nTotal cost of spanning tree=%d",total_cost);
  return 0;
}

// 0 3 1 6 0 0
// 3 0 5 0 3 0
// 1 5 0 5 6 4
// 6 0 5 0 0 2
// 0 3 6 0 0 6
// 0 0 4 2 6 0
