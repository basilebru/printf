#include "printf.h"
#include "libft.h"

int	main()
{
		int a;
		int ret;
		char c;
		char *str;

		str = ft_strdup("Hello");
		a = 12;
		c = 50;
			
		ret = 0;
		ret = ft_printf("%0*d", 12, a);
		printf("end\n");
		printf("ret: %d\n", ret);
			
		ret = 0;
		ret = printf("%0*d", 12, a);
		printf("end\n");
		printf("ret: %d\n", ret);
	
		free(str);
}


