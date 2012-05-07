#!/bin/bash

patch -b ./AVRISP-MKII.c			./AVRISP-MKII.c.patch
patch -b ./Descriptors.c			./Descriptors.c.patch
patch -b ./Descriptors.h			./Descriptors.h.patch
patch -b ./Lib/V2Protocol.c			./V2Protocol.c.patch
patch -b ./Lib/XPROG/XPROGProtocol.c		./XPROGProtocol.c.patch		
patch -b ./Lib/ISP/ISPProtocol.c		./ISPProtocol.c.patch
