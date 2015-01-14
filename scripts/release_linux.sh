#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: ./release_linux.sh path-to-bin-folder"
  exit 1
fi

destdir=`readlink -f "$1"`

mkdir -p build
cd build
rm CMakeCache.txt # make sure to use default settigs
cmake \
-D COMPILER=ICC \
-D ENABLE_XEON_PHI_SUPPORT=ON \
-D RTCORE_SPINLOCKS=ON \
..
make -j 8 preinstall
cmake -D CMAKE_INSTALL_PREFIX="$destdir" -P cmake_install.cmake
cd ..

# assumes documentation repo cloned into embree-doc
make -C embree-doc docbin
cp embree-doc/docbin/* "$destdir"
