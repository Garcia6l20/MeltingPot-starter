# HelloConan starter project

This project shows how to create a simple conan package using MeltingPot.

## Building the project

```bash
mkdir build && cd build
cmake ..
# notice the created conanfile.py
make -j
ctest
```

## Create the package

```bash
mkdir build && cd build
cmake ..
conan create .. -s compiler=<compiler> -s compiler.version=<version> -s compiler.cppstd=17
```

> Notice that extra conan settings are not required if you remove CMAKE_CXX_STANDARD in CMakeLists.txt
