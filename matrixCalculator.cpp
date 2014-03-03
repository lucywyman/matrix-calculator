#include<cmath>
#include<iostream>
#include<cstdlib>

using namespace std;

/*Get user input to construct matrix with*/
int getN();

void createMatrix(int N);

void resultMatrix(int **matrix);

int sumSquare(int a, int b, int c, int d);

int main(){
    int N = getN();
    createMatrix(N);
    return 0;
}

int getN(){
    int N;
    cout<<"Please enter a number to construct the NxN matrix.";
    cin>>N;
    return N;
}

void createMatrix(int N){
    int matrix[N][N];
    int answer[N-1][N-1];
    int k = 1;
    for (int i = 0; i<N; i++){
	for(int j = 0; j<N; j++){
	    matrix[i][j] = k;
	    k += 1;
	    cout<<matrix[i][j];
	    }
	cout<<endl;
    }
}

void resultMatrix(int **matrix){
	
}

int sumSquare(int a, int b, int c, int d){
    int sum = a + b + c + d;
    return sum;
}


