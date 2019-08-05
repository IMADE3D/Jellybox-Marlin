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

#include "menu_preflight_check_imade3d.h"
#include "../../lcd/menu/menu_preflight_check_imade3d.h"


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
// Preflight functions below
//

void lcd_return_to_status() {
   ui.return_to_status();
}

    /**
    *
    * Move axes Menu
    *
    */
  //   void lcd_move_axes_menu(){
  //     START_MENU();

  //     //
  //     // ^ Main
  //     //
  //     MENU_BACK(MSG_BACK);

  //     //
  //     // Abort if long action
  //     //
  //     if (longActionRunning && planner.movesplanned()){
  //       MENU_ITEM(function , MSG_ABORT , lcd_abort_action);
  //     }

  //     //
  //     // Move X
  //     //
  //     MENU_ITEM(submenu, MSG_MOVE_X, lcd_move_x_1mm);

  //     //
  //     // Move Y
  //     //
  //     MENU_ITEM(submenu, MSG_MOVE_Y, lcd_move_y_1mm);

  //     //
  //     // Move Z
  //     //
  //     MENU_ITEM(submenu, MSG_MOVE_Z, lcd_move_z_1mm);

  //     END_MENU();
  //   }

  //  /**
  //   *
  //   * Home Menu
  //   *
  //   */
  //   void lcd_home_menu(){
  //     START_MENU();

  //     //
  //     // ^ Main
  //     //
  //     MENU_BACK(MSG_BACK);

  //     //
  //     // Home X
  //     //
  //     MENU_ITEM(gcode, MSG_AUTO_HOME_X, PSTR("G28 X"));

  //     //
  //     // Home Y
  //     //
  //     MENU_ITEM(gcode, MSG_AUTO_HOME_Y, PSTR("G28 Y"));

  //     //
  //     // Home XYZ
  //     //
  //     MENU_ITEM(gcode, MSG_HOME_XYZ, PSTR("G28 X Y Z"));

  //     END_MENU();
  //   }

  //  /**
  //   *
  //   * 1 Test Motors Menu
  //   *
  //   */
  //   void lcd_test_motors_menu(){
  //     START_MENU();

  //     //
  //     // ^ Main
  //     //
  //     MENU_BACK(MSG_BACK);

  //     //
  //     // Move X
  //     //
  //     MENU_ITEM(submenu, MSG_MOVE_X, lcd_move_x_1mm);

  //     //
  //     // Move Y
  //     //
  //     MENU_ITEM(submenu, MSG_MOVE_Y, lcd_move_y_1mm);

  //     //
  //     // Move Z
  //     //
  //     enqueue_and_echo_commands_P(PSTR("M302 P1"));
  //     MENU_ITEM(submenu, MSG_MOVE_Z, lcd_move_z_1mm);

  //     //
  //     // Move E
  //     //
  //     MENU_ITEM(submenu,  MSG_MOVE_E,  lcd_move_e_1mm);

  //     END_MENU();
  //   }

  //  /**
  //   *
  //   * 2 Check Endstops Menu
  //   *
  //   */
  //   void lcd_check_endstops_menu(){
  //     START_MENU();

  //     //
  //     // ^ Main
  //     //
  //     MENU_BACK(MSG_BACK);

  //     //
  //     //Display X endstop status
  //     //

  //     MENU_ITEM(gcode, "Click to Update" , PSTR(""));

  //    #if HAS_X_MIN
  //      SERIAL_PROTOCOLPGM(MSG_X_MIN);
  //      SERIAL_PROTOCOLLN(((READ(X_MIN_PIN)^X_MIN_ENDSTOP_INVERTING) ? MSG_ENDSTOP_HIT : MSG_ENDSTOP_OPEN));

  //      if (READ(X_MIN_PIN)^X_MIN_ENDSTOP_INVERTING){
  //         STATIC_ITEM("X : Triggered          ");
  //      }
  //      else{
  //         STATIC_ITEM("X : Not Triggered      ");
  //      }

  //    #endif

  //     //
  //     // Display Y endstop status
  //     //

  //    #if HAS_Y_MIN
  //      SERIAL_PROTOCOLPGM(MSG_Y_MIN);
  //      SERIAL_PROTOCOLLN(((READ(Y_MIN_PIN)^Y_MIN_ENDSTOP_INVERTING) ? MSG_ENDSTOP_HIT : MSG_ENDSTOP_OPEN));

  //      if (READ(Y_MIN_PIN)^Y_MIN_ENDSTOP_INVERTING){
  //         STATIC_ITEM("Y : Triggered          ");
  //      }
  //      else{
  //         STATIC_ITEM("Y : Not Triggered      ");
  //      }

  //    #endif

  //     //
  //     // Display Z endstop status
  //     //
  //     //READ(Z_MIN_PROBE_PIN) != Z_MIN_PROBE_ENDSTOP_INVERTING)
  //    #if HAS_Z_MIN
  //      SERIAL_PROTOCOLPGM(MSG_Z_MIN);
  //      SERIAL_PROTOCOLLN(((READ(Z_MIN_PIN)^Z_MIN_ENDSTOP_INVERTING) ? MSG_ENDSTOP_HIT : MSG_ENDSTOP_OPEN));

  //      //if (READ(Z_MIN_PIN)^Z_MIN_ENDSTOP_INVERTING){
  //      if (READ(Z_MIN_PIN) != Z_MIN_ENDSTOP_INVERTING) {
  //         STATIC_ITEM("Z : Triggered          ");
  //      }
  //      else{
  //         STATIC_ITEM("Z : Not Triggered      ");
  //      }

  //    #endif

  //     END_MENU();
  //   }

  //  /**
  //   *
  //   * 3 Test Z Endstop Menu
  //   *
  //   */
  //   void lcd_test_z_endstop(){
  //     START_MENU();

  //     //
  //     // ^ Main
  //     //
  //     MENU_BACK(MSG_BACK);

  //     //
  //     // Warning
  //     //
  //     STATIC_ITEM("!  Prerequisites  !     ");
  //     STATIC_ITEM("-Setup Z probe height   " );
  //     STATIC_ITEM("-Test X and test Y      ");

  //     //
  //     // Home Z
  //     //
  //     MENU_ITEM(gcode, MSG_TEST_Z_ENDSTOP, PSTR("G28 Z"));

  //     END_MENU();
  //   }

   /**
    *
    * 3 Test Endstops Menu
    *
    */
    // void lcd_test_endstops_menu(){
    //   START_MENU();

    //   //
    //   // ^ Main
    //   //
    //   MENU_BACK(MSG_BACK);

    //   //
    //   // Home X
    //   //
    //   MENU_ITEM(gcode, MSG_TEST_X_ENDSTOP, PSTR("G28 X"));

    //   //
    //   // Home Y
    //   //
    //   MENU_ITEM(gcode, MSG_TEST_Y_ENDSTOP, PSTR("G28 Y"));

    //   //
    //   // Home XYZ
    //   //
    //   MENU_ITEM(submenu, MSG_TEST_Z_ENDSTOP, lcd_test_z_endstop);

    //   END_MENU();
    // }

    // void lcd_change_x_home_offset_msg1_menu(){
    //     START_MENU();

    //     STATIC_ITEM("Position the          ");
    //     STATIC_ITEM("nozzle over           ");
    //     STATIC_ITEM("the left edge of      ");
    //     STATIC_ITEM("the build plate.      ");
    //     STATIC_ITEM(" - Click to continue -");


    //     if(lcd_clicked) {
    //       lcd_goto_screen(lcd_move_x_01mm);
    //     }

    //     END_MENU();

    // }

    // void change_x_home_offset(){

    //   enqueue_and_echo_commands_P(PSTR("G28"));
    //   enqueue_and_echo_commands_P(PSTR("G0 Z0 Y0 X0"));
    //   changing_home_offsets = true;
    //   lcd_goto_screen(lcd_change_x_home_offset_msg1_menu);
    // }

   /**
    *
    * 4 Set Origin Menu
    *
    */
    // void lcd_set_origin_menu(){
    //   START_MENU();

    //   //
    //   // ^ Main
    //   //
    //   MENU_BACK(MSG_BACK);

    //   //
    //   // Home XYZ
    //   //
    //   MENU_ITEM(function, MSG_CHANGE_X_HOME_OFFSET, change_x_home_offset);
    //   //MENU_ITEM(gcode, MSG_SET_HOME_OFFSETS, PSTR("M428"));

    //   //
    //   // Message
    //   //
    //   STATIC_ITEM("? This procedure will     ");
    //   STATIC_ITEM("ensure you can use the  ");
    //   STATIC_ITEM("whole build plate.       ");

    //   END_MENU();
    // }

   /**
    *
    * 5 Test auto bed level menu
    *
    */
    // void lcd_test_auto_bed_level_menu(){
    //   START_MENU();

    //   //
    //   // ^ Main
    //   //
    //   MENU_BACK(MSG_BACK);

    //   //
    //   // Home XYZ
    //   //
    //   MENU_ITEM(gcode, MSG_TEST_AUTO_BED_LEVEL, PSTR("G28\nG29"));

    //   //
    //   // Message
    //   //
    //   STATIC_ITEM("! Make sure to insert   ");
    //   STATIC_ITEM("the removable         ");
    //   STATIC_ITEM("build plate.           ");

    //   END_MENU();
    // }

   /**
    *
    * 6 Test Nozzle Heater
    *
    */

    // void lcd_test_nozzle_menu(){

    //   enqueue_and_echo_commands_P(PSTR("M104 S35"));
    //   testing_nozzle = true;
    //   lcd_setstatusPGM(PSTR(".Click to stop heating and go back to Preflight"), -1);
    //   lcd_return_to_status();

    // }

   /**
    *
    * 7 Test Bed Heater
    *
    */
    void lcd_test_bed_menu(){
      enqueue_and_echo_commands_P(PSTR("M140 S35"));
      // testing_bed_heater = true;
      // lcd_setstatusPGM(PSTR(".Click to stop heating and go back to Preflight"), -1);
      ui.set_status_P(PSTR("Is the bed heating up?"), -1);
      lcd_return_to_status();
    }

