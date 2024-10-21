# Neural-Network

## What are neural networks?

Neural Networks are a common architecture used for non-linear machine learning problems. In the real world a lot of the data we encounter is complex and non-linear, this is where Neural Networks shine.

## Example

A simple example of this is the XOR gate problem. Below the table lists the inputs and outputs for the XOR gate.

| Input 1 | Input 2 | Output |
| ------- | ------- | ------ |
| 0       | 0       | 0      |
| 1       | 0       | 1      |
| 1       | 1       | 0      |
| 0       | 1       | 1      |

![XOR inputs plotted](/images/xorPlot.png)
We see different input points for our problem plotted.

![Not Linearly seperatable 1](/images/notL1.png)

![Not Linearly seperatable 2](/images/notL2.png)

It is evident that a straight line cannot be drawn to seperate `(1,0),(0,1)` on one side and `(0,0),(1,1)` on another. This is a good problem for a Neural Network.

## Initialization

Our Neural Network is made up of units referred to as Neurons. Each neuron has a `weight`, this is a value to represent how much of a say the neuron has in the network. A larger value indicates the neuron has more of a say while a lower value indicates the opposite. At initilization we want these `weights` to be a random value.

## Forward Progpogation

Training data is passed to our neurons. The dot product of the inputs and weights are summed together with the bias. The resulting value is passed to the activation function. In this case we are using the `sigmoid` function as our activation function.
$\sigma ({i_1} * {w_1} + {i_2} * {w_2} + b)$ <br />

**What is an activation function?**
An activation function allows us to introduce `non-linearity` into our network. The sumation of linear function will result in another linear function, regardless of the number of layers, we would still end up with a linear function.

![Boundary](/images/boundary.png)

As indicated in the photo we need a qudaratic function to repersent this relation, we can achieve this by applying an activation function. We are using the sigmoid function,
which can be represented as the following, <br /> $\sigma (x) = {1 \over {1 + {e^{-x}}}}$

`Sigmoid` makes for a good activation function due to the following reasons.

- The output is always between 0 and 1. As we approach $-\infty$ our function approaches 0 and as we approach $+\infty$ out function aproaches 1.
- The function is differentiable, which is important for gradient descent.

### Calculating error

We want to get an idea of how our network is performing, based on this we can adjust our weights and bias to get better results from our model. To caculate our error we use the following formula: <br /> $\sigma′(output) * (expected - output)$ <br />
We are multiplying the slope by output, the reasoning behind this is we want to adjust predictions which are stuck around the middle. Predicitions that are near 0 or 1 can be considered high confidence predictions, multiplying by the slope will essentially mean multiplying by 0 as the slope is near 0. We want to increase the error for predicitions near the middle. As seen in our $sigmoid$ function some sort of slope exists near the middle. The error will be multiplied and turn into a larger number.

### Backward Propogation

To train our network we want to go backwards and update the value of our weights and bias. Gradient Descent is used to find the lowest error value. We iteratively update our weights and bias to inch closer and closer to our minimum error value.



