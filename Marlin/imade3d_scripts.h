//
// Test Script
//

#define imade3d_test_script "G28 X\nG28 Y"

//
// Load Filament Script
//
#define imade3d_load_filament_script "M109 S235 \nM84 E\nM300 S440 P500\nG4 P500\nM300 S440 P500\nM0 Insert filament now\nM117 Loading filament...\nG92 E0 \nG91\nM117 Loading 80mm...\nG1 F300 E5\nM400\nM117 Loading 75mm...\nG1 F300 E5\nM400\nM117 Loading 70mm...\nG1 F300 E5\nM400\nM117 Loading 65mm...\nG1 F300 E5\nM400\nM117 Loading 60mm...\nG1 F300 E5\nM400\nM117 Loading 55mm...\nG1 F300 E5\nM400\nM117 Loading 50mm...\nG1 F300 E5\nM400\nM117 Loading 45mm...\nG1 F300 E5\nM400\nM117 Loading 40mm...\nG1 F300 E5\nM400\nM117 Loading 35mm...\nG1 F275 E5\nM400\nM117 Loading 30mm...\nG1 F250 E5\nM400\nM117 Loading 25mm...\nG1 F225 E5\nM400\nM117 Loading 20mm...\nG1 F200 E5\nM400\nM117 Loading 15mm...\nG1 F200 E5\nM400\nM117 Loading 10mm...\nG1 F200 E5\nM400\nM117 Loading 5mm...\nG1 F200 E5\nM400\nG1 E-30 F3000 \nG90 \nG92 E0\nM84 E \nM104 S0\nM0 Filament loaded!\nM117 Done."

//
// Eject Filament Script
//
#define imade3d_eject_filament_script "M109 S235\nM117 Ejecting filament...\nG92 E90 \nG91\nM117 Ejecting 45mm...\nG1 F650 E-5\nM400\nM117 Ejecting 40mm...\nG1 F700 E-5\nM400\nM117 Ejecting 35mm...\nG1 F750 E-5\nM400\nM117 Ejecting 30mm...\nG1 F800 E-5\nM400\nM117 Ejecting 25mm...\nG1 F850 E-5\nM400\nM117 Ejecting 20mm...\nG1 F900 E-5\nM400\nM117 Ejecting 15mm...\nG1 F950 E-5\nM400\nM117 Ejecting 10mm...\nG1 F1000 E-5\nM400\nM117 Ejecting 5mm...\nG1 F1000 E-5\nM400\nM84 E\nM300 S440 P500\nG4 P500\nM300 S440 P500\nG90\nG92 E0\nM104 S0\nM0 Pull filament out!\nM117 Done."



// Here are the scripts ready to be put on an SD card. Good for visual check.
/**
* ; Load new filament
* M109 S235        ;heat up to 235C
* M84 E            ;release the E motor
* M300 S440 P500  ;play tone
* G4 P500
* M300 S440 P500  ;play tone
* M0 Insert filament now
* M117 Loading filament...
* G92 E0           ;reset the extruder position
* G91              ;relative positioning
* ;load 60x5mm (Stoppable)
* M117 Loading 80mm...
* G1 F300 E5
* M400
* M117 Loading 75mm...
* G1 F300 E5
* M400
* M117 Loading 70mm...
* G1 F300 E5
* M400
* M117 Loading 65mm...
* G1 F300 E5
* M400
* M117 Loading 60mm...
* G1 F300 E5
* M400
* M117 Loading 55mm...
* G1 F300 E5
* M400
* M117 Loading 50mm...
* G1 F300 E5
* M400
* M117 Loading 45mm...
* G1 F300 E5
* M400
* M117 Loading 40mm...
* G1 F300 E5
* M400
* M117 Loading 35mm...
* G1 F275 E5
* M400
* M117 Loading 30mm...
* G1 F250 E5
* M400
* M117 Loading 25mm...
* G1 F225 E5
* M400
* M117 Loading 20mm...
* G1 F200 E5
* M400
* M117 Loading 15mm...
* G1 F200 E5
* M400
* M117 Loading 10mm...
* G1 F200 E5
* M400
* M117 Loading 5mm...
* G1 F200 E5
* M400
* G1 E-30 F3000   ;retract to minimize oozing
* G90             ;Absolute Positioning
* G92 E0          ;reset the extruder position
* M84 E           ;release the E motor
* M104 S0         ;extruder heater off
* M0 Filament loaded!
* M117 Done. 
*
*
*
* ; Eject the Filament
* M109 S235               ;wait to heat up to 235C
* M117 Ejecting filament...
* G92 E90                 ;set extruder at 90mm...
* G91                     ;relative positioning
* ;eject 45x5mm (Stoppable)
* M117 Ejecting 45mm...
* G1 F650 E-5
* M400
* M117 Ejecting 40mm...
* G1 F700 E-5
* M400
* M117 Ejecting 35mm...
* G1 F750 E-5
* M400
* M117 Ejecting 30mm...
* G1 F800 E-5
* M400
* M117 Ejecting 25mm...
* G1 F850 E-5
* M400
* M117 Ejecting 20mm...
* G1 F900 E-5
* M400
* M117 Ejecting 15mm...
* G1 F950 E-5
* M400
* M117 Ejecting 10mm...
* G1 F1000 E-5
* M400
* M117 Ejecting 5mm...
* G1 F1000 E-5
* M400
* M84 E     ;release the E motor
* M300 S440 P500  ;play tone
* G4 P500
* M300 S440 P500  ;play tone
* G90       ;absolute positioning
* G92 E0    ;zero the extruder
* M104 S0   ;extruder heater off
* M0 Pull filament out!
* M117 Done.
*/
