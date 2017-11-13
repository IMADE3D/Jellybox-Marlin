# JB-Marlin 3D Printer Firmware
<img align="right" src="../../raw/1.1.x/buildroot/share/pixmaps/logo/marlin-250.png" />

# How and Why Upgrade JellyBOX Firmware

You can think of firmware as the sum of your printer's knowledge and skills. It's the contents of its imaginary brain. It's a piece of software directly controlling the motors and temperatures and interpreting the gcode. 

The firmware that came with your JellyBOX works fine, but if there is a newer firmware available, you should upgrade. We constantly work to bring you new features and fix any mistakes we may discover.  

## Upgrading the firmware takes only a few minutes and it's not difficult at all: 

1. You download the latest firmware from our website. 
2. You connect your JellyBOX to the computer with a USB cable
3. You run the upgrade procedure using Cura - the same program you are already using to slice your 3D models. 
4. That's it. 

Let me show you. 

- Go to the imade3d support page and download the latest firmware.
    - ![](https://i.imgur.com/JZS8vLg.png)
    - If you are tech inclined, you can always find the latest firmware ready to hack on our Github. https://github.com/IMADE3D/Marlin/releases
- Connect your JellyBOX to a computer with a USB cable. 
- Start Cura. Go to Settings > Printer > Manage Printers. 
  - ![](https://i.imgur.com/LcbgyQs.png)
- Select the Upgrade Firmware button. 
  - ![](https://i.imgur.com/ASCHe6t.png)
- Then, Upload custom Firmware. 
  - ![](https://i.imgur.com/DetdfS0.png)
- Select the file you just downloaded with .hex extension
- Wait a bit. 
- And it's done!
- Restart your JellyBOX.  Watch the splash screen and you will see your JellyBOX is running a new firmware version. 

## Compile JB-Marlin from Source

If you want to compile from source, you can. 

You have to use the correct Configuration.h file! Go to Marlin/JellyBOX_configurations and to find the one one need.

To use one of these configurations, simply copy it, and then paste and OVERWRITE the Configuration.h in Marlin folder.

Finally, compile and flash with the latest Arduino IDE (https://www.arduino.cc/). You will also need to have the U8GLIB library installed (from zip or through the Arduino library manager.)

## Marlin Documentation

For complete Marlin documentation click over to the [Marlin Homepage <marlinfw.org>](http://marlinfw.org/), where you will find in-depth articles, how-to videos, and tutorials on every aspect of Marlin, as the site develops. 

## Stable Release Branch

It's whatever is in Master branch. 

## Contributing to Marlin

Click on the [Issue Queue](https://github.com/MarlinFirmware/Marlin/issues) and [Pull Requests](https://github.com/MarlinFirmware/Marlin/pulls) links above at any time to see what the Marlin community is currently working on.

## Marlin Resources

- [Marlin Home Page](http://marlinfw.org/) - The Marlin Documentation Project. Join us!
- [RepRap.org Wiki Page](http://reprap.org/wiki/Marlin) - An overview of Marlin and its role in RepRap.
- [Marlin Firmware Forum](http://forums.reprap.org/list.php?415) - Find help with configuration, get up and running.
- [@MarlinFirmware](https://twitter.com/MarlinFirmware) on Twitter - Follow for news, release alerts, and tips & tricks. (Maintained by [@thinkyhead](https://github.com/thinkyhead).)

## Credits

The current Marlin dev team consists of:
 - Roxanne Neufeld [[@Roxy-3D](https://github.com/Roxy-3D)] - English
 - Scott Lahteine [[@thinkyhead](https://github.com/thinkyhead)] - English
 - Bob Kuhn [[@Bob-the-Kuhn](https://github.com/Bob-the-Kuhn)] - English
 - Andreas Hardtung [[@AnHardt](https://github.com/AnHardt)] - Deutsch, English
 - Nico Tonnhofer [[@Wurstnase](https://github.com/Wurstnase)] - Deutsch, English
 - Jochen Groppe [[@CONSULitAS](https://github.com/CONSULitAS)] - Deutsch, English
 - João Brazio [[@jbrazio](https://github.com/jbrazio)] - Portuguese, English
 - Bo Hermannsen [[@boelle](https://github.com/boelle)] - Danish, English
 - Bob Cousins [[@bobc](https://github.com/bobc)] - English
 - [[@maverikou](https://github.com/maverikou)]
 - Chris Palmer [[@nophead](https://github.com/nophead)]
 - [[@paclema](https://github.com/paclema)]
 - Erik van der Zalm [[@ErikZalm](https://github.com/ErikZalm)]
 - David Braam [[@daid](https://github.com/daid)]
 - Bernhard Kubicek [[@bkubicek](https://github.com/bkubicek)]

More features have been added by:
 - Alberto Cotronei [[@MagoKimbra](https://github.com/MagoKimbra)] - English, Italian
 - Thomas Moore [[@tcm0116](https://github.com/tcm0116)]
 - Ernesto Martinez [[@emartinez167](https://github.com/emartinez167)]
 - Petr Zahradnik [[@clexpert](https://github.com/clexpert)]
 - Kai [[@Kaibob2](https://github.com/Kaibob2)]
 - Edward Patel [[@epatel](https://github.com/epatel)]
 - F. Malpartida [[@fmalpartida](https://github.com/fmalpartida)] - English, Spanish
 - [[@esenapaj](https://github.com/esenapaj)] - English, Japanese
 - [[@benlye](https://github.com/benlye)]
 - [[@Tannoo](https://github.com/Tannoo)]
 - [[@teemuatlut](https://github.com/teemuatlut)]
 - [[@bgort](https://github.com/bgort)]
 - Luc Van Daele[[@LVD-AC](https://github.com/LVD-AC)] - Dutch, French, English
 - [[@paulusjacobus](https://github.com/paulusjacobus)]
 - ...and many others

The IMADE3D JB-Marlin team consists of
- Filip
- Ian
- Bruce
- Ladi
- and others

## License

Marlin is published under the [GPL license](https://github.com/COPYING.md) because we believe in open development. The GPL comes with both rights and obligations. 

While we can't prevent the use of this code in products (3D printers, CNC, etc.) that are closed source or crippled by a patent, we would prefer that you choose another firmware or, better yet, make your own.