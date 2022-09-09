#include <stdio.h>

void traitement(int nombre, unsigned char drapeaux)
{
	if (drapeaux & 0x01) /* Si le nombre est pair */
	{
		printf("le nombre est impair\n");
	}
	if (drapeaux & 0x02) /* Si le nombre est une puissance de deux */
	{
		printf("le nombre est une puissance de deux\n");
	}
	if (drapeaux & 0x03) /* Si le nombre est premier */
	{
		printf("le nombre est premier\n");
	}
}


int main(void)
{
	int nombre = 21;
	unsigned char drapeaux = 0x03; /* 0000 0011 */

	traitement(nombre, drapeaux);
	unsigned int	a = 3 << 24;
	printf("a : %d\n", a);
	//nombre = 17;
	//drapeaux = 0x04; 0000 0100
	//traitement(nombre, drapeaux);
	return 0;
}
