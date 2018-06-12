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

LNode * MergeTwoorderLink(linknode a, linknode b)
{
   linknode head,r,s, p, q;
   head = (LNode *)malloc(sizeof(LNode));
   head->next = NULL;
   r = head;
   p = a->next;
   q = b->next;
   while(p && q)
      {
       if(p->data > q->data)
             {
               s = (LNode *)malloc(sizeof(LNode));
               s->data = q->data;
               r->next = s;
               r = s;
               q = q->next;
                 }
        else
             {
               s = (LNode *)malloc(sizeof(LNode));
               s->data = p->data;
               r->next = s;
               r = s;
               p = p->next;
             } 
     }
     if(!q)
         r->next = p;
     if(!p)
         r->next = q;
     return head;
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
    printf("merge order link :\n");
    
    l =  MergeTwoorderLink(a,b);
    display(l);
    return 0;
    
}
