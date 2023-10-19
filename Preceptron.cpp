#include<iostream>
#include<cstdlib>
using namespace std;
class Preceptron{
    private:
        float w1,w2,b;
        int output;
        int iteration;
        int learning_rate;
    public:
        Preceptron();
        Preceptron(int,int);
        float forward_prop(float x[]);
};
Preceptron::Preceptron(){
    w1 = getRandom();
    w2 = getRandom();
    b = getRandom();
    iteration = 100;
    learning_rate = 0.1;
}
Preceptron::Preceptron(int iteration=100,int learning_rate=0.1){
    w1 = getRandom();
    w2 = getRandom();
    b = getRandom();
    this->iteration = iteration;
    this->learning_rate = learning_rate;
}
float Preceptron::forward_prop(float x[]){
    return x[0]*w1 + x[1]*w2 + b;
}