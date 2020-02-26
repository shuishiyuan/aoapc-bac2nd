#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50
#define MOD 1000
#define HIGH_VAL 65536

long int work_sheet[MAX][MAX];
long int work_sheet_bak[MAX][MAX];
int process_info[MAX];
long int blank_set[MAX];
int row_num;
int col_num;

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

void copy_line(long int *p_from, long int *p_to) {
    for (long int j = 0; j < col_num; ++j) {
        p_to[j] = p_from[j];
    }
}

void copy_col(long int *p_from, long int *p_to) {
    for (long int i = 0; i < row_num; ++i) {
        p_to[i * col_num] = p_from[i * col_num];
    }
}

void copy_back() {
    memset(work_sheet, '\0', MAX * MAX);
    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < MAX; ++j) {
            work_sheet[i][j] = work_sheet_bak[i][j];
        }
    }
}

int main() {
    printf("Solution a of Spreadsheet Tracking!\n");
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
        blank_set[i] = HIGH_VAL;
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
        memset(work_sheet_bak, '\0', sizeof(int) * MAX * MAX);
        readChars(current_key);
	int num_counter = 0;
	if (current_key[0] == 'I' || current_key[0] == 'D') {
	    printf("%s", current_key);
	    memset(process_info, '\0', sizeof(int) * MAX);
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
	    int current_bak_index = 0;
	    if (current_key[0] == 'I') {
		if (current_key[1] == 'R') {
		    for (int i = 0; i < row_num; ++i) {
			if (process_info[i]) {
			    copy_line(blank_set, work_sheet_bak[current_bak_index++]);
			}
			copy_line(work_sheet[i], work_sheet_bak[current_bak_index++]);
		    }
		}
		if (current_key[1] == 'C') {
		    for (int j = 0; j < col_num; ++j) {
			if (process_info[j]) {
			    copy_col(blank_set,work_sheet_bak[0] + current_bak_index++);
			}
			copy_col(work_sheet[0] + j, work_sheet_bak[0] + current_bak_index++);
		    }
		}
	    }
	    if (current_key[0] == 'D') {
		if (current_key[1] == 'R') {
		    for (int i = 0; i < row_num; ++i) {
			if (process_info[i]) {
			    continue;
			}
			copy_line(work_sheet[i], work_sheet_bak[current_bak_index++]);
		    }
		}
		if (current_key[1] == 'C') {
		    for (int j = 0; j < col_num; ++j) {
			if (process_info[j]) {
			    continue;
			}
			copy_col(work_sheet[0] + j,work_sheet_bak[0] + current_bak_index++);
		    }
		}
	    }
	    copy_back();
    // } else if (strcmp(current_key, "EX")) {
	    //continue;
	} else if (current_key[0] == 'E' && current_key[1] == 'X') {
		printf("%s", current_key);
		// printf(" This is an exchange!\n");
		int *index_tmp = (int*)malloc(sizeof(int)*5);
		// int *index_tmp_start = index_tmp;
		while(readIntegers(&current_num)) {
		    printf(" %d", current_num);
		    *index_tmp++ = current_num;
		    continue;
		}
		printf(" %d", current_num);
		*index_tmp++ = current_num;
		*index_tmp = '\0';
		index_tmp -= 4;
		printf(" %ld %ld",work_sheet[index_tmp[0]][index_tmp[1]], work_sheet[index_tmp[2]][index_tmp[3]]);
		// int tmp = work_sheet[index_tmp[2]][index_tmp[3]];
		// work_sheet[index_tmp[2]][index_tmp[3]] = work_sheet[index_tmp[0]][index_tmp[1]];
		// work_sheet[index_tmp[0]][index_tmp[1]] = tmp;
		work_sheet[index_tmp[2]][index_tmp[3]] += work_sheet[index_tmp[0]][index_tmp[1]];
		work_sheet[index_tmp[0]][index_tmp[1]] = 
			work_sheet[index_tmp[2]][index_tmp[3]] - work_sheet[index_tmp[0]][index_tmp[1]];
		work_sheet[index_tmp[2]][index_tmp[3]] = 
			work_sheet[index_tmp[2]][index_tmp[3]] - work_sheet[index_tmp[0]][index_tmp[1]];
		printf(" %ld %ld",work_sheet[index_tmp[0]][index_tmp[1]], work_sheet[index_tmp[2]][index_tmp[3]]);
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
	bool is_hit = false;
	for (int i = 0; i < row_num && !is_hit; ++i) {
	    for (int j = 0; j < col_num && !is_hit; ++j) {
		if (work_sheet[i - 1][j - 1] / MOD == row_pos + 1 &&
		    work_sheet[i - 1][j - 1] % MOD == col_pos + 1) {
			printf("Cell data in (%d, %d) moved to (%d, %d)\n", row_pos, col_pos, i - 1, j - 1);
			is_hit = true;
		}
	    }
	}
	printf("Cell data in (%d, %d) GONE\n", row_pos, col_pos);
    }
    // Test For Push 2019/08/26.
    return 0;
}
