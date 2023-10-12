#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define base_salary 60000
#define ta 5000
#define sda 30000

///structure

struct employee{
    int id;
    long int salary;
    char name[100];
  unsigned  int ssn;
}s[10];

enum post{hr=0,sales=1,software=2,research=3,executive=4};

///////main fucntion

int main()
{
   srand(time(0));
int i=0, n ;

printf("\t\t\tCOMPANY\t\t\t\n\n");
printf("employee details\n");
while(i<10)
{
printf("\n\n EMPLOYEE %d\n",i+1);
printf("name :");
scanf("%s",s[i].name);
printf("id no :");
scanf("%d",&s[i].id);
i++;
}

//salary generator and ssn generator

for(i=0;i<10;i++)
{
     s[i].ssn=(rand()%999999999 + 111111111);
    n = rand()%4+0;
    
  
  if(n>=0 || n<=1)
  {
      
      s[i].salary = (base_salary+(rand()%25000+10000));
      
  }
    else if(n>1 || n<=2)
    {
        
    s[i].salary = (base_salary+ta+(rand()%50000+30000));
    }
    else if(n>=3||n<=4)
    {
       
    s[i].salary=(base_salary+ta+sda+(rand()%85000+75000));
    }
    
}
//////printing details

printf("\t\t\t*******************************************\n");
printf("ID\tNAME\tSSN\t\t\tsalary\t\tpost\n");


for(i=0;i<10;i++)
{


printf("%d\t",s[i].id);
printf("%s\t",s[i].name);
printf("%d\t\t",s[i].ssn);
printf("%d\t\t",s[i].salary);

if(s[i].salary<=180000 && s[i].salary>=115000)
printf("executive\n");

else if(s[i].salary<=115000 && s[i].salary>=100000)
printf("research\n");

else if(s[i].salary<=100000 && s[i].salary>=85000)
printf("software\n");

else if(s[i].salary<=85000 && s[i].salary>=80000)
printf("hr\n");

else if(s[i].salary<80000)
printf("sales\n");


}

return 0;
getch();
}


