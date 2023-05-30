#include "icecream.h"

int	main(void)
{
	char str[10];

	str[0] = 'I';
	str[1] = 'C';
	str[2] = 'E';
	str[3] = 'C';
	str[4] = 'R';
	str[5] = 'E';
	str[6] = 'A';
	str[7] = 'M';
	str[8] = '\0';
	printf("%s", ft_arom());
	printf("%s", ft_milk());
	printf("%s", ft_water());
	printf("%s", str);
	return (0);
}