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

#include "../../inc/MarlinConfig.h"

#include "../../inc/MarlinConfigPre.h"
#include "menu.h"

#if HAS_LCD_MENU

#include "menu.h"
#include "../../module/motion.h"
#include "../../module/planner.h"
#include "../../module/temperature.h"
#include "../../Marlin.h"

#if HAS_LEVELING
  #include "../../feature/bedlevel/bedlevel.h"
#endif

//
// The MAIN PREFLIGHT SUBMENU BELOW
//

void menu_preflight_check() {
  START_MENU();
  MENU_BACK(MSG_MAIN);

    //
    // 1 Test Motors
    //
    MENU_ITEM(submenu, MSG_TEST_MOTORS, lcd_test_motors_menu);

    //
    // 2 Endstop status
    //
    MENU_ITEM(submenu, MSG_CHECK_ENDSTOPS, lcd_check_endstops_menu);

    //
    // 3 Test endstops
    //
    MENU_ITEM(submenu, MSG_TEST_ENDSTOPS, lcd_test_endstops_menu);

    //
    // 4 Set (X) origin
    //
    MENU_ITEM(submenu, MSG_SET_ORIGIN_PREFLIGHT, lcd_set_origin_menu);

    //
    // 5 Test auto bed level
    //
    MENU_ITEM(submenu, MSG_TEST_AUTO_BED_LEVEL_PREFLIGHT, lcd_test_auto_bed_level_menu);

    //
    // 6 Test nozzle heater
    //
    MENU_ITEM(function, MSG_TEST_NOZZLE, lcd_test_nozzle_menu);

    //
    // 7 Test bed heater
    //
    MENU_ITEM(function, MSG_TEST_BED, lcd_test_bed_menu);

    //
    // 8 Test Filament Fans
    //
    MENU_ITEM(gcode, MSG_TEST_FILAMENT_FANS, PSTR("M106 S255\nG4 S1\nM106 S130\nG4 S1\nM106 S0"));

  END_MENU(); // menu_preflight_check
}

#endif //  HAS_LCD_MENU // not yet && ENABLED(PREFLIGHT_CHECK_IMADE3D)
