#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0. 20, ..., 300 */
void fahrToCelsius(int fahr, int upper);

int main ()
{
	fahrToCelsius(0, 100);
	return 0;
}

void fahrToCelsius(int fahr, int upper)
{
	while (fahr <= upper) {
		int celsius = 5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr += 20;
	}

}
