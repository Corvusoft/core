Core
=============================================================================================================================

License
-------

&copy; 2013-2017 Corvusoft Limited, United Kingdom. All rights reserved.

The Core framework is dual licensed; See [LICENSE](LICENSE) for full details.

Support
-------

Please contact sales@corvusoft.co.uk, for support and licensing options including bespoke software development, testing, design consultation, training, mentoring and code review.

Build
-----

*Unix*
```bash
git clone --recursive https://github.com/corvusoft/core.git
mkdir core/build
cd core/build
cmake ..
make [-j CPU_CORES+1] install
make test
```

*Windows*
```bash
git clone --recursive https://github.com/corvusoft/core.git
mkdir core/build
cd core/build
cmake -G "Visual Studio 15 2017" ..
cmake --build . --target ALL_BUILD --config Release
ctest
```

You will now find all required components installed in the distribution folder.

Please submit all enhancements, proposals, and defects via the [issue](http://github.com/corvusoft/core/issues) tracker.

Documentation
-------------

This codebase is intended to be as self documenting as possible. We have supplied many [test cases](https://github.com/corvusoft/core/tree/master/test) to help aid developers.

You can locate the latest API documentation [here](https://github.com/Corvusoft/core/tree/master/documentation).

Minimum Requirements
--------------------

| Resource | Requirement                                     |
|:--------:|:-----------------------------------------------:|
| Compiler |            C++14 compliant or above             |
|    OS    |          BSD, Linux, Mac OSX, Windows           |

Contact
-------

| Method                                      | Description                                 |
|:--------------------------------------------|:--------------------------------------------|
| [Twitter](http://www.twitter.com/corvusoft) | Tweet us your questions & feature requests. |
| support@corvusoft.co.uk                     | Support related queries.                    |
| sales@corvusoft.co.uk                       | Sale related queries.                       |
