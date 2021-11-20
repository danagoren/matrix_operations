#include "mat.h"

int main()
{
	mat MAT_A = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	mat MAT_B = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	mat MAT_C = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	mat MAT_D = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	mat MAT_E = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	mat MAT_F = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	char maybe_mat[6];
	char maybe_mat2[6];
	char maybe_mat3[6];
	mat *mats[7];
	mats[0] = &MAT_A; mats[1] = &MAT_B; mats[2] = &MAT_C; mats[3] = &MAT_D;
	mats[4] = &MAT_E; mats[5] = &MAT_F;

	while (1)
	{
	int acceptable_command = 1; /*0 means acceptable, 1 means error*/
	char line[20];
	char trash[10];
	char trash2[200];
	trash2[0] = 'a';
	trash2[1] = 'a';
	printf("\nGive me a command\n");
	scanf("%s", line);
	if (line[0]==EOF)
	{
		printf("Error - reached End Of File");
		exit(1);
	}
	if ((strncmp(line, "stop", 4))==0)
	{
		acceptable_command = 0;
		scanf("%[^\n]s", trash2);
		if ((line[4] != '\0') || (trash2[0] != 'a'))
		{
			printf("\nError - extraneous text after end of command\n");
			exit(1);
		}
		exit(0);
	}
	if ((strncmp(line, "read_mat", 9))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		maybe_mat[5] = '\0';
		if (is_mat(maybe_mat))
		{
			double nums[16];
			int count = 0;
			while (scanf(", %lf", &nums[count]))
			{
				count++;
			}
			if (count==0)
			{
				printf("Missing argument");
			}
			else
			{
				int i = 0;
				printf("\n%s %s", line, maybe_mat);
				while (i<count)
				{
					printf(", %g", nums[i]);
					i++;
				}
				read_mat(string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), count, nums);
			}
		}/*end of 2nd if*/
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of read_mat*/
	if ((strncmp(line, "print_mat", 9))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		if (is_mat(maybe_mat))
		{
			printf("\n%s %s\n",line, maybe_mat);
			print_mat(*(string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5])));
		}
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of print_mat*/
	if ((strncmp(line, "add_mat", 7))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		maybe_mat[5] = '\0';
		if (is_mat(maybe_mat))
		{
			fgets(trash, 3, stdin); /*space*/
			fgets(maybe_mat2, 6, stdin);
			maybe_mat2[5] = '\0';
			if (is_mat(maybe_mat2))
			{
				fgets(trash, 3, stdin); /*space*/
				fgets(maybe_mat3, 6, stdin);
				maybe_mat3[5] = '\0';
				if (is_mat(maybe_mat3))
				{
					printf("\n%s %s, %s, %s\n", line, maybe_mat, maybe_mat2, maybe_mat3);
					add_mat(*string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), *string_to_mat(maybe_mat2, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), (string_to_mat(maybe_mat3, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5])));
				}/*end of 4th if*/
				else
				{
					printf("Undefined matrix name");
				}
			}/*end of 3rd if*/
			else
			{
				printf("Undefined matrix name");
			}
		}/*end of 2nd if*/
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of case line=add_mat*/
	if ((strncmp(line, "sub_mat", 7))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		maybe_mat[5] = '\0';
		if (is_mat(maybe_mat))
		{
			fgets(trash, 3, stdin); /*space*/
			fgets(maybe_mat2, 6, stdin);
			maybe_mat2[5] = '\0';
			if (is_mat(maybe_mat2))
			{
				fgets(trash, 3, stdin); /*space*/
				fgets(maybe_mat3, 6, stdin);
				maybe_mat3[5] = '\0';
				if (is_mat(maybe_mat3))
				{
					printf("\n%s %s, %s, %s\n", line, maybe_mat, maybe_mat2, maybe_mat3);
					sub_mat(*string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), *string_to_mat(maybe_mat2, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), (string_to_mat(maybe_mat3, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5])));
				}/*end of 4th if*/
				else
				{
					printf("Undefined matrix name");
				}
			}/*end of 3rd if*/
			else
			{
				printf("Undefined matrix name");
			}
		}/*end of 2nd if*/
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of case line=sub_mat*/
	if ((strncmp(line, "mul_mat", 7))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		maybe_mat[5] = '\0';
		if (is_mat(maybe_mat))
		{
			fgets(trash, 3, stdin); /*space*/
			fgets(maybe_mat2, 6, stdin);
			maybe_mat2[5] = '\0';
			if (is_mat(maybe_mat2))
			{
				fgets(trash, 3, stdin); /*space*/
				fgets(maybe_mat3, 6, stdin);
				maybe_mat3[5] = '\0';
				if (is_mat(maybe_mat3))
				{
					printf("\n%s %s, %s, %s\n", line, maybe_mat, maybe_mat2, maybe_mat3);
					mul_mat(*string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), *string_to_mat(maybe_mat2, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), (string_to_mat(maybe_mat3, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5])));
				}/*end of 4th if*/
				else
				{
					printf("Undefined matrix name");
				}
			}/*end of 3rd if*/
			else
			{
				printf("Undefined matrix name");
			}
		}/*end of 2nd if*/
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of case line=mul_mat*/
	if ((strncmp(line, "mul_scalar", 10))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		maybe_mat[5] = '\0';
		if (is_mat(maybe_mat))
		{
			double scalar;
			/*fgets(trash, 2, stdin); */
			if (scanf(", %lf", &scalar))
			{
				fgets(trash, 3, stdin); /*space*/
				fgets(maybe_mat3, 6, stdin);
				maybe_mat3[5] = '\0';
				if (is_mat(maybe_mat3))
				{
					printf("\n%s %s, %g, %s\n", line, maybe_mat, scalar, maybe_mat3);
					mul_scalar(*string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), scalar, (string_to_mat(maybe_mat3, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5])));
				}/*end of 4th if*/
				else
				{
					printf("Undefined matrix name");
				}
			}/*end of 3rd if*/
			else
			{
				printf("Missing Scalar");
			}
		}/*end of 2nd if*/
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of case line=mul_scalar*/
	if ((strncmp(line, "trans_mat", 9))==0)
	{
		acceptable_command = 0;
		fgets(trash, 2, stdin); /*space*/
		fgets(maybe_mat, 6, stdin);
		maybe_mat[5] = '\0';
		if (is_mat(maybe_mat))
		{
				fgets(trash, 3, stdin); /*space*/
				fgets(maybe_mat3, 6, stdin);
				maybe_mat3[5] = '\0';
				if (is_mat(maybe_mat3))
				{
					printf("\n%s %s, %s\n", line, maybe_mat, maybe_mat3);
					trans_mat(*string_to_mat(maybe_mat, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5]), (string_to_mat(maybe_mat3, mats[0], mats[1], mats[2], mats[3], mats[4], mats[5])));
				}/*end of 3rd if*/
				else
				{
					printf("Undefined matrix name");
				}
		}/*end of 2nd if*/
		else
		{
			printf("Undefined matrix name");
		}
	}/*end of case line=trans_mat*/
	scanf("%[^\n]s", trash); /*cleaning buffer for the next command*/
	if (acceptable_command == 1)
	{
		printf("Undefined command name");
		continue;
	}
	}/*end of while*/
}/*end of main*/


