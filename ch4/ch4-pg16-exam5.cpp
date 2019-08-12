#include <stdio.h>
#include <string.h>
#define MAX 50

int main() {
    printf("Solution a of Spreadsheet Tracking!\n");
    int work_sheet[MAX][MAX];
    int row_num;
    int col_num;
    int operation_num;
    int query_num;

#ifdef LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
#endif
    scanf("%d%d\n", &row_num, &col_num);
    scanf("%d\n", &operation_num);
    char operation_key[4];
    char current_key[4];
    scanf("%s", operation_key);
    printf("\n%s ", operation_key);
    while(operation_num--) {
        scanf("%s", current_key);
        if (strlen(current_key) > 2) {
            break;
        }
        while(current_key[0] >= '0' && current_key[0] <= '9') {
            printf("%s ", current_key);
            scanf("%s", current_key);
            if (strlen(current_key) > 2) {
                // putchar('\n');
                break;
            }
        }
        strcpy(operation_key, current_key);
        printf("\n%s ", operation_key);
    }

    int row_pos;
    int col_pos;
    // Test Push in Proxy
    // scanf("%d\n", &query_num);
    putchar('\n');
    query_num = (current_key[0] - '0') * 100 + (current_key[1] - '0') * 10 + current_key[2] - '0';
    // printf("%s\t", current_key);
    // printf("%d", query_num);
    while(query_num--) {
        scanf("%d %d\n", &row_pos, &col_pos);
        printf("%d %d\n", row_pos, col_pos);
    }
    return 0;
}
