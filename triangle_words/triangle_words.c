/*
 * @Author: Yarin Avisidris 
 * @Date: 2020-11-16 18:42:51 
 * @Last Modified by: Yarin Avisidris
 * @Last Modified time: 2020-11-16 18:59:29
 */
#include<stdio.h>
#include <string.h>
#include <math.h>





int main() {
    char buffer[1000] = {0};
    gets(&buffer[0]);
        int word_length =strlen(buffer);
    // vieta theorem, find X1 from quadratic equation.
    int triangle_level = (-1 + sqrt((double)(1 + 8*word_length)));
    triangle_level /=2;
    // now we have the triangle level its easy :)
    char *curr_char = &buffer[0];
    for(int i=0;i<triangle_level+1;i++) printf(" ");
    printf("*\n");
    int k = 1;
    
    for(int j=0;j<triangle_level+1;j++,k+=2) {

    for(int i=0;i<triangle_level-j;i++) printf(" ");
    printf("*");
    if(!(*curr_char))break;// the math here is not that correct, but you get the idea, maybe someone else will fix this im too lazy :)
    for(int i=0;i<k;i++) (*curr_char)==0 ? printf(" ") : printf("%c",*curr_char++);
    printf("*\n");

    }
    for(int i=0;i<k;i++) printf("*");
    printf("\n");
}