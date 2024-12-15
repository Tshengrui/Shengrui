#include<stdio.h>

int getDayOfWeek(int year,int month,int day){
    if(month < 3){
       year--;
       month += 12;
    }
    int k =year % 100;
    int j =year / 100;
    int h =(day +((26 *(month +1))/10) + k + (k/4) + (j/4) + (5 * j)) % 7;  
    return h;
 }



void printDayOfWeek(int dayOfWeek) {
    switch (dayOfWeek) {
      case 0: 
           printf("Saturday\n");
           break;
      case 1: 
           printf("Sunday\n");
           break;
      case 2: 
           printf("Monday\n");
           break;
      case 3: 



           printf("Tuesday\n");

           break;
      case 4:
           printf("Wednesday\n");
           break;
      case 5:
           printf("Thuresday\n");
           break;
      case 6:
           printf("Friday\n");
           break;
     }
 }

int main(){
    int year , month , day;
    printf("please_input_year:");
    scanf("%d",&year);
    printf("please_input_month:");
    scanf("%d" , &month);
    printf("please_input_day");
    scanf("%d" ,  &day);
    int dayOfWeek =
 getDayOfWeek(year,month,day);


    printDayOfWeek(dayOfWeek);
    return 0;
 }

























 



  
 



      

























    





























































   


      
  
        



















 