void read_mat(mat *x, int count, double *a)
{
	switch (count)
	{
		case 16:	(*x)[3][3] = a[15];
		case 15:	(*x)[3][2] = a[14];
		case 14:	(*x)[3][1] = a[13];
		case 13:	(*x)[3][0] = a[12];
		case 12:	(*x)[2][3] = a[11];
		case 11:	(*x)[2][2] = a[10];
		case 10:	(*x)[2][1] = a[9];
		case 9:		(*x)[2][0] = a[8];
		case 8:		(*x)[1][3] = a[7];
		case 7:		(*x)[1][2] = a[6];
		case 6:		(*x)[1][1] = a[5];
		case 5:		(*x)[1][0] = a[4];
		case 4:		(*x)[0][3] = a[3];
		case 3:		(*x)[0][2] = a[2];
		case 2:		(*x)[0][1] = a[1];
		case 1:		(*x)[0][0] = a[0];
				break;
	}
	return;
}
void print_mat(mat x)
{
	printf("\n%7.2f\t%7.2f\t%7.2f\t%7.2f", x[0][0], x[0][1], x[0][2], x[0][3]);
	printf("\n%7.2f\t%7.2f\t%7.2f\t%7.2f", x[1][0], x[1][1], x[1][2], x[1][3]);
	printf("\n%7.2f\t%7.2f\t%7.2f\t%7.2f", x[2][0], x[2][1], x[2][2], x[2][3]);
	printf("\n%7.2f\t%7.2f\t%7.2f\t%7.2f",x[3][0], x[3][1], x[3][2], x[3][3]);
}

/*a function that "converts" a string of a mat's name into a pointer to the mat*/
mat * string_to_mat (char * str, mat *a, mat *b, mat *c, mat *d, mat *e, mat *f)
{
	if ((strcmp(str, "MAT_A"))==0) return a;
	if ((strcmp(str, "MAT_B"))==0) return b;
	if ((strcmp(str, "MAT_C"))==0) return c;
	if ((strcmp(str, "MAT_D"))==0) return d;
	if ((strcmp(str, "MAT_E"))==0) return e;
	if ((strcmp(str, "MAT_F"))==0) return f;
	printf("There is a problem in the code, you have called the function string_to_mat with a string that doesn't match any matrix.\nEdit the code.");
	printf("\n(Solution: First check if the string matches with any matrix with the function is_mat)");
	return a; /*default*/
}/*end of function string_to_mat*/

/*a function to check if a string has a mat's name*/
int is_mat (char str[])
{
	if ((strcmp(str, "MAT_A"))==0) return 1;
	if ((strcmp(str, "MAT_B"))==0) return 1;
	if ((strcmp(str, "MAT_C"))==0) return 1;
	if ((strcmp(str, "MAT_D"))==0) return 1;
	if ((strcmp(str, "MAT_E"))==0) return 1;
	if ((strcmp(str, "MAT_F"))==0) return 1;
	return 0; /*returns 0 if the given string doesn't match with any matrix*/
}
