#include <stdio.h>

int main() {
    printf("Hangman Judge, UVa489\n\n");
    int rnd;
#ifdef LOCAL
    freopen("./data/ch4-pg12-exam2.in", "r", stdin);
#endif
    while(scanf("%d\n", &rnd) == 1 && rnd != -1) {
        int n[26] = {0};
        int left = 0;
        int chance = 7;
        char c;
        while((c = getchar()) != '\n') {
            if (n[c - 'a']++ == 0) {
                left++;
            }
        }
        while((c = getchar()) != '\n') {
            if (left > 0 && chance > 0) {
                if (n[c - 'a'] > 0) {
                    left--;
                    n[c - 'a'] = 0;
                } else {
                    chance--;
                }
            }
        }
        printf("Round %d\n", rnd);
        if (!left) {
            printf("You Win.\n");
        } else if (!chance) {
            printf("You Lose.\n");
        } else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
