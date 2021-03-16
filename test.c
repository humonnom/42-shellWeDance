#include <stdio.h>
#include <unistd.h> 
int main ()
{
	while (1)
	{
		printf("==================\n");
		printf("program start\n");
		while (1)
		{
			printf("program is running\n");
			sleep(4);
		}
		printf("program end\n");
	}
}
