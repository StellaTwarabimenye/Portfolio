# Portfolio

#include <iostream>
#include <string>
using namespace std;


int main()
{
   int year,month,day,total=0;
   string mo[]= {"Janurary","Feburary","March","April","May","June","July","August","September","October","November","December"};
   string day_of_the_week[]={"Sunday","Monday","Tuesday","Wenesday","Thursday","Friday","Saturday"};

      cout<<"What is the year?:";
      cin>>year;
      cout<<"Which month?:";
      cin>>month;
      cout<<"Which day of the week did the 1st of the month fell?:";
      cin>>day;

          if(month == 1 ||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
              total = 31;/// Janurary,March,May,July,August,October and December all are 31 day months

        else if(month == 4||month == 6||month == 9||month == 11)
         total = 30;
    else
{
if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
total = 29;
else
total = 28;
}///This is where the program decides for a leap year by mentioning they happen every 4 years

cout<<"\nHere is the calendar for"<<mo[month-1]<<"of the year"<<year;
   cout<<"\nSunday\tMonday\tTuesday\tWedsday\tThursday\tFriday\tSaturday\n";///I put tabs to create even spacing between the days

   int i;
   int j;///we mostly use those variable in class
for(i=0;i<day-1;i++)///Error in the loops. When I run my program, it shows an extra line. The count becomes wrong after a few days.
    cout<<"\t";
for(j=1;j<=total;j++)
{
    cout<<j<<"\t";
if(i++>7)
{
    i=0;
    cout<<"\n";
}
}

i=i-1;
if(i<0)
i = 7;
cout<<"\nThe month ends on a "<<day_of_the_week[i]<<".";

     return 0;



}
