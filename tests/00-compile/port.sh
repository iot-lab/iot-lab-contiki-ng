#!/bin/bash

CONTIKI=../contiki-ng/
BASENAME=$(basename $0 .sh)

source $CONTIKI/tests/utils.sh

# Enter the directory
cd $CONTIKI/examples/hello-world

# Clean it
ARCH_PATH=../../../arch make clean TARGET=iotlab BOARD=m3 

# Compile for the m3 board
ARCH_PATH=../../../arch make TARGET=iotlab BOARD=m3

# Clean it
ARCH_PATH=../../../arch make clean TARGET=iotlab BOARD=m3 

# Clean it
ARCH_PATH=../../../arch make clean TARGET=iotlab BOARD=a8-m3

# Compile for the a8-m3 board
ARCH_PATH=../../../arch make TARGET=iotlab BOARD=a8-m3

# Clean it
ARCH_PATH=../../../arch make clean TARGET=iotlab BOARD=a8-m3
