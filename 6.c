#include <stdio.h>
 
// 函数声明
int two_dim_array_access(int *x, int row, int col, int rows, int cols);
 
// 函数定义
int two_dim_array_access(int *x, int row, int col, int rows, int cols) {
    // 验证参数的有效性
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        // 处理错误情况，返回-1表示错误
        return -1;
    }
 
    // 计算目标元素相对于数组首元素的偏移量
    int offset = row * cols + col;
 
    // 返回目标元素的值（通过指针偏移和解引用）
    return *(x + offset);
}
 
// 示例用法
int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
 
    // 正确的调用
    int result = two_dim_array_access((int*)&A[0][0], 1, 2, 2, 3);
    if (result != -1) {
        printf("%d\n", result); // 应该输出6
    } else {
        printf("Error: Index out of bounds\n");
    }
 
    // 注意：不要尝试从非首地址开始访问二维数组，因为那是不合法的。
    // 下面的调用是错误的，并且在实际编程中应该避免。
    // int wrong_result = two_dim_array_access((int*)&A[0][1], 0, 1, 2, 3);
    // printf("%d\n", wrong_result); // 这将产生未定义行为
 
    return 0;
}
