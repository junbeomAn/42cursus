	#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
  int fd, sz;
  char *c;

  fd = open("testfile.txt", O_RDONLY);
//   if (fd < 0) { perror("r1"); exit(1); }
	while (sz = get_next_line(fd, &c))
	{
		printf("%s\n", c);
		free(c);
	}
	free(c);
}
