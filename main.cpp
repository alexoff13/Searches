#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "LibSearches.h"
using namespace std;

char* FillMatrix( std::ifstream& in,int &n);
int main() {
    int a[]={0,1,1,1,1,1,1,1,1,1,1,1,1,2};
    ifstream in;
    in.open("C:\\Users\\davyd\\git\\Labs\\BinaryInterpolationSearches\\input.txt");
    int n=6;
    char* matrix =FillMatrix(in,n);

    std::cout<<BinarySearch(a,14,1);
    std::cout<<InterpolationSearch(a,14,1);

}

void FillMatrix( std::ifstream& in,int &n,char ( &matrix )[n][n] ){
    std::string line;
    for (int i = 0; i < n; ++i) {
        getline(in, line);
        size_t pos = 0;
        while( (pos = line.find(' ', pos)) != std::string::npos )
            line.replace(pos, 1, "");
        for (int j = 0; j < n; ++j) {
            matrix[i,j], line[j]
        }
    }
}

