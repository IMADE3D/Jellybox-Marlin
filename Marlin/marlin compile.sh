#This scripts compiles all the JellyBOX versions with Arduino-cli. Yay. 

### DEFINE MARLIN VERSION
marlin_version="jb_marlin_3.0_dev2"

### WHICH JellyBOX VERSIONS TO COMPILE?

jellybox_2_cold_bed="1"
jellybox_2_heated_bed="1"
jellybox_original_cold_bed_one_fan_green_probe="1"
jellybox_original_cold_bed_one_fan_yellow_probe="1"
jellybox_original_cold_bed_two_fans="1"
jellybox_original_heated_bed_one_fan_green_probe="1"
jellybox_original_heated_bed_one_fan_yellow_probe="1"
jellybox_original_heated_bed_two_fans="1"

### MODIFY THESE FOLDERS IF NEEDED
root_dir="/Users/filipgoc/Documents/OneDrive/imade3d-onedrive/GITHUB/Marlin-githubapp/Marlin-JB-4"
marlin_dir=${root_dir}"/Marlin"
conf_dir="/Users/filipgoc/Documents/OneDrive/imade3d-onedrive/GITHUB/Marlin-githubapp/Marlin-JB-4/Marlin/jellybox-configs"
hex_dir="/Users/filipgoc/Documents/OneDrive/imade3d-onedrive/GITHUB/Marlin-githubapp/Marlin-JB-4/Marlin/hex-files"
echo $l \\nRoot: $root_dir \\nMarlin: $marlin_dir \\nConfigs: $conf_dir \\nHex: $hex_dir

### INIT
clear
l="--------------"
echo $l\\n"==== INITIALIZING ===="\\n$l\\n$l
# increase the opened files limit (needed for arduino-cli; it's a bug I think)
ulimit -S -n 1000
#archive old config
cd $marlin_dir
date=`date +%d-%m-%y_%H-%M`
mv -v Configuration.h _Configuration-ARCHIVE-$date.h
echo $l \\n'Archived the old config (or not)'
echo \\n\\n"==== COMPILING ===="\\n\\n\\n

#####################################
### jellybox_2_cold_bed
#####################################
if [ 1 = $jellybox_2_cold_bed ]
then
    jb_version="jellybox_2_cold_bed"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_2_heated_bed
#####################################
if [ 1 = $jellybox_2_heated_bed ]
then
    jb_version="jellybox_2_heated_bed"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_original_cold_bed_one_fan_green_probe
#####################################
if [ 1 = $jellybox_original_cold_bed_one_fan_green_probe ]
then
    jb_version="jellybox_original_cold_bed_one_fan_green_probe"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_original_cold_bed_one_fan_yellow_probe
#####################################
if [ 1 = $jellybox_original_cold_bed_one_fan_yellow_probe ]
then
    jb_version="jellybox_original_cold_bed_one_fan_yellow_probe"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_original_cold_bed_two_fans
#####################################
if [ 1 = $jellybox_original_cold_bed_two_fans ]
then
    jb_version="jellybox_original_cold_bed_two_fans"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_original_heated_bed_one_fan_green_probe
#####################################
if [ 1 = $jellybox_original_heated_bed_one_fan_green_probe ]
then
    jb_version="jellybox_original_heated_bed_one_fan_green_probe"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_original_heated_bed_one_fan_yellow_probe
#####################################
if [ 1 = $jellybox_original_heated_bed_one_fan_yellow_probe ]
then
    jb_version="jellybox_original_heated_bed_one_fan_yellow_probe"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#####################################
### jellybox_original_heated_bed_two_fans
#####################################
if [ 1 = $jellybox_original_heated_bed_two_fans ]
then
    jb_version="jellybox_original_heated_bed_two_fans"
    echo "==== NOW COMPILING: "$jb_version" ===="\\n
    hex_name=$marlin_version'-'$jb_version
    cd $conf_dir
    cp -v -f ${jb_version}.h ../Configuration.h
    echo $l \\n'Loaded the new config'\\n$l
    cd $root_dir
    #arduino-cli compile --fqbn arduino:avr:mega Marlin
    echo 'it werks' >Marlin/Marlin.arduino.avr.mega.hex
    cd $hex_dir
    mv -v ../Marlin.arduino.avr.mega.hex ${hex_name}.hex
    rm ../Marlin.arduino.avr.mega.elf
    echo $l \\n${jb_version}' HEX exported, yo!'\\n$l\\n\\n\\n
fi

#define JELLYBOX_VARIANT_LINE1 "JellyBOX 1.3, one fan"
#define JELLYBOX_VARIANT_LINE2 "cold bed, green probe"

#define JELLYBOX_VARIANT_LINE1 "JellyBOX 1.3, one fan"
#define JELLYBOX_VARIANT_LINE2 "cold bed, yellow probe"

#define JELLYBOX_VARIANT_LINE1 "JellyBOX 1.3"
#define JELLYBOX_VARIANT_LINE2 "cold bed, two fans"

#define JELLYBOX_VARIANT_LINE1 "JellyBOX 1.3, one fan"
#define JELLYBOX_VARIANT_LINE2 "hot bed, green probe"

#define JELLYBOX_VARIANT_LINE1 "JellyBOX 1.3, one fan"
#define JELLYBOX_VARIANT_LINE2 "hot bed, yellow probe"

#define JELLYBOX_VARIANT_LINE1 "JellyBOX 1.3"
#define JELLYBOX_VARIANT_LINE2 "hot bed, two fans"