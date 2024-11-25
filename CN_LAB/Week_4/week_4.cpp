#include<stdio.h>

int main()
{
    int path[10][10], i, j, min, a[10][10], p, st = 1, ed, stp, edp, t[10], index, n;

    printf("\nEnter number of vertices:\n");
    scanf("%d", &n);
    
    ed = n;  // Set the destination as the last vertex

    printf("Enter the cost matrix:\n");
    // Input the cost matrix (adjacency matrix for the graph)
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the number of paths:\n");
    scanf("%d", &p);
    
    printf("Enter the possible paths:\n");
    // Input the possible paths
    for(i = 1; i <= p; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &path[i][j]);
        }
    }

    // Calculate the total cost for each path
    for(i = 1; i <= p; i++)
    {
        t[i] = 0;
        stp = st;  // Start point for the path
        for(j = 1; j <= n; j++)
        {
            edp = path[i][j+1];  // Get the next vertex in the path
            t[i] = t[i] + a[stp][edp];  // Add the cost to the total cost

            // If destination is reached, break
            if(edp == ed)
                break;
            else
                stp = edp;  // Otherwise, move to the next vertex
        }
    }

    // Find the path with the minimum cost
    min = t[st];
    index = st;
    for(i = 1; i <= p; i++)
    {
        if(min > t[i])
        {
            min = t[i];
            index = i;  // Store the index of the minimum cost path
        }
    }

    // Output the results
    printf("Minimum cost: %d\n", min);
    printf("Minimum cost path: ");
    
    // Output the path corresponding to the minimum cost
    for(i = 1; i <= n; i++)
    {
        printf("--->%d", path[index][i]);
    }
}
