#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_LEN 100

struct EmployeeData
{
    char name[MAX_BUF_LEN];
    int experience;
    int salary;
};

int search(const char* employee, struct EmployeeData *emps, int count)
{
    if(!*employee && !employee) return -1;

    for(int i=0; i< count; i++)
    {
        if(strcmp(emps[i].name, employee) == 0)
        {
            return 0;
        }
    }
    return -1;
}

char* findNewbie(struct EmployeeData *emps, int count)
{
    int min_index = 0;
    if(count <= 0) return NULL;
    
    for(int i = 0; i< count; i++)
    {
        if(emps[i].experience < emps[min_index].experience)
        {
            min_index = i;
        }
    }
    return emps[min_index].name;
}
int main()
{
    int num= 0;
    printf("Enter no.of employees: \n");
    scanf("%d", &num);
    struct EmployeeData *emp = malloc( num * sizeof(struct EmployeeData));
    if(emp ==  NULL) return 1;

    for(int i = 0; i< num;i++)
    {
        char str[MAX_BUF_LEN];
        int exp =0, sal = 0;
        printf("Enter Name of Employee[%d]: ", i+1);
        scanf("%s", str);
        printf("Enter the work experience of the employee[%d]: ", i+1);
        scanf("%d", &exp);
        printf("Enter the salary of the employee[%d]: ", i+1);
        scanf("%d", &sal);

        strcpy(emp[i].name, str);
        emp[i].experience = exp;
        emp[i].salary = sal;
    }
    char key[MAX_BUF_LEN];

    printf("Enter the name of the employee to be searched: _");
    scanf("%99s", key);
    if(search(key, emp, num) == -1)
    {
        printf("Not found\n");
    }
    else
    {
        printf("Found\n");
    }

    printf("The newbie is: %s\n", findNewbie(emp, num));


}