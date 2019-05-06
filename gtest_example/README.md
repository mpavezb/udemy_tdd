# README

## Gtest Installation

```bash
sudo apt-get install cmake # install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
 
# copy or symlink libgtest.a and libgtest_main.a to your /usr/lib folder
sudo cp *.a /usr/lib
```

## Compilation and Running

```bash
mkdir -p build && cd build
cmake .. && make
make test
```