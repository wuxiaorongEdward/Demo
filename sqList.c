#include<stdio.h>

#define maxSize 50
typedef int ElemType;

     ElemType data[maxSize];
     int length;

int  listInsert(ElemType L[], int pos, ElemType e)
{
    int i;
    if(pos < 1 || pos > length+1)
           return 0;
   if(length >=maxSize)
          return 0;
   for(i = length; i >= pos; i--)
        L[i] = L[i];
   L[pos -1] = e;
   length++;
   return 1;   
}

void printL(ElemType L[])
{
     int i;
     for(i = 0 ; i < length; i++)
        printf("%4d", L[i]);
    printf("\n");
}

int main()
{
    int ret;
   // ElemType data;
    data[0] = 1;
    data[1] = 2;
    data[2] = 3;
    length = 3;
   ret = listInsert(data, 2, 60);
   if(ret)
          printL(data);
   return 0; 
}
