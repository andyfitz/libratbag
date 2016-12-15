/*
 * HID++ constants definitions
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

/*
 * Based on the HID++ documentation provided by Nestor Lopez Casado at:
 *   https://drive.google.com/folderview?id=0BxbRzx7vEV7eWmgwazJ3NUFfQ28&usp=sharing
 */

#ifndef HIDPP_CONSTANTS_H
#define HIDPP_CONSTANTS_H

#define HIDPP_RECEIVER_IDX			0xFF
#define HIDPP_WIRED_DEVICE_IDX			0x00

#define HIDPP_REPORT_ID_SHORT			0x10
#define HIDPP_REPORT_ID_LONG			0x11

#define HIDPP_SHORT_MESSAGE_LENGTH		7
#define HIDPP_LONG_MESSAGE_LENGTH		20

#define HIDPP_SET_REGISTER_REQ			0x80
#define HIDPP_SET_REGISTER_RSP			0x80
#define HIDPP_GET_REGISTER_REQ			0x81
#define HIDPP_GET_REGISTER_RSP			0x81
#define HIDPP_SET_LONG_REGISTER_REQ		0x82
#define HIDPP_SET_LONG_REGISTER_RSP		0x82
#define HIDPP_GET_LONG_REGISTER_REQ		0x83
#define HIDPP_GET_LONG_REGISTER_RSP		0x83
#define HIDPP_ERROR_MSG				0x8F

#define HIDPP_ERR_SUCCESS			0x00
#define HIDPP_ERR_INVALID_SUBID			0x01
#define HIDPP_ERR_INVALID_ADDRESS		0x02
#define HIDPP_ERR_INVALID_VALUE			0x03
#define HIDPP_ERR_CONNECT_FAIL			0x04
#define HIDPP_ERR_TOO_MANY_DEVICES		0x05
#define HIDPP_ERR_ALREADY_EXISTS		0x06
#define HIDPP_ERR_BUSY				0x07
#define HIDPP_ERR_UNKNOWN_DEVICE		0x08
#define HIDPP_ERR_RESOURCE_ERROR		0x09
#define HIDPP_ERR_REQUEST_UNAVAILABLE		0x0A
#define HIDPP_ERR_INVALID_PARAM_VALUE		0x0B
#define HIDPP_ERR_WRONG_PIN_CODE		0x0C

#endif /* HIDPP_CONSTANTS_H */
