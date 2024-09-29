/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Authors : Andreas Granig <andreas@granig.com>
 */

#ifndef __SIPP_MQTT_LOGGER_H__
#define __SIPP_MQTT_LOGGER_H__

#include <time.h>
#include "sipp.hpp"

void print_count_mqtt();
void print_error_codes_mqtt();
void print_errors_mqtt(int fatal, bool use_errno, int error, const char *fmt, va_list ap);

void print_message_mqtt(struct timeval *currentTime, const char* cid, const char* direction, const char *transport, const char *sock_type, ssize_t msg_size, const char *msg);

void print_log_mqtt(struct timeval *currentTime, const char* cid, const char *msg);
void print_warning_mqtt(struct timeval *currentTime, const char* cid, const char *msg);

#endif /* __SIPP_MQTT_LOGGER_H__ */
