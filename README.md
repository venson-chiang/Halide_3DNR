# Halide_3DNR
3DNR proccessing using Halide

# Requirements
1.Halide 12.0.0 or above: https://github.com/halide/Halide

# Methods
1.Resize input image to get low resolution image for deep learning.

2.Apply laplacian pyramid and deep learning model to correct exposure of image.

3.Apply Bilateral Guided Upsampling to get high resolution exposure corrected image. 

4.Fuse input image and exposure corrected image to get better performance of exposure correction.

# Input Images
Input images are reference from https://github.com/mahmoudnafifi/Exposure_Correction/tree/master/example_images

<img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_01.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_02.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_03.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_04.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_05.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_06.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_07.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/input_images/noisy_sequence_08.png" width="20%" height="20%"> 

# Result
<img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_01_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_02_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_03_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_04_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_05_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_06_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_07_3dnr.png" width="20%" height="20%"> <img src="https://github.com/venson-chiang/Halide_3DNR/blob/main/output_images/noisy_sequence_08_3dnr.png" width="20%" height="20%">

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
Exposure correction model is reference to https://github.com/mahmoudnafifi/Exposure_Correction

