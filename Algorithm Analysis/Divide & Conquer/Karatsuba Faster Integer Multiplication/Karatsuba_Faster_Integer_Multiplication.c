#include <stdio.h>
#include <math.h>

/** Function Header Declaration */
long long int KaratsubaMultiplication(int, int);
int no_of_digits(int);
int max(int, int);

int main() {
    int a = 14612;
    int b = 35212;

    long long int c = KaratsubaMultiplication(a, b);
    printf("%d x %d = %lld\n", a, b, c);
    return 0;
}

long long int KaratsubaMultiplication(int x, int y) {
    if (x < 10 || y < 10) {
        return (long long int)x * y;
    } else {
        int n = max(no_of_digits(x), no_of_digits(y));

        int m = n / 2;

        int a = x / pow(10, m);
        int b = x % (int)pow(10, m);

        int c = y / pow(10, m);
        int d = y % (int)pow(10, m);

        long long int ac = KaratsubaMultiplication(a, c);
        long long int bd = KaratsubaMultiplication(b, d);
        long long int ad_plus_bc = KaratsubaMultiplication(a + b, c + d) - ac - bd;

        return ac * (long long int)pow(10, 2 * m) + ad_plus_bc * (long long int)pow(10, m) + bd;
    }
}

int no_of_digits(int x) {
    int n = 0;
    while (x != 0) {
        x = x / 10;
        n++;
    }
    return n;
}

int max(int x, int y) {
    return x > y ? x : y;
}

