#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
/* linklist.h, �p�`��C�����Y�� */
struct node
{
    int data;           /* ��Ʀ��� */
    struct node *next;  /* �쵲�����A�s����V�U�@�Ӹ`�I�����СC */
};
typedef struct node NODE;

NODE *createList(int *, int );    /* ��C�إߨ�� */
void printList(NODE *);           /* ��C�C�L��� */
void freeList(NODE *);            /* �����C�O�ЪŶ���� */
void insertNode(NODE *, int );    /* ���J�`�I��� */
NODE *searchNode(NODE *, int );   /* �j�M���I��� */
NODE *deleteNode(NODE *, NODE *); /* �R���`�I��� */
int listLength(NODE *);           /* �p��list������ */
void combineList(NODE *, NODE *); /* �X���쵲 */



#endif // LINKLIST_H_INCLUDED
