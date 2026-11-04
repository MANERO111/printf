#include "ft_printf.h"
#include <stdio.h>
int main()
{
	close(1);
	int a = ft_printf("%d\n",1234); 
	printf("%d\n",1234);
	int b = fflush(stdout);

	dprintf(2,"count: %d count %d\n",a,b);  
}