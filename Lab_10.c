#include<math.h>
#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include <malloc.h>


void program_21()
{
    int i, j, c = 0, row, column, k = 0;
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
    srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            a[i][j] = rand() % 50 - 25; // generates random numbers from -25 to 24 in an array a[i][j]
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }

    /* Go through each matrix element and if it is 0, then increment the local variable k and then display it on each line. If the string does not contain zero matrix elements, then increment the local variable c */

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] == 0)
                c++;
        }
    }
    printf("\nThe number of columns that do not contain any null items = %d \n", column - c); //the number of columns that do not contain any zero elements
    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}


void program_22()
{
    int i, j, c, row, column;
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
    int* s = (int*)malloc(row * sizeof(int)); // an array to calculate the number of identical elements

    srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            a[i][j] = rand() % 6 - 3; // generates random numbers from -3 to 2 in an array a[i][j]
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    /* zero the array to store the same records */
    for (int i = 0; i < row; i++) {
        s[i] = 0;
    }

    /* calculate the characteristics */
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (a[i][j] > 0 && a[i][j] % 2 == 0)
                s[i] += a[i][j];
        }
        printf("Sum of positive odd elements in %d string - %d\n", i, *(s + i));
    }
    printf("\n");

    /* Use bubble sorting by comparing array elements with characteristics. When shifting the elements, we also shift the lines with the corresponding indexes. */

    for (int i = 0; i < row; i++)
        for (int j = row - 1; j > i; j--)
            if (s[j] < s[i])
            {
                int t = s[i];
                s[i] = s[j];
                s[j] = t;
                /* swapping line elements */
                for (int k = 0; k < column; k++)
                {
                    t = a[i][k];
                    a[i][k] = a[j][k];
                    a[j][k] = t;
                }
            }
    /* The output of the new stores matrix */
    for (i = 0; i < row; i++) {
        for (j = 0; j < column; j++) {
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }

    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}

void program_23()
{
    int i, j, c = 0, row, column, p, k, t, m = 0, sumR = 0, sumC = 0, d1 = 0, d2 = 0;
    printf("\nEnter the size of the square\n");
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
    srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            a[i][j] = rand() % 2; // generates random numbers from 0 to 1 in an array a[i][j]
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    for (i = 0; i < row; i++) 
    {
        for (j = 0; j < column; j++)
        {
            m += a[i][j];
        }
    }
    for (i = 1; i < row; i++) { // check the lines
        sumR = 0;
        for (j = 0; j < column; j++)
            sumR += a[i][j];
        if (sumR != m) {
        }
    }

    for (j = 0; j < column; j++) { // check the columns
        sumC = 0;
        for (t = 0; t < column; t++)
            sumC += a[t][j];
        if (sumC != m) {
        }

    }
    for (p = 0, j = 0; p < column; p++, j++) // check the diagonals
        d1 += a[p][j];
    if (d1 != m) {
    }

    for (i = 0, k = row - 1; i < row; i++, k--)
        d2 += a[i][k];
    if (d2 != m) {
    }

    printf("\nSum of Rows: %d", sumR); printf("\n");
    printf("Sum of Columns: %d", sumC); printf("\n");
    printf("Sum of diagonal 1: %d", d1); printf("\n");
    printf("Sum of diagonal 2: %d", d2); printf("\n");

    if ((sumR == sumC) && (d1 == d2)) {
        printf("\nMagic matrix");
    }
    else {
        printf("\nNot magic matrix");
    }

    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}