/**
*
* The MAIN PREFLIGHT SUBMENU BELOW
*
*/

void menu_preflight_check() {
  START_MENU();
  MENU_BACK(MSG_MAIN);

  enqueue_and_echo_commands_P(PSTR("M104 S0")); // always disable nozzle heater when entering the Preflight as a safety feature
  enqueue_and_echo_commands_P(PSTR("M140 S0")); // always disable bed heater when entering the Preflight as a safety feature

    //
    // 1 Test Motors
    //
    // MENU_ITEM(submenu, MSG_TEST_MOTORS, lcd_test_motors_menu);

    //
    // 2 Endstop status
    //
    // MENU_ITEM(submenu, MSG_CHECK_ENDSTOPS, lcd_check_endstops_menu);

    //
    // 3 Test endstops
    //
    // MENU_ITEM(submenu, MSG_TEST_ENDSTOPS, lcd_test_endstops_menu);

    //
    // 4 Set (X) origin
    //
    // MENU_ITEM(submenu, MSG_SET_ORIGIN_PREFLIGHT, lcd_set_origin_menu);

    //
    // 5 Test auto bed level
    //
    // MENU_ITEM(submenu, MSG_TEST_AUTO_BED_LEVEL_PREFLIGHT, lcd_test_auto_bed_level_menu);

    //
    // 6 Test nozzle heater
    //
    // MENU_ITEM(function, MSG_TEST_NOZZLE, lcd_test_nozzle_menu);

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
