#include <stdio.h>

int main() {
    printf("Hangman Judge, UVa489\n\n");
    int rnd;
#ifdef LOCAL
    freopen("./data/ch4-pg12-exam2.in", "r", stdin);
#endif
    while(scanf("%d\n", &rnd) == 1 && rnd != -1) {
        int n[26] = {0};
        int cnt = 0;
        int wronger = 0;
        char c;
        while((c = getchar()) != '\n') {
            if (n[c - 'a']++ == 0) {
                cnt++;
            }
        }
        while((c = getchar()) != '\n') {
            if (cnt > 0 && wronger < 7) {
                if (n[c - 'a'] > 0) {
                    cnt--;
                    n[c - 'a'] = 0;
                } else {
                    wronger++;
                }
            }
        }
        printf("Round %d\n", rnd);
        if (cnt == 0) {
            printf("You Win.\n");
        } else if (wronger == 7) {
            printf("You Lose.\n");
        } else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
