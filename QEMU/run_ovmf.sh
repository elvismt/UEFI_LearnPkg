#!/bin/bash
#
# Copyright 2017 Elvis M. Teixeira
#
# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files (the "Software"), to  deal in the Software without
# restriction, including without limitation the rights to use,
# copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following
# conditions:
# 
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
# OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
# HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
# WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
# OTHER DEALINGS IN THE SOFTWARE.

##
## Runs QEMU with the specified firmware image
##
if [ $# -lt 1 ]; then
  echo "You must inform the Ovmf image name to run, usage:"
  echo "  $0 <Ovmf firmware name>"
  exit 1
fi

FIRMWARE="-drive file=$1,format=raw,if=pflash"
VIRTUAL_HDD="-drive id=nvme0,file=fat:wr:harddisk,format=raw,if=none"
VIRTUAL_HDD="$VIRTUAL_HDD -device nvme,drive=nvme0,serial=1234"
MACHINE="-m 1G -machine q35"
SERIAL_OUTPUT="-serial file:serial_output.txt"

if [[ -f 'serial_output.txt' ]]; then
  rf -f 'serial_output.txt'
fi

qemu-system-x86_64  $MACHINE $FIRMWARE $VIRTUAL_HDD $SERIAL_OUTPUT "${@:2}"

