#include <stdio.h>
#include <stdlib.h>

struct return_size {
    int size1;
    int size2;
    int size3;
};
struct return_size * convert(char *input,int **a,int **b,char **c) {
    struct return_size * result = (struct return_size *)calloc(1,sizeof(struct return_size));

    while(*input) {
        if( (*input)>='A' && (*input) <='z') {
            result->size1++;
            (*a) = (int*)realloc((*a),result->size1 * sizeof(int));
            (*a)[result->size1-1] = (*input);
        }
        else if((*input) >='0' && (*input) <='9') {
            result->size2++;
            (*b) = (int*)realloc((*b),result->size2 * sizeof(int));
            (*b)[result->size2-1] = (*input) - '0';
        }
        else {
            result->size3++;
            (*c) = (char*)realloc((*c),result->size3*sizeof(char));
            (*c)[result->size3-1] = (*input);
        }
        input++;
    }
    return result;
}


int main() {
    char test[50] = "bY?3Z";
    int *a  = NULL;
    int *b  = NULL;
    char *c = NULL;
    struct return_size *ret = convert(test,&a,&b,&c);
    for(int i=0;i<ret->size1;i++) {
        printf("%d,",a[i]);
    }
    printf("\n");
    for(int i=0;i<ret->size2;i++) {
        printf("%d,",b[i]);
    }
    printf("\n");
    for(int i=0;i<ret->size3;i++) {
        printf("%c",c[i]);
    }
    printf("\n");
}