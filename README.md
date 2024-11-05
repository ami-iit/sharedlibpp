Simple cross platform plug-in system
====================================

`sharedlibpp` is a tiny cross-platform library to create and load shared
libraries for different platform (Linux/Mac/Windows). `sharedlibpp` provides
an easy and portable way to create plug-ins which encapsulate your c++ classes
inside a shared library (so, dylib, dll).
The original code is taken and from
[YARP (Yet Another Robot Platform)](http://www.yarp.it/).
The code is simplified by removing dependencies and some helper functions are
added to report the native OS error messages on failures.


Building on Linux/Mac
---------------------
    $ cd sharedlibpp
    $ cmake -Bbuild -S. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./install
    $ cmake --build . --config Release
    $ cmake --install .


Running example
---------------
The build system by default compiles and build the examples.

* On Linux/Mac
```
    $ cd sharedlibpp/build/examples
    $ ./math_test mymath
    $ ./math_test_custom mymathcustom
```
* On Windows first switch to directory where example is created and then
```
    > math_test mymath
    > math_test_custom mymathcustom
```
