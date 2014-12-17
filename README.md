[![Build Status](https://travis-ci.org/JoakimSoderberg/coveralls-cmake-example.svg?branch=master)](https://travis-ci.org/JoakimSoderberg/coveralls-cmake-example)
[![Coverage Status](https://img.shields.io/coveralls/JoakimSoderberg/coveralls-cmake-example.svg)](https://coveralls.io/r/JoakimSoderberg/coveralls-cmake-example?branch=master)

Coveralls CMake example project
===============================

This is an example project that demonstrates how
https://github.com/JoakimSoderberg/coveralls-cmake can be used.

Usage
-----

```bash
$ git clone https://github.com/JoakimSoderberg/coveralls-cmake-example.git
$ cd coveralls-cmake-example
$ git submodule update --init
$ mkdir build && cd build
$ cmake -DCOVERALLS=ON -DCMAKE_BUILD_TYPE=Debug ..
$ make
$ make coveralls
```
