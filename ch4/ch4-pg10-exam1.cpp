#include<stdio.h>

int main() {
    printf("Ancient Cipher, NEERC 2004, UVa1339\n");
    int cnt1[26] = {0};
    int cnt2[26] = {0};
    char c = '\0';
#ifdef LOCAL
    freopen("./data/ch4-pg10-exam1.in", "r", stdin);
#endif
    while((c = getchar()) != '\n') {
        cnt1[c - 'A']++;
    }
    while((c = getchar()) != '\n') {
        cnt2[c - 'A']++;
    }
    for (int i = 0; i < 26; ++i) {
        printf("%d", cnt1[i]);
    }
    putchar('\n');
    for (int i = 0; i < 26; ++i) {
        printf("%d", cnt2[i]);
    }
    return 0;
}
