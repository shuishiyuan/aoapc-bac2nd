#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int row_num;
int col_num;
int prc_num;


int *prc;

bool read_char(char *res) {
    printf("reading chars\n");
    char c;
    while((c = getchar()) != 20 && c != '\n') {
        *res++ = c;
    }
    *res = '\0';
    if (c == '\n') {
        return false;
    }
    return true;
}

int main() {
    printf("Spreadsheet #1\n");
#if LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
#endif
    scanf("%d %d", &row_num, &col_num);
    scanf("%d\n", &prc_num);
    printf("The input row number is: %d\n", row_num);
    printf("The input col number is: %d\n", col_num);
    printf("The input process number is: %d\n", prc_num);
    prc = (int*)malloc(prc_num * MAX * sizeof(int));
    char key[3];
    // key = (char*)malloc(3 * sizeof(char));
    for (int i = 0; i < prc_num; ++i) {
        while (read_char(key)) {
            printf("%s", key);
        }
        putchar('\n');
    }
    return 0;
}
