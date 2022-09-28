#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 5

void createList(int list[])
{
    for(int i=0; i<size; i++)
    {
        list[i]=-1;
    }
}

int isFull(int list[])
{
    int count=0;
    for(int i=0; i<size; i++)
    {
        if(list[i]!=-1)
            count++;
        else
            return 0;
    }
    if(count==size)
        return 1;
    else
        return 0;
}

int isEmpty(int list[])
{
    int count=0;
    for(int i=0; i<size; i++)
    {
        if(list[i]==-1)
            count++;
        else
            return 0;
    }
    if(count==size)
        return 1;
    else
        return 0;
}

void insert(int list[],int el,int p)
{
    int temp1,k;
    int c=0;
    if(isFull(list)==1)
    {
        printf("list full");
        exit(1);
    }
    else
    {
        if(list[p]==-1)
            list[p]=el;

        else
        {
            for(int i=p; i<size; i++)
            {
                if(list[i]==-1)
                {
                    k=i;
                    break;
                }
            }
            for(int i=k; i>p; i--)
            {
                list[i]=list[i-1];
            }
            list[p]=el;
        }



    }


}

void update(int list[],int el,int p)
{
    if(isEmpty(list)==1)
    {
        printf("list full");
        exit(1);
    }
    else
    {
        list[p]=el;
    }
}
void removed(int list[],int p)
{
    if(isEmpty(list)==1)
    {
        printf("list empty");
        exit(1);
    }
    else
    {
        for(int i=p;i<size;i++)
	   {
	   	list[i]=list[i+1];
	   }
	   list[size-1]=-1;
    }
}

int print(int list[],int p)
{
    if(isEmpty(list)==1)
    {
        printf("list empty");
        exit(1);
    }
    else
    {
        return list[p];
    }
}

void traverse(int list[])
{
    if(isEmpty(list)==1)
    {
        printf("list empty");
        exit(1);
    }
    else
    {
        for(int i=0; i<size; i++)
            printf("%d,%d\n",i,list[i]);
    }
}


int main()
{
    int list[size];
    createList(list);
    int ch;
    do
    {
        system("cls");
        printf("1.Insert Element\n");
        printf("2.Update Element\n");
        printf("3.Remove Element\n");
        printf("4.Delete List\n");
        printf("5.Print Element\n");
        printf("6.Traverse List\n");
        printf("7.Exit\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {

            int el,p;
            printf("enter element");
            scanf("%d",&el);
insert:
            printf("enter position");
            scanf("%d",&p);
            if(p>=size)
                goto insert;
            else
                insert(list,el,p);

            break;
        }
        case 2:
        {
            int el,p;
            printf("enter element");
            scanf("%d",&el);
insert2:
            printf("enter position");
            scanf("%d",&p);
            if(p>=size)
                goto insert2;
            else
                update(list,el,p);
            break;
        }
        case 3:
        {
            int p;
insert3:
            printf("enter position");
            scanf("%d",&p);
            if(p>=size)
                goto insert3;
            else
                removed(list,p);
            break;
        }
        case 4:
        {
            createList(list);
            break;
        }
        case 5:
        {
            int p,el;
insert4:
            printf("enter position");
            scanf("%d",&p);
            if(p>=size)
                goto insert4;
            else
                el=print(list,p);
            printf("%d",el);
            break;
        }
        case 6:
        {
            traverse(list);
        }
        case 7:
        {
            break;
        }
        default:
        {
            printf("Wrong choice");
        }
        }
        getch();
    }
    while(1);
}