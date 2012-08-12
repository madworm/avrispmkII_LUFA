#!/bin/bash

diff -u ./AVRISP-MKII.c.orig 			./AVRISP-MKII.c			>./AVRISP-MKII.c.patch
diff -u ./Descriptors.c.orig 			./Descriptors.c 		>./Descriptors.c.patch
diff -u ./Descriptors.h.orig 			./Descriptors.h 		>./Descriptors.h.patch
diff -u ./Lib/V2Protocol.c.orig 		./Lib/V2Protocol.c 		>./V2Protocol.c.patch
diff -u ./Lib/XPROG/XPROGProtocol.c.orig 	./Lib/XPROG/XPROGProtocol.c	>./XPROGProtocol.c.patch		
diff -u ./Lib/ISP/ISPProtocol.c.orig		./Lib/ISP/ISPProtocol.c		>./ISPProtocol.c.patch
