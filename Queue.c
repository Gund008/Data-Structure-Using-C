#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Structure Declaration
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
/////////////////////////////////////////////////////////////////////////////////////////////////

bool IsQueueEmpty(PPNODE First)
{
    if(*First==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void EnQueue(PPNODE First,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
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
    printf("gets pushed in the stack Succesfully:\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////////
int DeQueue(PPNODE First)
{
   PNODE temp=*First;

    if(*First==NULL)
    {
        printf("Unable to Pop the elements as Stack is empty:\n");
        return -1;
    }
    else if((*First)->next==NULL)
    {
        free (*First);
        *First=NULL;
    }
    else
    {
        int ivalue=(*First)->data;

        *First=(*First)->next;
        free(temp);

        return ivalue;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE First)
{
    if(First==NULL)
    {
        printf("Stack is Empty:\n");
    }
    else
    {
        printf("Elements of Stack are:\n");
        while(First!=NULL)
        {
            printf("|%d|->",First->data);
            First=First->next;
        }
        printf("NULL\n");
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE First)
{
    int iCnt=0;
    if(First==NULL)
    {
        return 0;
    }
    else
    {
        while(First!=NULL)
        {
            iCnt++;
            First=First->next;
        }
    }
    return iCnt;
}
//////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE Head=NULL;
    int iRet=0;
    bool bRet=false;

    bRet=IsQueueEmpty(&Head);
    if(bRet==true)
    {
        printf("Linked list is empty:\n",bRet);
    }
    else
    {
        printf("Linked list is Full:\n",bRet);
    }

   EnQueue(&Head,11);
   EnQueue(&Head,21);
   EnQueue(&Head,51);
   EnQueue(&Head,101);

    Display(Head);
   
    iRet=DeQueue(&Head);
    printf("Poped Elements is:%d\n",iRet);
    
    iRet=DeQueue(&Head);
    printf("Poped Elements is:%d\n",iRet);

    Display(Head);
    iRet=Count(Head);
    printf("Count of linked list  is:%d\n",iRet);

    return 0;

}