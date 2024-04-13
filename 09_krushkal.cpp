#include <stdio.h>

int min, cost[100][100], parent[100], i, j, x, y, n;

void findMin();
int checkCycle(int x, int y);

void main() {
    int count = 0, total = 0, flag = 0;

    printf("Enter the number of towns: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            parent[i] = 0;

            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    while (count != n - 1 && min != 999) {
        findMin();
        flag = checkCycle(x, y);

        if (flag == 1) {
            printf("\n%d-->%d == %d\n", x, y, cost[x][y]);
            total += cost[x][y];
            count++;
        }
        cost[x][y] = cost[y][x] = 999;
    }
    printf("\nThe total cost of the minimum spanning tree: %d\n", total);
}

void findMin() {
    min = 99;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                x = i;
                y = j;
            }
        }
    }
}

int checkCycle(int x, int y) {
    if (parent[x] == parent[y] && parent[x] != 0) {
        return 0;
    } else if (parent[x] == 0 && parent[y] == 0) {
        parent[x] = parent[y] = x;
    } else if (parent[x] == 0) {
        parent[x] = parent[y];
    } else if (parent[x] != parent[y]) {
        parent[y] = parent[x];
    }
    return 1;
}
