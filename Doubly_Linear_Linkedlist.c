#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to insert at first position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:Void
*/
void InsertFirst(PPNODE First,int no)
{
    PNODE newn=NULL;
    newn=(PNODE)malloc(sizeof(NODE));    //12 Byte

    newn->data=no;
    newn->next=NULL;
    newn->next=NULL;

    if(*First==NULL)
    {
        *First=newn;   //Atleast One node insert
    }
    else
    {
       newn->next=*First;
       (*First)->prev=newn;
       *First=newn;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to insert at Last position of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:Void
*/
void InsertLast(PPNODE First,int no)
{
    PNODE newn=NULL;
    PNODE temp=*First;
    newn=(PNODE)malloc(sizeof(NODE));    //12 Byte

    newn->data=no;
    newn->next=NULL;
    newn->prev=NULL;

    if(*First==NULL)
    {
        *First=newn;   //Atleast One node insert
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        temp->prev=temp;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Display of linked list
Parameter:Address of First Pointer and Data of Node
Return Value:Void
*/
void Display(PNODE First)
{
    printf("Elements of linked list are\n");

    while(First!=NULL)
    {
        printf("|%d|<=>",First->data);
        First=First->next;
    }
    printf("NULL\n");
}
//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to Count  of Elements  linked list
Parameter:Address of First Pointer 
Return Value:int
*/
int Count(PNODE First)
{
    int iCnt=0;
    while(First!=NULL)
    {
        iCnt++;
        First=First->next;
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to Delete First Elements  linked list
Parameter:Address of First Pointer 
Return Value:void
*/
void DeleteFirst(PPNODE First)
{
    PNODE temp=*First;
    if(*First==NULL)
    {
        return;
    }
    else if((*First)->next==NULL)
    {
       free(*First);
       *First=NULL;
    }
    else
    {
      (*First)=(*First)->next;
      free((*First)->prev);
      (*First)->prev=NULL;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////

/*
Function name:DeleteLast
Description:Used to Delete First Elements  linked list
Parameter:Address of First Pointer 
Return Value:void
*/
void DeleteLast(PPNODE First)
{
     PNODE temp=*First;
    if(*First==NULL)
    {
        return;
    }
    else if((*First)->next==NULL)
    {
       free(*First);
       *First=NULL;
    }
    else
    {
      while(temp->next->next!=NULL)
       {
          temp=temp->next;
       }
       free(temp->next);
       temp->next=NULL;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////

/*
Function name:InsertAtPos
Description:Used to Delete First Elements  linked list
Parameter:Address of First Pointer and Position Accept user,Number  
Return Value:void
*/
void InsertAtPos(PPNODE First,int ipos,int no)
{
    PNODE temp=*First;
    int iNodeCnt=0;
    PNODE newn=NULL;
    int iCnt=0;

    iNodeCnt=Count(*First);
    if((ipos<1)||(ipos>(iNodeCnt+1)))
    {
        printf("Inavalid position:\n");
        return;
    }

    if(ipos==1)
    {
        InsertFirst(First,no);
    }
    else if(ipos==(iNodeCnt+1))
    {
        InsertLast(First,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));

        newn->data=no;
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
Description:Used to Delete First Elements  linked list
Parameter:Address of First Pointer  and Position Accept in User
Return Value:void
*/
void DeleteAtPos(PPNODE First,int ipos)
{
    int iNodeCnt=0;
    PNODE temp1=NULL;
    PNODE temp2=NULL;
    int iCnt=0;

    iNodeCnt=Count(*First);   
    if((ipos<1)||(ipos>iNodeCnt))
    {
        printf("Inavalid position:\n");
        return;
    }
    if(ipos==1)
    {
        DeleteFirst(First);  
    }
    else if(ipos==(iNodeCnt))
    {
        DeleteLast(First); 
    }
    else
    {
        temp1=*First;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
           temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp1->next->prev=temp1;
        free(temp2);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE Head=NULL;     //struct node *head=NULL;
    int iRet=0;
    
    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    Display(Head);
    iRet=Count(Head);
    printf(" Count Elements of Linked list Are:%d\n",iRet);

    
    InsertLast(&Head,111);
    InsertLast(&Head,121);

    Display(Head);
    iRet=Count(Head);
    printf(" Count Elements of Linked list Are:%d\n",iRet);
   
    InsertAtPos(&Head,5,101);
    Display(Head);
    iRet=Count(Head);
    printf(" Count Elements of Linked list Are:%d\n",iRet);

    
    DeleteAtPos(&Head,5);
    Display(Head);
    iRet=Count(Head);
    printf(" Count Elements of Linked list Are:%d\n",iRet);
 
    DeleteFirst(&Head);
    Display(Head);
    iRet=Count(Head);
    printf(" Count Elements of Linked list Are:%d\n",iRet);
   
    DeleteLast(&Head);
    Display(Head);
    iRet=Count(Head);
    printf(" Count Elements of Linked list Are:%d\n",iRet);
   
   
    return 0;

}