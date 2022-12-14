#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int iNo)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((*First==NULL)&&(*Last==NULL))
    {
        *First=*Last=newn;
    }
    else
    {
        newn->next=*First;
        newn->prev=*First;
        *First=newn;
        (*Last)->next=*First;
        (*First)->prev=*Last;
        
    }
}
/////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE First,PNODE Last)
{
    
    printf("Linked list elements are:\n");

    do
    {
        printf("|%d|<=>",First->data);
        First=First->next;
    }while(First!=Last->next);
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE First,PNODE Last)
{
    
    int iCnt=0;

    do
    {
        iCnt++;
        First=First->next;
    }while(First!=Last->next);
    return iCnt;
}
/////////////////////////////////////////////////////////////////////////////////////


void InsertLast(PPNODE First,PPNODE Last,int iNo)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if((*First==NULL)&&(*Last==NULL))
    {
        *First=*Last=newn;
    }
    else
    {
        (*Last)->next=newn;
        newn->prev=*Last;
        *Last=newn;
        (*Last)->next=*First;
        (*First)->prev=*Last;

    }
}
/////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE First,PPNODE Last)
{
    if((*First==NULL)&&(*Last==NULL))
    {
        return;
    }
    else if((*First)==(*Last))
    {
        free(*First);
        *First=NULL;
        *Last=NULL;
    }
    else
    {
        PNODE temp=*First;
        (*First)=(*First)->next;
        free(temp);
        (*Last)->next=*First;
        (*First)->prev=*Last;
        
    }
}
////////////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE First,PPNODE Last)
{
    if((*First==NULL)&&(*Last==NULL))
    {
        return;
    }
    else if((*First)==(*Last))
    {
        free(*First);
        *First=NULL;
        *Last=NULL;
    }
    else
    {
       PNODE temp=*First;
       while(temp->next->next!=(*First))
       {
         temp=temp->next;
       }
       free(temp->next);
       (*Last)=temp;
       (*Last)->next=*First;
       (*First)->prev=*Last;
       
    }
}
/////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE First,PPNODE Last,int iNo,int ipos)
{
     int iNodeCnt=0;
     iNodeCnt=Count(*First,*Last);

     if((ipos<1)||(ipos>iNodeCnt+1))  //filter
     {
        printf("Invalid position:\n");
        return;
     }

     if(ipos==1)
     {
        InsertFirst(First,Last,iNo);
     }
     else if(ipos==iNodeCnt+1)
     {
        InsertLast(First,Last,iNo);
     }
     else
     {

       int iCnt=0;
       PNODE temp=*First;
       PNODE newn=NULL;
       newn=(PNODE)malloc(sizeof(NODE));

       newn->data=iNo;
       newn->next=NULL;
       newn->prev=NULL;

       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
        temp=temp->next;
       }
       newn->next=temp->next;
       temp->next->prev=newn;
       temp->next=newn;
       newn->prev=temp;
     }
}
//////////////////////////////////////////////////////////////////

void DeleteAtPos(PPNODE First,PPNODE Last,int ipos)
{
     int iNodeCnt=0;
     iNodeCnt=Count(*First,*Last);

     if((ipos<1)||(ipos>iNodeCnt))  //filter
     {
        printf("Invalid position:\n");
        return;
     }

     if(ipos==1)
     {
        DeleteFirst(First,Last);
     }
     else if(ipos==iNodeCnt)
     {
        DeleteLast(First,Last);
     }
     else
     {
       int iCnt=0;
       PNODE temp1=*First;
       PNODE temp2=NULL;
       for(iCnt=1;iCnt<ipos-1;iCnt++)
       {
        temp1=temp1->next;
       }
       temp2=temp1->next;
       temp1->next=temp2->next;
       free(temp2);

     }
}
/////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iRet=0;

    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);

    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Count of linked list elements are:%d\n",iRet);

    InsertLast(&Head,&Tail,151);
    InsertLast(&Head,&Tail,121);
    InsertLast(&Head,&Tail,111);

    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Count of linked list elements are:%d\n",iRet);
   
    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Count of linked list elements are:%d\n",iRet);
   
   
    DeleteAtPos(&Head,&Tail,5);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Count of linked list elements are:%d\n",iRet);
   

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Count of linked list elements are:%d\n",iRet);
   
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("Count of linked list elements are:%d\n",iRet);
    
    return 0;

}