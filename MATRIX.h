
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

template <class DATATYPE>
class MATRIX {
private:
  int m;
  int n; // rozmery matice

public:
  vector<vector<DATATYPE>> container;
  MATRIX(int rows, int cols) : m(rows), n(cols), container(rows, vector<DATATYPE>(cols)) { //inicializuje randomnu maticu, nemusi byt nutne pekna
    for(int i = 0 ; i < rows; i ++){
      for(int j = 0 ; j < cols ; j++){
        container[i][j]=  ( rand()%11-5 );
      }

    }
  } // inicializuje random maticu o m x n
  //parametricka inicializacia, momentalne iba vracia nulovu maticu alebo LU matice
  MATRIX(int rows, int cols , vector<int> *return_vector ) : m(rows), n(cols), container(rows, vector<DATATYPE>(cols)) {
    // pekna random, vracia aj vektor, hodnot, ak DATATYPE je cislo
    // return_vector zaroven sluzi ako parameter, a zaroven ako vracajuca hodnota inicializacie
    vector<int> temp;
    if( !return_vector->empty() ) { // ak vektor ma nejake hodnoty, nas return_vektor sa stane vektorom hodnot
      temp = *return_vector;
      return_vector->clear();
    }
    else
      for(int i =0; i < n ; i ++)
        temp.push_back( rand()%11-5 );


    for(int i = 0 ; i < rows; i ++){
      int sum=0;
      for(int j = 0 ; j < cols ; j++){
        container[i][j]=  ( rand()%11-5 );
        sum+= container[i][j]*temp[j];
      }
      return_vector->push_back(sum);
    }

  } // generuje maticu na zaklade vstupneho vektora

  void display(){
    for(int i = 0 ; i < m; i ++){
      cout<<" [";
      for(int j = 0 ; j < n ; j++){
        cout<< setw(4)<<container[i][j];
      }
      cout<<" ]\n";
    }
  }
  void latex_display(){
    cout<<"\n\\[\n\\begin{bmatrix}\n";
    for(int i = 0 ; i < m; i ++){
      cout<<" ";
      for(int j = 0 ; j < n ; j++){
        cout <<setw(3)<< container[i][j];
        string x= ( j==(n-1) )?  " ":"  &" ;
        cout<<x;
      }
      string x=(i==(m-1))? "\n" : " \\\\\n" ;
      cout<<x;
    }

    cout<<"\\end{bmatrix}\n\\]\n";
  }
  void display(vector<int> b){
    for(int i = 0 ; i < m; i ++){
      cout<<" [";
      for(int j = 0 ; j < n ; j++){
        cout<< setw(4)<<container[i][j];
      }
      cout<< " ][ " <<setw(4)<<b[i]<<" ]\n";
    }
  }
  void latex_display(vector<int> b){
    cout<<"\n\\[\n\\begin{bmatrix}\n";
    for(int i = 0 ; i < m; i ++){
      cout<<" ";
      for(int j = 0 ; j < n ; j++){
        cout <<setw(3)<< container[i][j];
        string x= ( j==(n-1) )?  " ":"  &" ;
        cout<<x;
      }
      string x=(i==(m-1))? "\n" : " \\\\\n" ;
      cout<<x;
    }
    cout<<"\\end{bmatrix}\n";
    cout<<"\\begin{bmatrix}\n";

    for(auto i= 0 ; i< b.size() ; i ++) {
      cout<<" "<<setw(4)<<b[i];
      string x= (i==(b.size()-1))? "\n": " \\\\\n";
      cout<<x;
    }
    cout<<"\\end{bmatrix}\n\\]\n";
  }

  vector<int> assign_vector(vector<int> span ) {
    vector<int> ans;
    for(int i =0 ; i < n ; i++) {
      ans.push_back(rand()%(span[1]-span[0])+span[0]);
    }
    return ans;
  }


  DATATYPE& operator()(int i, int j){
    return container[i][j];
  }

  MATRIX<DATATYPE> operator+(MATRIX<DATATYPE> B) {
    MATRIX<DATATYPE> ans(m,n);
    for(int i= 0; i < m ; i ++) {
      for(int j=0 ; j < n ; j++) {
        ans(i,j) = container[i][j] + B(i,j);
      }
    }
    return ans;
  }

  MATRIX<DATATYPE> operator-(MATRIX<DATATYPE> B) {
    MATRIX<DATATYPE> ans(m,n,"");
    for(int i= 0; i < m ; i ++) {
      for(int j=0 ; j < n ; j++) {
        ans(i,j) = container[i][j] - B(i,j);
      }
    }
    return ans;
  }

  MATRIX<DATATYPE> operator*(MATRIX<DATATYPE> B) {
    if (n != B.m) {
      throw std::invalid_argument("Matrix dimensions do not match for multiplication!");
    }

    MATRIX<DATATYPE> ans(m, B.n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < B.n; j++) {
        ans.container[i][j] = 0; // Ensure result is initialized
        for (int k = 0; k < n; k++) {
          ans.container[i][j] += container[i][k] * B.container[k][j];
        }
      }
    }
    return ans;
  }
};
#endif //MATRIX_H
