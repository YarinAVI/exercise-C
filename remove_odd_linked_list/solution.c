#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int val;
    struct list_node *next;
};
struct sizes {
    int original_size;
    int size_after_remove;
};
//1->2->4->5->6->7
struct sizes * rm_odd(struct list_node **head) {
    struct sizes *result =(struct sizes*)calloc(1,sizeof(struct sizes));
    int deletions = 0;
    struct list_node * rm = (*head);

    while((*head)->val %2 !=0) {
        result->original_size++;
        deletions++;
        (*head) = (*head)->next;
        free(rm);
        rm = (*head);
    }

    while(rm->next) {
        result->original_size++;
        if(rm->next->val %2 !=0) {
            struct list_node *rm2 = rm->next;
            rm->next = rm->next->next;
            free(rm2);
            deletions++;
        }
        else rm = rm->next;
    }
    result->original_size++;
    result->size_after_remove = result->original_size - deletions;
    return result;
}




int main() {
    struct list_node *head = (struct list_node*)calloc(1,sizeof(struct list_node));
    head->val = 1;
    head->next =(struct list_node*)calloc(1,sizeof(struct list_node));
    head->next->val =2;
    head->next->next = (struct list_node*)calloc(1,sizeof(struct list_node));
    head->next->next->val = 4;
    head->next->next->next = (struct list_node*)calloc(1,sizeof(struct list_node));
    head->next->next->next->val = 5;
    head->next->next->next->next = (struct list_node*)calloc(1,sizeof(struct list_node));
    head->next->next->next->next->val = 6;
    head->next->next->next->next->next = (struct list_node*)calloc(1,sizeof(struct list_node));
    head->next->next->next->next->next->val = 6;
    struct sizes * ret =rm_odd(&head);
    printf("%d\n",ret->original_size);
    printf("%d\n",ret->size_after_remove);
}