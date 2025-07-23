#include "regex.h"
#include <stddef.h>

/**
 * regex_match - Checks if a given pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
    if (!pattern || !str)
        return (0);

    if (*pattern == '\0')
        return (*str == '\0');

    if (*(pattern + 1) != '*')
    {
        if (*pattern == '.' || *pattern == *str)
            return (*str && regex_match(str + 1, pattern + 1));
        return (0);
    }

    while (*str && (*pattern == '.' || *pattern == *str))
    {
        if (regex_match(str, pattern + 2))
            return (1);
        str++;
    }

    return (regex_match(str, pattern + 2));
}