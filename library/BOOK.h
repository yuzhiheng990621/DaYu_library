#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 图书结构 */
struct book{
    char name[50];      //图书书名
    struct book * pNext;//指向下一本书
};
typedef struct book Book;

/* 图书馆菜单 */
void Menu();
/* 增加图书 */
void AddBook();
/* 浏览图书 */
void LookBook();
/* 删除图书 */
void delBook();
/* 查找图书/修改图书 */
void finBoook();
#endif // BOOK_H_INCLUDED
