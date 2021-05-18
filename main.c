#include "src/ft_printf.h"
#include <stdio.h>


#include <stdio.h>
#define BLURB "Authentic imitation!"

	int main()
	{
		const double RENT = 3852.99;
		printf("printf    *%8f*\n", RENT);
		ft_printf("ft_printf *%8f*\n", RENT);
		printf("printf    *%4.2f*\n", RENT);
		ft_printf("ft_printf *%4.2f*\n", RENT);
		printf("printf    *%3.1f*\n", RENT);
		ft_printf("ft_printf *%3.1f*\n", RENT);
		printf("printf    *%10.3f*\n", RENT);
		ft_printf("ft_printf *%10.3f*\n", RENT);
		printf("printf    *%+4.2f*\n", RENT);
		printf("ft_printf *%+4.2f*\n", RENT);

		printf("%x %X %#x\n", 31, 31, 31);
		ft_printf("%x %X %#x\n", 31, 31, 31);
		printf("**%d**% d% d **\n", 42, 42, -42);
		ft_printf("**%d**% d% d **\n", 42, 42, -42);
		printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
		ft_printf("**%5d**%5.3d**%05d**%05.3d**\n", 6, 6, 6, 6);
		printf("\n");

		printf("[%2s]\n", BLURB);
		ft_printf("[%2s]\n", BLURB);
		printf("[%24s]\n", BLURB);
		ft_printf("[%24s]\n", BLURB);
		printf("[%24.5s]\n", BLURB);
		ft_printf("[%24.5s]\n", BLURB);
		printf("[%-24.5s]\n", BLURB);
		ft_printf("[%-24.5s]\n", BLURB);

		return 0;
	}