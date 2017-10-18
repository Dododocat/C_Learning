#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
    /* 建立LinkedList、列印與記憶體釋放 */
    NODE *first1;
    int arr1[]={1,2,3,4,5};
    first1=createList(arr1,5);
    printList(first1);
    freeList(first1);
    printf("\n");

    /* 節點的搜尋與插入 */
    NODE *first2, *node;
    int arr2[]={11,22,44,55};
    first2 = createList(arr2,4);
    printList(first2);
    node  = searchNode(first2, 22);
    insertNode(node,33);
    printList(first2);

    /* 刪除節點 */
    node  = searchNode(first2, 55);
    first2 = deleteNode(first2, node);
    printList(first2);

    first2 = deleteNode(first2, first2);
    printList(first2);
    first2 = deleteNode(first2, first2);
    printList(first2);
    first2 = deleteNode(first2, first2);
    printList(first2);
    first2 = deleteNode(first2, first2);
    printList(first2);
    printf("\n");

    /* 計算鏈節長度 */
    int arr3[] = {1,2,3,4,5,6,7,8,9};
    NODE *first3;
    first3 = createList(arr3,9);
    printList(first3);
    printf("Length of list = %d\n\n",listLength(first3));

    /* 合併鏈結 */
    int ar1[] = {12,43,56,34,98};
    int ar2[] = {36,77,99};
    NODE *fir1, *fir2;
    fir1 = createList(ar1,5);
    fir2 = createList(ar2,3);
    printList(fir1);
    printList(fir2);
    combineList(fir1,fir2);
    printList(fir1);

    return 0;
}

/* createList()，串列建立函數 */
NODE *createList(int *arr, int len)
{
    int i;
    NODE *first,*current,*previous;
    for (i=0;i<len;i++)
    {
        current = (NODE *) malloc(sizeof(NODE));
        current->data = arr[i];        /* 設定節點的資料成員 */
        if (i==0)
            first=current;
        else
            previous->next = current;  /* 把前一個節點的 next 指向目前的結點 */
        current->next = NULL;
        previous = current;
    }
    return first;
}

/* printList，串列建立函數 */
void printList(NODE* first)
{
    NODE* node = first;   /* 將node指向第一個節點 */
    if (first==NULL)      /* 如果串列是空的，則列印出 List is empty! */
            printf("List is empty!\n");
    else
    {
        while (node!=NULL)
        {
            printf("%3d", node->data);
            node=node->next;
        }
        printf("\n");
    }
}

/* freeList()，釋放串列記憶空間函數 */
void freeList(NODE* first)
{
    NODE *current,*tmp;
    current = first;
    while (current!=NULL)
    {
        tmp=current;
        current = current->next;
        free(tmp);
    }
}

/* 搜尋結點函數 */
NODE* searchNode(NODE* first, int item)
{
    NODE *node=first;
    while(node!=NULL)
    {
        if (node->data==item)
            return node;
        else
            node=node->next;
    }
    return NULL;
}

/* 插入節點函數 */
void insertNode(NODE *node, int item)
{
    NODE *newnode;
    newnode = (NODE *) malloc(sizeof(NODE));
    newnode->data = item;
    newnode->next = node->next;
    node->next = newnode;
}


/* 刪除節點函數 */
NODE *deleteNode(NODE *first, NODE *node)
{
    NODE *ptr = first;
    if(first==NULL)
    {
        printf("Nothing to be delete!\n");
        return NULL;
    }
    if(node==first)
        first = first->next;
    else
    {
        while (ptr->next != node)
            ptr = ptr->next;
        ptr->next = node->next;
    }
    free(node);
    return first;
}

/* 計算鏈節長度 */
int listLength(NODE *first)
{
    int L=0;
    NODE *node=first;
    while (node!= NULL)
    {
        L++;
        node = node->next;
    }
    return L;
}

/* 合併鏈結 */
void combineList(NODE *first1, NODE *first2)
{
    NODE* node = first1;
    while(node->next != NULL)
    {
        node = node->next;
    }
    node->next = first2;
}

