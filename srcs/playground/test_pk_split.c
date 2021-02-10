#include "../minishell.h"

#include <stdio.h>
int main(void) {
	char **res;
	char *str     = "abcd   efg  hI";
	char *str_cpy = "abcd   efg__hi";

	printf("str    : %s\n", str);
	printf("str_cpy: %s\n", str_cpy);

	res = pk_split(str, str_cpy, ' ');
	for (int i = 0; res[i]; ++i) {
		printf("res[%d]: %s\n", i, res[i]);
	}
	return (0);
}
