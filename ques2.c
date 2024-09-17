// create a phonebook with cno,customer name and phone number
// 1-Display the phone book as a linked list
// 2-search the customer with cno and count the search
// 3-add a linked list with customer name whom you searched more on a favourite linked list

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Phone
{
    int cno;
    char name[50];
    long long number;
    struct Phone *next;
};
struct searchNCount
{
    int cno;
    int count;
};

int cno_arr[50] = {0};
int search_count[50] = {0};
static int i = 0;

struct Phone *createPhone(int cno, char *name, long long number)
{
    // syntax  int* newNode=(int*)malloc(sizeof(int))
    cno_arr[i++] = cno;
    struct Phone *newPhone = (struct Phone *)malloc(sizeof(struct Phone));
    newPhone->cno = cno;
    strcpy(newPhone->name, name);
    newPhone->number = number;
    newPhone->next = NULL;
    return newPhone;
}
// insert phone to the phonebook
void insertNode(struct Phone *head, int cno, char *name, long long number)
{
    struct Phone *createdNode = createPhone(cno, name, number);
    struct Phone *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        temp->next = createdNode;
    }
}

void print(struct Phone *head)
{
    // printf("Inside print function");
    if (head == NULL)
    {
        printf("Phone Book is empty");
        return;
    }
    struct Phone *temp = head;
    while (temp != NULL)
    {
        printf("%d %s %ld\n", temp->cno, temp->name, temp->number);
        // printf("Inside print");
        temp = temp->next;
    }
}
// get the number of records in the phonebook
int length(struct Phone *head)
{
    if (head == NULL)
    {
        return 0;
    }
    struct Phone *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

// search the customer with cno and count the search
void search(struct Phone *head, int cno)
{
    if (head == NULL)
    {
        printf("Phone book is empty");
        return;
    }
    struct Phone *temp = head;
    while (temp != NULL && temp->cno != cno)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("record not found");
        return;
    }
    if (temp->cno == cno)
    {
        printf("\nPhone number details found\n");
        int len = length(head);
        for (int i = 0; i < len; i++)
        {
            if (cno_arr[i] == cno)
            {
                search_count[i]++;
                printf("%d has been searched %d no. of times", cno, search_count[i]);
            }
        }
    }
}

void favourite_LL(struct Phone *head)
{
    // we will be giving first 3's favourite's list
    int fav[3];
    int len = length(head);
    for (int j = 0; j < 3; j++)
    {
        int maxindex = -1;
        for (int i = 0; i < len; i++)
        {
            if (search_count[i] > maxindex)
            {
                maxindex = i;
            }
        }
        // we will store the cno with the maximum search count.
        fav[j] = cno_arr[maxindex];
        search_count[maxindex] = -1;
    }
    struct Phone *temp = head;
    struct Phone *favhead = (struct Phone *)malloc(sizeof(struct Phone));
    favhead->cno=-1;
    strcpy(favhead->name,"");
    favhead->number=-1;
    favhead->next=NULL;
    while (temp != NULL)
    {
        if (temp->cno == fav[0] || temp->cno == fav[1] || temp->cno == fav[2])
        {
            insertNode(favhead, temp->cno, temp->name, temp->number);
        }
        temp=temp->next;
    }

    temp = favhead->next;
    printf("\nThe list of favourite Phone Numbers with their details:\n");
    while (temp != NULL)
    {
        printf("%d %s %ld\n", temp->cno, temp->name, temp->number);
        temp = temp->next;
    }
}

int main()
{
    struct Phone *head = (struct Phone *)malloc(sizeof(struct Phone));

    head->cno = 3;
    strcpy(head->name, "Amita");
    head->number = 32984934;

    cno_arr[i++] = 3;
    // printf("%d %s %ld",head->cno,head->name,head->number);
    insertNode(head, 5, "sdhf", 932482304);
    insertNode(head, 9, "sdhfdfswe", 932482304);
    insertNode(head, 70, "ssdfdhf", 932482304);
    // print(head);
    int len = length(head);

    int cno_to_search = 9;
    // this search funtion will give the number of times the given cno has been searched.
    search(head, cno_to_search);
    search(head, cno_to_search);
    cno_to_search = 3;
    search(head, cno_to_search);
    cno_to_search = 70;
    search(head, cno_to_search);
    // to see the list of 3 most favourite phone number with their details.
    favourite_LL(head);

    return 0;
}