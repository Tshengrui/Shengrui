#include<stdio.h>
int isLeapYear(int year){
      return(year % 4 ==0 && year % 100!=0 || (year % 400 == 0));
      }
int getDaysInMonth(int month , int year){
    int days [] ={31,28,31,30,31,30,31,31,30,31,30,31};
    if (month == 2 && isLeapYear(year))
             return 29;
    else 
             return days[month-1];
}

void printCalendar (int month, int year){
    int daysInMonth =getDaysInMonth(month,year);

    int dayOfWeek = 0; 
    printf("Calendar for %d/%d\n",month,year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i=0; i<dayOfWeek; i++)
         printf("   ");
    for (int day = 1; day <=daysInMonth; day++) {
               printf("%3d",day);
               if ((day + dayOfWeek) % 7 == 0)
                     printf("\n");
           }
           printf("\n");
}
 
int main(){
    int year,month;
    printf("Enter year:");
    scanf("%d", &year);
    printf("Enter month:");
    scanf("%d",&month); 

    printCalendar(month,year);
    return 0;
}  
 
