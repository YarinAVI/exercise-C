/*
 * @Author: Yarin Avisidris 
 * @Date: 2020-09-24 15:56:18 
 * @Last Modified by:   Yarin Avisidris 
 * @Last Modified time: 2020-09-24 15:56:18 
 */
#include<stdio.h>
#include<string.h> // strstr()

int missing_numbers(char *str1,char *str2) {
// set nulls in str1 so we can split them by words using strstr;
int str1_size = strlen(str1);
int result = 0;
for(int i=0;i<str1_size;i++) if(str1[i]==' ') str1[i] = 0;
// now words are seperated by NULLs and not by spaces, now its useful for us to use strstr and count matching words.
int i =0 ;
while(i<str1_size) {
    if(str1[i]) {
        if(!strstr(str2,&str1[i])) result++;
    }
    while(str1[i] && i<str1_size) i++; // iterate words
    // we reached NULL now inc by 1
    i++;
}
return result;
}

int main () {
    char str1[100] = "set your goals and achieve them if you are good enough";
    char str2[100] = "each course has a set of goals to achieve and a set of tools to use";
    printf("String1 = %s\n",str1);
    printf("string2 = %s\n",str2);
    printf("There were %d words in str1 that don't exist in str2\n",missing_numbers(str1,str2));

}