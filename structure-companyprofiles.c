#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CompanyProfiles
{
    char name[100];
    int age;
} CompanyProfiles;

const char* findOldest(CompanyProfiles *profiles, int n)
{
    if(n<=0) return NULL;
    int max_idx = 0;
    for(int i=0; i<n; i++)
    {
        if(profiles[i].age > profiles[max_idx].age)
        {
            max_idx = i;
        }
    }
    return profiles[max_idx].name;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
  CompanyProfiles *arr;
  arr = malloc(n * sizeof(CompanyProfiles));
  
  char str[100];
  int x = 0;
  for(int i = 0; i< n; i++) 
  {
      printf("Enter Company[%d] Name: ", i+1);
      scanf("%99s", &str);
      strcpy(arr[i].name, str);
    
     printf("Enter Company[%d] age: ", i+1);
      scanf("%d", &x);
      arr[i].age =  x;
  }
  
  printf("Oldest compnay is: %s\n", findOldest(arr, n));
  return 0;
}