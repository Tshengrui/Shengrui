#include <stdio.h>
 
// 矩阵乘法函数声明
void matrix_multi(double A[3][4], double B[4][5], double C[3][5]);
 
// 矩阵乘法函数实现
void matrix_multi(double A[3][4], double B[4][5], double C[3][5]) {
    // 初始化矩阵C为0（可选，但推荐，以避免未初始化的内存垃圾值）
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            C[i][j] = 0;
        }
    }
 
    // 执行矩阵乘法
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
 
// 测试函数
void test_matrix_multi() {
    // 定义矩阵A和B
    double A[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
 
    double B[4][5] = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0}
    };
 
    // 定义结果矩阵C
    double C[3][5];
 
    // 调用矩阵乘法函数
    matrix_multi(A, B, C);
 
    // 打印结果矩阵C
    printf("Result matrix C:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%lf ", C[i][j]);
        }
        printf("\n");
    }
 
    // 预期结果：C应该是一个单位矩阵的前4列加上一个零列
    // 因为B是一个单位矩阵加上一个零列，所以A*B应该是A的前4列
    // 验证：
    // C[0][0] = 1, C[0][1] = 2, C[0][2] = 3, C[0][3] = 4, C[0][4] = 0
    // C[1][0] = 5, C[1][1] = 6, C[1][2] = 7, C[1][3] = 8, C[1][4] = 0
    // C[2][0] = 9, C[2][1] = 10, C[2][2] = 11, C[2][3] = 12, C[2][4] = 0
}
 
// 主函数
int main() {
    // 测试矩阵乘法函数
    test_matrix_multi();
 
    return 0;
}
