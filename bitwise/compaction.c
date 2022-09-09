#include <stdio.h>

static void modifie_jour(unsigned char *date, unsigned jour)
{
	/* Nous stockons le jour (cinq bits). */
	date[0] |= jour;
}


static void modifie_mois(unsigned char *date, unsigned mois)
{
	/* Nous ajoutons les trois premiers bits du mois après ceux du jour. */
	date[0] |= (mois & 0x07) << 5;
	/* Puis le bit restant dans le second octet. */
	date[1] |= (mois >> 3);
}

int main(void)
{
	unsigned char	date[3] = {0};
	unsigned jour, mois, annee;

	jour = 21;
	mois = 3;
	
	date[0] |= jour;
	date[1] = (mois & 0x07) << 5;
	//date[1] |= (mois >> 3);
	
	printf("date[1] : %u\n", date[1]);
}
