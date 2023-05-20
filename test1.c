#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct t_list{
    int data;
    struct t_list *next;
} t_list;

t_list *top = NULL;


int main()
{
    t_list *head;
    t_list *node1;
    t_list *node3;

    head = malloc(sizeof(t_list));
    node1 = malloc(sizeof(t_list));
    node3 = malloc(sizeof(t_list));
    top = head;
    head->data = 35;
    head->next = node1;
    node1->data = 45;
    node1->next = NULL;
    while(head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}