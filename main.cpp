#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "LibSearches.h"
#include "Constants.h"
#include "FillMatrix.h"

using namespace std;

void GetDiagonal(char** matrix,int n);

int main() {
    ifstream in;
    in.open("C:\\Users\\davyd\\git\\Labs\\BinaryInterpolationSearches\\input.txt");
    int n, responseCode;
    char** matrix = getMatrixFromFile(in, n, responseCode);
    if(responseCode==ExceptionsMatrix::SUCCESS){
        GetDiagonal(matrix,n);
    }
    else cout<< (const char *[]) {
                "SUCCESS",
                "FILE_NOT_FOUND",
                "FILE_IS_EMPTY",
                "UNPARSEABLE",
                "NOT_A_QUADRATIC_MATRIX",
                "WRONG_ELEMENT"
    }[responseCode];

}
void GetDiagonal(char** matrix,int n){

    for(int k = -n+1; k < n; ++k)
    {
        char* diagonal=new char[n];
        int d = 0;
        for(int i = std::max(0,k), j = std::max(-k,0); j < std::min(n,n-k); i++, j++){
           diagonal[d]= matrix[i][j];
           cout<<matrix[i][j];
           d++;
        }
        cout<<"\nВведите ключ поиска:";
        char key;
        cin>>key;
        cout<<"\n";
        int findIndex=BinarySearch(diagonal,(int)strlen(diagonal),key);
        cout<<findIndex;
        cout<<"Введите ключ поиска:";
        cin>>key;
        cout<<"\n";
        findIndex=InterpolationSearch(diagonal,strlen(diagonal),key);
        cout<<findIndex;
        cout<<"\n";

    }


}
void UseBinarySearch() {

}



