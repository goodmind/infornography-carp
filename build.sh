#!/usr/bin/env bash

TAG=$(git describe --tags --long | sed -E -e 's,^[^0-9]*,,;s,([^-]*-g),r\1,;s,[-_],.,g')
CARP_DIR=$HOME/Carp

clean () {
  rm -rf *.tar.gz;
  rm -rf out;
  rm -rf dist;
  mkdir dist;
  mkdir out;
}

compress () {
  mv out/Untitled dist/infornography;
  tar -czf infornography-$TRAVIS_OS_NAME-$TAG.tar.gz -C dist infornography && echo 'Compressed';
}

build () {
  clean;
  carp -x infornography.carp && echo 'Building successful';
  compress;
}

build;