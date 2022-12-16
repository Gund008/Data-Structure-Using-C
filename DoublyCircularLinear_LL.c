#include<stdio.h>
#include<stdlib.h>

//Structure Declaration
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to Insert at first position of linked list
Parameter:Address of First node and Last Node,Data of Node
Return Value:Void
*/
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
        (*First)->prev=newn;
        *First=newn;
    }
     (*Last)->next=*First;
     (*First)->prev=*Last;
        
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to insert at Last position of linked list
Parameter:Address of First and Last Pointer
Return Value:Void
*/

void Display(PNODE First,PNODE Last)  //call by value
{
    if((First==NULL)&&(Last==NULL))
    {
        printf("Linked list is empty\n");
        return;
    }

    printf("Linked list elements are:\n");
    do
    {
        printf("|%d|<=>",First->data);
        First=First->next;
    }while(First!=Last->next);
    printf("\n");
}

/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to Count of node in linked list
Parameter: Address of First And Last Pointer
Return Value:int
*/
int Count(PNODE First,PNODE Last)
{
    int iCnt=0;
    if((First==NULL)&&(Last==NULL))  //filter
    {
       return iCnt;
    }

    do
    {
        iCnt++;
        First=First->next;
    }while(First!=Last->next);
    return iCnt;
}
//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to Insert at Last position of linked list
Parameter:Address of First Pointer and Last Pointer,Data of Node
Return Value:Void
*/
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
    }
     (*Last)->next=*First;
     (*First)->prev=*Last;
}
//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete at First position of linked list
Parameter:Address of first and Last pointer
Return Value:Void
*/
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
        (*First)=(*First)->next;
        free((*Last)->next);

        (*Last)->next=*First;
        (*First)->prev=*Last;
        
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to Delete at Last position of linked list
Parameter:Address of First and Last Poniter
Return Value:Void
*/
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
        *Last=(*Last)->prev;
        free((*First)->prev);

       (*Last)->next=*First;
       (*First)->prev=*Last;
       
    }
}
////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPos
Description:Used to InsertAt Any  position of linked list
Parameter:Data of Node,Address of First  And Last Pointer,and Postion of node.
Return Value:Void
*/

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
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPos
Description:Used to Delete at Any position of linked list
Parameter:Address of First and Last Pointer,and Position of node.
Return Value:Void
*/
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
////////////////////////////////////////////////////////////////////////////////////////

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
