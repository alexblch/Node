#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *createCell(int data)
{
    Node *new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

Node *append(Node *head, int data)
{
    if(head == NULL)
        return createCell(data);
    Node *current = head;
    while(current->next != NULL)
        current = current->next;
    current->next = createCell(data);
    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while(current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

Node *removeFirst(Node *head)
{
    Node *current = head->next;
    return current;
}

Node *remove_end(Node *head)
{
    Node *current = head;
    while(current->next->next != NULL)
        current = current->next;
    current->next = NULL;
    return head;
}




int main()
{
    Node *head = createCell(1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    head = append(head, 6);
    head = removeFirst(head);
    head = remove_end(head);
    printList(head);
    printf("\n");
    return 0;
}
