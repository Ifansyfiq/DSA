#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global variable declaration
int dimension1[10]; // record matrix size
int dimension2[10]; // record matrix size
int parentheses[10][10]; // record which parenthesize is taken
int m[10][10]; // record amount of minimum operation
int n; // number of elements

// function declaration
void read();�// to take input from user
void calculate();�// to calculate number of operation and write into memory table
int matrixmultiply(int, int, int);�// to multiply matrix
void printlist();
void printchainorder();

int main()
{
 read();

int length;
��� // when length = 1, calculates cost from 1st element of the first row diagonally to next right bottom element
��� // counts from 0th; but 1st element is all 0 cost, so start from length = 1;
��� for(length=1;length<n+1;length++)
��� {
������� calculate(length);
��� }

��� // prints out cost of each element in the table
��� printlist();

��� printf("\nmultiplication sequence is : ");
��� // prints bracket
��� // 0, n-1 is to start with first row last element of the matrix
��� printchainorder(0, n - 1);

��� // showing cost of last element in the first row
��� // that is the minimum amount of operation needed for the matrix chain multiplication
��� printf("\nmininum number of multiplication is : %d\n\n", m[0][n-1]);

��� return 0;
}

void read()
{
��� char dummy; // to write 'x' when user key in matrix size
��� int i;

��� printf("Enter the number of elements : ");
��� scanf("%d", &n); // read number of elements

��� // read matrix size
��� printf("Enter the dimensions:\n");
��� for(i=0;i<n;i++){
������� printf("A%d : ", i+1);
������� scanf("%d %c %d", &dimension1[i],
� � � � � � � � � � � &dummy, &dimension2[i]);
��� }

��� // set m11,m22,m33.... to 0;
��� // cost is 0 when multiply with 1 matrix.
��� for(i=0;i<n;i++){
������� parentheses[i][i] = 0;
������� m[i][i] = 0;
��� }
}

void calculate(int length)
{
��� int a = 0; // to target specific element in row matrix
��� int b = 0; // to target specific element in row matrix
��� int c = a+1; // to target specific element in column matrix
��� int d = length;// to target specific element in column matrix
��� int min = 999999; // records least m available for compare
��� int cost; // utility
��� int i,j; // utility

��� // n-length = amount of element to be calculated diagonally
��� for(i=0;i<n-length;i++){
������� // length = amount of element to be checked in corresponding row/column
������� for(j=0;j<length;j++){
����������� cost = m[a][b] + m[c][d] + matrixmultiply(a,b,d);// calculates amount of cost

����������� // to target which parenthesize gives minimum amount of cost
����������� if(cost<min){
��������������� min = cost;
��������������� parentheses[a][d] = b+1;
����������� }
����������� b++;c++;// moves on to next element
������� }
������� m[a][d] = min; // records minimum amount of cost for that element of matrix
������� a++;d++;b=a;c=a+1;min=999999; // reset value for next calculation
��� }

��� return;
}

int matrixmultiply(int a, int b, int d)
{
��� return dimension1[a] * dimension2[b] * dimension2[d];
}

void printlist()
{
��� int i,j,k;

��� k=0; // counter to avoid printing irrelevant matrix.
��� printf("cost matrix M :\n");

������� for(i=0+k;i<n;i++)
������� {
����������� for(j=0+k;j<n;j++)
����������� {
��������������� printf("A[%d][%d] = %d\n", i+1, j+1, m[i][j]);
����������� }
����������� k++;
������� }

��� return;
}

void printchainorder(int i, int j)
{
��� if(i == j){
������� // when i == j, the bracket only have 1 or 2 element
������� printf("A%d ", i+1);
������� return;
��� }
��� else{
������� printf("( ");
������� printchainorder(i, parentheses[i][j] - 1); // left side of sequence
������� printchainorder(parentheses[i][j] , j); // right side of sequence
������� printf(" )");
��� }
}


