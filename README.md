# Halide_3DNR
3DNR proccessing using Halide

# Requirements
1.Halide 12.0.0 or above: https://github.com/halide/Halide

# Methods
1.Seperate images to serveral 4x4 blocks.

2.Calculate the difference between base block and others. If difference is larger, weight is smaller.

3.Calculate the difference between block center pixel and surroundings. If difference is larger, weight is smaller.

4.Combine all images multiplied by their weights, to get result image.

# Input Images
Input images are reference from https://github.com/zongwave/IPASS/tree/master/Sample

<img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_01.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_02.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_03.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_04.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_05.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_06.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_07.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_08.png" width="20%" height="20%"> 

Combine input images to GIF animation

<img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noise_sequence.gif" width="100%" height="100%">

# Result
<img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_01_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_02_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_03_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_04_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_05_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_06_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_07_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_08_3dnr.png" width="20%" height="20%">

Combine Output images to GIF animation

<img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noise_sequence_3dnr.gif" width="100%" height="100%">

# Usage
1. Change HALIDE_DISTRIB_PATH to yours in Makefile.inc
```
HALIDE_DISTRIB_PATH ?= /mnt/d/Software/Halide-12/distrib 
```
2. Run Makefile 
```
make test
```

# Reference
3DNR model is reference to https://github.com/zongwave/IPASS

