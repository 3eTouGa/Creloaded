#ifndef CRELOAD_H
#define CRELOAD_H
/*** includes ***/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
/*** my funcs ***/
void f_putstr(char *str);
void f_puterror(char *str);
char *f_read_file(int fd);
char *f_parse_flags(char *buff);
char **f_split(char *buff, int words);
void f_free_2d(char **s_buff, int words);
int f_count_words(char *buff);
#endif
