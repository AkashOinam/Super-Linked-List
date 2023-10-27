#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

//functions for Singly Linked List

void Sinsertbeg(struct node **head)// insert at beginning
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next=*head;
    *head=newnode;
}
void Sinsertend(struct node **head)// insert at end
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void Sinsertanypos(struct node **head,int pos)// insert at any position
{  
}
void Sdeletebeg(struct node **head)// delete at beginning
{
        if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);

}
void Sdeleteend()// delete at end
{
}
void Sdeleteanypos()// delete at any position
{
}
void Ssearchbeg()// searching at beginning
{
}

//functions for Doubly Linked List

void Dinsertbeg()// insert at beginning
{
}
void Dinsertend()// insert at end 
{
}
void Dinsertanypos()// insert at any position
{
}
void Ddeletebeg()// delete at beginning
{
}
void Ddeleteend()// delete at end
{
}
void Ddeleteanypos()// delete at any position
{
}
void Dsearchbeg()// delete at beginning
{
}

//functions for Circular Linked List

void Cinsertbeg()// insert at begin
{   
}
void Cinsertend()// insert at end
{
}
void Cinsertanypos()// insert at any position
{
}
void Cdeletebeg()// delete at beginnning
{
}
void Cdeleteend()// delete at end
{
}
void Cdeleteanypos()// delete at any position
{
}
void Csearchbeg()// searching at beginning
{
}


// function for displaying 

void display(struct node *head) {
	struct node *temp = head;
	while (temp != NULL) {
		printf("%d | ", temp->data);
		temp = temp->next;
	}
}

int main()
{
    int i,n,pos;
    struct node *head = NULL;
    int opt1, opt2, opt3, opt4, opt5;
    printf("Choose the type of Linked list:\n");
    printf("1)Singly Linked list\n2)Doubly Linked List\n3)Circular Linked list\n");
    scanf("%d", &opt1);
    
    printf("Choose operation:\n");
    printf("1)Insert\n2)Delete\n3)Search\n");
    scanf("%d", &opt2);

    switch(opt1) {
        case 1: // Singly Linked list
        printf("Singly Linked List selected\n");
            switch(opt2) {
                case 1: // Insert
                    printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n");
                    scanf("%d", &opt3);
                    switch(opt3)
                    {
                        case 1:// insert at begin
                        printf("Insert at beginning:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Sinsertbeg(&head);
                        }
                        display(head);
                        break;
                        
                        case 2:// insert at end
                        printf("Insert at end:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Sinsertend(&head);
                        }
                        display(head);
                        break;
                        
                        case 3:// insert at any position
                        printf("Insert at any position:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Sinsertanypos(&head,pos);
                        }
                        display(head);
                        break;
                    }
                    break;
                case 2: // Delete
                    printf("1)Delete at beginning\n2)Delete at end\n3)Delete at any position\n");
                    scanf("%d", &opt4);
                    switch(opt4)
                    {
                        case 1:// delete at beginning
                        printf("Delete at beginning:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Sinsertend(&head);
                        }
                        display(head);
                        break;

                        case 2:// delete at end
                        printf("Delete at end:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Sinsertend(&head);
                        }
                        break;

                        case 3:// delete at any position
                        printf("Delete at any position");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Sinsertend(&head);
                        }
                        break;
                    }
                    break;
                case 3: // Search
                    break;
                default:
                    printf("Invalid operation selection.\n");
                    return 0;
            }
            break;

        case 2: printf("Doubly Linked list selected.\n");
        switch(opt2) {
                case 1: // Insert
                    printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n");
                    scanf("%d", &opt3);
                    switch(opt3)
                    {
                        case 1:// insert at beginning
                        printf("Enter the size of list:\n");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Dinsertbeg(&head);
                        }
                        display(head);
                        break;

                        case 2:// insert at 
                        printf("Enter the size of list:\n");
                        scanf("%d",n);
                        for(i=1;i<n;i++)
                        {
                            Dinsertend(&head);
                        }
                        display(head);
                        break;

                        case 3:// insert at any 
                        printf("Enter the size of list:\n");
                        scanf("%d",&n);
                        for(i=1;i<n;i++)
                        {
                            Dinsertanypos(&head);
                        }
                        display(head);
                        break;
                    }
                    break;
                case 2: // Delete
                    printf("1)Delete at beginning\n2)Delete at end\n3)Delete at any position\n");
                    scanf("%d", &opt4);
                    switch(opt4)
                    {
                        case 1:// delete at beginning
                        printf("Delete at beginning:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Dinsertend(&head);
                        }
                        break;

                        case 2:// delete at end
                        printf("Delete at end:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Dinsertend(&head);
                        }
                        break; 

                        case 3:// delete at any position
                        printf("Delete at any position:\n");
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Dinsertend(&head);
                        }
                    }
                    break;
                case 3: // Search
                    break;
                default:
                    printf("Invalid operation selection.\n");
                    return 0;
            }
            break;

        case 3: printf("Circular Linked list selected.\n");
        switch(opt3) {
                case 1: // Insert
                    printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n");
                    scanf("%d", &opt3);
                    switch(opt3)
                    {
                        case 1:// insert at beginning
                        printf("Enter the size of list: ");
                        scanf("%d", &n);
                        for (i = 0; i < n; i++)
                        {
                            Cinsertbeg(&head);
                        }
                        display(head);
                        break;
                        
                        case 2:// insert at end
                        printf("Insert at end:\n");
                        printf("Enter the size of list:\n");
                        scanf("%d",&n);
                        for(i=1;i<n;i++)
                        {
                            Cinsertend(&head);
                        }
                        display(head);
                        break;
                        
                        case 3:// insert at any position
                        printf("Insert at any position:\n");
                        printf("Enter the size of list:\n");
                        scanf("%d",&n);
                        for(i=1;i<n;i++)
                        {
                            Cinsertanypos(&head);
                        }
                        display(head);
                    }
                    break;
                case 2: // Delete
                    printf("1)Delete at beginning\n2)Delete at end\n3)Delete at any position\n");
                    scanf("%d", &opt4);
                    switch(opt4)
                    {
                        case 1:// delete at beginning
                        printf("delete at beginning:\n");
                        break;

                        case 2:// delete at end
                        printf("Delete at end:\n");
                        break;

                        case 3:// delete at any position
                        printf("Delete at any position:\n");
                        break;
                    }
                    break;
                case 3: // Search
                    break;
                default:
                    printf("Invalid operation selection.\n");
                    return 0;
            }
            break;

        default:
            printf("Invalid Input.\n");
            return 0;
    }

    return 0;
}
