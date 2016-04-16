/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
int * spiralarray(int **, int *, int *, int *, int *, int *, int *, int *);

int *spiral(int rows, int columns, int **input_array)
{
	int c = 0, top, down, left, right,*p,c1=0;
	if (rows <= 0 || columns <= 0||input_array==NULL)
		return NULL;
	p = (int *)malloc(rows*columns*sizeof(int));
	top = 0;
	down = rows - 1;
	left = 0;
	right = columns - 1;
	if (c <= rows*columns)
		return spiralarray(input_array, p, &top, &down, &left, &right, &c, &c1);
}
int * spiralarray(int **a, int *p, int *top, int *down, int *left, int *right, int *c, int *count)
{
	int i;
	if (*top <= *down&&*left <= *right)
	{
		(*c)++;
		if ((*c) % 4 == 1)
		{
			for (i = *left; i <= *right; i++)
				p[(*count)++] = a[*top][i];
			(*top)++;
		}
		if ((*c) % 4 == 2)
		{
			for (i = *top; i <= *down; i++)
				p[(*count)++] = a[i][*right];
			(*right)--;
		}
		if ((*c) % 4 == 3)
		{
			for (i = *right; i >= *left; i--)
				p[(*count)++] = a[*down][i];
			(*down)--;
		}
		if ((*c) % 4 == 0)
		{
			for (i = *down; i >= *top; i--)
				p[(*count)++] = a[i][*left];
			(*left)++;
		}
		return spiralarray(a, p, top, down, left, right, c, count);
	}
	else
		return p;
}