void program_24()
{
int i, j, c = 0, row, column, iteration, temp, max_i, max_j;
		printf("\nEnter the size of the square\n");
        printf("\nEnter row = ");   // the size of the array
        scanf("%d", &row);
        printf("\nEnter  column = ");   // the size of the array
        scanf("%d", &column);
        printf("\n");
        int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
        for (i = 0; i < row; i++)
        {
            a[i] = (int*)malloc(column * sizeof(int));
        }
        srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < column; j++)
            {
                a[i][j] = rand() % 1000 - 500; // generates random numbers from -500 to 499 in an array a[i][j]
                printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
            }
            printf("\n");
        }

        printf("\n");
        /* finding the maximum matrix element */
        max_i = 0;
        max_j = 1;
        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                if (a[i][j] > a[max_i][max_j]) {
                    max_i = i;
                    max_j = j;
                }
            }
        }
        /* Arrange the maximum and diagonal elements. Rearrangement of columns */
        for (i = max_j; i; i--) {
            for (j = 0; j < column; j++) {
                temp = a[j][i];
                a[j][i] = a[j][i - 1];
                a[j][i - 1] = temp;
            }
            printf("Swapped columns %d and %d.\n", i, i + 1);
        }

        /* Rearrangement of columns */
        for (i = max_i; i; i--) {
            for (j = 0; j < column; j++) {
                temp = a[i][j];
                a[i][j] = a[i - 1][j];
                a[i - 1][j] = temp;
            }
            printf("Swapped rows %d and %d.\n", i, i + 1);
        }
        printf("\n");
        for (i = 0; i < row; i++) { // The output of the new sorted matrix
            for (j = 0; j < column; j++) {
                printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
            }
            printf("\n");
        }
        for (i = 0; i < row; i++) {
            free(a[i]);
        } free(a); // Release of dynamically allocated memory
}


void program_161()
{
    int i, j, row, column, k, counter = 0, temp = 0;
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
    int* eq = (int*)malloc(row * sizeof(int)); // массив для подсчёта количества одинаковых элементов

    srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            a[i][j] = rand() % 6 - 3; // generates random numbers from -3 to 2 in an array a[i][j]
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }

    /* zero the array to store the same records */
    for (int i = 0; i < row; i++) {
        eq[i] = 0;
    }

    printf("\n");

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column - 1; j++)
        {
            for (k = j + 1; k < column; k++)
            {
                if (a[i][j] == a[i][k]) 
                    counter++; // a variable to calculate the number of identical elements
            }

            /* if there are several repetitive elements in one line, more will be written. */
            if (counter > eq[i]) 
                eq[i] = counter;
            counter = 1;
        }
    }

    /* sorting by bubble method */
    for (i = 1; i < row; i++)
    {
        for (j = row - 1; j >= i; j--)
        {
            if (eq[j] < eq[j - 1]) {
                for (k = 0; k < column; k++)
                {
                    temp = a[j][k];
                    a[j][k] = a[j - 1][k];
                    a[j - 1][k] = temp;
                }
                temp = eq[j];
                eq[j] = eq[j - 1];
                eq[j - 1] = temp;
            }
        }
    }

    printf("Sorted Matrix: \n");
    /* The output of the sorted matrix */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d\t", *(*(a + i) + j));
        }
        printf("\n");
    }
    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}


void program_162()
{
    int i, j, row, column, k, nomer;
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
    int* eq = (int*)malloc(row * sizeof(int)); // массив для подсчёта количества одинаковых элементов

    srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            a[i][j] = rand() % 100 - 50; // generates random numbers from -50 to 49 in an array a[i][j]
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }
    nomer = -1;
    for (j = 0; j < column; j++)
    {
        for (i = 0; i < row; i++)
        {
            if (*(*(a + i) + j) < 0) // searching for negative elements
                break;
        }
        if (i == row)
        {
            nomer = j;
            break;
        }
    }
    printf("\nThe number of the first of the columns containing no negative elements: %d\n", nomer);
    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}


