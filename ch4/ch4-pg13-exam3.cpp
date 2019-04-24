#include <stdio.h>

int n;
// int q[20] = {[0 ... 19] = 1};
// int q[20] = { 1 };
int q[20] = { 0 };

int move(int pos, int step, int direct) {
    while (step--) {
        do {
            pos = (pos + direct + n - 1) % n + 1;
        } while (q[pos]);
    }
    return pos;
}

int main() {
    printf("The Dole Queue, UVa133!\n");
#ifdef LOCAL
    freopen("./data/ch4-pg13-exam3.in", "r", stdin);
#endif
    int k;
    int m;
    scanf("%d%d%d\n", &n, &k, &m);
    int k_pos = n;
    int m_pos = 1;
    int left = n;
    while(left) {
        k_pos = move(k_pos, k, 1);
        m_pos = move(m_pos, m, -1);
        if (k_pos == m_pos) {
            q[k_pos] = 1;
            left--;
            printf("%2d", k_pos);
        } else {
            q[k_pos] = q[m_pos] = 1;
            left -= 2;
            printf("%d%3d", k_pos, m_pos);
        }
        if (left) {
            printf(", ");
        }
    }
    return 0;
}
