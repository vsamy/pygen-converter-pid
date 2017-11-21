
Overview
=========

This is an header only library that provides list to eigen and numpy to eigen converters for boost python.

The license that applies to the whole package content is **CeCILL-C**. Please look at the license.txt file at the root of this repository.

## How-to
You can find more details [here](https://vsamy.github.io/en/git-repositories/pygen_converter).
To make things simple, in your .cpp boost binding file you need to `#include <pygen/converters.h>`.

The simplest way to get the conversions for a type **T** (*int*, *float*, *std::complex<double>*, ...) is to call the function `pygen::convert<T>(Converters::All)`. This will generate all conversions from Eigen Matrix and Array of *Scalar* **T** to Numpy ndarray of *dtype* **T** and generate all conversions from Numpy ndarray and python list to Eigen Matrix and Array.

## Why binding everything to Numpy ndarray
I could have bind Eigen Array to Numpy ndarray and Eigen Matrix to Numpy Matrix.
The reason i have bind everything to Numpy ndarray is because of [Numpy Matrix performances](https://stackoverflow.com/questions/16929211/numpy-np-array-versus-np-matrix-performance) and [scipy recommendations](https://docs.scipy.org/doc/numpy-dev/user/numpy-for-matlab-users.html#head-e9a492daa18afcd86e84e07cd2824a9b1b651935)

## Running Tests
To run the tests, you need first to set the cmake option `BUILD_AND_RUN_TESTS` to `ON`.
In the CMakeLists of the tests folder, comment everything.
Build the package, uncomment and rebuild.
If not done this way, the test will be launch before the installation and as the python lib is not yet install, the python test will fail.

Installation and Usage
=======================

The procedures for installing the pygen-converter package and for using its components is based on the [PID](http://pid.lirmm.net/pid-framework/pages/install.html) build and deployment system called PID. Just follow and read the links to understand how to install, use and call its API and/or applications.

About authors
=====================

pygen-converter has been developped by following authors: 
+ Vincent Samy (LIRMM)

Please contact Vincent Samy (vsamy@outlook.fr) - LIRMM for more information or questions.




