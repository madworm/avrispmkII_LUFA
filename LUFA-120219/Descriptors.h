/*
             LUFA Library
     Copyright (C) Dean Camera, 2012.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2012  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Descriptors.c.
 */

#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

	/* Includes: */
		#include <avr/pgmspace.h>

		#include <LUFA/Drivers/USB/USB.h>

	/* Macros: */

		/**
		 * Don't use the makefile option '#LUFA_OPTS += -D LIBUSB_DRIVER_COMPAT',
		 * just define all of it here.
		 *
		 */

		#define AVRISP_DATA_OUT_EPNUM__COMMON	2
		#define AVRISP_DATA_IN_EPNUM__DEFAULT	2

		/**
		 * This is needed for libusb on windows only.
		 * avrdude 5.11 on linux doesn't seem to care which endpoint is used.
		 * Don't forget to remove the 'Jungo' driver and install libusb and
		 * related things.
		 *
		 */
		#define AVRISP_DATA_IN_EPNUM__LIBUSB	3

		/** Size in bytes of the AVRISP data endpoint. */
		#define AVRISP_DATA_EPSIZE             64

	/* Type Defines: */
		/** Type define for the device configuration descriptor structure. This must be defined in the
		 *  application code, as the configuration descriptor contains several sub-descriptors which
		 *  vary between devices, and which describe the device's usage to the host.
		 */
		typedef struct
		{
			USB_Descriptor_Configuration_Header_t    Config;

			// Atmel AVRISP-MKII Interface
			USB_Descriptor_Interface_t               AVRISP_Interface;
			USB_Descriptor_Endpoint_t                AVRISP_DataInEndpoint;
			USB_Descriptor_Endpoint_t                AVRISP_DataOutEndpoint;
		} USB_Descriptor_Configuration_t;

	/* Function Prototypes: */
		uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
		                                    const uint8_t wIndex,
		                                    const void** const DescriptorAddress)
		                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);
						    
		
		/**
		 * This will be used to read MCUSR early on and evaluate it.
		 *
		 * An external reset (pressing the reset button) will change the device's behaviour. 				    
		 * Information is persistently stored in 'use_libusb', which survives a reset.
		 *
		 */
		extern bool use_libusb __attribute__ ((section(".noinit")));
		void eval_mcusr(void) __attribute__((section(".init3"))) __attribute__((naked));					  

#endif

