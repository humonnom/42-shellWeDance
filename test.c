#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	DIR				*folder;
	struct dirent	*item;
	char			*path;

	path = NULL;
	folder = opendir("/bin");
	while ((item = readdir(folder)))
	{
		printf("item->d_mane: %s\n", item->d_name);
	}
	closedir(folder);
	return (0);
}

