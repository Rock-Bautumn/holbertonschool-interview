#include "palindrome.h"

/**
 * reverse_num - Reverse a size_t integer, such that 12345 becomes 54321.
 * @num: The number to reverse
 * Return: The reversed number
*/

size_t reverse_num(size_t num)
{
	size_t mun_desrever = 0;

	while (num != 0)
	{
		mun_desrever = mun_desrever * 10 + num % 10;
		num = num / 10;
	}

	return (mun_desrever);
}

/**
 * is_palindrom - Checks if a number is a palindrome or not
 * @n: The number being checked if it is a palindrome
 * Return: true/1 if palindrome, false/0 if not a palindrome
*/

int is_palindrome(unsigned long n)
{
	if (n == reverse_num(n))
		return (true);

	return (false);
}
