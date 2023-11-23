#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
char *dic[80] = {
"A", "APPLE",
"B", "BOY",
"C", "CAT",
"D", "DOG",
"E", "ELEPHANT"
};
char word[100];
printf("enter character u want  A/B/C/D/E  \n");
gets(word);
char **p;
p = (char **)dic;
do {
if(!strcmp(*p, word)) {
puts(word);
puts("for");
puts(*(p+1));
break;
}
p = p + 2;
} while(*p);
if(!*p){
puts("Word not in dictionary.");
}
return 0;
} 