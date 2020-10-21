	#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
  int fd, sz;
  char *c;

  fd = open("testfile.txt", O_RDONLY);
	while ((sz = get_next_line(fd, &c)))
	{
		printf("%s\n", c);
		free(c);
	}
	free(c);
}
