# SaveableFlannBasedMatcher

## Overview
An extension of OpenCV's FlannBasedMatcher class which exposes additional methods for writing and reading matchers to disk.
This code is inspired by [this stack overflow solution](http://stackoverflow.com/questions/9248012/saving-and-loading-flannbasedmatcher).

To get started:
* Clone this repo
* `#include "saveable_matcher.hpp"` in your source
* Include `saveable_matcher.cpp` when compiling

## Usage
### To instantiate a matcher:

`Ptr<SaveableFlannBasedMatcher> matcher = new SaveableFlannBasedMatcher(filename);`

Where `filename` is a C string which will prefix the files to which the matcher will be saved.

### To build and use the matcher, simply use the parent class methods provided by OpenCV, e.g.:

* `matcher->add(descriptors);`
* `matcher->train();`
* `matcher->match(descriptor, matches);`

### To save a matcher:

`matcher->store()`

This will write three files to disk which describe the matcher:
* filename-descriptors.bin
* filename-tree.xml.gz
* filename.flannindex

Note that at least one call to `match()` must be made before storing, so that OpenCV actually constructs the matcher.

### To load a matcher which has already been written to disk:
`matcher->load()`

You can now make calls to e.g. `match()`.

## Dependencies

* OpenCV 3.0

## LICENCE
The MIT License (MIT)

Copyright (c) 2016 Mike Christensen

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
