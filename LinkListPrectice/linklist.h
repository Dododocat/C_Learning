#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
/* linklist.h, 聯節串列的標頭檔 */
struct node
{
    int data;           /* 資料成員 */
    struct node *next;  /* 鏈結成員，存放指向下一個節點的指標。 */
};
typedef struct node NODE;

NODE *createList(int *, int );    /* 串列建立函數 */
void printList(NODE *);           /* 串列列印函數 */
void freeList(NODE *);            /* 釋放串列記憶空間函數 */
void insertNode(NODE *, int );    /* 插入節點函數 */
NODE *searchNode(NODE *, int );   /* 搜尋結點函數 */
NODE *deleteNode(NODE *, NODE *); /* 刪除節點函數 */
int listLength(NODE *);           /* 計算list的長度 */
void combineList(NODE *, NODE *); /* 合併鏈結 */



#endif // LINKLIST_H_INCLUDED
