# There are 4 things to change

[x] increment the version number
[-] SettingsDataStruct , you add your data structures you want to save to this (is only used in calculating EEPROM size)
[-] modify MarlinSettings::save to save your data
[-] modify MarlinSettings::_load to load your data