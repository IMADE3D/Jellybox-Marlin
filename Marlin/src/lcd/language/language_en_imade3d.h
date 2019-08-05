/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

/**
 * English : IMADE3D ADDITIONS/ MODIFICATIONS
 *
 * LCD Menu Messages
 * See also http://marlinfw.org/docs/development/lcd_language.html
 *
 */
#define LANGUAGE_EN_IMADE3D_H

#ifndef CHARSIZE
  #define CHARSIZE 1
#endif

///////////////////////
///// Overwrites///////
///////////////////////

#define MSG_ZPROBE_ZOFFSET                  _UxGT("Live Adj. Z Height")
#define MSG_DISABLE_STEPPERS                _UxGT("Release motors")
#define MSG_RESTORE_FAILSAFE                _UxGT("Factory Reset (!)")
#define WELCOME_MSG                         MACHINE_NAME _UxGT(" is ready.")

///////////////////////
///// Utilities //////
//////////////////////

#ifndef MSG_SPACE
  #define MSG_SPACE                            _UxGT(" ")
#endif

///////////////////////
// JellyBOX Specific //
///////////////////////

#define MSG_SET_X_ORIGIN                _UxGT("Set X Origin")
#define MSG_SET_Y_ORIGIN                _UxGT("Set Y Origin")
#define MSG_X_ORIGIN_UPDATED            _UxGT("X-Origin updated")
#define MSG_Y_ORIGIN_UPDATED            _UxGT("Y-Origin updated")
#ifndef MSG_MATERIAL
  #define MSG_MATERIAL                        _UxGT("Material")
#endif
#ifndef MSG_BEEP
  #define MSG_BEEP                             _UxGT("Beep")
#endif 
#ifndef MSG_TWEAK_FIRST_LAYER
  #define MSG_TWEAK_FIRST_LAYER               _UxGT("Live adj. Z height")
#endif
#ifndef MSG_DISABLE_HEATBED
  #define MSG_DISABLE_HEATBED                 _UxGT("Disable heated bed")
#endif
#ifndef MSG_ENABLE_HEATBED
  #define MSG_ENABLE_HEATBED                  _UxGT("Enable heated bed")
#endif
#ifndef MSG_DISABLE_HEATBED_MENU
  #define MSG_DISABLE_HEATBED_MENU            _UxGT("Heatbed On/Off")
#endif
#ifndef MSG_HEATBED_ENABLED
  #define MSG_HEATBED_ENABLED                 _UxGT("Heated bed enabled")
#endif
#ifndef MSG_HEATBED_DISABLED
  #define MSG_HEATBED_DISABLED                _UxGT("Heated bed disabled")
#endif

// About Printer Menu Annotations
#ifndef MSG_FIRMWARE_VERSION
  #define MSG_FIRMWARE_VERSION            _UxGT("FIRMWARE VERSION:")
#endif
#ifndef MSG_JELLYBOX_VARIANT
  #define MSG_JELLYBOX_VARIANT           _UxGT("JELLYBOX VARIANT:")
#endif
#ifndef MSG_DISTRIBUTION_DATE
  #define MSG_DISTRIBUTION_DATE           _UxGT("DISTRIBUTION DATE:")
#endif
#ifndef MSG_SOURCE_URL
  #define MSG_SOURCE_URL                 _UxGT("SOURCE URL:")
#endif
#ifndef MSG_WEBSITE_URL
  #define MSG_WEBSITE_URL                 _UxGT("HOMEPAGE URL:")
#endif
#ifndef MSG_LEVELING_METHOD
  #define MSG_LEVELING_METHOD                 _UxGT("LEVELING METHOD:")
#endif

// Misc
#ifndef MSG_HOME_RELEASE
  #define MSG_HOME_RELEASE                    _UxGT("Home & Release")
#endif 
#ifndef MSG_FILAMENTLOAD
  #define MSG_FILAMENTLOAD                    _UxGT("Load filament")
#endif
#ifndef MSG_FILAMENTEJECT 
  #define MSG_FILAMENTEJECT                    _UxGT("Eject filament")
#endif
#ifndef MSG_HOME_AXES
  #define MSG_HOME_AXES                       _UxGT("Home X, Y, or Z")
#endif

// Preflight menu
#ifndef MSG_PREFLIGHT_MENU
  #define MSG_PREFLIGHT_MENU                   _UxGT("Preflight Check")
#endif
#ifndef MSG_TEST_MOTORS
  #define MSG_TEST_MOTORS                     _UxGT("1. Test motors")
#endif
#ifndef MSG_CHECK_ENDSTOPS
  #define MSG_CHECK_ENDSTOPS                  _UxGT("2. Endstop status")
#endif 
#ifndef MSG_TEST_ENDSTOPS
  #define MSG_TEST_ENDSTOPS                   _UxGT("3. Test endstops")
#endif 
#ifndef MSG_SET_ORIGIN_PREFLIGHT
  #define MSG_SET_ORIGIN_PREFLIGHT            _UxGT("4. Set origin")
#endif
#ifndef MSG_CHANGE_X_HOME_OFFSET
  #define MSG_CHANGE_X_HOME_OFFSET            _UxGT("Set X-origin")
#endif
#ifndef MSG_TEST_AUTO_BED_LEVEL_PREFLIGHT
  #define MSG_TEST_AUTO_BED_LEVEL_PREFLIGHT   _UxGT("5. Test bed leveling")
#endif
#ifndef MSG_TEST_AUTO_BED_LEVEL
  #define MSG_TEST_AUTO_BED_LEVEL              _UxGT("Test bed leveling")
#endif
#ifndef MSG_TEST_NOZZLE
  #define MSG_TEST_NOZZLE                      _UxGT("6. Test nozzle heater")
#endif 
#ifndef MSG_TEST_BED
  #define MSG_TEST_BED                         _UxGT("7. Test bed heater")
#endif 
#ifndef MSG_TEST_FILAMENT_FANS
  #define MSG_TEST_FILAMENT_FANS              _UxGT("8. Test filament fans")
#endif
#ifndef MSG_FILAMENTLOAD_PREFLIGHT
  #define MSG_FILAMENTLOAD_PREFLIGHT          _UxGT("9.  Load filament")
#endif
#ifndef MSG_FILAMENTEJECT_PREFLIGHT
  #define MSG_FILAMENTEJECT_PREFLIGHT         _UxGT("10. Eject filament")
#endif

// #endif // LANGUAGE_EN_IMADE3D_H
