<!-- This README is in markdown format, It is should be viewed using a markdown viewer -->

<!-- This is because there will be pictures, gif and links embedded in the file to help explain the programs -->

<!-- If you do not have a markdown viewer please visit the flowing github link to  properly view the file in the intended format -->

<!-- https://github.com/ajayvarghese2000/22WSD530-Programming-Multi-many-core-Systems-Coursework-2/ -->

<!-- This GitHub will be private until after the submission deadline -->

# 22WSD530-Programming-Multi-many-core-Systems-Coursework-2

This repository contains the code for coursework 2 for 22WSD530 Programming Multi/many-core Systems. The coursework is split into 4 parallel programs.

Each program has its own README.md file that explains what it is doing and how to build/run it which can be found in their respective folders.

The vTune folder contains the vTune profiling result for each program. The special binaries that were used to profile the programs are also included in the subfolder `vTune_Binaries`.

To view the vTune profiling results open the `.vtune`, found within the programs subfolder, with the [vTune program](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler-download.html).

For further explanation of what was done in this coursework please see the `Report.pdf` file in the root directory.

## Report Abstract
>This paper looked at increasing the performance of machine learning models by leveraging multiple cores to execute code in parallel. It detailed how each program was parallelised and the performance impact gained or lost, giving reasons for the increase or decrease. Intel vTune was used to profile each of the learning models to list the bottlenecks in the code and identify potential areas of parallelisation. OpenMP was used to execute segments of each program on threads resulting in a parallel version. For the NN and SVM a fast and slow parallel version was created to highlight the issues with inefficient parallelisation. Overall, it was found that single threaded performance, parallelisation code efficiency, amount of data to be executed in parallel and the number of threads available were the major factors in determining the speed up that could be gained from parallelisation. Intel vTune was effective at identifying program hotspots  however, each hotspot may not be an ideal area for parallelisation and so it should be used in conjunction with a programmer's intuition and knowledge to create efficient parallel programs.

The speed up data of each program can be found in the `.xlsx` file in the root directory. 

The graphs are also shown below.

<p align="center">
	<img src="https://i.imgur.com/42bqO3B.png">
</p>

<p align="center">
	<img src="https://i.imgur.com/O8G6Y3F.png">
</p>

<p align="center">
	<img src="https://i.imgur.com/cFpIPXq.png">
</p>