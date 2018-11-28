/*
Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "config_common.h"

#ifndef CONFIG_H
#define CONFIG_H

#define VENDOR_ID       0x20A0
#define PRODUCT_ID      0x422D
// TODO: share these strings with usbconfig.h
// Edit usbconfig.h to change these.
#define MANUFACTURER    winkeyless.kr
#define PRODUCT         CGx Keyboard [JJ40]

/* matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 15

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define BACKLIGHT_LEVELS 12

#define TAPPING_TOGGLE 3

#define MOUSEKEY_DELAY             200
#define MOUSEKEY_INTERVAL          20
#define MOUSEKEY_MAX_SPEED         3
#define MOUSEKEY_TIME_TO_MAX       15
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40

#define NO_UART 1

/* key combination for command */
#define IS_COMMAND() (keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)))

#endif
