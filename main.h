#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED



#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int _printf(const char *format, ...);
unsigned int write_char(char ch);
unsigned int write_string(char *s);
unsigned int write_int(long int, int);
unsigned int convert_num_to_base(uint32_t n, unsigned int base);
unsigned int write_hexadecimal(uint32_t, char);
#endif /* MAIN_H_INCLUDED */


