#include "mat.h"

void add_mat(mat a, mat b, mat *c)
{
	int row = 0;
	while (row<4)
	{
		int column = 0;
		while (column<4)
		{
			(*c)[row][column] = (a[row][column])+(b[row][column]);
			column++;
		}
		row++;
	}
	return;
}

void sub_mat(mat a, mat b, mat *c)
{
	int row = 0;
	while (row<4)
	{
		int column = 0;
		while (column<4)
		{
			(*c)[row][column] = (a[row][column])-(b[row][column]);
			column++;
		}
		row++;
	}
	return;
}

void mul_mat(mat a, mat b, mat *c)
{
	int row = 0;
	while (row<4)
	{
		int column = 0;
		while (column<4)
		{
			(*c)[row][column] = 0;
			column++;
		}
		row++;
	}
	row = 0;
	while (row<4)
	{
		int column = 0;
		while (column<4)
		{
			int i = 0;
			while (i<4)
			{
				(*c)[row][column] += (a[row][i])*(b[i][column]);
				i++;
			}
			column++;
		}
		row++;
	}
	return;
}

void mul_scalar(mat a, double x, mat *b)
{
	int row = 0;
	while (row<4)
	{
		int column = 0;
		while (column<4)
		{
			(*b)[row][column] = (a[row][column])*x;
			column++;
		}
		row++;
	}
	return;
}

void trans_mat(mat a, mat *b)
{
	int row = 0;
	while (row<4)
	{
		int column = 0;
		while (column<4)
		{
			(*b)[row][column] = a[column][row];
			column++;
		}
		row++;
	}

	return;
}
