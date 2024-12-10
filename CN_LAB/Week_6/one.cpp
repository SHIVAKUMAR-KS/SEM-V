#include<stdio.h>
#include<stdlib.h>

int i, j, k, a, b, u, v, n, ne = 1;
int min, mincost = 0, cost[9][9], parent[9];

int find(int);
int uni(int, int);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 99;
        }
    }

    printf("The edges of the minimum cost spanning tree are:\n");
    while(ne < n) {
        for(i = 1, min = 99; i <= n; i++) {
            for(j = 1; j <= n; j++) {
                if(cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u, v)) {
            printf("%d edge (%d, %d) = %d\n", ne++, a, b, min);
            mincost += min;
        }

        cost[a][b] = cost[b][a] = 99;
    }

    printf("\nMinimum cost = %d\n", mincost);
}

int find(int i) {
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if(i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

/*
Enter the number of vertices: 5
Enter the cost adjacency matrix:
0 1 7 10 5
1 0 3 0 0  
7 3 0 4 0
10 0 4 0 2
5 0 0 2 0
The edges of the minimum cost spanning tree are:
1 edge (1, 2) = 1
2 edge (4, 5) = 2
3 edge (2, 3) = 3
4 edge (3, 4) = 4

Minimum cost = 10
*/