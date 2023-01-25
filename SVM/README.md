<!-- This README is in markdown format, It is should be viewed using a markdown viewer -->

<!-- This is because there will be pictures, gif and links embedded in the file to help explain the programs -->

<!-- If you do not have a markdown viewer please visit the flowing github link to  properly view the file in the intended format -->

<!-- https://github.com/ajayvarghese2000/22WSD530-Programming-Multi-many-core-Systems-Coursework-2/tree/main/SVM -->

<!-- This GitHub will be private until after the submission deadline -->
# Table of Contents

- [Support Vector Machine](#support-vector-machine)
    - [Working Principle](#working-principle)
- [File Structure](#file-structure)
- [Build Instructions](#build-instructions)
    - [Prerequisites](#pre-requisites)
    - [Compiling](#compiling)
    - [Running](#running)


# Support Vector Machine

<p align="center">
	<img src="https://i.imgur.com/QhkcXQr.png">
</p>

Support vector machines are learning machines for two-group classification problems. Developed at Bell Laboratories by Corinna Cortes and Vladimir Vapnik in 1993. Similar to ANN’s the SVM is also used to classify groups by recognising patterns. 

However, the SVM can only differentiate between two classifications unlike ANN that can classify as many inputs as it was trained on. On the other hand, due to the less computational method that SVM uses it can predict faster than an equivalent ANN.


## Working Principle

The SVM uses regression analysis in n-dimensional space to classify new items into two groups. Here n refers to the number of features that the SVM uses to classify. It achieves this by finding the hyperplane between the two groups. Much like the ANN the SVM must first be trained using a labelled dataset so that it can create the hyperplane. Once this is done, any new data will either fall on either side of the plane which will correspond to the classification result.

The hyperplane for n equal to two is a line of best fit, and new data will either be above or below the line which will in turn classify it into the two groups red or blue. When n is equal to three the hyperplane is a three dimensional plane of best fit, it works similar to the two dimensional example. The number of features can be very large however it is difficult to visualise higher than three dimensional space.

The hyperplane is optimised to create the largest margin between the input training data. In other words, to create the largest gap between all the reference points.


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