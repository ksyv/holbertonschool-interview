<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Requirements

## Table of Contents :

  - [0. Simple RegEx](#subparagraph0)

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
* The prototypes of all your functions should be included in your header file calledregex.h
* Don’t forget to push your header file
* All your header files should be include guarded

## Task
### 0. Simple RegEx <a name='subparagraph0'></a>

Write a function that checks whether a given pattern matches a given string.

* Prototype: <code>int regex_match(char const *str, char const *pattern);</code>, where:


  * <code>str</code> is the string to scan
  * <code>pattern</code> is the regular expression
* Your function must return <code>1</code> if the pattern matches the string, or <code>0</code> if it doesn’t
* <code>str</code> can be empty, and can contain any ASCII character in the exception of <code>.</code> and <code>*</code>
* <code>pattern</code> can be empty, and can contain any ASCII character, including <code>.</code> and <code>*</code>
* The regular expression matching must support the characters <code>.</code> and <code>*</code>

  * <code>.</code> matches any single character
  * <code>*</code> matches zero or more of the preceding character

```
alex@~/holbertonschool-interview_prep/regex$ cat main.c
#include <stdlib.h>
#include <stdio.h>

#include "regex.h"

#define TEST_MATCH(s, p)    do {\
    {\
        int res = regex_match(s, p);\
        printf("%s -> %s = %d\n", s, p, res);\
    }\
} while(0)

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    TEST_MATCH("H", "H");
    TEST_MATCH("HH", "H");
    TEST_MATCH("HH", "H*");
    TEST_MATCH("HHHHHHHHHHHHHHHHH", "H*");

    TEST_MATCH("Holberton", ".*");
    TEST_MATCH("Alex", ".*");
    TEST_MATCH("Guillaume", ".*");
    TEST_MATCH("Julien", ".*");

    TEST_MATCH("Holberton", "Z*H.*");
    TEST_MATCH("Holberton", "Z*H.*olberton");
    TEST_MATCH("Holberton", "Z*H.*o.");
    TEST_MATCH("Holberton", "Z*H.*o");

    TEST_MATCH("Holberton", "holberton");
    TEST_MATCH("Holberton", ".olberton");

    TEST_MATCH("!H@o#l$b%e^r&t(o)n_", "!.@.#.$.%.^.&.(.)._");

    return (EXIT_SUCCESS);
}
alex@~/holbertonschool-interview_prep/regex$ gcc -Wall -Wextra -Werror -pedantic main.c regex.c
alex@~/holbertonschool-interview_prep/regex$ ./a.out
H -> H = 1
HH -> H = 0
HH -> H* = 1
HHHHHHHHHHHHHHHHH -> H* = 1
Holberton -> .* = 1
Alex -> .* = 1
Guillaume -> .* = 1
Julien -> .* = 1
Holberton -> Z*H.* = 1
Holberton -> Z*H.*olberton = 1
Holberton -> Z*H.*o. = 1
Holberton -> Z*H.*o = 0
Holberton -> holberton = 0
Holberton -> .olberton = 1
!H@o#l$b%e^r&t(o)n_ -> !.@.#.$.%.^.&.(.)._ = 1
alex@~/holbertonschool-interview_prep/regex$
```

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
