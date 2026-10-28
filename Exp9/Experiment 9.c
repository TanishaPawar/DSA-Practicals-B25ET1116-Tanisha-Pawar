#include <stdio.h>

int main() {
    int a[6][6], v[6] = {0};
    int i, j, k, min, total = 0;

    printf("Enter 6x6 adjacency matrix:\n");

    for (i = 0; i < 6; i++)
        for (j = 0; j < 6; j++) {
            scanf("%d", &a[i][j]);

            if (a[i][j] == 0)
                a[i][j] = 999;
        }

    v[0] = 1;

    for (k = 0; k < 5; k++) {
        min = 999;

        for (i = 0; i < 6; i++)
            if (v[i] == 1)
                for (j = 0; j < 6; j++)
                    if (v[j] == 0 && a[i][j] < min) {
                        min = a[i][j];
                        int x = i, y = j;
                        /* Selected edge is x-y */
                        v[y] = 1;
                        total += min;
                        printf("%d - %d : %d\n", x, y, min);
                        goto next;
                    }
        next:;
    }
    printf("Total cost = %d\n", total);

    return 0;
}
