<!-- This README is in markdown format, It is should be viewed using a markdown viewer -->

<!-- This is because there will be pictures, gif and links embedded in the file to help explain the programs -->

<!-- If you do not have a markdown viewer please visit the flowing github link to  properly view the file in the intended format -->

<!-- https://github.com/ajayvarghese2000/22WSD530-Programming-Multi-many-core-Systems-Coursework-2/ -->

<!-- This GitHub will be private until after the submission deadline -->
# Table of Contents

- [Artificial Neural Network](#artificial-neural-network)
    - [Working Principle](#working-principle)
- [File Structure](#file-structure)
- [Build Instructions](#build-instructions)
    - [Prerequisites](#pre-requisites)
    - [compiling](#compiling)
    - [Running](#running)


# Artificial Neural Network

<p align="center">
	<img src="https://i.imgur.com/ELjIutZ.png">
</p>

ANNs were the first learning models that drove machine learning research based on the model of a biological neuron. 

It began with work done by McCulloch and Pitts who in 1943 modelled a neuron as a switch that takes inputs from other neurons and depending on the total weighted input, is either activated or not. The weight corresponds to the strength of a synapse, the neural contacts between nerve cells. These weights can be both positive (excitatory) and negative (inhibitory).

Using this research, in 1958 Rosenblatt created the first supervised learning algorithm of binary classifiers named the perceptron. As software was still in its infancy the Mark I Perceptron machine was realised fully in hardware using potentiometers and circuitry to adjust the weights.

As computers and software developed, today huge ANN can be programmed and executed in memory. These networks are not limited by physical circuit limitations and so can span hundreds of neurons across multiple layers allowing them to classify many patterns with greater accuracy.

## Working Principle

The original images pixels are fed into a set of input neurons then a weighted multiplication is computed and fed into the hidden layers represented by the lines connecting the input layer to the hidden layer.

Inside the hidden layers the sum of the weighted multiplication is calculated and depending on whether the threshold is met or not the neurons in the hidden layers are activated.

The output from the activated neurons in the hidden layer could then be passed to other layers or directly to the output layer depending on the complexity of the network.

The output layer computes the same calculation as the hidden layer, sums up the outputs from the previous layer. However, instead of passing the data forward, the neuron with the largest sum is the classification end result.

The exact weights are pre-calculated through training against a labelled dataset using forward and backward propagation. The predicted output is compared against the expected output and the system attempts to minimise the error difference between the two. There are many different optimisation algorithms that attempt to achieve this in the most efficient way.

# File Structure

There are 3 main files in the project:

- `main.c` - This is the original version of the program it is a single threaded version of the program that is used to compare the performance of the parallelised version.
- `main_slow.c` - This is the inefficiently parallelised version of the program. It uses the OpenMP library to parallelise the program. However, the pragma directives are not placed in the most efficient sections.
- `main_fast.c` - This is the most efficient parallelised version of the program. It uses the OpenMP library to parallelise the program. The pragma directives are placed in the most efficient sections.

When the each program is run, they will create a `.csv` file and append the run time to the end of the file.

Results from the experiments done for the report can be found in the `results` folder. The `results` folder contains sub folders for each of the 3 devices that were used to run the experiments. The sub folders contain the `.csv` files that were generated from the programs.

`./bin/` contains the executable files for the programs.

# Build Instructions

## Pre-requisites

This is a c program and therefore requires a c compiler. The program was developed using the gcc compiler. The program also requires the OpenMP library to be installed and a version GNU Make to be installed.

Although the program was developed on Windows 10, it should work on any operating system that supports OpenMP and has gcc installed and callable from the terminal.

If you are on windows you can obtain gcc by downloading the **MSYS2** project from [here](https://www.msys2.org/). Once installed, you can install g++ by running the following command in the MSYS2 terminal.

```
    pacman -S mingw-w64-x86_64-toolchain
```

This will install g++, gcc and a version of make. 

Once installed you must add the executable to your environment path.

## Compiling

To compile simply run the following command in the terminal.

```
    make
```

This will build all three versions of the program and create an executable file in `./bin/` directory.

## Running

There are many ways to run the program. The easiest way is to run the executable directly from the terminal.

```
    ./bin/original.exe
```

```
    ./bin/fast.exe
```

```
    ./bin/slow.exe
```

Alternatively, you can run the program using the makefile. This will compile and run once the specified program.

```
    make original
```

```
    make fast
```

```
    make slow
```

If you need to run the program multiple times you can use the following command. 

**NOTE: This will not compile the programs, it will only run the program so make sure you have compiled the program first by running `make`.**

```
    make run_all
```

This will run all three versions of the program 100 times and append the results to the `.csv` file created.

**Linux users may have issue with this command and so a `.sh` file has been provided to do this instead.**

```
    ./run.sh
```