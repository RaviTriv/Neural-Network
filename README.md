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

It is evident that a straight line cannot be drawn to seperate `(1,0),(0,1)` on one side and `(0,0),(1,1)` on another.

Using linear regression for this type of problem won't cut it. Instead, we can utilize a neural network to model complex relationships.

With the use of `activation functions` we can introduce `non-linearity` into our neural network to do this.

### Initialization
Our Neural Network is made up of units referred to as Neurons. Each neuron has a `weight`, this is a value to repersent how much of a say the neuron has in the network. A larger value indicates the neuron has more of a say while a lower value indicates the opposite. At initilization we want these `weights` to be a random value. This is important for gradient descent (more about this later). The process of doing this is often referred to as breaking the symmetry.

### Forward Progpogation
After this we pass our training data to our neurons. We then multiply our inputs by our weights and add them together and add the bias. We then pass the resulting value to our activation function. In this case we are using the `sigmoid` function as our activation function.
$\sigma ({i_1} * {w_1} + {i_2} * {w_2} + b)$ <br />

**What is an activation function?**
An activation function allows us to introduce `non-linearity` into our network. The sumation of linear function will result in another linear function, regardless of the number of layers, we would still end up with a linear function. 

INSERT PIC HERE

As indicated in the photo we need a qudaratic function to repersent this relation, we can achieve this by applying an activation function. We are using the sigmoid function,
which can be represented as the following, <br /> $\sigma (x) = {1 \over {1 + {e^{-x}}}}$

`Sigmoid` makes for a good activation function due to the following reasons.
  - The output is always between 0 and 1. As we approach $-\infty$ our function approaches 0 and as we approach $+\infty$ out function aproaches 1.
  - The function is differentiable, which is important for gradient descent.

### Calculating error
Calculate error is an important part of training neural networks, we want to get an idea of how our network is performing. Based on this we can adjust our weights and bias to get better results from our model.
To caculate our error we use the following formula, <br /> $\sigma′(output) * (expected - output)$ <br />
We are multiplying the slope by output, the reasoning behind this is we want to adjust predictions which are stuck around the middle. Predicitions that are near 0 or 1 are high confidence predictions, multiplying by the slope will essentially mean multiplying by 0 as the slope there is near 0. We want to increase the error for predicitions near the middle, as some sort of slope exists near the middle the error will be multiplied and turn into a larger number.

### Gradient Descent
We essentially use Gradient Descent to find a minimum. In many cases we can have many local miniums, thats why its important to have random starting points as we can increase our chances of finding the best min.



**Loss function**
Our loss function is essentially the derivative of the sigmoid function.
INSERT DERIVATIVE HERE
Derivatives are very useful as they measure rate of change. So we can use the derivative of the sigmoid function

### Backward Propogation 


### Forward Pass

Total Net Input = (Input1 \* weight1) + (Input2 + weight2)
Sigmoid(z) = 1 / (1 + e ^ -z)

### Total Error

Error = 1/2(target - result)^2

ErrorTotal = Error1 + Error2

## Supervised Training Dataset

| Input 1 | Input 2 | Output |
| ------- | ------- | ------ |
| 0       | 0       | 0      |
| 1       | 0       | 1      |
| 1       | 1       | 0      |
| 0       | 1       | 1      |
