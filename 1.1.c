#include<stdio.h>
//"mao_pao_suanfa_define_a_function" 
void bubble(int A[] , int n ){
     for (int i = 0 ; i < n - 1 ; i++){
         for ( int j = 0 ; j < n - 1 - i ; j++){
             if (A[j] > A[j+1]){
             int temp = A[j];
             A[j]=A[j+1];
             A[j+1]=temp;
             }
          }    
     }
}
//"define_a_print_function"
void print(int A[], int n){
  for (int i=0; i<n; i++){
      printf(" %d ",A[i]);
      }
      printf("\n");
}

int main(){
    int A[]={45,12,19,36,95,42};

    int n = sizeof(A) / sizeof(A[0]);

    printf("yuan_shuzhu: \n");
    print( A , n);   //"diao_yong_print_function" 

    bubble( A , n);  //"diao_yong_bulle_function" 

    printf("paixuhou_shuzhu: \n");
    print( A , n);   //"diao_yong_print_function" 

    return 0;
}

          


