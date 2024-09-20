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

Layer create(neuronCount)
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
    l->neurons[i].weight = ((double)rand() / (double)RAND_MAX);
    l->neurons[i].bias = 0;
  }
}

int main()
{
  Neuron n1;
  return 0;
}