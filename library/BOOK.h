#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ͼ��ṹ */
struct book{
    char name[50];      //ͼ������
    struct book * pNext;//ָ����һ����
};
typedef struct book Book;

/* ͼ��ݲ˵� */
void Menu();
/* ����ͼ�� */
void AddBook();
/* ���ͼ�� */
void LookBook();
/* ɾ��ͼ�� */
void delBook();
/* ����ͼ��/�޸�ͼ�� */
void finBoook();
#endif // BOOK_H_INCLUDED
