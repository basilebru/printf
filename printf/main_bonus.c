#include "printf_bonus.h"
#include "libft.h"
#include <locale.h>
#include <limits.h>

int	main()
{
		int ret;
		unsigned long long a;
		wchar_t t[4];
		t[0] = 65;
		t[1] = 0xBF;
		t[2] = 128519;
		t[3] = 0;

		a = 10;
	
		setlocale(LC_CTYPE, "");
		
		ret = 0;
		ret = ft_printf("%ls", t);
		printf("end\n");
		printf("ret: %d\n", ret);
			
		ret = 0;
		ret = printf("%ls", t);
		printf("end\n");
		printf("ret: %d\n", ret);
/*	
		ret = ft_printf("llu %hhtx\n", (unsigned char)a);
		ret = ft_printf("lu %hx\n", (unsigned short)a);
		ret = ft_printf("u %x\n", (unsigned int)a);
		ret = printf("hhu %hhtx\n", (unsigned char)a);
		ret = printf("hu %hx\n", (unsigned short)a);
		ret = printf("u %x\n", (unsigned int)a);
*/
}


