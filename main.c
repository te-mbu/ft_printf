#include "ft_printf.h"
/*
int		main()
{
	#define INPUT "%s", NULL

	printf("\nret : %d\n", ft_printf(INPUT));
	printf("\n**********************\n");
	printf("\nret : %d\n", printf(INPUT));
}
*/

//"%0.*x DcnkFGSFog%014.0X", 7, 0, 0


int		main()
{
	printf("\nret : %d\n", printf("%s", NULL));
	write(1, "\n\n", 2);
	printf("\nret : %d\n", ft_printf("%s", NULL));
}