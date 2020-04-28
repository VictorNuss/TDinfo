#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	printf("ce programme converti les degres Farenheit en degres C\n");
	float deg=0;
	printf("rentrez une valeur\n");
	scanf("%f",&deg);
	deg=deg*9/5 +32;
	printf("en degres ça fait %f \n",deg);
	return 0;
}

