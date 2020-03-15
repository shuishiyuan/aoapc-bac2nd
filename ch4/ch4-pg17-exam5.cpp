#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define MAX_INT_W 10

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

bool read_num(int *res) {
    char req[MAX_INT_W];
    bool rtv = false;
    rtv = read_char(req);

    int pow = str_len(req);
    while(--pow >= 0) {
        *res += req[pow] * power(2, pow);
    }
    return rtv;
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
        read_char(key);
        if (key[0] == 0x00) {
            --i;
            continue;
        }
        printf("%s ", key);
        int num = 0;'
        while (read_num(&num)) {
            printf("%d ", num);
        }
        printf("%d\n", num);
    }
    return 0;
}
