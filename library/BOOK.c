/**
 *
 * �ļ���: BOOK.c
 * ��  ��: ����ʵ�ּ���ͼ��ݵ�С����
 * ��  ��: ����
 *
 **/
#include "BOOK.h"
Book * pHead = NULL;           //������Ԫ��
Book * pEnd;            //����βԪ��
int BookCount = 0;      //��ǰͼ�������
/* ͼ��ݲ˵� */
void Menu()
{
    for(;;)
    {
        printf("\n************************************\n");
        printf("\n��ӭ�����ϵ۵Ĳ����\n");
        printf("1.���ͼ��\n");
        printf("2.����ͼ��\n");
        printf("3.ɾ��ͼ��\n");
        printf("4.���һ����޸�ͼ��\n");
        printf("\n************************************\n");
        printf("��ѡ��:");
        int choose = 0;
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            LookBook();
            break;
        case 2:
            AddBook();
            break;
        case 3:
            delBook();
            break;
        case 4:
            finBoook();
            break;
        default :
            break;
        }
    }
}
/* ����ͼ�� */
void AddBook()
{
    Book * pNew;        //����
    for(;;)
    {
        pNew = (Book *)malloc(sizeof(Book));      //���ռ�
        printf("����������ͼ�������:");
        scanf("%s",pNew->name);
        pNew->pNext = NULL;
        BookCount++;
        if(BookCount == 1)
        {
            pHead = pNew;
            pEnd = pNew;
        }
        else
        {
            pEnd->pNext = pNew;
            pEnd = pEnd->pNext;
        }
        char key;
        printf("�Ƿ��������(y/n)?\n");
        key = getch();
        if(key == 'n' || key =='N')
            {
                break;
                }
    }
}

/* ���ͼ�� */
void LookBook()
{
    Book * preBook = pHead;     //�򵼵���һ������
    Book * LeadBook = pHead;    //�� - ���������������
    int n = 1;
    if(LeadBook == NULL)
    {
        printf("ͼ���������ͼ�飡�����ͼ��!!!");
        return;
    }
    printf("���\t����\n");
    while(LeadBook != NULL)
    {
        printf("%d\t%s\n",n++,LeadBook->name);
        preBook = LeadBook;
        LeadBook = LeadBook->pNext;
    }
}

/* ɾ��ͼ�� */
void delBook()
{
    Book * preBook = pHead;     //�򵼵���һ������
    Book * LeadBook = pHead;    //�� - ���������������
    if(LeadBook == NULL)
    {
        printf("ͼ���������ͼ�飡�����ͼ��!!!");
        return;
    }
    int n=1;
    char name[50];
    printf("������Ҫɾ�����鼮:");
    scanf("%s",name);
    getchar();
    int i=0;
    while(LeadBook != NULL)
    {
        if(strcmp(LeadBook->name,name) == 0)
        {
            if(n == 1)
            {
                pHead = pHead->pNext;
            }
            else
                preBook->pNext = LeadBook->pNext;
            i=1;
            free(LeadBook);//�ͷ��ڴ�
            BookCount--;
            printf("�ɹ�ɾ���鼮��(����س�����)");
            getchar();
            break;
        }
        preBook = LeadBook;
        LeadBook = LeadBook->pNext;
        n++;
    }
    if(i == 0)
    {
        printf("δ�ҵ�����Ϊ%s���鼮!(����س�����)",name);
        getchar();
    }
}
/* ����ͼ��/�޸�ͼ�� */
void finBoook()
{
    Book * preBook = pHead;     //�򵼵���һ������
    Book * LeadBook = pHead;    //�� - ���������������
    if(LeadBook == NULL)
    {
        printf("ͼ���������ͼ�飡�����ͼ��!!!");
        return;
    }
    int n=1;
    char key;
    char name[50];
    printf("������Ҫ���ҵ��鼮:");
    scanf("%s",name);
    getchar();
    int i=0;
    while(LeadBook != NULL)
    {
        if(strcmp(LeadBook->name,name) == 0)
        {
            i=1;
            printf("���ҵ��鼮,�Ƿ�����鼮(y/n)?\n");
            key = getch();
            if(key == 'n' || key =='N')
            {
                break;
            }
            else
            {
                printf("�������鼮:");
                scanf("%s",LeadBook->name);
                getchar();
                break;
            }

        }
        preBook = LeadBook;
        LeadBook = LeadBook->pNext;
        n++;
    }
    if(i == 0)
    {
        printf("δ�ҵ�����Ϊ%s���鼮!(����س�����)",name);
        getchar();
    }
}













































