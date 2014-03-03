#include<cmath>
#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

/*Get user input to construct matrix with*/
int getN();

void createMatrix(int N);

void resultMatrix(int **matrix, int N);

int sumSquare(int a, int b, int c, int d);

int main(){
    string play = "yes";
    while (1){
	while (play == "Yes" || play == "yes" || play == "y" || play == "Y"){
	    int N = getN();
	    if (N == 0){
		break;
	    }
	    createMatrix(N);
	    cout<<"Would you like to generate another matrix?  "<<endl;
	    cin>>play;
	}
	if (play!= "Yes" && play!="yes" && play!="y" && play!="Y" && play!="continue"){
	    break;
	}
    }
    return 0;
}

int getN(){
    int N;
    cout<<"Please enter a number to construct the NxN matrix:  ";
    cin>>N;
    if (cin.fail() || N>100 || N<0){
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
    for(int h=0; h<N;h++){
	matrix[h] = new int[N];
    }
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
}

int sumSquare(int a, int b, int c, int d){
    int sum = a + b + c + d;
    return sum;
}


