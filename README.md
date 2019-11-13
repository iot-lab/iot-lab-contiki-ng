Welcome to Contiki-NG for IoT-LAB !
==================================

[![Build Status](https://travis-ci.org/iot-lab/iot-lab-contiki-ng.svg?branch=master)](https://travis-ci.org/iot-lab/iot-lab-contiki-ng)

This repository is a port of the official Contiki-NG repository, bringing support for the IoT-LAB platform.

Supported boards (arch/platform/iotlab/ directory):

- m3
- a8-m3

## Requirements

- gcc-toolchain: https://launchpad.net/gcc-arm-embedded

## Basic setup

- ``$ git submodule update --init ``
- ``$ cd contiki-ng/examples/hello-world ``
- ``$ ARCH_PATH=../../../arch make TARGET=iotlab BOARD=m3 savetarget ``     # for m3 nodes
- ``$ ARCH_PATH=../../../arch make TARGET=iotlab BOARD=a8-m3 savetarget ``  # for a8 nodes
- ``$ ARCH_PATH=../../../arch make ``

See this [tutorial](https://www.iot-lab.info/tutorials/contiki-ng-compilation/) for explanations on how to compile default examples on IoT-LAB testbed.


## Acknowledgements

A special thanks to our Contiki-NG Yoda master, [Simon Duquennoy](http://www.simonduquennoy.net/). Without him this port would not exist.  
