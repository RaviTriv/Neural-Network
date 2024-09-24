#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double inputs[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
double expectedOutput[4] = {0, 1, 1, 0};

typedef struct
{
  double inputs[2];
  double weights[2];
  double bias;
} Neuron;

void populateLayer(Neuron *neuron)
{
  for (int i = 0; i < 2; i++)
  {
    neuron->weights[i] = ((double)rand() / (double)RAND_MAX);
  }
  neuron->bias = ((double)rand() / (double)RAND_MAX);
}

double dotProduct(double i1, double w1, double i2, double w2)
{
  double res = ((i1 * w1) + (i2 * w2));
  return res;
}

double sigmoid(double z)
{
  double res = 1 / (1 + exp(-z));
  return res;
}

double sigmoidDerivative(double x)
{
  return (x * (1. - x));
}

double error(double target, double output)
{
  return target - output;
}

double feedForward(Neuron *neuron)
{
  double res = 0;
  res += dotProduct(neuron->inputs[0], neuron->weights[0], neuron->inputs[1], neuron->weights[1]);
  res += neuron->bias;
  return sigmoid(res);
}

void backwards(Neuron *neuron, double error)
{
  for (int i = 0; i < 2; i++)
  {
    neuron->weights[i] += error * neuron->inputs[i];
  }
  neuron->bias += error;
}

int main()
{
  printf("START\n");
  Neuron hiddenLayer[2];
  Neuron outputLayer;

  for (int i = 0; i < 2; i++)
  {
    populateLayer(&hiddenLayer[i]);
  }

  populateLayer(&outputLayer);
  for (int e = 0; e < 10000; e++)
  {
    int randomIndex = (rand() % 4);
    double tempTraining[2];
    tempTraining[0] = inputs[randomIndex][0];
    tempTraining[1] = inputs[randomIndex][1];
    printf("EXPECTED %d XOR %d ", (int)tempTraining[0], (int)tempTraining[1]);

    for (int i = 0; i < 2; i++)
    {
      Neuron *n = &hiddenLayer[i];
      n->inputs[0] = tempTraining[0];
      n->inputs[1] = tempTraining[1];
      outputLayer.inputs[i] = feedForward(n);
    }

    double out = feedForward(&outputLayer);
    double err = sigmoidDerivative(out) * (error(expectedOutput[randomIndex], out));

    backwards(&outputLayer, err);

    for (int k = 0; k < 2; k++)
    {
      double err2 = sigmoidDerivative(outputLayer.inputs[k]) * err * outputLayer.weights[k];
      backwards(&hiddenLayer[k], err2);
    }

    printf("= %d GOT %d XOR %d = %d OUTPUT: %f ERROR: %f\n", (int)expectedOutput[randomIndex], (int)tempTraining[0], (int)tempTraining[1], out > 0.5, out, err);
  }

  printf("END\n");

  return 0;
}