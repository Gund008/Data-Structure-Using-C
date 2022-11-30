#include<stdio.h>
#include<stdlib.h>

struct node 
{
   int data;
   struct node *next;
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
   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;

   if(*First==NULL)
   {
      *First=newn;
   }
   else             
   {
      newn->next=*First;
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
   newn=(PNODE)malloc(sizeof(NODE));

   newn->data=no;
   newn->next=NULL;

   if(*First==NULL)
   {
      *First=newn;
   }
   else
   {
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
      temp->next=newn;
   }
 }

/////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Display
Description:Used to Display node  of linked list
Parameter:Address of First Pointer 
Return Value:Void
*/

void Display(PNODE First)
{
   printf("Enter the elements of linked list:\n");
   while(First!=NULL)
   {
      printf("| %d |->",First->data);
      First=First->next;
   }
   printf("NULL\n");
}

///////////////////////////////////////////////////////////////////////////////////////
/*
Function name:Count
Description:Used to count node  of linked list
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
//////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteFirst
Description:Used to Delete at First position of linked list
Parameter:Address of First Pointer
Return Value:Void
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
   free(temp);
  }
}

////////////////////////////////////////////////////////////////////////////////////////
/*
Function name:DeleteLast
Description:Used to Delete at Last position of linked list
Parameter:Address of First Pointer 
Return Value:Void
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
///////////////////////////////////////////////////////////////////////////////////////

/*
Function name:InsertAtPosition
Description:Used to insert at  position of linked list
Parameter:Address of First Pointer and position , Data of Node
Return Value:Void
*/

void InsertAtPos(PPNODE First,int no,int ipos)
{
   PNODE newn=NULL;
   PNODE temp=*First;
   int iCnt=0,NodeCnt=0;
   NodeCnt=Count(*First);

   if((ipos<1)||(ipos>NodeCnt+1))
   {
      printf("Invalid Position\n");
      return;
   }
   if(ipos==1)
   {
      InsertFirst(First,no);
   }
   else if(ipos==NodeCnt+1)
   {
     InsertLast(First,no);
   }
   else
   {
     newn=(PNODE)malloc(sizeof(NODE));

     newn->data=no;
     newn->next=NULL;

     for(iCnt=1;iCnt<ipos-1;iCnt++)
     {
      temp=temp->next;
     }
   newn->next=temp->next;
   temp->next=newn;

   }
}

//////////////////////////////////////////////////////////////////////////////////////

/*
Function name:DeleteAtPosition
Description:Used to Delete at  position of linked list
Parameter:Address of First Pointer and position 
Return Value:Void
*/

void DeleteAtPos(PPNODE First,int ipos)
{
   PNODE temp1=NULL;
   PNODE temp2=NULL;
   PNODE temp=*First;
   int iCnt=0,NodeCnt=0;
   NodeCnt=Count(*First);

   if((ipos<1)||(ipos>NodeCnt))
   {
      printf("Invalid Position\n");
      return;
   }
   if(ipos==1)
   {
      DeleteFirst(First);
   }
   else if(ipos==NodeCnt)
   {
     DeleteLast(First);
   }
   else
   {
     for(iCnt=1;iCnt<ipos-1;iCnt++)
     {
      temp1=temp1->next;
     }
    temp2=temp1->next;
    temp1->next=temp2->next;
    free(temp2);
   }
}

//////////////////////////////////////////////////////////////////////////////////////

int main()
{
   PNODE Head=NULL;  
   int iRet=0;

   InsertFirst(&Head,51);  //call by address
   InsertFirst(&Head,21);
   InsertFirst(&Head,11);

   Display(Head);   //call by value

   iRet=Count(Head);
   printf("Count the number of linked list node:%d\n",iRet);

   InsertLast(&Head,101);
   InsertLast(&Head,111);
   InsertLast(&Head,121);

   Display(Head);

   iRet=Count(Head);
   printf("Count the number of linked list node:%d\n",iRet);

   InsertAtPos(&Head,122,5);

   Display(Head);

   iRet=Count(Head);
   printf("Count the number of linked list node:%d\n",iRet);

   DeleteFirst(&Head);
   Display(Head);

   iRet=Count(Head);
   printf("Count the number of linked list node:%d\n",iRet);

   DeleteLast(&Head);
   Display(Head);

   iRet=Count(Head);
   printf("Count the number of linked list node:%d\n",iRet);

   DeleteAtPos(&Head,5);

   Display(Head);

   iRet=Count(Head);
   printf("Count the number of linked list node:%d\n",iRet);
   return 0;

}


