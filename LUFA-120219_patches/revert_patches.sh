#!/bin/bash

patch -R ../AVRISP-MKII.c			./AVRISP-MKII.c.patch
patch -R ../Descriptors.c			./Descriptors.c.patch
patch -R ../Descriptors.h			./Descriptors.h.patch
patch -R ../Lib/V2Protocol.c			./V2Protocol.c.patch
patch -R ../Lib/XPROG/XPROGProtocol.c		./XPROGProtocol.c.patch		
patch -R ../Lib/ISP/ISPProtocol.c		./ISPProtocol.c.patch
