/*
 * Copyright © 2015 Red Hat, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef LIBRATBAG_HIDRAW_H
#define LIBRATBAG_HIDRAW_H

#include <linux/hid.h>
#include <stdint.h>
#include <pthread.h>

#include "libratbag.h"

/* defined in the internal hid API in the kernel */
#define HID_INPUT_REPORT	0
#define HID_OUTPUT_REPORT	1
#define HID_FEATURE_REPORT	2

struct ratbag_hidraw {
	int fd;
	uint8_t *report_ids;
	unsigned num_report_ids;
	pthread_t events_thread;
	int use_thread;
	pthread_mutex_t lock;
	pthread_mutex_t grab_lock;
	int pipe_fds[2];
};

/**
 * Open the hidraw device associated with the device.
 *
 * @param device the ratbag device
 *
 * @return 0 on success or a negative errno on error
 */
int ratbag_open_hidraw(struct ratbag_device *device);

/**
 * Close the hidraw device associated with the device.
 *
 * @param device the ratbag device
 */
void ratbag_close_hidraw(struct ratbag_device *device);

/**
 * Send report request to device
 *
 * @param device the ratbag device
 * @param reportnum report ID
 * @param buf in/out data to transfer
 * @param len length of buf
 * @param rtype HID report type
 * @param reqtype HID_REQ_GET_REPORT or HID_REQ_SET_REPORT
 *
 * @return count of data transfered, or a negative errno on error
 *
 * Same behavior as hid_hw_request, but with raw buffers instead.
 */
int ratbag_hidraw_raw_request(struct ratbag_device *device, unsigned char reportnum,
			      uint8_t *buf, size_t len, unsigned char rtype,
			      int reqtype);

/**
 * Send output report to device
 *
 * @param device the ratbag device
 * @param buf raw data to transfer
 * @param len length of buf
 *
 * @return count of data transfered, or a negative errno on error
 */
int ratbag_hidraw_output_report(struct ratbag_device *device, uint8_t *buf, size_t len);

/**
 * Read an input report from the device
 *
 * @param device the ratbag device
 * @param[out] buf resulting raw data
 * @param len length of buf
 * @param propagate notify or not the raw_event driver callback
 *
 * @return count of data transfered, or a negative errno on error
 */
int ratbag_hidraw_read_input_report(struct ratbag_device *device, uint8_t *buf,
				    size_t len, int propagate);

/**
 * Propagate an input report from the device to the raw_event driver callback
 *
 * @param device the ratbag device
 * @param buf buffer containing the raw data
 * @param len length of buf
 *
 * @return 0, or a negative errno on error
 */
int ratbag_hidraw_propagate_report(struct ratbag_device *device, uint8_t *buf,
				   size_t len);

/**
 * Start an event thread reader
 *
 * @param device the ratbag device
 *
 * @return 0 or a negative errno on error
 */
int ratbag_hidraw_start_events(struct ratbag_device *device);

/**
 * Stop the events thread reader
 *
 * @param device the ratbag device
 *
 * @return 0 or a negative errno on error
 */
void ratbag_hidraw_stop_events(struct ratbag_device *device);

int ratbag_hidraw_lock_events(struct ratbag_device *device);
int ratbag_hidraw_unlock_events(struct ratbag_device *device);

/**
 * Tells if a given device has the specified report ID.
 *
 * @param device the ratbag device which hidraw node is opened
 * @param report_id the report ID we inquire about
 *
 * @return 1 if the device has the given report id, 0 otherwise
 */
int
ratbag_hidraw_has_report(struct ratbag_device *device, uint8_t report_id);

#endif /* LIBRATBAG_HIDRAW_H */
