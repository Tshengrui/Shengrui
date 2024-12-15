#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 比较函数，用于qsort，先按行的ASCII码和排序，若相同再按行内字符顺序排序
int cmp(const void *a, const void *b) {
    char **row1 = (char **)a;
    char **row2 = (char **)b;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; row1[0][i]!= '\0'; i++) {
        sum1 += row1[0][i];
    }
    for (int i = 0; row2[0][i]!= '\0'; i++) {
        sum2 += row2[0][i];
    }
    if (sum1!= sum2) {
        return sum1 - sum2;
    } else {
        return strcmp(*row1, *row2);
    }
}

int main() {
    char A[5][6] = {
        {'S', 'D', 'U', 'Y', 'E', 'S'},
        {'C', 'H', 'I', 'N', 'A', '!'},
        {'A', 'F', 'T', 'E', 'R', 'X'},
        {'h', 'e', 'r', 'o', 'a', 'b'},
        {'C', 'y', 'y', 'D', 'S', '!'}
    };

    // 输出初始化后的二维数组内容，方便查看初始化情况（调试用，可按需保留或删除）
    printf("初始化后的二维数组 A 的内容如下：\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%c", A[i][j]);
        }
        printf("\n");
    }

    char *rows[5];
    for (int i = 0; i < 5; i++) {
        rows[i] = A[i];
    }

    qsort(rows, 5, sizeof(char *), cmp);

    // 输出排序后的二维数组内容，方便查看排序结果（调试用，可按需保留或删除）
    printf("排序后的二维数组内容如下：\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (rows[i][j]!= '\0') {
                printf("%c", rows[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // 正式输出排序后的二维数组（按照每行固定格式输出，看起来更规整）
    printf("最终输出的排序后二维数组：\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            if (rows[i][j]!= '\0') {
                printf("%c", rows[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
