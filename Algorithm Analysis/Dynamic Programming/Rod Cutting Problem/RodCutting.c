#include <stdio.h>
#include <math.h>

int Memoized_Cut_Rod(int p[], int n);
int Memoized_Cut_Rod_Aux(int p[], int n, double r[]);
int max(int num1, int num2);

int main() {
    int p[8] = {1, 5, 8, 9, 10, 17, 17, 20};
    int MaxRev = Memoized_Cut_Rod(p, 8);
    printf("Maximum Revenue Earned: %d", MaxRev);
    return 0;
}

int Memoized_Cut_Rod(int p[], int n) {
    double r[n + 1]; // Maximum Revenue Earnable
    int i;
    for (i = 0; i <= n; i++) {
        r[i] = -INFINITY;
    }
    return Memoized_Cut_Rod_Aux(p, n, r);
}

int Memoized_Cut_Rod_Aux(int p[], int n, double r[]) {
    double q = 0;
    int i;
    if (r[n] >= 0) {
        return (int)r[n];
    }
    if (n == 0) {
        q = 0;
    } else if (n != 0) {
        q = -INFINITY;
        for (i = 0; i < n; i++) {
            q = max(q, p[i] + Memoized_Cut_Rod_Aux(p, n - i - 1, r));
        }
        r[n] = q;
    }
    return (int)q;
}

int max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}
