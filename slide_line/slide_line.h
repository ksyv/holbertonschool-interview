#ifndef __SLIDE_LINE__
#define __SLIDE_LINE__

#include <stddef.h>
#include <stdio.h>

#define SLIDE_LEFT 76
#define SLIDE_RIGHT 82

int slide_line(int *line, size_t size, int direction);
void to_the_left(int *, size_t);
void to_the_right(int *, size_t);

#endif
