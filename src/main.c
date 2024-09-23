#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double inputs[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
double expectedOutput[4] = {0, 1, 1, 0};

typedef struct
{
  double inputs[2];
  double weights[2];
  double bias;
} Neuron;

typedef struct
{
  Neuron *neurons;
  int neuronCount;
} Layer;

typedef struct
{
  Layer input;
  Layer hidden;
  Layer output;
} Network;

Layer create(int neuronCount)
{
  Layer l;
  l.neurons = malloc(neuronCount * sizeof(Neuron));
  l.neuronCount = neuronCount;
  return l;
}

void populateLayer(Layer *l)
{
  for (int i = 0; i < l->neuronCount; i++)
  {
    // setting to random at start so values are not same for gradient
    l->neurons[i].weights[0] = ((double)rand() / (double)RAND_MAX);
    l->neurons[i].weights[1] = ((double)rand() / (double)RAND_MAX);
    l->neurons[i].bias = 0;
  }
}

double dotProduct(double i1, double w1, double i2, double w2)
{
  double res = ((i1 * w1) + (i2 * w2));
  // printf("DOT PRODUCT RES: %f\n", res);
  return res;
}

double sigmoid(double z)
{
  double res = 1 / (1 + exp(-z));
  // printf("SIGMOID RES: %d\n", res);
  return res;
}

double error()
{
  double target;
  double output;

  double res;
  res = 0.5 * pow((target - output), 2);
}

double feedForward(Neuron *n)
{
  double res;

  for (int i = 0; i < 2; i++)
  {
    res += n->weights[i] * n->inputs[i];
  }

  return sigmoid(res);
}

void backwards(Neuron *neuron, double error)
{
  for (int i = 0; i < 2; i++)
  {
    neuron->weights[i] = error * neuron->inputs[i];
  }
}

int main()
{
  Network neuralNetwork;
  neuralNetwork.input = create(2);
  neuralNetwork.hidden = create(2);
  neuralNetwork.output = create(1);

  populateLayer(&neuralNetwork.input);
  populateLayer(&neuralNetwork.hidden);
  populateLayer(&neuralNetwork.output);

  printf("INPUT 1: %f, %f\n", inputs[1][0], inputs[1][1]);
  int randomIndex = rand() % 3;
  for (int i = 0; i < 2; i++)
  {
    Neuron *n = &neuralNetwork.input;
  }
  return 0;
}