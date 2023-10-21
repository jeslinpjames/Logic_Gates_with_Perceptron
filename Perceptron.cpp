#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

class Perceptron {
private:
    float* W;
    float b;
    int input_dim;
    int iterations;
    float learning_rate;
public:
    ~Perceptron() {
        delete[] W;
    }
    Perceptron(int, int, float);
    void train(float x[][2], float y[], int num_samples);
    float* predict(float x[][2], int num_samples);
    void describe();
    void printPrediction(float pred[], float y[]);
private:
    float forward_prop(float x[]);
    float activation(float x);
    float getRandom();
};

Perceptron::Perceptron(int input_dim, int iterations, float learning_rate) {
    this->input_dim = input_dim;
    W = new float[input_dim];
    for (int i = 0; i < input_dim; i++) {
        W[i] = getRandom();
    }
    b = getRandom();
    this->iterations = iterations;
    this->learning_rate = learning_rate;
}

float Perceptron::getRandom() {
    float min = 1.0;
    float max = 10.0;
    return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}


float Perceptron::forward_prop(float x[]) {
    float sum = -b;
    for (int i = 0; i < input_dim; i++) {
        sum += W[i] * x[i];
    }
    return sum;
}

float Perceptron::activation(float x) {
    return (x > 0) ? 1.0 : 0.0;
}

void Perceptron::printPrediction(float pred[], float y[]) {
    cout << "\n\n\tPREDICTIONS\n\n";
    cout << setw(10) << "  actual   |" << setw(10) << "   predicted" << endl;
    cout << setw(10) << "-----------|" << setw(10) << "------------" << endl;
    for (int i = 0; i < 4; i++)
        cout << setw(6) << y[i] << "     |" << setw(8) << "   " << pred[i] << endl;
}

void Perceptron::train(float x[][2], float y[], int num_samples) {
    int j = 0;
    while (j <= iterations) {
        int noChange = 0;
        for (int i = 0; i < num_samples; i++) {
            float ypred = forward_prop(x[i]);
            if (ypred > 0 && y[i] == 0) {
                for (int k = 0; k < input_dim; k++)
                    W[k] -= learning_rate * x[i][k];
            }
            else if (ypred < 0 && y[i] == 1) {
                for (int k = 0; k < input_dim; k++)
                    W[k] += learning_rate * x[i][k];
            }
            else {
                noChange++;
            }
        }
        if (noChange == num_samples) {
            break;
        }
        j++;
    }
}

float* Perceptron::predict(float x[][2], int num_samples) {
    float* pred = new float[num_samples];
    for (int i = 0; i < num_samples; i++) {
        pred[i] = activation(forward_prop(x[i]));
    }
    return pred;
}

void Perceptron::describe() {
    cout << "Perceptron Parameters:\n";
    cout << "---------------------\n";
    cout << "Input Dimensions: " << input_dim << endl;
    cout << "Iterations: " << iterations << endl;
    cout << "Learning Rate: " << learning_rate << endl;
    cout << "Weights (W): ";
    for (int i = 0; i < input_dim; i++) {
        cout << "W[" << i << "] = " << W[i] << " ";
    }
    cout << "\nBias (b): " << b << endl;
}

int main() {
    int num_samples = 4;
    int input_dim = 2;

    // OR gate inputs and outputs
    float or_inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    float or_outputs[4] = {0, 1, 1, 1};
    
    Perceptron or_perceptron(input_dim, 100, 0.1);

    or_perceptron.train(or_inputs, or_outputs, num_samples);

    float* or_predictions = or_perceptron.predict(or_inputs, num_samples);

    or_perceptron.printPrediction(or_predictions, or_outputs);

    or_perceptron.describe();

    return 0;
}