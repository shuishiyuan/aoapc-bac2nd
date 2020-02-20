#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 50
#define MOD 1000

long int work_sheet[MAX][MAX];
long int work_sheet_bak[MAX][MAX];
int process_info[MAX];
int blank_set[MAX];

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
	blank_set[i] = 0;
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
		memset(process_info, 0, sizeof(int) * MAX);
		num_counter = readIntegers(&current_num) ? current_num : 0;
		while(num_counter--) {
		    readIntegers(&current_num);
		    printf(" %d", current_num);
		    if (!process_info[current_num - 1]) {
			process_info[current_num - 1] = 1;
		    }
		}
		putchar('\n');
		for (int i = 0; i < MAX; ++i) {
			printf("%d ", process_info[i]);
		}
	// } else if (strcmp(current_key, "EX")) {
		//continue;
	} else if (current_key[0] == 'E' && current_key[1] == 'X') {
		printf("%s", current_key);
		// printf(" This is an exchange!\n");
		int *index_tmp = (int*)malloc(sizeof(int)*5);
		int *index_tmp_start = index_tmp;
		while(readIntegers(&current_num)) {
			printf(" %d", current_num);
			*index_tmp++ = current_num;
			continue;
		}
		printf(" %d", current_num);
		*index_tmp++ = current_num;
		*index_tmp = '\0';
		index_tmp -= 4;
		printf(" %d %d",work_sheet[index_tmp[0]][index_tmp[1]], work_sheet[index_tmp[2]][index_tmp[3]]);
		// int tmp = work_sheet[index_tmp[2]][index_tmp[3]];
		// work_sheet[index_tmp[2]][index_tmp[3]] = work_sheet[index_tmp[0]][index_tmp[1]];
		// work_sheet[index_tmp[0]][index_tmp[1]] = tmp;
		work_sheet[index_tmp[2]][index_tmp[3]] += work_sheet[index_tmp[0]][index_tmp[1]];
		work_sheet[index_tmp[0]][index_tmp[1]] = work_sheet[index_tmp[2]][index_tmp[3]] - work_sheet[index_tmp[0]][index_tmp[1]];
		work_sheet[index_tmp[2]][index_tmp[3]] = work_sheet[index_tmp[2]][index_tmp[3]] - work_sheet[index_tmp[0]][index_tmp[1]];
		printf(" %d %d",work_sheet[index_tmp[0]][index_tmp[1]], work_sheet[index_tmp[2]][index_tmp[3]]);
		// index_tmp = index_tmp_start;
		/* while (*index_tmp != '\0') {
		    printf(" %d", *index_tmp++);
		}*/
		// continue;
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

    int row_pos;
    int col_pos;
    readIntegers(&query_num);
    printf("There are %d queries!\n", query_num);
    while(query_num--) {
        scanf("%d %d\n", &row_pos, &col_pos);
	for (int i = 0; i < row_num; ++i) {
	    for (int j = 0; j < col_num; ++j) {
		if (work_sheet[i - 1][j - 1] / MOD == row_pos + 1 &&
		    work_sheet[i - 1][j - 1] % MOD == col_pos + 1) {
			printf("Cell data in (%d, %d) moved to (%d, %d)\n", row_pos, col_pos, i - 1, j - 1);
		}
	    }
	}
    }
    // Test For Push 2019/08/26.
    return 0;
}
