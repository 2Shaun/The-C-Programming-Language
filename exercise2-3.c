#include <stdio.h>
#include <math.h>

int htoi (char []);
int hexVal (char);

int main ()
{
	char thirty[2] = "FF";
	printf("%d", htoi(thirty));
	return 0;
}

int 
htoi (char h[])
{
	int hexTotal = 0;
	int i;

	for (i = 0; i <= 2; i++){
		hexTotal += pow(hexVal(h[i]), i);
	}
}

int 
hexVal (char h)
{
	if (h >= 'A' && h <= 'Z')
		return h - '7';
	else if (h >= 'a' && h <= 'z')
		return h - 'W';
	else if (h >= '0' && h <= '9')
		return h - '0';
	else
		return 0;
}
