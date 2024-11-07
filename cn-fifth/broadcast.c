#include <stdio.h>

#define MAX 10

int a[MAX][MAX], n;

void adj(int k);

int main() {
    int i, j, root;

    // Input number of nodes
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter adjacency matrix (1 for connected, 0 for not connected):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter connection between node %d and node %d (1 for connected, 0 for not connected): ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Input the root node
    printf("Enter root node (1 to %d): ", n);
    scanf("%d", &root);

    // Display the adjacent nodes of the root node and other information
    adj(root);

    return 0;
}

// Function to find and display adjacent nodes and non-connected nodes
void adj(int k) {
    int i, j;

    // Display the adjacent nodes of the root node
    printf("\nAdjacent nodes of root node %d:\n", k);
    for (j = 1; j <= n; j++) {
        if (a[k][j] == 1 || a[j][k] == 1) {
            printf("%d\t", j);
        }
    }

    // Display nodes that are not directly connected to the root node
    printf("\nNodes that are not directly connected to root node %d:\n", k);
    for (i = 1; i <= n; i++) {
        if (i != k && a[k][i] == 0 && a[i][k] == 0) {
            printf("%d\t", i);
        }
    }

    printf("\n");
}


/*output
Enter number of nodes: 5
Enter adjacency matrix (1 for connected, 0 for not connected):
Enter connection between node 1 and node 1 (1 for connected, 0 for not connected): 0
Enter connection between node 1 and node 2 (1 for connected, 0 for not connected): 1
Enter connection between node 1 and node 3 (1 for connected, 0 for not connected): 1
Enter connection between node 1 and node 4 (1 for connected, 0 for not connected): 0
Enter connection between node 1 and node 5 (1 for connected, 0 for not connected): 0
Enter connection between node 2 and node 1 (1 for connected, 0 for not connected): 1
Enter connection between node 2 and node 2 (1 for connected, 0 for not connected): 0
Enter connection between node 2 and node 3 (1 for connected, 0 for not connected): 1
Enter connection between node 2 and node 4 (1 for connected, 0 for not connected): 1
Enter connection between node 2 and node 5 (1 for connected, 0 for not connected): 0
Enter connection between node 3 and node 1 (1 for connected, 0 for not connected): 1
Enter connection between node 3 and node 2 (1 for connected, 0 for not connected): 1
Enter connection between node 3 and node 3 (1 for connected, 0 for not connected): 0
Enter connection between node 3 and node 4 (1 for connected, 0 for not connected): 0
Enter connection between node 3 and node 5 (1 for connected, 0 for not connected): 0
Enter connection between node 4 and node 1 (1 for connected, 0 for not connected): 0
Enter connection between node 4 and node 2 (1 for connected, 0 for not connected): 1
Enter connection between node 4 and node 3 (1 for connected, 0 for not connected): 0
Enter connection between node 4 and node 4 (1 for connected, 0 for not connected): 0
Enter connection between node 4 and node 5 (1 for connected, 0 for not connected): 1
Enter connection between node 5 and node 1 (1 for connected, 0 for not connected): 0
Enter connection between node 5 and node 2 (1 for connected, 0 for not connected): 0
Enter connection between node 5 and node 3 (1 for connected, 0 for not connected): 0
Enter connection between node 5 and node 4 (1 for connected, 0 for not connected): 1
Enter root node (1 to 5): 2

Adjacent nodes of root node 2:
1   3   4   

Nodes that are not directly connected to root node 2:
5   
*/
