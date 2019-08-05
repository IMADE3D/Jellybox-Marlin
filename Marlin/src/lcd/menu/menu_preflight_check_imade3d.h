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

#include "../../inc/MarlinConfigPre.h"
#include "menu.h"
#include "../../module/motion.h"
#include "../../module/planner.h"
#include "../../module/temperature.h"
#include "../../Marlin.h"

#if HAS_LEVELING
  #include "../../feature/bedlevel/bedlevel.h"
#endif

//
// Preflight variables below
//

// static bool longActionRunning;
// static bool printer_paused;
// static bool changing_home_offsets;

// static bool testing_nozzle;
// static bool testing_bed_heater = false;
// static bool testing_motors;

void menu_preflight_check();
void menu_test_nozzle();
void menu_test_bed();