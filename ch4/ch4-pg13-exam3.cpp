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

void process() {
    
    for (int k_skip = 0; k_skip < k; ++k_pos) {
        if (k_pos == n + 1) {
            k_pos = 1;
        }
        if (!q[k_pos]) {
            k_skip++;
        }
    }
    for (int m_skip = 0; m_skip < m; --m_pos) {
        if (m_pos == 0) {
            m_pos = n;
        }
        if (!q[m_pos]) {
            m_skip++;
        }
    }
    if (--k_pos == ++m_pos) {
        q[k_pos] = 1;
        left--;
        printf("%d", k_pos);
    } else {
        q[k_pos] = q[m_pos] = 1;
        left--;
        left--;
        printf("%d %d", k_pos, m_pos);
    }
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
        /* if (left < k) {
            k = left - 1;
        }
        if (left < m) {
            m = left - 1;
        } */
        process();
        if (left > 0) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
    return 0;
}
