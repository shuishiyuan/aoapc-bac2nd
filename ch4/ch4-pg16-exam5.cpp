#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50
#define MOD 100

int work_sheet[MAX][MAX];
int work_sheet_bak[MAX][MAX];
int process_info[MAX];

bool readChars(char *keys) {
    char c;
    while((c = getchar()) != '\n') {
        if (c != ' ') {
            *keys++ = c;
        } else {
            *keys = '\0';
            return true;
        }
    }
    *keys = '\0';
    return false;
}

bool readIntegers(int *number) {
    *number = 0;
    char keys[4];
    bool ret_val = readChars(keys);
    int max_pow = strlen(keys) - 1;
    char c;
    char *p = keys;
    while((c = *p++) != '\0') {
        *number += pow(10, max_pow--) * (c - '0');
    }
    return ret_val;
}

int main() {
    printf("Solution a of Spreadsheet Tracking!\n");
    int row_num;
    int col_num;
    int operation_num;
    int query_num;

#ifdef LOCAL
    freopen("data/ch4-exam5.in", "r", stdin);
#endif
    scanf("%d %d\n", &row_num, &col_num);
    scanf("%d\n", &operation_num);
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            work_sheet[i][j] = (i + 1) * MOD + (j + 1);
        }
    }
    
    /*
    printf("The initialized work sheet is :\n");
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            printf("%d ", work_sheet[i][j]);
        }
        putchar('\n');
    }
    */

    char current_key[4];
    int current_num;
    while(operation_num--) {
        readChars(current_key);
	int num_counter = 0;
	if (current_key[0] == 'I' || current_key[0] == 'D') {
		printf("%s", current_key);
		num_counter = readIntegers(&current_num) ? current_num : 0;
	// } else if (strcmp(current_key, "EX")) {
		//continue;
	} else if (current_key[0] == 'E' && current_key[1] == 'X') {
		// printf(" This is an exchange!\n");
		while(readIntegers(&current_num)) {
			// printf("%d ", current_num);
			continue;
		}
		continue;
	}
	while(num_counter--) {
	    readIntegers(&current_num);
	    printf(" %d", current_num);
	}
        // printf(" %d\n", current_num);
	// memset(current_key, '\0', sizeof(char) * 4);
        putchar('\n');
    }

    /*
    printf("The targeted work sheet is :\n");
    for (int i = 0; i < row_num; ++i) {
        for (int j = 0; j < col_num; ++j) {
            printf("(%d %d) ", work_sheet[i][j] / MOD, work_sheet[i][j] % MOD);
        }
        putchar('\n');
    }
    */

    // int row_pos;
    // int col_pos;
    readIntegers(&query_num);
    printf("There are %d queries!\n", query_num);
    /* while(query_num--) {
        scanf("%d %d\n", &row_pos, &col_pos);
        printf("Cell data in (%d, %d) moved to (%d, %d)\n", row_pos, col_pos, work_sheet[row_pos - 1][col_pos - 1] / MOD, work_sheet[row_pos - 1][col_pos - 1] % MOD);
    } */
    // Test For Push 2019/08/26.
    return 0;
}
