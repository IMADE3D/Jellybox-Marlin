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

#include "../../../inc/MarlinConfig.h"

#if ENABLED(GCODE_MACROS)

#include "../../gcode.h"
#include "../../queue.h"
#include "../../parser.h"
#include "../../../module/motion.h"
#include "../../../module/stepper.h"
#include "../../../module/printcounter.h"
#include "../../../module/planner.h"

//INSPIRATION
 // #ifdef G29_FAILURE_COMMANDS
//   gcode.process_subcommands_now_P(PSTR(G29_FAILURE_COMMANDS));
 // #endif 

#define TEST "G0 X10\nG0 X40\nM300 S500 P500"
#define SETUP "G21               ;metric values\nG90               ;absolute positioning\nM82               ;set extruder to absolute mode\nM107              ;start with the fan off\nM117 Preparing    ;write Preparing\n;M190 S20          ;wait for the bed to reach 20C\n;M109 S180         ;wait for the extruder to reach 180C\nG28               ;home all axes\nG29 O             ;auto bed leveling procedure only if leveling NOT active\n;M500              ;optionally save the mesh\nG28 X             ;home x to get as far from the plate as possible\nM420 S1           ;(re) enable bed leveling if turned off by the G28\nG0 Y0 F5000       ;position Y in front\nG0 Z15 F3000      ;position Z\n;M190 S0           ;wait for the bed to reach desired temperature\n;M109 S215         ;wait for the extruder to reach desired temperature"
#define PRINT_LINE "M117 Print starting\nG90               ;absolute positioning\nM83               ;relative extrusion mode\nG0 Z0             ;get Z down\nG1 E18 F500       ;extrude __mm of feed stock\nG1 E16 F400       ;extrude __mm of feed stock\nG1 E8 F400        ;extrude __mm of feed stock\nG4 S2             ;pause for ooze\nM400              ;make sure all is finished\nG0 F500 X3 Y0 Z0.6;get to the start of the LINE\nG1 E2 F300        ;extrude __mm of feed stock\nG1 F1000 X104 E10 ;print a thick LINE extruding __mm along the way\nM82               ;absolute extrusion mode (many slicers have absolute as default)\nG92 E0            ;reset the extruder position"
#define PRINT_FILL ";test ;test\nG1 F2400 E-1.3\nG0 F3600 X99.5 Y20 Z0.3\nG1 F600 E1.3\nG1 F1200 X99.5 Y10 E0.59245\nG0 F3600 X100 Y10\nG1 F1200 X100 Y20 E0.59245\nG0 F3600 X100.5 Y20\nG1 F1200 X100.5 Y10 E0.59245\nG0 F3600 X101 Y10\nG1 F1200 X101 Y20 E0.59245\nG0 F3600 X101.5 Y20\nG1 F1200 X101.5 Y10 E0.59245\nG0 F3600 X102 Y10\nG1 F1200 X102 Y20 E0.59245\nG0 F3600 X102.5 Y20\nG1 F1200 X102.5 Y10 E0.59245\nG0 F3600 X103 Y10\nG1 F1200 X103 Y20 E0.59245\nG0 F3600 X103.5 Y20\nG1 F1200 X103.5 Y10 E0.59245\nG0 F3600 X104 Y10\nG1 F1200 X104 Y20 E0.59245\nG0 F3600 X104.5 Y20\nG1 F1200 X104.5 Y10 E0.59245\nG0 F3600 X105 Y10\nG1 F1200 X105 Y20 E0.59245\nG0 F3600 X105.5 Y20\nG1 F1200 X105.5 Y10 E0.59245\nG0 F3600 X106 Y10\nG1 F1200 X106 Y20 E0.59245\nG0 F3600 X106.5 Y20\nG1 F1200 X106.5 Y10 E0.59245\nG0 F3600 X107 Y10\nG1 F1200 X107 Y20 E0.59245\nG0 F3600 X107.5 Y20\nG1 F1200 X107.5 Y10 E0.59245\nG0 F3600 X108 Y10\nG1 F1200 X108 Y20 E0.59245\nG0 F3600 X108.5 Y20\nG1 F1200 X108.5 Y10 E0.59245\nG0 F3600 X109 Y10\nG1 F1200 X109 Y20 E0.59245\nG0 F3600 X109.5 Y20\nG1 F1200 X109.5 Y10 E0.59245\nG0 F3600 X110 Y10\nG1 F1200 X110 Y20 E0.59245\nG0 F3600 X110.5 Y20\nG1 F1200 X110.5 Y10 E0.59245\nG0 F3600 X111 Y10\nG1 F1200 X111 Y20 E0.59245\nG0 F3600 X111.5 Y20\nG1 F1200 X111.5 Y10 E0.59245\nG0 F3600 X112 Y10\nG1 F1200 X112 Y20 E0.59245\nG0 F3600 X112.5 Y20\nG1 F1200 X112.5 Y10 E0.59245\nG0 F3600 X113 Y10\nG1 F1200 X113 Y20 E0.59245\nG0 F3600 X113.5 Y20\nG1 F1200 X113.5 Y10 E0.59245\nG0 F3600 X114 Y10\nG1 F1200 X114 Y20 E0.59245\nG0 F3600 X114.5 Y20\nG1 F1200 X114.5 Y10 E0.59245\nG0 F3600 X115 Y10\nG1 F1200 X115 Y20 E0.59245\nG0 F3600 X115.5 Y20\nG1 F1200 X115.5 Y10 E0.59245\nG0 F3600 X116 Y10\nG1 F1200 X116 Y20 E0.59245\nG0 F3600 X116.5 Y20\nG1 F1200 X116.5 Y10 E0.59245\nG0 F3600 X117 Y10\nG1 F1200 X117 Y20 E0.59245\nG0 F3600 X117.5 Y20\nG1 F1200 X117.5 Y10 E0.59245\nG0 F3600 X118 Y10\nG1 F1200 X118 Y20 E0.59245\nG0 F3600 X118.5 Y20\nG1 F1200 X118.5 Y10 E0.59245\nG0 F3600 X119 Y10\nG1 F1200 X119 Y20 E0.59245\nG0 F3600 X119.5 Y20\nG1 F1200 X119.5 Y10 E0.59245\nG0 F3600 X120 Y10\nG1 F1200 X120 Y20 E0.59245\nG0 F3600 X120.5 Y20\nG1 F1200 X120.5 Y10 E0.59245\nG0 F3600 X121 Y10\nG1 F1200 X121 Y20 E0.59245\nG0 F3600 X121.5 Y20\nG1 F1200 X121.5 Y10 E0.59245\nG0 F3600 X122 Y10\nG1 F1200 X122 Y20 E0.59245\nG0 F3600 X122.5 Y20\nG1 F1200 X122.5 Y10 E0.59245\nG0 F3600 X123 Y10\nG1 F1200 X123 Y20 E0.59245\nG0 F3600 X123.5 Y20\nG1 F1200 X123.5 Y10 E0.59245\nG0 F3600 X124 Y10\nG1 F1200 X124 Y20 E0.59245\nG0 F3600 X124.5 Y20\nG1 F1200 X124.5 Y10 E0.59245\nG0 F3600 X125 Y10\nG1 F1200 X125 Y20 E0.59245\nG0 F3600 X125.5 Y20\nG1 F1200 X125.5 Y10 E0.59245\nG0 F3600 X126 Y10\nG1 F1200 X126 Y20 E0.59245\nG0 F3600 X126.5 Y20\nG1 F1200 X126.5 Y10 E0.59245\nG0 F3600 X127 Y10\nG1 F1200 X127 Y20 E0.59245\nG0 F3600 X127.5 Y20\nG1 F1200 X127.5 Y10 E0.59245\nG0 F3600 X128 Y10\nG1 F1200 X128 Y20 E0.59245\nG0 F3600 X128.5 Y20\nG1 F1200 X128.5 Y10 E0.59245\nG0 F3600 X129 Y10\nG1 F1200 X129 Y20 E0.59245\nG0 F3600 X129.5 Y20\nG1 F1200 X129.5 Y10 E0.59245\nG0 F3600 X130 Y10\nG1 F1200 X130 Y20 E0.59245\nG0 F3600 X130.5 Y20\nG1 F1200 X130.5 Y10 E0.59245\nG0 F3600 X131 Y10\nG1 F1200 X131 Y20 E0.59245\nG0 F3600 X131.5 Y20\nG1 F1200 X131.5 Y10 E0.59245\nG0 F3600 X132 Y10\nG1 F1200 X132 Y20 E0.59245\nG0 F3600 X132.5 Y20\nG1 F1200 X132.5 Y10 E0.59245\nG0 F3600 X133 Y10\nG1 F1200 X133 Y20 E0.59245\nG0 F3600 X133.5 Y20\nG1 F1200 X133.5 Y10 E0.59245\nG0 F3600 X134 Y10\nG1 F1200 X134 Y20 E0.59245\nG0 F3600 X134.5 Y20\nG1 F1200 X134.5 Y10 E0.59245\nG0 F3600 X135 Y10\nG1 F1200 X135 Y20 E0.59245\nG0 F3600 X135.5 Y20\nG1 F1200 X135.5 Y10 E0.59245\nG0 F3600 X136 Y10\nG1 F1200 X136 Y20 E0.59245\nG0 F3600 X136.5 Y20\nG1 F1200 X136.5 Y10 E0.59245\nG0 F3600 X137 Y10\nG1 F1200 X137 Y20 E0.59245\nG0 F3600 X137.5 Y20\nG1 F1200 X137.5 Y10 E0.59245\nG0 F3600 X138 Y10\nG1 F1200 X138 Y20 E0.59245\nG0 F3600 X138.5 Y20\nG1 F1200 X138.5 Y10 E0.59245\nG0 F3600 X139 Y10\nG1 F1200 X139 Y20 E0.59245\nG0 F3600 X139.5 Y20\nG1 F1200 X139.5 Y10 E0.59245\nG0 F3600 X140 Y10\nG1 F1200 X140 Y20 E0.59245\nG0 F3600 X140.5 Y20\nG1 F1200 X140.5 Y10 E0.59245\nG0 F3600 X141 Y10\nG1 F1200 X141 Y20 E0.59245\nG0 F3600 X141.5 Y20\nG1 F1200 X141.5 Y10 E0.59245\nG0 F3600 X142 Y10\nG1 F1200 X142 Y20 E0.59245\nG0 F3600 X142.5 Y20\nG1 F1200 X142.5 Y10 E0.59245\nG0 F3600 X143 Y10\nG1 F1200 X143 Y20 E0.59245\nG0 F3600 X143.5 Y20\nG1 F1200 X143.5 Y10 E0.59245\nG0 F3600 X144 Y10\nG1 F1200 X144 Y20 E0.59245\nG0 F3600 X144.5 Y20\nG1 F1200 X144.5 Y10 E0.59245\nG0 F3600 X145 Y10\nG1 F1200 X145 Y20 E0.59245\nG0 F3600 X145.5 Y20\nG1 F1200 X145.5 Y10 E0.59245\nG0 F3600 X146 Y10\nG1 F1200 X146 Y20 E0.59245\nG0 F3600 X146.5 Y20\nG1 F1200 X146.5 Y10 E0.59245\nG0 F3600 X147 Y10\nG1 F1200 X147 Y20 E0.59245\nG0 F3600 X147.5 Y20\nG1 F1200 X147.5 Y10 E0.59245\nG0 F3600 X148 Y10\nG1 F1200 X148 Y20 E0.59245\nG0 F3600 X148.5 Y20\nG1 F1200 X148.5 Y10 E0.59245\nG0 F3600 X149 Y10\nG1 F1200 X149 Y20 E0.59245\nG0 F3600 X149.5 Y20\nG1 F1200 X149.5 Y10 E0.59245\nG0 F3600 X150 Y10\nG1 F1200 X150 Y20 E0.59245\nG0 F3600 X150.5 Y20\nG1 F1200 X150.5 Y10 E0.59245\nG0 F3600 X151 Y10\nG1 F1200 X151 Y20 E0.59245\nG0 F3600 X151.5 Y20\nG1 F1200 X151.5 Y10 E0.59245\nG0 F3600 X152 Y10\nG1 F1200 X152 Y20 E0.59245\nG0 F3600 X152.5 Y20\nG1 F1200 X152.5 Y10 E0.59245\nG0 F3600 X153 Y10\nG1 F1200 X153 Y20 E0.59245\nG0 F3600 X153.5 Y20\nG1 F1200 X153.5 Y10 E0.59245\nG0 F3600 X154 Y10\nG1 F1200 X154 Y20 E0.59245\nG0 F3600 X154.5 Y20\nG1 F1200 X154.5 Y10 E0.59245\nG0 F3600 X155 Y10\nG1 F1200 X155 Y20 E0.59245\nG0 F3600 X155.5 Y20\nG1 F1200 X155.5 Y10 E0.59245\nG0 F3600 X156 Y10\nG1 F1200 X156 Y20 E0.59245\nG0 F3600 X156.5 Y20\nG1 F1200 X156.5 Y10 E0.59245\nG0 F3600 X157 Y10\nG1 F1200 X157 Y20 E0.59245\nG0 F3600 X157.5 Y20\nG1 F1200 X157.5 Y10 E0.59245\nG0 F3600 X158 Y10\nG1 F1200 X158 Y20 E0.59245\nG0 F3600 X158.5 Y20\nG1 F1200 X158.5 Y10 E0.59245\nG1 X158.5 Y9.874\nG1 F2400 E-1.3\nG0 Z2\nG0 Y140\nG0 Z10\n"

/**
 * M822 IMADE3D_CALIBRATE_1ST_LAYER
 *
 */
void GcodeSuite::M822() {
  // CURRENT ISSUE: the print is quite long and cannot be stopped. Using M410 or M112 resets the printer connection... 
    //gcode.process_subcommands_now_P(PSTR(SETUP));
    //gcode.process_subcommands_now_P(PSTR(PRINT_LINE));
    if (axis_unhomed_error()) return;
    SERIAL_ECHOPGM("Use Z babystepping to calibrate the 1st layer");
    gcode.process_subcommands_now_P(PSTR(PRINT_FILL));
}
void GcodeSuite::M823() {
    return; //placeholder
}

void GcodeSuite::M824() {
  return; //placeholder
}

void GcodeSuite::M825() {
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
  gcode.process_subcommands_now_P(PSTR(TEST));
}

#endif // IMADE3D_CALIBRATE_1ST_LAYER
