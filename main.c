#include "printf.h"
#include "libft.h"

int	main()
{
		//int a;
		int ret;
		//char c;
		char *str;

		str = NULL;
		//a = 12;
		//c = 50;
			
		ret = 0;
		ret = ft_printf("Hello %.3%");
		printf("end\n");
		printf("ret: %d\n", ret);
			
		ret = 0;
		ret = printf("Hello %.3%");
		printf("end\n");
		printf("ret: %d\n", ret);
	
		free(str);
}


