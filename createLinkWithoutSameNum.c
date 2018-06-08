#include<stdio.h>
#include<stdlib.h>
typedef int Elem;
typedef struct LNode{
      Elem data;
      struct LNode *next;  
}LNode, *LinkNode;

void CreateFromTrail(LinkNode *head)
{
        Elem num;
        LinkNode p, r, q;
        *head = (LinkNode)malloc(sizeof(LNode));
       ( *head)->next = NULL;
        r = *head;
      printf("input positive num, if the number occurs only once, store it <-1 to exit>\n");
       scanf("%d", &num);
       
        while(num != -1)
             {
              q = (*head)->next;
              while(q)
                   {
                  if(q->data == num)
                     break;
                   q = q->next;
                }
          if(!q)
           {
              p = (LinkNode)malloc(sizeof(LNode));
              p->data = num;
              r->next = p;
              r = p;
           }
                    scanf("%d", &num);
           } 
}

void display(LinkNode head)
{
           LinkNode p;
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
    LinkNode p;
    CreateFromTrail(&p);
    display(p);
     return 0;
}
