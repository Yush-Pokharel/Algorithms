#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *next;
};
 struct node *head=NULL;



struct node* create(int n)
{
    struct node *p;
	head=(struct node*)malloc(sizeof(struct node)); 	//head is created
    head->next=NULL;						//head address is null
    printf("Enter data 1:");
    scanf("%d",&(head->data));				//head gets data

    p=head;								//p gets address of head
    for(int i=1; i<n; i++)
    {
        p->next=(struct node*)malloc(sizeof(struct node));	//head address changes from null(loop1),(loop2)previously temp node has now new address to be stored
        p=p->next;						//temp node is loaded with the head address,(loop2 the new address now is second temp node
        printf("Enter data %d:",i+1);			//temp node gets data
        scanf("%d",&(p->data));
        p->next=NULL;						//temp node has address stored as NULL
    }
    return head;
}
void insert_atfirst(int item)
{
    struct node *nnode;
    nnode=(struct node*)malloc(sizeof(struct node));
    nnode->data=item;
    nnode->next=head;
    head=nnode;
}

void insert_position(int item)
{
    struct node *nnode;
    struct node *temp;
    int p,i;
    temp=head;				//temp does the work on head
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=item;
    if(head==NULL)
    {
        nnode->next=NULL;
        head=nnode;
    }
    else
    {
        printf("enter position");
        scanf("%d",&p);
        for(i=1; i<p-1; i++)
        {
            temp=temp->next;
        }
        nnode->next =temp->next;
        temp->next=nnode;			//temp is doing work on head address
    }
}

void insert_atlast(int item)
{
    struct node *nnode;
    struct node *temp;
    int p,i;
    temp=head;				//temp does the work on head
    nnode=(struct node *)malloc(sizeof(struct node));
    nnode->data=item;
    if(head==NULL)
    {
        nnode->next=NULL;
        head=nnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        nnode->next=NULL;
        temp->next=nnode;
    }
}

void delete_first()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("void deletion");
        return;
    }
    else
    {
        temp=head;
        head=head->next;
        free(temp);		//freeing up the deleted data
    }
}

void delete_last()
{
    struct node *temp,*hold;
    if(head==NULL)
    {
        printf("void deletion");
        return;
    }
    else if(head->next==NULL)
    {
        hold=head;
        head=NULL;
        free(hold);
    }		//if head has only one node
    else
    {
        temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        hold=temp->next;
    }
    temp->next=NULL;
    free(hold);
}

void delete_nth()
{
    struct node *temp,*hold;
    int pos,i;
    if(head==NULL)
    {
        printf("void deletion");
        return;
    }
    else
    {
        temp=head;
        printf("enter position to delete node");
        scanf("%d",&pos);
        for(i=1; i<pos-1; i++)
        {
            temp=temp->next;
        }
        hold=temp->next;
        temp->next=hold->next;
        free(hold);
    }
}

void print()
{
    struct node *temp;
    temp=head;
    int pos,i=0;
    printf("enter position to print node");
    scanf("%d",&pos);
    printf("the nodes are");
    while(temp!=NULL)
    {
        if(i==pos)
            printf("%d\t",temp->data);
        temp=temp->next;
        i++;
    }
}

void traverse()
{
    struct node *temp;
    temp=head;
    printf("the nodes are");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void count()
{
    int cnt=0;
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
    }
    printf("total nodes%d",cnt);
}

void search()
{
    int flag=0;
    int key,pos;
    printf("enter item to be searched");
    scanf("%d",&key);
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        pos++;
        if(key==temp->data)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag)
    {
        printf("The item %d was found at position %d",key, pos);
    }
}

int main()
{
    printf("enter number of nodes to be create");
    int first;
    scanf("%d",&first);
    create(first);
    do
    {
    	system("cls");
        printf("1.Insert at first\n");
        printf("2.Insert at given position\n");
        printf("3.Insert at end\n");
        printf("4.Delete first node\n");
        printf("5.Delete nth node\n");
        printf("6.Delete last node\n");
        printf("7.Display node\n");
        printf("8.Display all nodes\n");
        printf("9.Search item\n");
        printf("10.Count nodes\n");
        //printf("11.Concatenation\n");
        printf("11.Exit\n");
        int ch,item;
        printf("Enter choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {
            printf("enter item to be inserted");
            scanf("%d",&item);
            insert_atfirst(item);
            break;
        }
        case 2:
        {
            printf("enter item to be inserted");
            scanf("%d",&item);
            insert_position(item);
            break;
        }
        case 3:
        {
            printf("enter item to be inserted");
            scanf("%d",&item);
            insert_atlast(item);
            break;
        }
        case 4:
        {
            delete_first();
            break;
        }
        case 5:
        {
            delete_nth();
            break;
        }
        case 6:
        {
            delete_last();
            break;
        }
        case 7:
        {
            print();
            break;
        }
        case 8:
        {
            traverse();
            break;
        }
        case 9:
        {
            search();
            break;
        }
        case 10:
        {
            count();
            break;

        }
        case 11:
        {
            exit(0);
        }
        default:
            printf("wrong choice");

        }

	getch();
    }
    while(1);
}