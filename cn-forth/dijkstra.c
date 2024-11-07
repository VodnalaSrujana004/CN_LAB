#include<stdio.h>
#define INFINITY 9999  // Use a large number to represent infinity
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
    int G[MAX][MAX], i, j, n, u;

    // Input the number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("\nEnter the adjacency matrix (0 means no path):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // Input the starting node
    printf("\nEnter the starting node (0 to %d): ", n - 1);
    scanf("%d", &u);

    // Call Dijkstra's algorithm
    dijkstra(G, n, u);

    return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Create the cost matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (G[i][j] == 0) {
                cost[i][j] = INFINITY; // No path
            } else {
                cost[i][j] = G[i][j]; // Edge weight
            }
        }
    }

    // Initialize pred[], distance[], and visited[]
    for (i = 0; i < n; i++) {
        distance[i] = cost[startnode][i]; // Distance from start node
        pred[i] = startnode;              // Predecessor of each node
        visited[i] = 0;                   // Mark all nodes as unvisited
    }

    distance[startnode] = 0;   // Distance to the start node is 0
    visited[startnode] = 1;    // Mark start node as visited
    count = 1;                 // Count of visited nodes

    // Dijkstra's algorithm main loop
    while (count < n - 1) {
        mindistance = INFINITY;
        
        // Find the node with the minimum distance
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        // Mark the nextnode as visited
        visited[nextnode] = 1;

        // Update the distances of the neighboring nodes
        for (i = 0; i < n; i++) {
            if (!visited[i]) {
                if (mindistance + cost[nextnode][i] < distance[i]) {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }

        count++; // Increment the visited node count
    }

    // Print the shortest path and distance for each node
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("\nDistance of node %d = %d", i, distance[i]);
            printf("\nPath = %d", i);

            // Print the path by following the predecessors
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != startnode);
        }
    }
}



/*output
Enter number of vertices: 5

Enter the adjacency matrix (0 means no path):
0 9 0 0 0
9 0 3 0 0
0 3 0 7 0
0 0 7 0 2
0 0 0 2 0

Enter the starting node (0 to 4): 0

Distance of node 1 = 9
Path = 1 <- 0

Distance of node 2 = 12
Path = 2 <- 1 <- 0

Distance of node 3 = 16
Path = 3 <- 2 <- 1 <- 0

Distance of node 4 = 18
Path = 4 <- 3 <- 2 <- 1 <- 0
*/
