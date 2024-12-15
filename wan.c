#include <stdio.h>
int lsLeapYear(int year){
    return (year %4 == 0 && year % 100!=0||(year % 400==0));
}
int getDaysInMonth(int month, int year){
    int days[ ] ={31,28,31,30,31,30,31,31,30,31,30,31};
    if (month ==2 &&  lsLeapYear(year))
               return 29;
    else  
               return days [month - 1];
}
int getDayOfWeek(int day ,int month,int year){
    int t[]={0,3,2,5,0,3,5,1,4,6,2,4};
    year -=month < 3;
  
    return (year +year /4 - year/100 +year/400 +t[month - 1] + day )%7;
}

void printMonthCalendar(int month,int year){
           int daysInMonth = getDaysInMonth(month , year);

           int dayOfWeek = getDayOfWeek(1,month,year);
            
           printf("Calendar for %d/%d\n",month,year);

           printf("Sun Mon Tue Wed Thu Fri Sat\n");

           for (int i=0; i < dayOfWeek; i++)
    
           printf("    ");
          
           for(int day = 1 ; day <= daysInMonth; day++){
                 printf("%3d", day);
                 if ((day + dayOfWeek)%7 == 0)
                 printf("\n");
            }
                 printf("\n");
        }
void printYearCalendar(int year){
      for (int month = 1; month <= 12; month++){
           printMonthCalendar(month,year);
         }
  } 
 
int main (){
      int year ;
      printf ("Emter a year:");
      scanf("%d", &year);
      printYearCalendar(year);
     
      return 0;
}
       
 
 
                    
            
            
  

             


     
 
