#include<stdio.h>
#include<stdlib.h>
typedef int Elem;
typedef struct LNode
{
   Elem data;
   struct LNode *next;
}LNode;

LNode *CreateFromTail(LNode *head)
{
    int num;
    LNode *r, *s;
    head = (LNode *)malloc(sizeof(LNode));
    head->next = NULL;
    r = head;
    printf("Enter -1 to exit.\n");
    scanf("%d", &num);
    while(num != -1)
       {
         s = (LNode *)malloc(sizeof(LNode));
         s->data = num;
         r->next = s;
         r = s;
         scanf("%d", &num);
   }
   r->next =NULL;
   return head;
}
//  ordered
/*LNode *MergeLink(LNode *A, LNode *B)
{
     LNode *q, *p, *r;
     p = A->next;
     q = B->next;
     free(B);
     A->next = NULL;
     r = A;
     while(p && q)
       {
         if(p->data < q->data)
            {
               r->next = p;
               r = p;
               p = p->next;    
              }
          else
            {
               r->next = q;
               r = q; 
               q = q->next;   
        }
      }
    if(p)  r->next = p;
    if(q)  r->next = q;
    return A;
}
*/
// reversed
LNode *MergeLink1(LNode *A, LNode *B, LNode *C)
{
     LNode *q, *p, *s;
     p = A->next;
     q = B->next;
     C = A;
     free(B);
     C->next = NULL;
    // r = A;
     while(p != NULL && q != NULL)
       {
         if(p->data <= q->data)
            {
               s = p;
               p = p->next;    
               s->next = C->next; 
               C->next = s;
              }
          else
            {
               s = q;
               q = q->next;
               s->next = C->next; 
               C->next = s;   
        }
      }
    while(p != NULL)
            {
               s = p;
               p = p->next;    
               s->next = C->next; 
               C->next = s;
        }
        
    while(q != NULL)  
            {
               s = q;
               q = q->next;    
               s->next = C->next; 
               C->next = s;
        }
    return C;
}


void display(LNode *head)
{
    LNode *p;
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
   LNode *a, *b, *c;
   a = CreateFromTail(a);
   display(a);
   b = CreateFromTail(b);
   display(b);
  // a = MergeLink(a, b);
  // display(a);
   c = MergeLink1(a, b, c);
   display(c);
   return 0;
}
