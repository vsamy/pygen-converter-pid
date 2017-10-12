## How to use

In your .cpp boost binding file you need to `#include <pygen/converters.h>`.

The simplest way to get the conversions is to call the function `pygen::convertEigen(Converters::All)`. This will generate all conversions from Eigen Matrix and Array to Numpy ndarray and generate all conversions from Numpy ndarray and python list to Eigen Matrix and Array.

## Why binding everything to Numpy ndarray
I could have bind Eigen Array to Numpy ndarray and Eigen Matrix to Numpy Matrix.
The reason i have bind everything to Numpy ndarray is because of [Numpy Matrix performances](https://stackoverflow.com/questions/16929211/numpy-np-array-versus-np-matrix-performance)