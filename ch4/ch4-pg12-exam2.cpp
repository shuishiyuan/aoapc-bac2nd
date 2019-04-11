#include <stdio.h>

int main() {
    printf("Hangman Judge, UVa489\n\n");
    int round;
#ifdef LOCAL
    freopen("./data/ch4-pg12-exam2.in", "r", stdin);
#endif
    while(scanf("%d\n", &round) == 1 && round != -1) {
        int n[26] = {0};
        int counter = 0;
        int wronger = 0;
        char c;
        while((c = getchar()) != '\n') {
            if (n[c - 'a']++ == 0) {
                counter++;
            }
        }
        while((c = getchar()) != '\n') {
            if (counter > 0 && wronger < 7) {
                if (n[c - 'a'] > 0) {
                    counter--;
                } else {
                    wronger++;
                }
            }
        }
        printf("Round %d\n", round);
        if (counter == 0) {
            printf("You Win.\n");
        } else if (wronger == 7) {
            printf("You Lose.\n");
        } else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}
