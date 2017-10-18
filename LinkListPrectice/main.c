#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int main()
{
    /* �إ�LinkedList�B�C�L�P�O�������� */
    NODE *first1;
    int arr1[]={1,2,3,4,5};
    first1=createList(arr1,5);
    printList(first1);
    freeList(first1);
    printf("\n");

    /* �`�I���j�M�P���J */
    NODE *first2, *node;
    int arr2[]={11,22,44,55};
    first2 = createList(arr2,4);
    printList(first2);
    node  = searchNode(first2, 22);
    insertNode(node,33);
    printList(first2);

    /* �R���`�I */
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

    /* �p����`���� */
    int arr3[] = {1,2,3,4,5,6,7,8,9};
    NODE *first3;
    first3 = createList(arr3,9);
    printList(first3);
    printf("Length of list = %d\n\n",listLength(first3));

    /* �X���쵲 */
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

/* createList()�A��C�إߨ�� */
NODE *createList(int *arr, int len)
{
    int i;
    NODE *first,*current,*previous;
    for (i=0;i<len;i++)
    {
        current = (NODE *) malloc(sizeof(NODE));
        current->data = arr[i];        /* �]�w�`�I����Ʀ��� */
        if (i==0)
            first=current;
        else
            previous->next = current;  /* ��e�@�Ӹ`�I�� next ���V�ثe�����I */
        current->next = NULL;
        previous = current;
    }
    return first;
}

/* printList�A��C�إߨ�� */
void printList(NODE* first)
{
    NODE* node = first;   /* �Nnode���V�Ĥ@�Ӹ`�I */
    if (first==NULL)      /* �p�G��C�O�Ū��A�h�C�L�X List is empty! */
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

/* freeList()�A�����C�O�ЪŶ���� */
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

/* �j�M���I��� */
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

/* ���J�`�I��� */
void insertNode(NODE *node, int item)
{
    NODE *newnode;
    newnode = (NODE *) malloc(sizeof(NODE));
    newnode->data = item;
    newnode->next = node->next;
    node->next = newnode;
}


/* �R���`�I��� */
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

/* �p����`���� */
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

/* �X���쵲 */
void combineList(NODE *first1, NODE *first2)
{
    NODE* node = first1;
    while(node->next != NULL)
    {
        node = node->next;
    }
    node->next = first2;
}

