#include <stdio.h>

/*
____/*\
___/_*_\
__/__*__\
_/___*___\
/____*____\
|____+____|

*/









int main() {
int ref;
scanf("%d",&ref);
int backup = ref;
for(;ref;ref--) {
//upper triangle
for(int i=0;i<ref-1;i++) printf(" ");
printf("/");
for(int i=backup;i!=ref;i--)printf(" ");
printf("*");
for(int i=backup;i!=ref;i--)printf(" ");
printf("\\");
printf("\n");
}
//print middle
printf("|");
for(int i=0;i<backup-1;i++) printf(" ");
printf("+");
for(int i=0;i<backup-1;i++) printf(" ");
printf("|");
printf("\n");
// at this point ref = 0, backup = original input;
for(;backup;backup--,ref++) {
for(int i=0;i!=ref;i++)printf(" ");
printf("\\");
for(int i=0;i<backup-1;i++)printf(" ");
printf("*");
for(int i=0;i<backup-1;i++)printf(" ");
printf("/");
printf("\n");
}
}