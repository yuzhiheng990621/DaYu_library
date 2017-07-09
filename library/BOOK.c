/**
 *
 * 文件名: BOOK.c
 * 描  述: 用于实现简易图书馆的小功能
 * 作  者: 大鱼
 *
 **/
#include "BOOK.h"
Book * pHead = NULL;           //链表首元素
Book * pEnd;            //链表尾元素
int BookCount = 0;      //当前图书的数量
/* 图书馆菜单 */
void Menu()
{
    for(;;)
    {
        printf("\n************************************\n");
        printf("\n欢迎来到上帝的藏书阁\n");
        printf("1.浏览图书\n");
        printf("2.增加图书\n");
        printf("3.删除图书\n");
        printf("4.查找或者修改图书\n");
        printf("\n************************************\n");
        printf("请选择:");
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
/* 增加图书 */
void AddBook()
{
    Book * pNew;        //新增
    for(;;)
    {
        pNew = (Book *)malloc(sizeof(Book));      //给空间
        printf("请输入新增图书的书名:");
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
        printf("是否继续增加(y/n)?\n");
        key = getch();
        if(key == 'n' || key =='N')
            {
                break;
                }
    }
}

/* 浏览图书 */
void LookBook()
{
    Book * preBook = pHead;     //向导的上一个房间
    Book * LeadBook = pHead;    //向导 - 用于浏览已有数据
    int n = 1;
    if(LeadBook == NULL)
    {
        printf("图书馆内暂无图书！请添加图书!!!");
        return;
    }
    printf("编号\t书名\n");
    while(LeadBook != NULL)
    {
        printf("%d\t%s\n",n++,LeadBook->name);
        preBook = LeadBook;
        LeadBook = LeadBook->pNext;
    }
}

/* 删除图书 */
void delBook()
{
    Book * preBook = pHead;     //向导的上一个房间
    Book * LeadBook = pHead;    //向导 - 用于浏览已有数据
    if(LeadBook == NULL)
    {
        printf("图书馆内暂无图书！请添加图书!!!");
        return;
    }
    int n=1;
    char name[50];
    printf("请输入要删除的书籍:");
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
            free(LeadBook);//释放内存
            BookCount--;
            printf("成功删除书籍！(输入回车继续)");
            getchar();
            break;
        }
        preBook = LeadBook;
        LeadBook = LeadBook->pNext;
        n++;
    }
    if(i == 0)
    {
        printf("未找到书名为%s的书籍!(输入回车继续)",name);
        getchar();
    }
}
/* 查找图书/修改图书 */
void finBoook()
{
    Book * preBook = pHead;     //向导的上一个房间
    Book * LeadBook = pHead;    //向导 - 用于浏览已有数据
    if(LeadBook == NULL)
    {
        printf("图书馆内暂无图书！请添加图书!!!");
        return;
    }
    int n=1;
    char key;
    char name[50];
    printf("请输入要查找的书籍:");
    scanf("%s",name);
    getchar();
    int i=0;
    while(LeadBook != NULL)
    {
        if(strcmp(LeadBook->name,name) == 0)
        {
            i=1;
            printf("已找到书籍,是否更换书籍(y/n)?\n");
            key = getch();
            if(key == 'n' || key =='N')
            {
                break;
            }
            else
            {
                printf("请输入书籍:");
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
        printf("未找到书名为%s的书籍!(输入回车继续)",name);
        getchar();
    }
}













































