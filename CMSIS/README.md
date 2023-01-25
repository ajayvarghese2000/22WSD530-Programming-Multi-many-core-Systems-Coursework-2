<!-- This README is in markdown format, It is should be viewed using a markdown viewer -->

<!-- This is because there will be pictures, gif and links embedded in the file to help explain the programs -->

<!-- If you do not have a markdown viewer please visit the flowing github link to  properly view the file in the intended format -->

<!-- https://github.com/ajayvarghese2000/22WSD530-Programming-Multi-many-core-Systems-Coursework-2/tree/main/CMSIS -->

<!-- This GitHub will be private until after the submission deadline -->
# Table of Contents

- [Convolutional Neural Network](#convolutional-neural-network)
    - [Working Principle](#working-principle)
- [File Structure](#file-structure)
- [Build Instructions](#build-instructions)
    - [Prerequisites](#pre-requisites)
    - [Compiling](#compiling)
    - [Running](#running)


# Convolutional neural network

<p align="center">
	<img src="https://i.imgur.com/HeV4pXY.png">
</p>

Convolutional Neural Networks (CNN) are a class of deep learning neural networks designed to process data that has a grid-like topology, such as an image. It was first developed by Yann LeCun in 1998.

CNNs are particularly useful for image recognition and classification tasks as they are able to learn and identify features in images using convolutional layers, which scan the image and apply filters to extract features. The extracted features can then be combined and analysed to classify the image.

## Working Principle

CNNs are an improvement over ANN for image classification. In image classification, ANNs feed each pixel into a neuron. Whilst this is ok for low resolution images, in higher resolution images, it would require a huge amount of neurons which would decimate performance and increase resource usage. 
A CNN however, takes the input and passes it through many stages that identifies only the key features of an input image. The identified features can then be passed to an ANN to classify the image.

A CNN can have many stages that are responsible for specific tasks; however there are three key stages in any CNN, convolution, pooling and fully connected.
The convolutional layer is the core building block of a CNN, which applies a set of filters to the input image. These filters can identify specific features in the input such as straight lines or more complex things like eyes etc. The identified features are then reduced to a feature map which is fed into a pooling stage.

The pooling stage helps to reduce the dimensionality of the data by downsampling the feature map. This reduces the size of the feature map matrix whilst retaining the most important data. This reduced matrix is then fed to the fully connected stage which is normally a ANN. The data from the down-sampled feature map is fed into each neuron after which the ANN will perform the classification as described in the Artificial Neural Network section.


# File Structure

There are two folders that contain the parallel and serial versions of the program. They are `./Serial/` and `./Parallel/`.

Each folder contains the serial or parallel version of the program and all the other files needed to run the program.

The main application, `app.c` can be found in the `/ml-cnn_cifar/` folder that is in the `./Serial/` and `./Parallel/` folders.

For a detailed list of changed made to parallelise the program, please see the report which can be found in the project root directory.

Results from the experiments done for the report can be found in the `results` folder. The `results` folder contains sub folders for each of the 3 devices that were used to run the experiments. The sub folders contain the `.csv` files that were generated from the programs.

# Build Instructions

## Pre-requisites

This is a c++ program and therefore requires a c++ compiler. The program was developed using the g++ compiler. The program also requires the OpenMP library to be installed and a version GNU Make to be installed.

Although the program was developed on Windows 10, it should work on any operating system that supports OpenMP and has gcc installed and callable from the terminal.

If you are on windows you can obtain g++ by downloading the **MSYS2** project from [here](https://www.msys2.org/). Once installed, you can install g++ by running the following command in the MSYS2 terminal.

```
    pacman -S mingw-w64-x86_64-toolchain
```

This will install g++, gcc and a version of make. 

Once installed you must add the executable to your environment path.

## Compiling

To compile use the makefile found in the `/ml-cnn_cifar/` folder. Then run the following command in the terminal.

```
    make
```

The makefile can be found in `./Serial/ml-cnn_cifar/` and `./Parallel/ml-cnn_cifar/`.

## Running

The make file will create the executable file in same folder as the makefile. To run the program, simply run the executable file from the terminal.

```
    ./app.exe
```

Alternatively, you can run the program using the makefile. This will compile and run the program once.

```
    make
```

