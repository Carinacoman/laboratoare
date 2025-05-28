#include <stdio.h>
#include "Math.h"

int main()
{
	Math x1;

	printf("%d \n", x1.Add(2, 3));
	printf("%d \n", x1.Add(2, 3, 4));
	printf("%lf \n", x1.Add(2.7, 3.2));
	printf("%lf \n", x1.Add(2.89, 3.67, 4.9));
	printf("%d \n", x1.Mul(2, 3));
	printf("%d \n", x1.Mul(2, 3, 4));
	printf("%lf \n", x1.Mul(2.2, 3.3));
	printf("%lf \n", x1.Mul(2.2, 3.3, 4.4));
	printf("%d \n", x1.Add(8, 3, 4, 5, 6, 7, 8, 9, 10));
	printf("%s", x1.Add("123", "456"));




	return 0;
}