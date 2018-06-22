#include<stdio.h>

#define N 10

int main()
{
   int a[N] = {-2, 1, 3, 45, -89, 34, -1, 56, -90, 78};
  /* int i, j, temp;
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
     }*/
   int b[N];
   int i, j, q;
   for(i = 0, j = N -1, q = 0; i < N; i++ )
     {
        if(a[i] >= 0)
              b[j--] = a[i];
         else
               b[q++] =a[i]; 
       }
  
   for(i = 0; i < N; ++i)
      printf("%d\t", b[i]);
   printf("\n");
   return 0;
}
