#include <stdio.h>
 
int main() {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int element_size = sizeof(A[0][0]); // 单个元素的大小（以字节为单位）
    int row_size = sizeof(A[0]) / element_size; // 一行中元素的数量（这里应该是3）
 
    // 打印每个元素的偏移量和值
    printf("Element\tOffset (bytes)\tValue\n");
    printf("-------\t--------------\t-----\n");
    for (int i = 0; i < 2; i++) { // 遍历行
        for (int j = 0; j < 3; j++) { // 遍历列
            // 计算偏移量（以字节为单位）
            int offset = i * row_size * element_size + j * element_size;
            // 或者更简单地，由于我们知道row_size和element_size，可以直接用
            // int offset = (i * 3 + j) * sizeof(int); 但为了展示计算过程，我们用了上面的方式
 
            // 打印偏移量和元素值
            printf("A[%d][%d]\t%d\t\t%d\n", i, j, offset, A[i][j]);
        }
    }
 
    // 观察输出，我们可以看到偏移量是按行增加的，这证明了二维数组在C语言中是按行存放的。
 
    return 0;
}
