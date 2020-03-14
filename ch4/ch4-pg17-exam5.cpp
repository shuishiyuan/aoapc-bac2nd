#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int row_num;
int col_num;
int prc_num;
int *prc;

bool read_char(char *res) {
    char c;
    while((c = getchar()) != 0x20 && c != 0x0a) {
        *res++ = c;
    }
    *res = 0x00;
    if (c == 0x0a) {
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
    scanf("%d", &prc_num);
    printf("The input row number is: %d\n", row_num);
    printf("The input col number is: %d\n", col_num);
    printf("The input process number is: %d\n", prc_num);
    prc = (int*)malloc(prc_num * MAX * sizeof(int));
    char key[3];
    for (int i = 0; i < prc_num; ++i) {
        while (read_char(key)) {
            printf("%s ", key);
        }
        if (key[0] == 0x00) {
            --i;
            continue;
        }
        printf("%s\n", key);
    }
    return 0;
}
