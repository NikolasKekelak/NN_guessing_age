#include <vector>
#include <iostream>
#include <random>

using namespace std;

double rand_double() {
        return (double)rand()/RAND_MAX;
    }


double cost(vector<vector<double>> &train,vector<double> &w,double &b) {
    double result = 0;
    for(int i =0 ; i< train.size(); i++) {
        double d = 0;
        for(int j =0 ; j < train[0].size()-1 ; j++)
            d+= w[j]*train[i][j];
        d+=b;
        double y = train[i][train[i].size()-1];
        d-=y;
        result+=d*d;
    }
    result/=train.size();
    return result;
}

void dcost(vector<vector<double>> &train,vector<double> &w , double &b,int iteration) {
    const double initial_rate = 0.01;
    double rate = initial_rate;
    double constant =2/(double)train.size() ;
    vector<double> dw(train[0].size()-1) ;
    double db=0;

    for(int i =0 ; i < train.size() ;i++ ) {
        float x = 0;
        for(int j = 0 ; j < train[i].size()-1; j++ )
            x+= train[i][j]*w[j];
        x+=b;
        x-=train[i][train[i].size()-1];
        for(int j=0; j <train[i].size()-1 ; j++)
            dw[j]+=x*train[i][j];
        db+= x;
    }

    double decay = initial_rate;
    rate = initial_rate / sqrt(iteration + 1);
    for (int i = 0; i < dw.size(); i++)
        w[i] -= constant * rate * dw[i];
    b-= 100 * constant * rate *db;
}

vector<double> mozgova_bunka(vector<vector<double>> &train){

  srand(time(0));
  vector<double> w;
  double  b =  (rand_double() - 0.5) ;
  for(int i =0 ; i < train[0].size()-1; i++ )
    w.push_back((rand_double() - 0.5) * 0.01);
    int max = 100000;
    int i =1;
    double memory=0;

    while( max-- ) {
        double current_cost = cost(train,w, b);
        cout<<current_cost<<"\n";
        if(abs(memory-current_cost) < 1e-16)
            break;
        dcost(train,w,b, i++);
        memory=current_cost;
    }


    cout<< i <<"-th genaration ,done \n";
    for( auto it : w )
        cout<< " "<< it ;
    cout << " "<< b  << " "<< cost(train,w,b);
    cout << "\n";

    return w;
}