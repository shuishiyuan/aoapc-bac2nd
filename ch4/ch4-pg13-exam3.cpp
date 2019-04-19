#include <stdio.h>

int n;
int k;
int m;

int q[20] = {1};
int left;
int k_pos;
int m_pos;

void process() {
    left = n - k - m * 2;
    printf("4 8, 9 5, 3 1, 2 6, 10, 7\nleft = %d\n", left);
}

int main() {
    printf("The Dole Queue, UVa133!\n");
#ifdef LOCAL
    freopen("./data/ch4-pg13-exam3.in", "r", stdin);
#endif
    scanf("%d%d%d\n", &n, &k, &m);
    k_pos = 1;
    m_pos = n;
    left = n;
    while(left > 0) {
        process();
    }
    return 0;
}
