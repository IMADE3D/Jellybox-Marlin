//
// Test Script
//

#define imade3d_test_script "G28 X\nG28 Y"

//
//Calibrate PLA 1st Layer Script 
//
#define imade3d_calibrate_pla_1st_layer_script "G29" 

//
//Calibrate PETG 1st Layer Script 
//
#define imade3d_calibrate_petg_1st_layer_script "G29" 

//
//Calibrate FLEX 1st Layer Script 
//
#define imade3d_calibrate_flex_1st_layer_script "G29" 

//
//Calibrate CUSTOM 1st Layer Script 
//
#define imade3d_calibrate_custom_1st_layer_script "G29" 

//
// Load Filament Script
//
#define imade3d_load_filament_script "M109 S235 \nM84 E\nM300 S440 P500\nG4 P500\nM300 S440 P500\nM0 Insert filament now\nM117 Loading filament...\nG92 E0 \nG91\nM117 Loading 80mm...\nG1 F300 E5\nM400\nM117 Loading 75mm...\nG1 F300 E5\nM400\nM117 Loading 70mm...\nG1 F300 E5\nM400\nM117 Loading 65mm...\nG1 F300 E5\nM400\nM117 Loading 60mm...\nG1 F300 E5\nM400\nM117 Loading 55mm...\nG1 F300 E5\nM400\nM117 Loading 50mm...\nG1 F300 E5\nM400\nM117 Loading 45mm...\nG1 F300 E5\nM400\nM117 Loading 40mm...\nG1 F300 E5\nM400\nM117 Loading 35mm...\nG1 F275 E5\nM400\nM117 Loading 30mm...\nG1 F250 E5\nM400\nM117 Loading 25mm...\nG1 F225 E5\nM400\nM117 Loading 20mm...\nG1 F200 E5\nM400\nM117 Loading 15mm...\nG1 F200 E5\nM400\nM117 Loading 10mm...\nG1 F200 E5\nM400\nM117 Loading 5mm...\nG1 F200 E5\nM400\nG1 E-30 F2500 \nG90 \nG92 E0\nM84 E \nM104 S0\nM0 Filament loaded!"

//
// Eject Filament Script
//
#define imade3d_eject_filament_script "M109 S235 \nM117 Ejecting filament...\nG92 E90 \nG91 \n\nM117 Pre-Purging...\nG1 F350 E15\nM117 Ejecting 60mm...\nG1 F650 E-5\nM400\nM117 Ejecting 55mm...\nG1 F650 E-5\nM400\nM117 Ejecting 50mm...\nG1 F650 E-5\nM400\nM117 Ejecting 45mm...\nG1 F650 E-5\nM400\nM117 Ejecting 40mm...\nG1 F700 E-5\nM400\nM117 Ejecting 35mm...\nG1 F750 E-5\nM400\nM117 Ejecting 30mm...\nG1 F800 E-5\nM400\nM117 Ejecting 25mm...\nG1 F850 E-5\nM400\nM117 Ejecting 20mm...\nG1 F900 E-5\nM400\nM117 Ejecting 15mm...\nG1 F950 E-5\nM400\nM117 Ejecting 10mm...\nG1 F1000 E-5\nM400\nM117 Ejecting 5mm...\nG1 F1000 E-5\nM400\nM84 E \nM300 S440 P500 \nG4 P500\nM300 S440 P500 \nG90 \nG92 E0 \nM104 S0 \nM0 Pull filament out!"
