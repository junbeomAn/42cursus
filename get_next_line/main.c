	#include<stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

int main()
{
  int fd, sz;
  char *c;

  fd = open("testfile.txt", O_RDONLY);
	while ((sz = get_next_line(fd, &c)) > 0)
	{
		printf("%s %d\n", c, sz);
		free(c);
	}
  	/*sz = get_next_line(fd, &c);
  	printf("%s %d\n", c, sz);
  	sz = get_next_line(fd, &c);
	printf("%s %d\n", c, sz);
  	sz = get_next_line(fd, &c);
	printf("%s %d\n", c, sz);
  	sz = get_next_line(fd, &c);
	printf("%s %d\n", c, sz);
	sz = get_next_line(fd, &c);
	printf("%s %d\n", c, sz);
	sz = get_next_line(fd, &c);
	printf("%s %d\n", c, sz);

	free(c);*/
}
