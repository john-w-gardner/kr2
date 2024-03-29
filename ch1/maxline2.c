#include <stdio.h>

/* print longest input line
 this version uses external variables*/

#define MAXLINE 1000 /* maximum input line size */

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getLine(void);
void copy(void);

int main()
{
  int len;  /* current line length */ 
  extern int max;  /* max length seen so far */
  extern char longest[];

  max = 0;
  while ((len = getLine()) >0)
    if (len > max) {
      max = len;
      copy();
    }
  if (max > 0)  /* there was a line */
    printf("%s", longest);
  return 0;
}

/* getLine: read a line into s, return length */
int getLine(void)
{
  int c, i;
  extern char line[];
  
  for (i=0; i<MAXLINE-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
  /* note that if we hit MAXLINE we don't get trailing \n */
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(void)
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
