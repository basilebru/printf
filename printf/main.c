#include "printf.h"
#include "libft.h"

int	main()
{
		long int a;
		int ret;
		char c;
		char *str;

		str = NULL;
		a = 20000000000;
		c = 50;
		
		ret = 0;
		ret = ft_printf("%s", 42);
		printf("end\n");
		printf("ret: %d\n", ret);
			
		ret = 0;
		ret = printf("%.s", 42);
		printf("end\n");
		printf("ret: %d\n", ret);
	
		free(str);
}


