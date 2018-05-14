//
// Test Script
//

#define imade3d_test_script "G28 X\nG28 Y"

//
//Calibrate PLA 1st Layer Script 
//
#define imade3d_calibrate_pla_1st_layer_script "G21\nG90\nM82\nM107\nM117 Preparing\nM109 S180\nG28\nM203 Z4\nG29\nM400\nM203 Z7\nG28 X\nM420 S1\nM400\nG0 Y0 F5000\nG0 Z15 F3000\nM109 S210\nM300 S440 P100\nG4 P200\nM300 S440 P100\nG4 P200\nM300 S440 P800\nM400\nM0 Live adjust Z height!\nM420 S1\nM117 Print starting\nG90\nG92 E0\nM420 S1\nG0 Z0\nM83\nG1 E22 F500\nG1 E18 F400\nG1 E10 F400\nG4 S2\nM400\nM420 S1\nG0 F500 X3 Y0 Z0.6\nG1 E2 F300\nG1 F1000 X104 E10\nM82\nG92 E0\nM107\nG0 F3600 X40.275 Y32.461 Z0.3\nG1 F840 X40.546 Y32.22 E0.01809\nG1 X40.863 Y32.053 E0.03597\nG1 X41.22 Y31.966 E0.0543\nG1 X41.58 Y31.966 E0.07226\nM117 Finishing Up\nM104 S0\nM140 S0\nG91\nG1 E-1 F300\nG1 Z+0.5 E-10 X-20 Y-20 F9000\nG1 E-15\nG90\nG28 X\nG1 Y140\nM84\nM117 Print finished\nM82" 

//
//Calibrate PETG 1st Layer Script 
//
#define imade3d_calibrate_petg_1st_layer_script "G28\nG29\nG90\nG92 E0\nG0 F500 X3 Y0 Z0.6\nG1 F1000 X104\nM82\nG92 E0\nM107\nG0 F3600 X40.275 Y32.461 Z0.3\nG1 F840 X40.546 Y32.22\nG1 X40.863 Y32.053\nG1 X41.22 Y31.966\nG1 X41.58 Y31.966\nM117 Finishing Up\nM104 S0\nM140 S0\nG91\nG1\nG1 Z+0.5\nG1\nG90\nG28 X\nG1 Y140\nM84\nM117 Print finished\nM82" 

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
#define imade3d_load_filament_script "M104 S325\nG28 X\nM84 X\nM109 S235 \nM84 E\nM300 S440 P500\nG4 P500\nM300 S440 P500\nM0 Insert filament now\nM117 Loading filament...\nG92 E0 \nG91\nM117 Loading 80mm...\nG1 F300 E5\nM400\nM117 Loading 75mm...\nG1 F300 E5\nM400\nM117 Loading 70mm...\nG1 F300 E5\nM400\nM117 Loading 65mm...\nG1 F300 E5\nM400\nM117 Loading 60mm...\nG1 F300 E5\nM400\nM117 Loading 55mm...\nG1 F300 E5\nM400\nM117 Loading 50mm...\nG1 F300 E5\nM400\nM117 Loading 45mm...\nG1 F300 E5\nM400\nM117 Loading 40mm...\nG1 F300 E5\nM400\nM117 Loading 35mm...\nG1 F275 E5\nM400\nM117 Loading 30mm...\nG1 F250 E5\nM400\nM117 Loading 25mm...\nG1 F225 E5\nM400\nM117 Loading 20mm...\nG1 F200 E5\nM400\nM117 Loading 15mm...\nG1 F200 E5\nM400\nM117 Loading 10mm...\nG1 F200 E5\nM400\nM117 Loading 5mm...\nG1 F200 E5\nM400\nG1 E-30 F2500 \nG90 \nG92 E0\nM84 E \nM104 S0\nM0 Filament loaded!"

//
// Eject Filament Script
//
#define imade3d_eject_filament_script "M109 S235 \nM117 Ejecting filament...\nG92 E90 \nG91 \n\nM117 Pre-Purging...\nG1 F350 E15\nM117 Ejecting 60mm...\nG1 F650 E-5\nM400\nM117 Ejecting 55mm...\nG1 F650 E-5\nM400\nM117 Ejecting 50mm...\nG1 F650 E-5\nM400\nM117 Ejecting 45mm...\nG1 F650 E-5\nM400\nM117 Ejecting 40mm...\nG1 F700 E-5\nM400\nM117 Ejecting 35mm...\nG1 F750 E-5\nM400\nM117 Ejecting 30mm...\nG1 F800 E-5\nM400\nM117 Ejecting 25mm...\nG1 F850 E-5\nM400\nM117 Ejecting 20mm...\nG1 F900 E-5\nM400\nM117 Ejecting 15mm...\nG1 F950 E-5\nM400\nM117 Ejecting 10mm...\nG1 F1000 E-5\nM400\nM117 Ejecting 5mm...\nG1 F1000 E-5\nM400\nM84 E \nM300 S440 P500 \nG4 P500\nM300 S440 P500 \nG90 \nG92 E0 \nM104 S0 \nM0 Unlock and pull out!"
