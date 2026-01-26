<div align="center"><img src="https://github.com/ksyv/holbertonschool-web_front_end/blob/main/baniere_holberton.png"></div>

# Requirements

## Table of Contents :

  - [0. Merge sort](#subparagraph0)

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
### 0. Merge sort <a name='subparagraph0'></a>

Write a function that sorts an array of integers in ascending order using the <a href="/rltoken/ySi_kjCNSAeBKdsCl8SgZw" target="_blank" title="Merge Sort">Merge Sort</a> algorithm:

* <p>Prototype: <code>void merge_sort(int *array, size_t size);</code></p>
* <p>You must implement the <code>top-down</code> merge sort algorithm</p>

  * When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. <code>{1, 2, 3, 4, 5}</code> -> <code>{1, 2}, {3, 4, 5}</code>
  * Sort the left array before the right array
* <p>You are allowed to use <code>printf</code></p>
* <p>You are allowed to use <code>malloc</code> and <code>free</code> only once (only one <strong>call</strong>)</p>
* <p>Output: see example</p>

In the file <code>0-O</code>, write the Big O notations of the time complexity of the Merge Sort algorithm, with 1 notation per line:

* <p>in the best case</p>
* <p>in the average case</p>
* <p>in the worst case</p>

```
alexa@ubuntu-xenial:merge_sort$ cat 0-main.c
#include 
#include 
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
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alexa@ubuntu-xenial:merge_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
alexa@ubuntu-xenial:merge_sort$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:merge_sort$
```

---


## Authors
Ksyv - [GitHub Profile](https://github.com/ksyv)
