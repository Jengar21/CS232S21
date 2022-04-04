#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024
//The program should count each character and keep track of how many characters it sees before EOF.
//It should also count how many whitespaces it sees along the way; we defined whitespace as either a space ‘ ‘ or a tab (special character '\t').
//The program should also count how many different words it sees; words are separated by whitespace or newlines.
//wordstats should also track how many uppercase and lowercase letters it sees separately, as well as how many numeric digits it sees.
//Finally, it should also count how many lines of text it reads; a newline indicator is '\n' (basically, you just count these).
//Check sample output for understanding the behavior of the program

int main () {
int len = 0;
char buf[MAX_BUF];
int chars = 0;
int words = 0;
int lines = 0;
int whitespaces = 0;
int uppercase = 0;
int lowercase = 0;
int digits = 0;

while(fgets((buf + len), MAX_BUF, stdin) != NULL) {
len = strlen(buf);
}

//Please do not modify the code above

//Your code here
   for(int i=0;i<len;i++)
  {
      if(buf[i]=='\n') // if enter is pressed
      {
          if(i!=0 && buf[i-1]!='\t' && buf[i-1]!=32 && buf[i-1]!='\n')
          words++;
          lines++;
      }
      else if(buf[i]==32 || buf[i]=='\t') // if whitespace is encountered 32 is ascii value of space
      {
          if(i!=0 && buf[i-1]!=32 && buf[i-1]!='\t' && buf[i-1]!='\n')
          words++;
          whitespaces++;
      }
      else  // if any char if found note digit is also a character
      {
          if(buf[i]>=97 && buf[i]<=122)  // 97 is ascii value of 'a' and 122 is ascii value of 'z'
          lowercase++;
          else if(buf[i]>=65 && buf[i]<=90) // 65 is ascii value of 'A'  and 90 is ascii value of 'Z'
          uppercase++;
          else if(buf[i]>=48 && buf[i]<=57) // 48 is ascii value of '0' and 57 is ascii value of '9'
          digits++;

          chars++;
      }
  }

//Please do not modify the code underneath
printf("%d %d %d %d %d %d %d\n", chars, words, lines, whitespaces, uppercase, lowercase, digits);
}
