/*Write a program to read the details of “n” Employees with following fields –
name, empid and salary and write the details into a file. Then read details from file
and display the name of employee who has highest salary.*/

#include<stdio.h>
struct Employee
{
    char name[30];
    int empid;
    double salary;
};

void main()
{
    FILE *fp;
    struct Employee e[10],res,temp;
    int i,n;
    fp = fopen("employee.dat","w");
    printf("Enter the limit:");
    scanf("%d",&n);
    printf("Enter the details of Employee\n");
    for(i=0;i<n;i++)
    {
        printf("Name:");
        scanf("%s",e[i].name);
        printf("EmpId:");
        scanf("%d",&e[i].empid);
        printf("Salary:");
        scanf("%lf",&e[i].salary);
        fwrite(&e[i],sizeof(e[i]),1,fp);
    }
    fclose(fp);

    fp = fopen("employee.dat","r");
    res.salary=-1.0;
    while(feof(fp) == 0)
    {
        fread(&temp,sizeof(temp),1,fp);
        if(res.salary < temp.salary)
        {
            res = temp;
        }
    }
    printf("Name of Employee with highest Salary:%s",res.name);
}