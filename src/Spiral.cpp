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

void spiralRec(int rows, int columns, int **input_array, int *CurrentRow, int *CurrentColumn, int *a, int *index){
	int i, cr = *CurrentRow, cc = *CurrentColumn;
	if (cr >= rows || cc >= columns){
		return;
	}
	for (i = cc; i < columns; ++i)
	{
		a[(*index)++] = input_array[cr][i];
	
	}
	cr++;

	for (i = cr; i < rows; ++i)
	{
		a[(*index)++] = input_array[i][columns - 1];

	}
	columns = columns - 1;

	if (cr < rows)
	{
		for (i = columns - 1; i >= cc; --i)
		{
			a[(*index)++] = input_array[rows - 1][i];

		}
		rows = rows - 1;
	}
	else
	{
		return;
	}

	if (cc < columns)
	{
		for (i = rows - 1; i >= cr; --i)
		{
			a[(*index)++] = input_array[i][cc];

		}
		cc++;
	}
	else
	{
		return;
	}
	*CurrentRow = cr;
	*CurrentColumn = cc;
	spiralRec(rows, columns, input_array, CurrentRow, CurrentColumn, a, index);
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
		return NULL;
	int index = 0, CurrentRow = 0, CurrentColumn = 0;
	int *res = (int *)malloc(sizeof(int)*(rows*columns));
	spiralRec(rows, columns, input_array, &CurrentRow, &CurrentColumn, res, &index);
	return res;
}
