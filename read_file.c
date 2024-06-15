#include "creload.h"

char *f_read_file(int fd) {
	/*** to calculate how many byte to allocate for the buffer ***/
	off_t position = lseek(fd,0,SEEK_END);
	char *buff = malloc(position + 1);
	lseek(fd,0,SEEK_SET);
	read(fd,buff,position);
	buff[position] = '\0';
	return buff;
}
