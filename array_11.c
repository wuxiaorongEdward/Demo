#include<stdio.h>

#define MAX 101

int array[MAX];
int n;

int main()
{
      int i;
      printf("please input the number n : ");
      scanf("%d", &n);
      for(i = 0; i < n; i++)
         scanf("%d", &array[i]);
      for(i = 0; i < n; i++)
         printf("%d\t", array[i]);
      printf("\n");
       return 0;
}
