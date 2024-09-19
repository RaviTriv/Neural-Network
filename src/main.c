#include <stdlib.h>
#include <stdio.h>
typedef struct
{
  double weight;
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


int main()
{
  Neuron n1;
  return 0;
}