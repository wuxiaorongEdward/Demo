#include<stdio.h>
#include<stdlib.h>

typedef int Elem;
typedef struct LNode{
     Elem data;
     struct LNode *next;
}LNode, *linknode;

LNode * createFromTrail(linknode head)
{
       Elem num;
       linknode s, r;
       head = (LNode *)malloc(sizeof(LNode));
       head->next = NULL;
       r = head;
       scanf("%d", &num);
       while(num != -1)
         {
          s = (LNode *)malloc(sizeof(LNode));
          s->data = num;
          r->next = s;
          r = s;
          scanf("%d", &num);
}
       r->next = NULL;
       return head;
}

LNode * unionlink(linknode a, linknode b)
{
   linknode p, q, s, r;
  // p = a->next;
   q = b->next;
   while(q)
        {
          p = a->next;
         while(p)
             {
               r = p;
               if(q->data != p->data)
                  {
                     p = p->next;
                   }
             }
         if(!p)
            {
               s = (LNode *)malloc(sizeof(LNode));
               s->data = q->data;
               r->next = s;
               s->next = NULL;
              }
           q = q->next; 
         }
     return a;
}

void display(linknode head)
{
    linknode p;
   p = head->next;
   while(p)
     {
       printf("%d\t", p->data);
       p = p->next;
}
       printf("\n");
}

int main()
{
    linknode a, b, l;
    printf("please input a : ");
    a = createFromTrail(a);
    printf("please input b : ");
    b = createFromTrail(b);
    display(a);
    display(b);
    printf("union link :\n");
    l = unionlink(a, b);
    display(l);
    return 0;
    
}
