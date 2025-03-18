#include <vector>
#include <iostream>
#include <random>
#include "MATRIX.h"


#define  matrix MATRIX<double>
using namespace std;

double rand_double(double low, double high){
      return (double)rand()/RAND_MAX;
}

//inputs, outputs
void cost( matrix &INPUTS , matrix &OUTPUTS,
             matrix &WEIGHTS, matrix &BIASES){
            double result=0;
            matrix PREDICT=(INPUTS*WEIGHTS);
            PREDICT.display();

}

int main(){
     matrix input(4,2);
     input.container={
         {0,0},
         {0,1},
         {1,0},
         {1,1}
     };
     matrix output(4,1);
     output.container={
       {0},
       {0},
       {0},
       {1}
     };
     matrix weight(2,1);
     weight.container = {
         {1},
         {2}
     };
     matrix bias(1,1);
     bias.container={
         {3}
     };
     cost(input, output, weight, bias);
     (weight*bias).display();

}




