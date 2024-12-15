#include<stdio.h>
#define H 10
int V(int L, int W);
int main() 
{
   int L;
  
   int W;
	
   int v;
 
   
   printf("chang_fang_ti_de_gao_wei: %d\n",H);

   printf("changwei:\n");
   scanf("%d",&L);
  
   printf("kuanwei:\n");
   scanf("%d",&W);
   
   v=V(L,W);
   printf("changfangtidetijiwei:");

   printf("%d",v); 
   return 0;
}
   
   
   int V(int L,int W)
{ 
   
   int v=L*W*H;
   return v; 
} 
