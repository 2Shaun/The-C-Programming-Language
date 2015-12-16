# define MAXLINE 1000

/* find longest line */
main()
{
	int len;
	int max;

	char line[MAXLINE];
	char save[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(line, save);
		}
	if (max > 0)
		printf("%s", save);
}

/* get line into s, return length */
getline(s, lim)
char s[];
int lim;
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return(i);
}

/* copy s1 to s2; assume s2 big enough */
copy(s1, s2)
char s1[], s2[];
{
	int i;

	i = 0;
	while ((s2[i] = s1[i]) != '\0')
		++i;
}

