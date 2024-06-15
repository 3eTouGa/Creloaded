#include "creload.h"

#define sp 32 /*** space ***/

static void f_fill_buffer(char *buff, char **s_buff) {
	int i = 0;
	int j =-1;
	while(buff[i] && buff[i] == sp) i++;
	while(buff[i]) {
		int k = 0;
		if (buff[i] && buff[i] != sp) {
			j++;
			while(buff[i] && buff[i] != sp) {
				s_buff[j][k] = buff[i];
				i++;
				k++;
			}
			s_buff[j][k] = '\0';
		}
		if (buff[i]) {
			i++;
		}
	}
}

static int f_count_characters(char *buff) {
	int i = 0;
	int count = 0;
	while(buff[i] && buff[i] == sp)
		i++;
	while(buff[i]) {
		if (buff[i] != sp) {
			count++;
		}
		i++;
	}
	return count;
}

int f_count_words(char *buff) {
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(buff[i] && buff[i] == sp)
		i++;
	while(buff[i]) {
		if (buff[i] != sp) {
			count++;
			while(buff[i] && buff[i] != sp) {
				i++;
			}
			continue;
		}
		i++;
	}
	return count;
}

char **f_split(char *buff, int words) {
	char **s_buff = malloc(words);
	if (s_buff == NULL) {
		f_puterror("Couldn't allocate, Not enough memory");
	}
	int characters = f_count_characters(buff);
	int j = 0;
	for (int i = 0; i < words; i++) {
		int word = 0;
		while(buff[j] && buff[j] == sp) j++;
		while (j < characters && buff[j] && buff[j] != sp) {
			word++;
			j++;
		}
		s_buff[i] = malloc(word + 1);
	}
	f_fill_buffer(buff,s_buff);
	return s_buff;
}
