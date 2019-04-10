#include<stdio.h>
#include<stdlib.h>

void showArray(int n[]) {
    for (int i = 0; i < 26; ++i) {
        printf("%d", n[i]);
    }
    putchar('\n');
}

bool decipherable(int a[], int b[]) {
    for (int i = 0; i < 26; ++i) {
        int j;
        for (j = 0; j < 26; ++j) {
            if (a[(j + i) % 26] != b[j]) {
                break;
            }
        }
        if (j == 26) {
            printf("%d\n", i);
            return true;
        }
    }
    return false;
}

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

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
    printf("Before sort:\n");
    showArray(cnt1);
    showArray(cnt2);
    printf("%s\n", decipherable(cnt1, cnt2) ? "YES" : "NO");

    qsort(cnt1, 26, sizeof(int), cmp);
    qsort(cnt2, 26, sizeof(int), cmp);

    printf("After sort:\n");
    showArray(cnt1);
    showArray(cnt2);
    printf("%s\n", decipherable(cnt1, cnt2) ? "YES" : "NO");
    return 0;
}
