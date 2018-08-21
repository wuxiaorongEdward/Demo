#include<stdio.h>

#define maxSize 100

typedef struct Node{
    int data[maxSize];
    int length;
}Sqlist;

//insert a number in the index i

int InsertN(Sqlist *list, int i, int number)
{
     int j;
     if(i < 0 || i > list->length)
           return 0;
     if(list->length > maxSize)
          return 0;
    for(j = list->length - 1; j >= i; j--)
        list->data[j+1] = list->data[j];
    list->data[i] = number;
    list->length++;
    return 1;
}

//display the sequence
void display(Sqlist *list)
{
   int i;
   for(i = 0; i < list->length; i++)
     printf("%d\t", list->data[i]);
   printf("\n");
}

//delete the number in the index i
int DeleteN(Sqlist *list, int i)
{
  
    int j;
    if(i < 0 || i > list->length -1)
         return 0;
    for(j = i; j < list->length -1; j++)
           list->data[j] = list->data[j+1];
    (list->length)--;
    return 1;
}


int main()
{
   Sqlist list;
   int status;
   list.data[0] = 1;
   list.data[1] = 2;
   list.data[2] = 3;
   list.length = 3;
   status = InsertN(&list, 1, 60);
   if(status)
      {
          printf("Insert successfully !\n");
         display(&list);
          }
   else
      printf("Failing !\n");
   status = DeleteN(&list, 1);
   if(status)
       {
         printf("Delete successfully !\n");
         display(&list);
         }
   else
       printf("Failing \n");

   return 0;
}
