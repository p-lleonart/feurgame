# feurgame

A desktop video game built with C++ and SFML.

The specs are available in the ``feurgame_spec_v1.pdf``.

## Get started (dev)

This project follows the [(GH) davidtazy/cmake_virtual_mono_repo](https://github.com/davidtazy/cmake_virtual_mono_repo) template for monorepo architecture.

Don't hesitate to fork/clone the project for contributing purposes ;) !

### Run

First get the project on your machine, then open a console at its root.

Type ``cmake -B build`` (or ``cmake -B build -G "MinGW Makefiles"`` if it doesn't work on Windows).

You may have an error, and to fix it, you have to search for all the ``all_Feurgame-XXX_enable`` inside ``build/CMakeCache.txt``and set them to ``ON``.

Then re-type the cmake command and then ``cmake --build build``.
