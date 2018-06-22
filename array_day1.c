#include<stdio.h>

#define N 10

int main()
{
   int a[N] = {-2, 1, 3, 45, -89, 34, -1, 56, -90, 78};
   int i, j, temp;
   i = 0; j = N - 1; 
   while(i < j)
     {
       while(a[i] < 0) i++;
      //  printf("%d\n", i);
       while(a[j] >= 0) j--;
       temp = a[i];
       a[i] = a[j];
       a[j] = temp;
       ++i;
       --j;
     }
   for(i = 0; i < N; ++i)
      printf("%d\t", a[i]);
   printf("\n");
   return 0;
}
