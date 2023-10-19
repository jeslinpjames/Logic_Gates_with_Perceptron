#include<iostream>
#include<cstdlib>
using namespace std;
class Perceptron{
    private:
        float *W;
        float b;
        int input_dim;
        int iteration;
        int learning_rate;
    public:
        ~Perceptron() {}
        Perceptron(int,int,int);
        float forward_prop(float x[]);
        float activation(float x);
        float getRandom(){}
};
Perceptron::Perceptron(int input_dim,int iteration=100,int learning_rate=0.1){
    this->input_dim = input_dim;
    W= new float[input_dim];
    for(int i=0;i<input_dim;i++){
        W[i] = getRandom();
    }
    b = getRandom();
    this->iteration = iteration;
    this->learning_rate = learning_rate;
}
Perceptron::~Perceptron() {
    delete[] W; 
}
float Perceptron::getRandom() {
    float min = 1.0;
    float max = 10.0;
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

float Perceptron::forward_prop(float x[]){
    float sum =b;
    for(int i =0;i<input_dim;i++){
        sum += W[i]*x[i];
    }
    return sum;
}
float Perceptron::activation(float x){
    if(x>0){
        return 1.0;
    }
    else{
        return 0.0;
    }
}