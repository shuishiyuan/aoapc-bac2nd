#include <stdio.h>
#define MAX 50

int main() {
    printf("Solution a of Spreadsheet Tracking!\n");
    int work_sheet[MAX][MAX];
    int row_num;
    int col_num;
    int operation_num;
    int query_num;

#ifdef LOCAL
    freopen("data\ch4-exam5.in", "r", stdin);
#endif
    scanf("%d%d\n", &row_num, &col_num);
    scanf("%d\n", &operation_num);
    while(operation_num--) {
        ;
    }

    int row_pos;
    int col_pos;
    // Test Push in Proxy
    scanf("%d\n", &query_num);
    while(query_num--) {
        scanf("%d%d\n", &row_pos, &col_pos);
        printf("%d\t%d\n", row_pos, col_pos);
    }
    return 0;
}
