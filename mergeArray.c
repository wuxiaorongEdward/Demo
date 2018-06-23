#include<stdio.h>

void mergeOfArray(int a[], int m, int b[], int n, int c[])
{ 
    int i, j, q;
     i = j = q = 0;
     while(i < m && j < n)
        {
            if(a[i] < b[j])
               c[q++] = a[i++];
            else 
               c[q++] = b[j++];
       }
    while(i < m) c[q++] = a[i++];
    while(j < n) c[q++] = b[j++]; 
}

int main()
{
   int i;
   int a[4] = {1, 3, 5, 7};
   int b[5] = {2, 4, 6, 8, 10};
   int c[9];
   mergeOfArray(a, 4, b, 5, c);
   for(i = 0; i < 9; i++)
      printf("%d\t", c[i]);
   printf("\n");
   return 0;
}
