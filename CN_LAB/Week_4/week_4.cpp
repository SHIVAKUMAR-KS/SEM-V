#include <stdio.h>

#define MAX_NODES 20
#define INF 9999

// Structure to store distance and next hop information for each node
struct node {
    unsigned dist[MAX_NODES];  // Distance vector
    unsigned from[MAX_NODES];  // Next hop for the shortest path
} rt[MAX_NODES];

// Function to implement Distance Vector Routing
void distance_vector_routing(int n, int dmat[MAX_NODES][MAX_NODES]) {
    int count, i, j, k;
    
    // Initialize distance vector and next hop for each router
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                rt[i].dist[j] = 0;
            else if (dmat[i][j] != 0)
                rt[i].dist[j] = dmat[i][j];
            else
                rt[i].dist[j] = INF;

            rt[i].from[j] = j;
        }
    }

    // Start the Bellman-Ford-like update process
    do {
        count = 0;
        // Iterate over each node
        for (i = 0; i < n; i++) {
            // Check the distance to all other nodes
            for (j = 0; j < n; j++) {
                // Relax the edges: check if we can improve the route to node j
                for (k = 0; k < n; k++) {
                    if (rt[i].dist[j] > dmat[i][k] + rt[k].dist[j]) {
                        rt[i].dist[j] = dmat[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k;  // Set next hop
                        count++;  // Indicate that there was an update
                    }
                }
            }
        }
    } while (count != 0);  // Continue until no more updates occur

    // Print the routing table for each node
    for (i = 0; i < n; i++) {
        printf("\nRouting table for router %d:\n", i + 1);
        for (j = 0; j < n; j++) {
            if (rt[i].dist[j] == INF)
                printf("Node %d is unreachable\n", j + 1);
            else
                printf("To node %d via node %d, Distance: %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
}

int main() {
    int n, i, j;
    int dmat[MAX_NODES][MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Input the cost matrix (adjacency matrix for the graph)
    printf("Enter the cost matrix (enter 0 for no direct connection):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dmat[i][j]);
            if (i == j) dmat[i][j] = 0;  // Distance to self is 0
        }
    }

    // Call the distance vector routing function
    distance_vector_routing(n, dmat);

    return 0;
}
/*
Enter the number of nodes: 4
Enter the cost matrix (enter 0 for no direct connection):
0 3 5 99
3 0 99 1
5 99 0 2
99 1 2 0

Routing table for router 1:
To node 1 via node 1, Distance: 0
To node 2 via node 2, Distance: 3
To node 3 via node 3, Distance: 5
To node 4 via node 2, Distance: 4

Routing table for router 2:
To node 1 via node 1, Distance: 3
To node 2 via node 2, Distance: 0
To node 3 via node 4, Distance: 3
To node 4 via node 4, Distance: 1

Routing table for router 3:
To node 1 via node 1, Distance: 5
To node 2 via node 4, Distance: 3
To node 3 via node 3, Distance: 0
To node 4 via node 4, Distance: 2

Routing table for router 4:
To node 1 via node 2, Distance: 4
To node 2 via node 2, Distance: 1
To node 3 via node 3, Distance: 2
To node 4 via node 4, Distance: 0
PS D:\Sem-V\LAB\CN_LAB\Week_4> 
*/