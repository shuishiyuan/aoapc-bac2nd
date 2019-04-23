#include <stdio.h>

int n;
int k;
int m;

// int q[20] = {[0 ... 19] = 1};
// int q[20] = { 1 };
int q[20] = { 0 };
int left;
int k_pos;
int m_pos;

void move() {
    for (int k_skip = 0; k_skip < k; ++k_skip) {
        do {
            k_pos++;
            if (k_pos == n + 1) {
                k_pos = 1;
            }
        } while (q[k_pos]);
    }
    for (int m_skip = 0; m_skip < m; ++m_skip) {
        do {
            m_pos--;
            if (m_pos == 0) {
                m_pos = n;
            }
        } while (q[m_pos]);
    }
}

int main() {
    printf("The Dole Queue, UVa133!\n");
#ifdef LOCAL
    freopen("./data/ch4-pg13-exam3.in", "r", stdin);
#endif
    scanf("%d%d%d\n", &n, &k, &m);
    k_pos = n;
    m_pos = 1;
    left = n;
    while(left) {
        /* if (left < k) {
            k = left - 1;
        }
        if (left < m) {
            m = left - 1;
        } */
        move();
        if (k_pos == m_pos) {
            q[k_pos] = 1;
            left--;
            printf("%d", k_pos);
        } else {
            q[k_pos] = q[m_pos] = 1;
            left--;
            left--;
            printf("%d %d", k_pos, m_pos);
        }
        if (left) {
            printf(", ");
        }
    }
    return 0;
}
