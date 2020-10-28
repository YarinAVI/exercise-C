#include<stdio.h>
#include<stdlib.h>


struct list_node {
    int val;
    struct list_node *next;
};



struct list_node * build_list_from_arr(int *arr, int arr_size) {


if(!arr_size) return NULL;
struct list_node * head = (struct list_node *)calloc(1,sizeof(struct list_node));
head->val = arr[0];
if(arr_size == 1) return head;

struct list_node * insertor = head;

for(int i=1;i<arr_size;i++,insertor=insertor->next) {
insertor->next = (struct list_node*)calloc(1,sizeof(struct list_node));
insertor->next->val  = arr[i];
}
return head;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct list_node * head = build_list_from_arr(arr,size);
    struct list_node *iterator = head;
    while(iterator) {
    printf("%d->",iterator->val);
    iterator = iterator->next;
    }
    printf("\n");

}