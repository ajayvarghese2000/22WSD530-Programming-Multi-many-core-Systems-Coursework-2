<!-- This README is in markdown format, It is should be viewed using a markdown viewer -->

<!-- This is because there will be pictures, gif and links embedded in the file to help explain the programs -->

<!-- If you do not have a markdown viewer please visit the flowing github link to  properly view the file in the intended format -->

<!-- https://github.com/ajayvarghese2000/22WSD530-Programming-Multi-many-core-Systems-Coursework-2/tree/main/RandomForest -->

<!-- This GitHub will be private until after the submission deadline -->
# Table of Contents

- [Random Forest](#random-forest)
    - [Working Principle](#working-principle)
- [File Structure](#file-structure)
- [Build Instructions](#build-instructions)
    - [Prerequisites](#pre-requisites)
    - [Compiling](#compiling)
    - [Running](#running)


# Random Forest

<p align="center">
	<img src="https://i.imgur.com/T1ogcAy.png">
</p>

Random Forest is a learning method for classification developed by Leo Breiman and Adele Cutler. First published in 2001, later trademarked in 2006, it is based on the concept of decision trees, where a large number of decision trees are created and combined to form a "forest" of decision trees. 
The idea behind this method is that each tree in the forest will make a prediction, and the final prediction will be the average of the predictions made by all the trees in the forest.

It uses a technique called "The Random Subspace Method", created by Tin Kam Ho of Bell Laboratories in 1998, which selects a random subset of features for each tree, rather than using all the available features to classify. This helps to reduce correlation between trees and improves the overall performance of the model as each individual tree will check the new data against a range of different identifiable features.

## Working Principle

A decision tree is created using a training dataset, which is used to make predictions on a new set of data. However, a single huge decision tree is prone to overfitting, which leads to poor performance and misclassification. As mentioned to overcome this problem, the Random Forest model uses the Random Subspace Method to select random samples of the data, to create multiple decision trees.

The final decision tree is created by combining the predictions of the smaller individual decision trees. This final decision tree is known as the “Random Forest”.



# File Structure

There are 3 main files in the project:

- `main.c` - This is the original version of the program it is a single threaded version of the program that is used to compare the performance of the parallelised version.
- `main_fast.c` - This is the most efficient parallelised version of the program. It uses the OpenMP library to parallelise the program. The pragma directives are placed in the most efficient sections.

When the each program is run, they will create a `.csv` file and append the run time to the end of the file.

Results from the experiments done for the report can be found in the `results` folder. The `results` folder contains sub folders for each of the 3 devices that were used to run the experiments. The sub folders contain the `.csv` files that were generated from the programs.

`./bin/` contains the executable files for the programs.

# Build Instructions

## Pre-requisites

This is a c program and therefore requires a c compiler. The program was developed using the gcc compiler. The program also requires the OpenMP library to be installed and a version GNU Make to be installed.

Although the program was developed on Windows 10, it should work on any operating system that supports OpenMP and has gcc installed and callable from the terminal.

If you are on windows you can obtain gcc by downloading the **MSYS2** project from [here](https://www.msys2.org/). Once installed, you can install gcc by running the following command in the MSYS2 terminal.

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

This will build all versions of the program and create an executable file in `./bin/` directory.

## Running

There are many ways to run the program. The easiest way is to run the executable directly from the terminal.

```
    ./bin/original.exe
```

```
    ./bin/fast.exe
```

Alternatively, you can run the program using the makefile. This will compile and run once the specified program.

```
    make original
```

```
    make fast
```

If you need to run the program multiple times you can use the following command. 

**NOTE: This will not compile the programs, it will only run the program so make sure you have compiled the program first by running `make`.**

```
    make run_all
```

This will run all versions of the program 100 times and append the results to the `.csv` file created.

**Linux users may have issue with this command and so a `.sh` file has been provided to do this instead.**

```
    ./run.sh
```