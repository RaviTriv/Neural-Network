# Neural-Network

## What are neural networks?
Neural Networks are a common architecture used for non-linear machine learning problems.


Often we come across data that cannot be linearly seperated. A good example of this is XOR.

![XOR inputs plotted](/images/xorPlot.png)
We see different input points for our problem plotted. 

![Not Linearly seperatable 1](/images/notL1.png)

![Not Linearly seperatable 2](/images/notL2.png)

It is evident that a straight line cannot be drawn to seperate `(1,0),(0,1)` on one side and `(0,0),(1,1)` on another.

## How does this work?

### Initialization
We begin by initializing neuron weights to a random value. This is important for gradient descent (more about this later). This process is often referred to as breaking the symmetry.

### Forward Pass
After this we pass our training data to our neurons.
//INSERT FUNCTION HERE
We then multiply our inputs by our weights and add them together. We then pass the resulting value to our activation function.

**What is an activation function?**
An activation function allows us to introduce `non-linearity` to our neural network. This is important because complex data problems are commonly `non-linear`.
An activation function simply determines if a neuron should be activated or not. In this case the `sigmoid` function is our activation function. We simply check if our output value from the `sigmoid` function is greater `0.5` or not to determine whether a node is activated or not.

**What is a sigmoid function and why is it important?**
INSERT SIGMOID FUNCTION FORMULA HERE
The sigmoid function is whats known as a squashing function. Essentially that means it takes any real number and returns a value between 0 and 1.

### Calculating error
We want to calculate error to get an idea of how our neural network is performing. We can use this value to adjust our weights and bias to get better results from our model.

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


