<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Requirements

## Table of Contents :

  - [0. Substring with concatenated words](#subparagraph0)

## Requirements
### General
* Allowed editors:vi,vim,emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled withgcc 4.8.4using the flags-Wall-Werror-Wextraand-pedantic
* All your files should end with a new line
* Your code should use theBettystyle. It will be checked usingbetty-style.plandbetty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* In the following examples, themain.cfiles are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our ownmain.cfiles at compilation. Ourmain.cfiles might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file calledsubstring.h
* Don’t forget to push your header file
* All your header files should be include guarded

## Task
### 0. Substring with concatenated words <a name='subparagraph0'></a>

Write a function that finds all the possible substrings containing a list of words, within a given string.

* <p>Prototype: <code>int *find_substring(char const *s, char const **words, int nb_words, int *n);</code>, where</p>

  * <code>s</code> is the string to scan
  * <code>words</code> is the array of words all substrings must be a concatenation arrangement of
  * <code>nb_words</code> is the number of elements in the array <code>words</code>
  * <code>n</code> holds the address at which to store the number of elements in the returned array.
* <p>Your function must return an allocated array, storing each index in <code>s</code>, at which a substring was found. If no solution is found, NULL can be returned</p>
* <p>All words in the array <code>words</code> are the same length</p>
* <p>A valid substring of <code>s</code> is the concatenation of each word in <code>words</code> exactly once and without any intervening characters</p>

```
alex@~/holbertonschool-interview_prep/substring$ cat main.c
#include 
#include 

#include "substring.h"

int main(int ac, char const **av)
{
    char const *s;
    char const **words;
    int nb_words;
    int *indices;
    int n;
    int i;

    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s  [word [word2 ...]]\n", av[0]);
        return (EXIT_FAILURE);
    }

    s = av[1];
    words = av + 2;
    nb_words = ac - 2;

    indices = find_substring(s, words, nb_words, &n);

    printf("Indices -> [");
    for (i = 0; i < n; i++)
    {
        if (i)
            printf(", ");
        printf("%d", indices[i]);
    }
    printf("]\n");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-interview_prep/substring$ gcc -Wall -Wextra -Werror -pedantic main.c substring.c
alex@~/holbertonschool-interview_prep/substring$ ./a.out barfoothefoobarman foo bar
Indices -> [0, 9]
alex@~/holbertonschool-interview_prep/substring$ ./a.out wordgoodgoodgoodbestword word good best word
Indices -> []
alex@~/holbertonschool-interview_prep/substring$ ./a.out wordgoodgoodgoodbestword word good best good
Indices -> [8]
alex@~/holbertonschool-interview_prep/substring$
```

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
