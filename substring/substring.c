#include "substring.h"

/**
 * check_match - Checks if a substring starting at index i is a concatenation.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: Number of words in the array.
 * @w_len: Length of each word.
 * @found: Buffer to track used words.
 *
 * Return: 1 if match, 0 otherwise.
 */
int check_match(char const *s, char const **words, int nb_words,
		int w_len, int *found)
{
	int j, k;
	char *temp_word;

	for (j = 0; j < nb_words; j++)
		found[j] = 0;

	for (j = 0; j < nb_words; j++)
	{
		temp_word = strndup(s + (j * w_len), w_len);
		for (k = 0; k < nb_words; k++)
		{
			if (!found[k] && strcmp(temp_word, words[k]) == 0)
			{
				found[k] = 1;
				break;
			}
		}
		free(temp_word);
		if (k == nb_words)
			return (0);
	}
	return (1);
}

/**
 * find_substring - Finds indices of substrings from concatenated words.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: Number of words.
 * @n: Pointer to store the number of found indices.
 *
 * Return: Allocated array of indices or NULL.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, w_len, total_len, i;
	int *indices, *found;

	*n = 0;
	if (!s || !words || nb_words == 0)
		return (NULL);

	s_len = (int)strlen(s);
	w_len = (int)strlen(words[0]);
	total_len = nb_words * w_len;

	if (total_len > s_len)
		return (NULL);

	indices = malloc(sizeof(int) * s_len);
	found = malloc(sizeof(int) * nb_words);
	if (!indices || !found)
	{
		free(indices);
		free(found);
		return (NULL);
	}

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (check_match(s + i, words, nb_words, w_len, found))
		{
			indices[*n] = i;
			(*n)++;
		}
	}

	free(found);
	if (*n == 0)
	{
		free(indices);
		return (NULL);
	}
	return (indices);
}
