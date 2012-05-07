#!/bin/bash

dfu-programmer at90usb162 erase && dfu-programmer at90usb162 flash *.hex
