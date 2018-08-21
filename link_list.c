#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct LNode{
     ElemType data;
     struct LNode *next;
}LNode, *linkNode;

//create a linear with a header
linkNode create_head_insert(LNode *L)
{
    int x;
    LNode *s, *r;
    L = (linkNode)malloc(sizeof(LNode));
    L->next = NULL;
    r = L;
    scanf("%d", &x);
    while(x != -1)      //if x == -1, stop inputing
       {
         s = (linkNode)malloc(sizeof(LNode));
         s->data = x;
         r->next = s;
         r = s;
         scanf("%d", &x);
        }
        r->next = NULL;
    return L;
}
 
//create a linear from trail with a header
linkNode create_trail_insert(LNode *L)
{
      int x;
      LNode *s;
      L = (linkNode)malloc(sizeof(LNode));
      L->next = NULL;
      scanf("%d", &x);
      while(x != -1)  //x = -1, stop
          {
           s = (linkNode)malloc(sizeof(LNode));
           s->data = x;
           s->next = L->next;
           L->next = s;
           scanf("%d", &x);
           }
      return L;
}

//print the list
void printL(linkNode L)
{
    LNode *p;
   p = L->next;
   while(p)
       {
        printf("%4d", p->data);
        p = p->next;
        }
   printf("\n");
}

//find the the number in the position i
LNode * findN(linkNode L, int i)
{
      int j = 1;
      LNode *p;
      p = L->next;
      if(i < 1)
          return NULL;
      while(p && j < i)
        {
           p = p->next;
           j++;
           }
      return p;
}
 
//locate the number's position
LNode *LocateElem(linkNode L, ElemType e)
{
   LNode *p = L->next;
   while(p && p->data != e)
     p = p->next;
   return p;
} 
//insert a number in the position i
int insertN(linkNode L, int i, ElemType e)
{
     LNode *s, *p;
     s = findN(L, i - 1);
    if(!s)
     {
          return 0;
        }
    else
     {
         p = (linkNode)malloc(sizeof(LNode));
         p->data = e;
         p->next = s->next;
         s->next = p;
         return 1;
       }
}

//delete the number in the position i
int DeleteN(linkNode L, int i)
{
       LNode *p = findN(L, i - 1);
       LNode *s;
       if(p)
         {
           s = p->next;
           p->next = p->next->next;
           free(s);
           return 1;
           }
       else
          {
            return 0;
             }
}
int main()
{
   int flag;
   linkNode L;
   LNode *s, *search;
  // L = create_head_insert(L);
   L = create_trail_insert(L); // input 1 2 3 4 5 6 -1
   printL(L);
   s  = findN(L, 2);
  printf("%4d\n", s->data);
  search = LocateElem(L, 4);
  if(search != NULL)
       {
         printf("search successfully !\n");
         printf("%4d\n", search->data);
           }
  else
     printf("the number searched is not in the list \n");

   flag = insertN(L, 4, 80);  // insert 80 in the postion 4
   if(flag)
       {
           printf("insert successfully !\n");
           printL(L);
            }
   else
       printf("failure !");

  flag = DeleteN(L, 4);
  if(flag)
    {
        printf("delete successfully !\n");
        printL(L);
       }
  else
     {
         printf("failure !\n");
 }

   return 0;
}
