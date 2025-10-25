#include <stdio.h>

int binsearch1(int x, int v[], int n);

int main() {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(v) / sizeof(v[0]);

    int x = 7;
    printf("Found %d at index %d\n", x, binsearch1(x, v, n));

    x = 6;
    printf("Found %d at index %d\n", x, binsearch1(x, v, n));

    return 0;
}

int binsearch1(int x, int v[], int n) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (low == high && v[low] == x)
        return low;
    else
        return -1;
}
