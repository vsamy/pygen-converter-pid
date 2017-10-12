
Overview
=========

This is an header only library that provides list to eigen and numpy to eigen converters for boost python.

The license that applies to the whole package content is **CeCILL-C**. Please look at the license.txt file at the root of this repository.

## How to use

In your .cpp boost binding file you need to `#include <pygen/converters.h>`.

The simplest way to get the conversions is to call the function `pygen::convertEigen(Converters::All)`. This will generate all conversions from Eigen Matrix and Array to Numpy ndarray and generate all conversions from Numpy ndarray and python list to Eigen Matrix and Array.

## Why binding everything to Numpy ndarray
I could have bind Eigen Array to Numpy ndarray and Eigen Matrix to Numpy Matrix.
The reason i have bind everything to Numpy ndarray is because of [Numpy Matrix performances](https://stackoverflow.com/questions/16929211/numpy-np-array-versus-np-matrix-performance)

Installation and Usage
=======================

The procedures for installing the pygen-converter package and for using its components is based on the [PID](http://pid.lirmm.net/pid-framework/pages/install.html) build and deployment system called PID. Just follow and read the links to understand how to install, use and call its API and/or applications.

About authors
=====================

pygen-converter has been developped by following authors: 
+ Vincent Samy (LIRMM)

Please contact Vincent Samy (vincent.samy@lirmm.fr) - LIRMM for more information or questions.




