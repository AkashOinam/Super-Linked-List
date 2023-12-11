#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Functions for Singly Linked List

void Sinsertbeg(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &newnode->data);
    newnode->next = *head;
    *head = newnode;
}

void Sinsertend(struct node **head)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
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

void Sinsertanypos(struct node **head, int data, int position)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    if (position == 0)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void Sdeletebeg(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void Sdeleteend(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void Sdeleteanypos(struct node **head, int position)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 0)
    {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node *temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    struct node *deleteNode = temp->next;
    temp->next = temp->next->next;
    free(deleteNode);
}

void Ssearchbeg(struct node *head, int key)
{
    struct node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element %d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found in the list.\n", key);
}

// Function for displaying

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int i, n, pos, key;
    struct node *head = NULL;
    int opt1, opt2, opt3, opt4, opt5;
    printf("Choose the type of Linked list:\n");
    printf("1)Singly Linked list\n2)Doubly Linked List\n3)Circular Linked list\n");
    scanf("%d", &opt1);

    printf("Choose operation:\n");
    printf("1)Insert\n2)Delete\n3)Search\n");
    scanf("%d", &opt2);

    switch (opt1)
    {
    case 1: // Singly Linked list
        printf("Singly Linked List selected\n");
        switch (opt2)
        {
        case 1: // Insert
            printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n");
            scanf("%d", &opt3);
            switch (opt3)
            {
            case 1: // insert at begin
                printf("Insert at beginning:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sinsertbeg(&head);
                }
                display(head);
                break;

            case 2: // insert at end
                printf("Insert at end:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sinsertend(&head);
                }
                display(head);
                break;

            case 3: // insert at any position
                printf("Insert at any position:\n");
                printf("Enter the data and position: ");
                scanf("%d %d", &key, &pos);
                Sinsertanypos(&head, key, pos);
                display(head);
                break;
            }
            break;

        case 2: // Delete
            printf("1)Delete at beginning\n2)Delete at end\n3)Delete at any position\n");
            scanf("%d", &opt4);
            switch (opt4)
            {
            case 1: // delete at beginning
                printf("Delete at beginning:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sdeletebeg(&head);
                }
                display(head);
                break;

            case 2: // delete at end
                printf("Delete at end:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sdeleteend(&head);
                }
                display(head);
                break;

            case 3: // delete at any position
                printf("Delete at any position:\n");
                printf("Enter the position: ");
                scanf("%d", &pos);
                Sdeleteanypos(&head, pos);
                display(head);
                break;
            }
            break;

        case 3: // Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            Ssearchbeg(head, key);
            break;

        default:
            printf("Invalid operation selection.\n");
            return 0;
        }
        break;

    case 2:
        // Doubly 
        printf("Doubly Linked List selected\n");
        switch (opt2)
        {
        case 1: // Insert
            printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n");
            scanf("%d", &opt3);
            switch (opt3)
            {
            case 1: // insert at begin
                printf("Insert at beginning:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sinsertbeg(&head);
                }
                display(head);
                break;

            case 2: // insert at end
                printf("Insert at end:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sinsertend(&head);
                }
                display(head);
                break;

            case 3: // insert at any position
                printf("Insert at any position:\n");
                printf("Enter the data and position: ");
                scanf("%d %d", &key, &pos);
                Sinsertanypos(&head, key, pos);
                display(head);
                break;
            }
            break;

        case 2: // Delete
            printf("1)Delete at beginning\n2)Delete at end\n3)Delete at any position\n");
            scanf("%d", &opt4);
            switch (opt4)
            {
            case 1: // delete at beginning
                printf("Delete at beginning:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sdeletebeg(&head);
                }
                display(head);
                break;

            case 2: // delete at end
                printf("Delete at end:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sdeleteend(&head);
                }
                display(head);
                break;

            case 3: // delete at any position
                printf("Delete at any position:\n");
                printf("Enter the position: ");
                scanf("%d", &pos);
                Sdeleteanypos(&head, pos);
                display(head);
                break;
            }
            break;

        case 3: // Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            Ssearchbeg(head, key);
            break;

        default:
            printf("Invalid operation selection.\n");
            return 0;
        }
        break;
    case 3:
        // Circular
        printf("Circular Linked List selected\n");
        switch (opt2)
        {
        case 1: // Insert
            printf("1)Insert at begin\n2)Insert at end\n3)Insert at position\n");
            scanf("%d", &opt3);
            switch (opt3)
            {
            case 1: // insert at begin
                printf("Insert at beginning:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sinsertbeg(&head);
                }
                display(head);
                break;

            case 2: // insert at end
                printf("Insert at end:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sinsertend(&head);
                }
                display(head);
                break;

            case 3: // insert at any position
                printf("Insert at any position:\n");
                printf("Enter the data and position: ");
                scanf("%d %d", &key, &pos);
                Sinsertanypos(&head, key, pos);
                display(head);
                break;
            }
            break;

        case 2: // Delete
            printf("1)Delete at beginning\n2)Delete at end\n3)Delete at any position\n");
            scanf("%d", &opt4);
            switch (opt4)
            {
            case 1: // delete at beginning
                printf("Delete at beginning:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sdeletebeg(&head);
                }
                display(head);
                break;

            case 2: // delete at end
                printf("Delete at end:\n");
                printf("Enter the size of list: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++)
                {
                    Sdeleteend(&head);
                }
                display(head);
                break;

            case 3: // delete at any position
                printf("Delete at any position:\n");
                printf("Enter the position: ");
                scanf("%d", &pos);
                Sdeleteanypos(&head, pos);
                display(head);
                break;
            }
            break;

        case 3: // Search
            printf("Enter the element to search: ");
            scanf("%d", &key);
            Ssearchbeg(head, key);
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
