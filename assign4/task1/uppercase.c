#include <stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {

 char str[25];
   int n = 0;

   scanf("%s",str);

   for(n=0;n<=strlen(str);n++){
      if(str[n]>=97&&str[n]<=122)
         str[n]=str[n]-32;
   }
  printf("%s\n",str);
   return 0;

 
}

