#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * diccionary - Returns the required function
 * Return: pointer to function required
 */
fmt *diccionary()
{
	fmt *dic = malloc(sizeof(fmt) * 13);

	if (dic)
	{
		dic[0].identifs = 'c';
		dic[0].print_funcs = print_char;
		dic[1].identifs = 'i';
		dic[1].print_funcs = print_int;
		dic[2].identifs = 's';
		dic[2].print_funcs = print_str;
		dic[3].identifs = 'd';
		dic[3].print_funcs = print_dec;
		dic[4].identifs = '%';
		dic[4].print_funcs = print_perc;
		dic[5].identifs = 'b';
		dic[5].print_funcs = print_binary;
		dic[6].identifs = 'u';
		dic[6].print_funcs = print_unsignedint;
		dic[7].identifs = 'o';
		dic[7].print_funcs = print_octal;
		dic[8].identifs = 'x';
		dic[8].print_funcs = print_hexadec;
		dic[9].identifs = 'X';
		dic[9].print_funcs = print_HexaDec;
		dic[10].identifs = 'r';
		dic[10].print_funcs = print_rev;
		dic[11].identifs = 'R';
		dic[11].print_funcs = print_rot13;
		dic[12].identifs = 0;
		dic[12].print_funcs = NULL;
		return (dic);
	}
	return (NULL);
}

/**
 * unknown_i - stores unknown identifiers in buffer
 * @p: char to print
 * @buffer: Pointer to a buffer that stores chars to print
 * @size: Pointer to a variable that counts the position in buffer
 */
void unknown_i(char p, char *buffer, unsigned int *size)
{
	buffer[*size] = '%';
	*size += 1;
	buffer[*size] = p;
	*size += 1;
}

/**
 * print_rev - stores reversed strings
 * @list: list of arguments
 * @buffer: Pointer to a buffer that stores chars to print
 * @size: Pointer to a variable that counts the position in buffer
 */
void print_rev(va_list list, char *buffer, unsigned int *size)
{
	char *str = va_arg(list, char *);
	int counter = 0;

	if (str == NULL)
		str = "(null)";
	while (str[counter])
		counter++;
	counter--;
	while (counter >= 0)
	{
		buffer[*size] = str[counter];
		*size += 1;
		counter--;
	}
}

/**
 * print_rot13 - stores reversed strings
 * @list: list of arguments
 * @buffer: Pointer to a buffer that stores chars to print
 * @size: Pointer to a variable that counts the position in buffer
 */
void print_rot13(va_list list, char *buffer, unsigned int *size)
{
	char *str = NULL;
	int counter = 0;

	str =  va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	while (str[counter])
	{
		if ((str[counter] > 64 && str[counter] < 78)
		    || (str[counter] > 96 && str[counter] < 110))
		{
			buffer[*size] = str[counter] + 13;
			*size += 1;
			counter++;
		}
		else if ((str[counter] > 77 && str[counter] < 91)
			 || (str[counter] > 109 && str[counter] < 123))
		{
			buffer[*size] = str[counter] - 13;
			*size += 1;
			counter++;
		}
		else
		{
			buffer[*size] = str[counter];
			*size += 1;
			counter++;
		}
	}
}
