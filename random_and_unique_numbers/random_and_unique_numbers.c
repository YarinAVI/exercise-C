/*
 * @Author: Yarin Avisidris 
 * @Date: 2020-09-23 22:14:01 
 * @Last Modified by: Yarin Avisidris
 * @Last Modified time: 2020-09-24 12:33:21
 */

#include<stdlib.h> // malloc
#include<stdio.h> // printf
#include<time.h> // time
int ** create_matrix_with_unique_random_numbers(int rows,int columns,int lower_bound,int higher_bound)  {
    // before we start to create a 2d matrix containing unique random numbers we need to check if its possible:
    // for example we can have a range of random numbers between 0-10 and user request a matrix in size of 10 rows and 10 columns.
    // we cannot provide such matrix because there are not enough unique random numbers that exist!
    if((rows*columns ) > (higher_bound-lower_bound)) {
        printf("ERROR:cannot create matrix of %d rows and %d columns such that all elements are random and unique in the given range %d <--> %d.\n",rows,columns,lower_bound,higher_bound);
        return NULL;
    }
    // create a list with all the possible numbers from lower_bound to higher_bound
    int *possible_numbers = (int*)malloc((higher_bound-lower_bound) *sizeof(int));
    if(!possible_numbers) {
        printf("Failed to allocate memory for possible_numbers list.\n");
        return NULL;
    } 
    for(int i=lower_bound,j=0;i<higher_bound;i++,j++) {
        // fill it with the numbers;
        possible_numbers[j] = i;
    }
    int random_factor = higher_bound-lower_bound; // we need to randomize it atleast our range of numbers times for it to be enough random.
    // now randomize the list random factor times
    for(int i=0;i<random_factor;i++) {
        int temp;
        //get two random indexes in range of (higher_bound-lower_bound):
        int rand1 = (rand() %(higher_bound-lower_bound)); // compute first random index
        int rand2 = (rand() %(higher_bound-lower_bound)); // compute second random index
        // there is no need to check if the indexes are the same because thats very rare, and in case they are that will be few redundant CPU instructions than
        // way more CPU instructions to check every iteration if they are not the same, if you want to be 100% correct then in case they are the same you need to loop over in that case!
        // but for simplicity i'll keep it like this!
        //if(rand1==rand2) {} // do somthing, they are the same index.
        temp = possible_numbers[rand1];
        possible_numbers[rand1] = possible_numbers[rand2];
        possible_numbers[rand2] = temp;
         
    }
    
    // we finished to pocker-randomize our list, we basically created a list containing all posibile numbers with no duplicates, and randomized them by indexes.
    int **mat = (int**)malloc(rows*sizeof(int*)); // allocate memory for matrix.
    if(!mat)  {
        printf("Failed to allocate memory.\n");
        return NULL;
    }
    for(int i = 0;i < rows;i++) { // allocate memo for each column
        mat[i] = (int*)malloc(columns*sizeof(int));
        if(!mat[i]) {
            for(int j=0;j<i;j++) free(mat[j]);
            free(mat);
            printf("Failed to allocate memory.\n");
            return NULL;
        }
    }
    // allocating is done, now fill the matrix with our randomized unique numbers from possible_numbers.
    for(int i=0,g=0;i<rows;i++) {
        for(int j=0;j<columns;j++) {
            mat[i][j] = possible_numbers[g++];
        }
    }
    free(possible_numbers); // free this list memory;
    return mat; // finally returned the matrix
}
void print_matrix(int **mat,int rows,int columns) {
    printf("unique and random matrix numbers:\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
void main() {
    int l_bound;
    int h_bound;
    // we want randoms between 0(including) to 100 (excluding)
    // Use current time as  
    // seed for random generator
    
    srand(time(0));
    while (1) { 
    int rows;
    int columns;
    do {
    printf("Enter Lower-bound:");
    scanf("%d",&l_bound);
    printf("Enter higher-bound:");
    scanf("%d",&h_bound);
    }
    while(h_bound<=l_bound);
    do {
    printf("Enter rows-size for matrix:");
    scanf("%d",&rows);
    printf("Enter columns-size for matrix:");
    scanf("%d",&columns);
    }
    while(rows<=0 || columns<=0);
    
    int **random_and_unique = create_matrix_with_unique_random_numbers(rows,columns,l_bound,h_bound);
    if(random_and_unique) {
        print_matrix(random_and_unique,rows,columns);
    for(int i=0;i<rows;i++) free(random_and_unique[i]);
    free(random_and_unique);
    random_and_unique= NULL;
    }
    } 
}