void program_163()
{
    int i, j, row, column, q, count = 0, k, min, temp;
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
    int* b = (int*)malloc(row * column *sizeof(int));
    srand((unsigned)time(NULL)); // random number generator base (current time)
    /* fill in the matrix and display it on the screen */
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            a[i][j] = rand() % 10 - 5; // generates random numbers from -5 to 4 in an array a[i][j]
            printf("a[%d][%d]\t = %d\t", i, j, *(*(a + i) + j));
        }
        printf("\n");
    }
    printf("\n");

    k = -1;
    for (j = 0; j < column; j++)
    {
        for (i = 0; i < row; i++)
        {
            k += 1;
            b[k] = a[i][j]; // convert a two-dimensional array into a one-dimensional array
        }
    }

    k = row * column;
    for (i = 0; i < k; i++) // sort the one-dimensional array for convenience
    {
        min = i;
        for (j = i + 1; j < k; j++)
        {
            if (b[min] > b[j])
            {
                min = j;
            }
        }
        {
            temp = b[min];
            b[min] = b[i];
            b[i] = temp;
        }
    }

    for (i = 0; i < k; i++) // searching for the number of different elements
    {
        if (b[i] != b[i - 1])
        {
            count++;
            while (b[i] == b[i - 1]) 
                i++;
        }
    }
    printf("Different elements: %d", count);

    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}


void program_164()
{
    int i = 0, j, row, column, k = 0, p = 1;
    printf("\nEnter row = ");   // the size of the array
    scanf("%d", &row);
    printf("\nEnter  column = ");   // the size of the array
    scanf("%d", &column);
    printf("\n");
    int** a = (int**)malloc(row * sizeof(int*)); // dynamic memory allocation for an array
    for (i = 0; i < row; i++)
    {
        a[i] = (int*)malloc(column * sizeof(int));
    }
 
    i = 0;
    while (i < row * column) // Loop by the number of the coil
    {
        k++;
        for (j = k - 1; j < column - k + 1; j++)
        {
            a[k - 1][j] = p++;
            i++;
        } // Determining the values of the upper horizontal column

        for (j = k; j < row - k + 1; j++)
        {
            a[j][column - k] = p++;
            i++;
        } // By the right vertical column

        for (j = column - k - 1; j >= k - 1; j--)
        {
            a[row - k][j] = p++;
            i++;
        } // By the lower horizontal column

        for (j = row - k - 1; j >= k; j--)
        {
            a[j][k - 1] = p++;
            i++;
        } // By the left vertical column

    }

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%4d", a[i][j]);
        }
        printf("\n"); // The output of the sorted matrix
    }
    

    for (i = 0; i < row; i++) {
        free(a[i]);
    } free(a); // Release of dynamically allocated memory
}

void show_menu() // Menu
{
	system("cls");
	printf("\n-------------------------\n");
	printf("\nAn integer rectangular matrix is given...\n");
	printf("\n21 - Determine the number of columns that do not contain any zero element");
	printf("\n22 - The characteristic of the row of the integer matrix is the sum of its positive even elements.By rearranging the rows of the given matrix, arrange them according to the growth of characteristics");
	printf("\n23 - Determine whether the matrix is a magic square, i.e. one in which the sums of elements in all rows and columns are the same");
	printf("\n24 - By rearranging its rows and columns, ensure that the largest element (or one of them) is in the upper left corner");
	printf("\n161 - Arrange the rows of an integer rectangular matrix by increasing the number of identical elements in each row");
	printf("\n162 - Find the number of the first of the columns that do not contain any negative elements");
	printf("\n163 - Calculate how many different numbers are in the matrix");
	printf("\n164 - Fill the matrix with natural numbers from 1 to a spiral beginning in the upper left corner and twisted clockwise\n");
	printf("Print '0' then 'Enter' to show menu.\n");
}

int main()
{
    int  n;
	
    show_menu();
	
    do
    {
	printf("\nInput number of task:\n");
	printf("-------------------------\n");
	
	scanf_s("%d", &n);
	switch (n)
        {
	case 21: program_21();
		break;
	case 22: program_22();
		break;
	case 23: program_23();
		break;
	case 24: program_24();
		break;
	case 161: program_161();
		break;
	case 162: program_162();
		break;
	case 163: program_163();
		break;
	case 164: program_164();
		break;
	case 0:
        {
		show_menu();
		break;
        }
        default:
            printf("\nThere are no tasks under this number\n");
        }
    } while (n != -1);
    printf("\nThe end\n");
    return 0;
}
 