<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Requirements

## Table of Contents :

  - [0. Radix sort](#subparagraph0)

## Requirements
### General
* Allowed editors:vi,vim,emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled withgcc 4.8.4using the flags-Wall-Werror-Wextraand-pedantic
* All your files should end with a new line
* AREADME.mdfile, at the root of the folder of the project, is mandatory
* Your code should use theBettystyle. It will be checked usingbetty-style.plandbetty-doc.pl
* You are not allowed to use global variables
* No more than 5 functions per file
* Unless specified otherwise, you are not allowed to use the standard library. Any use of functions likeprintf, puts, …is totally forbidden.
* In the following examples, themain.cfiles are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our ownmain.cfiles at compilation. Ourmain.cfiles might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file calledsort.h
* Don’t forget to push your header file
* All your header files should be include guarded
* A list/array does not need to be sorted if its size is less than 2.

## Task
### 0. Radix sort <a name='subparagraph0'></a>

Write a function that sorts an array of integers in ascending order using the <a href="/rltoken/gEDsl63pd3J_pt5ywkTE4w" target="_blank" title="Radix sort">Radix sort</a> algorithm

* Prototype: <code>void radix_sort(int *array, size_t size);</code>
* You must implement the <code>LSD</code> radix sort algorithm
* You can assume that <code>array</code> will contain only numbers <code>&gt;= 0</code>
* You are allowed to use <code>malloc</code> and <code>free</code> for this task
* You’re expected to print the <code>array</code> each time you increase your <code>significant digit</code> (See example below)

```
alexa@ubuntu-xenial:radix_sort$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alexa@ubuntu-xenial:radix_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
alexa@ubuntu-xenial:radix_sort$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:radix_sort$
```

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
