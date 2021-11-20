#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef double mat[4][4];

void read_mat(mat *p, int, double arr[]);
void print_mat(mat);
void add_mat(mat, mat, mat *);
void sub_mat(mat, mat, mat *);
void mul_mat(mat, mat, mat *);
void mul_scalar(mat, double, mat *);
void trans_mat(mat, mat *);
mat * string_to_mat (char str[], mat *, mat *, mat *, mat *, mat *, mat *); /*a function to convert string to mat*/
int is_mat (char str[]); /*a function to check if a string has a mat's name*/
