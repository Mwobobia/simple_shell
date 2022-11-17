#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _puts - prints a string to stdout
  * @str: string to print
  *
  * Return: 0 on success
  */
int _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	return (0);
}
/**
 * _putchar_p - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar_p(char c)
{
	return (write(2, &c, 1));
}

/**
  * _puts_p - prints a string to stderr
  * @str: string to print
  *
  * Return: 0 on success
  */
int _puts_p(char *str)
{
	while (*str != '\0')
	{
		_putchar_p(*str);
		str++;
	}
	return (0);
}

