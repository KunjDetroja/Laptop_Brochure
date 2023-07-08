#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char name[50];
    int carno;
    struct node *next;
    struct node *last;
    struct node *up;

} *head = NULL, *END = NULL;

struct node1
{
    struct node *next;
    struct node *last;
    struct node *down;
    char model[20];
    int price;
    char ctp[100];
} *head1[1000], *END1[1000];
int count = 0;

int addatfirst()
{
    int b, l, i, f;
    struct node *temp = head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    fflush(stdin);
    printf("Enter CAR NAME to enter at first:");
    gets(newnode->name);
    newnode->carno = count;
    //////////////////////Here 2nd link list starts/////////////////////////////////////

    printf("Enter how many models are available:");
    scanf("%d", &f);
    struct node1 *newnode1;

    for (i = 0; i < f; i++)
    {
        newnode1 = (struct node *)malloc(sizeof(struct node));
        fflush(stdin);
        printf("Enter model:");
        gets(newnode1->model);
        printf("Enter price:");
        scanf("%d", &newnode1->price);
        fflush(stdin);
        printf("Enter CC,torque and power:");
        gets(newnode1->ctp);

        if (i == 0)
        {
            head1[count] = END1[count] = NULL;
            // struct node1 *temp1=head1[count];

            newnode1->last = head1[count];
            newnode1->next = END1[count];
            newnode1->down = newnode;
            head1[count] = END1[count] = newnode1;
        }
        else
        {
            struct node1 *temp1 = head1[count];

            while (temp1->next != NULL)
                temp1 = temp1->next;

            newnode1->last = temp1;
            newnode1->next = NULL;
            newnode1->down = newnode;

            temp1->next = newnode1;

            END1[count] = newnode1;
        }
    }

    //////////////////////Here 2nd link list ends/////////////////////////////////////

    if (head == NULL)
    {
        newnode->next = newnode->last = NULL;
        head = END = newnode;
        newnode->up = head1[count];
    }
    else
    {
        newnode->last = NULL;
        newnode->next = head;
        head = newnode;
        temp->last = newnode;
        newnode->up = head1[count];
    }
    count++;
}

int display()
{
    int i = 1, s = 0;
    char n;
    struct node *temp = head;
    struct node1 *temp1;
    if (head == NULL)
    {
        printf("list is empty");
        getch();
    }
    else
    {
        while (1)
        {
            system("cls");
            printf("\n\n\t\t\t\t\t\tdata %d:", i);
            puts(temp->name);
            getch();
            printf("\n\n\n\n\n\nPress <- to see previous data,Press -> to see next data,Press up key to see models,Press esc to exit: ");
            getch();
            n = getch();
            if (n == 77)
            {
                if (temp->next == NULL)
                {
                    printf("\ncant move forward");
                    getch();
                }
                else
                {
                    i++;
                    temp = temp->next;
                }
            }
            if (n == 75)
            {
                if (temp->last == NULL)
                {
                    printf("\ncant move backwards");
                    getch();
                }
                else
                {
                    i--;
                    temp = temp->last;
                }
            }
            if (n == 72)
            {
                temp1 = head1[temp->carno];

                while (1)
                {
                    system("cls");
                    printf("\n\n");
                    puts(temp->name);
                    printf("\n\n\n\n\n,Press -> to see next model,Press <- to see previous model,Press ESC to go back\n\n\n\n\n\n");

                    printf("\nModel name: ");
                    puts(temp1->model);

                    printf("\nPrice:%d ", temp1->price);

                    printf("\nEngine cc, Torque and Horse power: ");
                    puts(temp1->ctp);

                    n = getch();
                    if (n == 77)
                    {
                        if (temp1->next == NULL)
                        {
                            printf("\ncant move forward");
                            getch();
                        }
                        else
                        {
                            temp1 = temp1->next;
                        }
                    }
                    if (n == 75)
                    {
                        if (temp1->last == NULL)
                        {
                            printf("\ncant move backwards");
                            getch();
                        }
                        else
                        {
                            temp1 = temp1->last;
                        }
                    }
                    if (n == 27)
                        goto s;
                }
            s:
                n = 28;
                s = 1;
            }
            if (n == 27)
                goto i;
        }
    i:
        i = 1;
    }
}

int addatend()
{
    int i, l, f;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    fflush(stdin);
    printf("Enter CAR NAME to enter at end :");
    gets(newnode->name);
    newnode->carno = count;

    //////////////////////Here 2nd link list starts/////////////////////////////////////

    printf("Enter how many models are available:");
    scanf("%d", &f);
    struct node1 *newnode1;

    for (i = 0; i < f; i++)
    {
        newnode1 = (struct node *)malloc(sizeof(struct node));
        fflush(stdin);
        printf("Enter model:");
        gets(newnode1->model);
        printf("Enter price:");
        scanf("%d", &newnode1->price);
        fflush(stdin);
        printf("Enter CC,torque and power:");
        gets(newnode1->ctp);

        if (i == 0)
        {
            head1[count] = END1[count] = NULL;
            // struct node1 *temp1=head1[count];

            newnode1->last = head1[count];
            newnode1->next = END1[count];
            newnode1->down = newnode;
            head1[count] = END1[count] = newnode1;
        }
        else
        {
            struct node1 *temp1 = head1[count];

            while (temp1->next != NULL)
                temp1 = temp1->next;

            newnode1->last = temp1;
            newnode1->next = NULL;
            newnode1->down = newnode;

            temp1->next = newnode1;

            END1[count] = newnode1;
        }
    }

    //////////////////////Here 2nd link list ends/////////////////////////////////////

    if (head == NULL)
    {
        newnode->next = NULL;
        END = head = newnode;
        newnode->up = head1[count];
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->last = temp;
        newnode->next = NULL;
        END = newnode;
        newnode->up = head1[count];
    }
    count++;
}

deleteatfirst()
{
    if (head == NULL)
        printf("List empty");
    else
    {
        struct node *temp;
        if (head->next == NULL)
        {
            free(head);
            head = END = NULL;
            printf("element deleted at first");
            getch();
        }
        else
        {
            temp = head;
            head = temp->next;
            head->last = NULL;
            free(temp);
            printf("element deleted at first");
            getch();
        }
    }
}

deleteatend()
{
    if (head == NULL)
        printf("List empty");
    else
    {
        if (head->next == NULL)
        {
            free(head);
            head = END = NULL;
            printf("element deleted at first");
            getch();
        }
        else
        {
            struct node *temp = head, *tem = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            END = temp->last;
            END->next = NULL;
            printf("element delete at last");
            getch();
            free(temp);
        }
    }
}

int main()
{
    int n = 1;
    while (n != 0)
    {
        printf("1.Press 1 to insert at front\n2.Press 2 to insert at end\n3.Press 3 to delete at end\n4.Press 4 to delete at front\n5.Press 5 to display\n6.Press 6 to exit\n");
        scanf("%d", &n);
        switch(n)
        {
        case 1:
            addatfirst();
            break;
        case 2:
            addatend();
            break;
        case 3:
            deleteatend();
            break;
        case 4:
            deleteatfirst();
            break;
        case 5:
            display();
            break;
        case 6:
            n = 0;
            break;
        default:
            printf("invalid input");
            getch();
            break;
        }
        system("cls");
    }
}