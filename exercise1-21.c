#include <stdio.h>

#define MAXLINE 1000	/* maximum input line size */
#define TABSTOP 8

int getliner(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
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
	int c, i, ws, o, nt, ns;

	/*for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;*/
	while ((c=getchar())!=EOF && c!= '\n'){
		if (c == ' ')
			ws++;
		else if (c == '\t')
			ws+=TABSTOP;
		else{
			nt = ws / TABSTOP;	
			for( ; nt > 0; nt--){
				s[i] = '\t';
				i++;
			}
			ns = ws % TABSTOP;
			for( ; ns > 0; ns--){
				s[i] = ' ';
				i++;
			}
			ws = 0;
			s[i] = c;
			++i;
		}
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}else if (c == EOF){
		return 0;
	}
	s[i] = '\0';
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

