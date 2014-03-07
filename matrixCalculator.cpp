/**************************************************
  **Filename: matrixCalculator.cpp
  **Author: Lucy Wyman
  **Date: March 5, 2014
  **Description: Create NxN matrix of 0--->(N*N)-1, where user inputs N, and find sum of all 2*2 squares in the matrix, then print to a resultant matrix.
  **Input: N--side length of original array.
  **Output: Three matrices: The original matrix, then two copies of the resulting matrix, one found iteratively and the other found recursively.
  ***************************************************/

#include<cmath>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

/*********************************************************************
   **Function: getN()
** Description: Get user input, N.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: User must input integer between 1 and 100.
*********************************************************************/ 
int getN();

/*********************************************************************
   **Function: createMatrix
** Description: Create N*N matrix (2D array) from user input, and populate with 0's.
** Parameters: int N
** Pre-Conditions: N must be an integer between 1 and 100
** Post-Conditions: 2D array--N arrays of N length.
*********************************************************************/ 
void createMatrix(int N);

/*********************************************************************
   **Function: resultMatrix
** Description: Iterate through original matrix and populate resulting matrix.
** Parameters: 2D array created by user input, and N
** Pre-Conditions: matrix must be of size N*N and be populated with numbers 0-->(N*N)-1
** Post-Conditions:
********************************************************************/ 
void resultMatrix(int **matrix, int N);

/*********************************************************************
   **Function: recursiveResultMatrix
** Description: Iterate recursively through original matrix and populate resulting matrix.
** Parameters: Original matrix, number of vertices N, row-counter i, "column" counter j
** Pre-Conditions: matrix must be of size N*N and be populated with numbers 0-->(N*N)-1
** Post-Conditions:
*********************************************************************/ 
void recursiveResultMatrix(int **matrix, int N, int i, int j);

/*********************************************************************
   **Function: sumSquare
** Description: Sum the four values input from the original matrix
** Parameters: four integers--a, b, c and d
** Pre-Conditions: 
** Post-Conditions:
*********************************************************************/ 
int sumSquare(int a, int b, int c, int d);

int main(){
    string play = "yes";
    while (1){
	while (play == "Yes" || play == "yes" || play == "y" || play == "Y"){
	    int N = getN();
	    if (N == 0)
		break;
	    createMatrix(N);
	    cout<<"Would you like to generate another matrix?  "<<endl;
	    cin>>play;
	}
	if (play!= "Yes" && play!="yes" && play!="y" && play!="Y" && play!="continue")
	    break;
    }
    return 0;
}

int getN(){
    int N;
    cout<<"Please enter a number to construct the NxN matrix:  ";
    cin>>N;
    if (cin.fail() || N>40 || N<0){
	cin.clear();
	cin.ignore(1000, '\n');
	cout<<"\033[1;31mSorry! You did not input a positive integer less than 100.  Please try again!\033[0m\n"<<endl;
	N = 0;
    }
    cout<<"Original Matrix: "<<endl;
    return N;
}

void createMatrix(int N){
    int **matrix;
    matrix = new int*[N];
    for(int h=0; h<N;h++)
	matrix[h] = new int[N];
    int k = 0;
    for (int i = 0; i<N; i++){
	for(int j = 0; j<N; j++){
	    matrix[i][j] = k;
	    k += 1;
	    cout<<matrix[i][j]<<" ";
	}
	cout<<endl;
    }
    cout<<"--------------------------------------"<<endl;
    cout<<"Resultant Matrix:"<<endl;
    resultMatrix(matrix, N);
    cout<<"Recursive Resultant Matrix:"<<endl;
    recursiveResultMatrix(matrix, N, 0, 0);
}

void resultMatrix(int **matrix, int N){
    int resultMatrix[N-1][N-1];
    for(int i=0; i<N-1; i++){
	for(int j=0; j<N-1; j++){
	    resultMatrix[i][j] = sumSquare(matrix[i][j], matrix[i+1][j], matrix[i][j+1], matrix[i+1][j+1]);
	    cout<<resultMatrix[i][j]<<" ";
	}
	cout<<endl;
    }
    cout<<"-------------------------------------------"<<endl;
}

void recursiveResultMatrix(int **matrix, int N, int i, int j){
    int resultMatrix[N-1][N-1];
    while (j==N-1){
	cout<<endl;
	i+= 1;
	if (i==N-1)
	    return;
	j = 0;
    }
    resultMatrix[i][j] = sumSquare(matrix[i][j], matrix[i+1][j], matrix[i][j+1], matrix[i+1][j+1]);
    cout<<resultMatrix[i][j]<<" ";
    j+= 1;
    recursiveResultMatrix(matrix, N, i, j);
}

int sumSquare(int a, int b, int c, int d){
    int sum = a + b + c + d;
    return sum;
}


