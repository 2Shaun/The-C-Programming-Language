#include <stdio.h>

#define MAXLINE 10	/* maximum input line size */

int getliner(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */

	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getliner(line, MAXLINE)) > 0)
		if (len > max){
			max = len;
			copy(longest, line);
		}
	if (max > 0)	/* there was a line */
		printf("%s", longest);
	return 0;
}

/* getline: read a line into s, return length */
int getliner(char s[], int lim)
{
	int c, i;

	for (i=0; (c=getchar())!=EOF && c!='\n'; ++i)
		if (i < lim-1)	
			s[i] = c;
	if (i > lim-1)
		;
	else if (c == '\n' && i < lim-1) {
		s[i] = c;
		++i;
		s[i] = '\0';
	}
	printf("%s", s);
	return i; 
}

/*copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

