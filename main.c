#include "creload.h"

void f_free_2d(char **s_buff, int words) {
	for (int i = 0; i < words; i++){
		free(s_buff[i]);
	}
	free(s_buff);
}

void f_puterror(char *str) {
	int i = 0;
	while (str[i]) {
		write(2,&str[i],1);
		i++;
	}
	exit(1);
}

void f_putstr(char *str) {
	int i = 0;
	while (str[i]) {
		write(1,&str[i],1);
		i++;
	}
	exit(1);
}

int main(int ac, char **av) {
	if (ac != 3) {
		f_puterror("Not Enough Args");
	}
	int fd = open(av[1],O_RDONLY);
	if (fd == -1) {
		f_puterror("Couldn't Open That File");
	}
	char *buff = f_read_file(fd);
	close(fd);
	int words = f_count_words(buff);
	char **s_buff = f_split(buff,words);
	free(buff);
	f_free_2d(s_buff,words);
	return 0;
}
