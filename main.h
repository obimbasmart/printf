#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED



#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int _printf(const char *format, ...);
unsigned int write_char(char ch);
unsigned int write_string(char *s);
unsigned int write_int(long int, int);

#endif /* MAIN_H_INCLUDED */


