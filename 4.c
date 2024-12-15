#include <stdio.h>
#include <string.h>
#include <ctype.h> // 包含 toupper 函数的声明
 
void print_character_pattern(char *input) {
    int length = strlen(input);
    if (length < 1 || length > 4) {
        printf("请输入不超过4个字符的字符串。\n");
        return;
    }
 
    // 打印字符的每一行
    for (int row = 0; row < 7; row++) { // 每个字符图案有7行
        for (int i = 0; i < length; i++) {
            char c = input[i];
            if (c == 'E') {
                switch (row) {
                    case 0: printf("******  "); break;
                    case 1: printf("*        "); break;
                    case 2: printf("*        "); break;
                    case 3: printf("******  "); break;
                    case 4: printf("*        "); break;
                    case 5: printf("*        "); break;
                    case 6: printf("******  "); break;
                }
            } else if (c == 'T') {
                switch (row) {
                    case 0: printf("*******  "); break;
                    case 1: printf("   *     "); break;
                    case 2: printf("   *     "); break;
                    case 3: printf("   *     "); break;
                    case 4: printf("   *     "); break;
                    case 5: printf("   *     "); break;
                    case 6: printf("   *     "); break;
                }
            } else {
                // 输出空白
                printf("        ");
            }
        }
        printf("\n");
    }
}
 
int main() {
    char input[5]; // 最大长度为4个字符，加一个字符串结束符
    printf("请输入不超过4个字符的字符串: ");
    fgets(input, sizeof(input), stdin);
    
    // 去掉换行符（如果存在）
    input[strcspn(input, "\n")] = 0;
 
    // 将输入字符串转换为大写（仅对E和T有效，但toupper确保其他字符不受影响）
    for (int i = 0; input[i]; i++) {
        input[i] = toupper(input[i]);
    }
 
    // 打印字符图案
    print_character_pattern(input);
 
    return 0;
}
