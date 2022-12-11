#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertFirst
Description:Used to insert at first position of linked list
Parameter:Address of First Pointer and Last Pointer Data of Node
Return Value:Void
*/

void InsertFirst(PPNODE First,PPNODE Last,int no)
{
    PNODE newn=NULL;  
    newn=((PNODE)malloc(sizeof(NODE)));

    newn->data=no;
    newn->next=NULL;

    if((*First==NULL) && (*Last==NULL))  
    {
        *First=*Last=newn;
    }
    else
    {
        newn->next=*First;
        *First=newn;
        (*Last)->next=*First;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertLast
Description:Used to insert at Last position of linked list
Parameter:Address of First Pointer and Last Pointer Data of Node
Return Value:Void
*/
void InsertLast(PPNODE First,PPNODE Last,int no)
{
    PNODE newn=NULL;  
    newn=((PNODE)malloc(sizeof(NODE)));

    newn->data=no;
    newn->next=NULL;

    if((*First==NULL) && (*Last==NULL))  
    {
        *First=*Last=newn;
    }
    else
    {
        (*Last)->next=newn;
        *Last=newn;
        (*Last)->next=*First;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete First Elements from  linked list
Parameter:Address of First Pointer And Last Pointer of linked list
Return Value:void
*/


void deleteFirst(PPNODE First,PPNODE Last)
{
        PNODE temp=*First;
       if((*First)&&(*Last)==NULL)
       {
         return;
       }
       else if(*First==*Last)
       {
           free(*First);
           *First=NULL;
           *Last=NULL;
       }
       else
       {
           (*First)=(*First)->next;
           free(temp);
           (*Last)->next=(*First);
       }       
}

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to Delete First Elements And Delete last element of linked list
Parameter:Address of First Pointer And Last Pointer of linked list
Return Value:void
*/

void deleteLast(PPNODE First,PPNODE Last)
{
    PNODE temp=*First;
    if((*First)&&(*Last)==NULL)
    {
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        *First=NULL;
        *Last=NULL;
    }
    else
    {
        while(temp->next!=(*Last))
        {
            temp=temp->next;
        }
        free (temp->next);
        (*Last)=temp;
        (*Last)->next=*First;
        
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Display of linked list
Parameter:Address of First Pointer and Address of Last pointer
Return Value:Void
*/
void Display(PNODE First,PNODE Last)
{
    printf("Linked list Elements are:\n");
    do
    {
        printf("|%d|->",First->data);
        First=First->next;
    }while(First!=Last->next);
    printf("\n");

}

///////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to Count  of Elements  linked list
Parameter:Address of First Pointer And Address of Last Pointer
Return Value:int
*/
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

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:InsertAtPos
Description:Used to Delete First Elements  linked list
Parameter:Address of First Pointer and  Last Pointer Position Accept user,And Number  
Return Value:void
*/
void InsertAtPos(PPNODE First,PPNODE Last, int no,int ipos)
{
      int iNodeCnt=0;
      int iCnt=0;
      PNODE temp=*First;
      iNodeCnt=Count(*First,*Last);

      if((ipos<1)||(ipos>iNodeCnt+1))
      {
          printf("Invalid position:\n");
          return;
      }

      if(ipos==1)
      {
          InsertFirst(First,Last,no);
      }
      else if(ipos==iNodeCnt+1)
      {
         InsertLast(First,Last,no);
      }
      else
      {
         PNODE newn=NULL;
         newn=(PNODE)malloc(sizeof(NODE));
         newn->data=no;
         newn->next=NULL;

         for(iCnt=1;iCnt<ipos-1;iCnt++)
         {
            temp=temp->next;
         }
         newn->next=temp->next;
         temp->next=newn;
         (*Last)->next=(*First);
      }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteAtPos
Description:Used to Delete First Elements  linked list
Parameter:Address of First Pointer  and Address of last pointe, Position Accept in User
Return Value:void
*/
void DeleteAtPos(PPNODE First,PPNODE Last,int ipos)
{
      int iNodeCnt=0;
      int iCnt=0;
      PNODE temp1=*First;
      PNODE temp2=NULL;
      
      iNodeCnt=Count(*First,*Last);

      if((ipos<1)||(ipos>iNodeCnt)) //filter
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
        for(iCnt=1;iCnt<ipos-1;iCnt++)
         {
            temp1=temp1->next;
         }
         temp2=temp1->next;
         free(temp2);
         temp1->next=temp2->next;
      }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //Struct node *head=NULL;
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iRet=0;
    

    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);    //call by Address

    Display(Head,Tail);
    iRet=Count(Head,Tail);   //call by Value
    printf("Total Count of Linked list is:%d\n",iRet);

    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);
    InsertLast(&Head,&Tail,151);

    Display(Head,Tail);
    iRet=Count(Head,Tail);   //call by Value
    printf("Total Count of Linked list is:%d\n",iRet);
    
    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);
    iRet=Count(Head,Tail);   //call by Value
    printf("Total Count of Linked list is:%d\n",iRet);

    DeleteAtPos(&Head,&Tail,5);
    Display(Head,Tail);
    iRet=Count(Head,Tail);   //call by Value
    printf("Total Count of Linked list is:%d\n",iRet);
    
    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);   //call by Value
    printf("Total Count of Linked list is:%d\n",iRet);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iRet=Count(Head,Tail);   //call by Value
    printf("Total Count of Linked list is:%d\n",iRet);

    return 0;

}
