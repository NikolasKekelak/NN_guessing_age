#include <iostream>
#include <vector>
#include <cmath>
#include "MATRIX.h"
using namespace std;


extern vector<double> mozgova_bunka(vector<vector<double>> &train);

vector<vector<double>> train =
    {
    {0, 8, 17, 67},
{15, 20, 14, 97},
{4, 11, 8, 50},
{9, 12, 6, 51},
{13, 10, 5, 48},
{14, 13, 4, 52},
{12, 19, 1, 53},
{7, 2, 19, 68},
{12, 5, 6, 40},
{7, 18, 12, 79},
{3, 12, 12, 63},
{12, 15, 3, 51},
{19, 8, 3, 44},
{19, 1, 16, 69},
{18, 12, 11, 75},
{17, 11, 15, 84},
{20, 16, 6, 70},
{19, 16, 19, 108},
{16, 14, 5, 59},
{6, 7, 5, 35},
{14, 9, 8, 56},
{18, 2, 14, 64},
{0, 13, 13, 65},
{9, 15, 0, 39},
{13, 7, 15, 72},
{4, 18, 20, 100},
{7, 4, 10, 45},
{17, 0, 0, 17},
{11, 3, 10, 47},
{1, 12, 10, 55},
{2, 20, 2, 48},
{7, 15, 5, 52},
{16, 9, 15, 79},
{2, 15, 15, 77},
{20, 9, 8, 62},
{19, 3, 2, 31},
{17, 0, 10, 47},
{14, 20, 19, 111},
{8, 8, 2, 30},
{7, 20, 11, 80},
{3, 0, 11, 36},
{14, 14, 3, 51},
{0, 16, 8, 56},
{16, 0, 3, 25},
{18, 3, 1, 27},
{6, 3, 14, 54},
{0, 6, 9, 39},
{4, 20, 8, 68},
{7, 18, 2, 49},
{4, 14, 1, 35},
{0, 10, 4, 32},
{19, 8, 11, 68},
{8, 8, 11, 57},
{6, 2, 14, 52},
{4, 14, 7, 53},
{3, 6, 8, 39},
{16, 11, 5, 53},
{3, 19, 6, 59},
{17, 6, 11, 62},
{11, 10, 11, 64},
{16, 15, 20, 106},
{9, 12, 3, 42},
{2, 15, 20, 92},
{14, 3, 14, 62},
{20, 20, 4, 72},
{1, 16, 16, 81},
{1, 2, 5, 20},
{1, 14, 4, 41},
{4, 18, 3, 49},
{20, 0, 1, 23},
{16, 0, 15, 61},
{15, 14, 16, 91},
{6, 6, 13, 57},
{16, 18, 0, 52},
{20, 20, 13, 99},
{1, 16, 7, 54},
{4, 6, 16, 64},
{11, 0, 10, 41},
{8, 14, 3, 45},
{14, 3, 5, 35},
{6, 8, 14, 64},
{13, 13, 9, 66},
{5, 9, 13, 62},
{3, 7, 20, 77},
{2, 14, 19, 87},
{4, 4, 1, 15},
{3, 16, 16, 83},
{9, 10, 7, 50},
{13, 7, 4, 39},
{2, 12, 10, 56},
{5, 12, 2, 35},
{8, 3, 10, 44},
{2, 6, 17, 65},
{19, 16, 11, 84},
{14, 7, 14, 70},
{6, 10, 0, 26},
{11, 12, 4, 47},
{14, 7, 20, 88},
{2, 5, 7, 33},
{15, 19, 3, 62}

};

vector<vector<double>> AND = {
{ 0 , 0 , 0},
{ 0 , 1 , 1},
{ 1 , 0 , 1},
{ 1 , 1 , 1}

};

vector<vector<double>> VEK ={
    {0,0},
    {1,1},
    {2,2},
    {69,69},
    {4,4},
    {5,5},
    {6,6},
};


int main() {

    vector<double> w = mozgova_bunka(VEK);
    cout<<"Give your age: ";
    double age;
    cin>>age;
    cout<<"You are " << age*w[0]+w[1] <<" years old";
    return 0;
}
