#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 * Return: number of words
 */
int count_word(char *s)
{
	int flag = 0, c, w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * allocate_word - allocate memory and copy a word from the string
 * @str: string containing words
 * @start: starting index of the word
 * @end: ending index of the word
 * Return: pointer to the allocated word
 */
char *allocate_word(char *str, int start, int end)
{
	int i, length = end - start;
	char *word = malloc(sizeof(char) * (length + 1));

	if (word == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		word[i] = str[start + i];

	word[length] = '\0';
	return (word);
}

/**
 * strtow - splits a string into words
 * @str: string to split
 * Return: pointer to an array of strings (Success) or NULL (Error)
 */
char **strtow(char *str)
{
	char **matrix, *word;
	int i, k = 0, len = 0, words, c = 0, start, end;

	while (str[len])
		len++;

	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				word = allocate_word(str, start, end);
				if (word == NULL)
				{
					for (i = 0; i < k; i++)
						free(matrix[i]);
					free(matrix);
					return (NULL);
				}
				matrix[k++] = word;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;
	return (matrix);
}

