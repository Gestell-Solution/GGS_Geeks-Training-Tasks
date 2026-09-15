# how to make the bluetooth module work on proteus

1-you download the bluetooth module "HC-05" is the one i used and add it to proteus library.</p>
2-open a new project and add atmega32,2 from bluetooth module ,leds and 2 virtual terminal .</p>
3-connect the leds to any pins in the atmega32 then 
you take the first terminal and bluetooth module and attach them like this </p>

* __atmega with bluetooth connection__

|atmega32   pins |bluetooth module pin|
|----------------|--------------------|
| PD0/RXD        |  -->bluetooth TX   |
| PD1/TXD        |  -->bluetooth RX   |

* __virtual terminal with bluetooth connection__

|bluetooth module 1 pin|virtual terminal 1 pins|
|-----------------------|----------------------|
|  bluetooth TX         | virtual RXD          |
|  bluetooth RX         | virtual TXD          |

4-know you take the second virtual terminal with the second bluetooth module.</p>

|bluetooth module 2 pin|virtual terminal 2 pins|
|-----------------------|----------------------|
|  bluetooth TX         | virtual RXD          |
|  bluetooth RX         | virtual TXD          |

5- check that every bluetooth module have these listed thing thy must be same or they wont work except for the physical port one. </p>
  1. virtual baud rate must equal each other they are 9600 that is what i made for me .</p>
  2. virtual data bits should be 8.</p>
  3. virtual parity NONE .</p>
  4. version 1.0.</p>
  5. advance properties dont get near it dont touch it we dont need it.</p>
  6. the physical port should be any number but i used com4 for bluetooth module 2 and com3 for bluetooth module 1.</p>

6- know download the app that will connect the bluetooth module with each other you have two apps one called "vspe" stand for "Virtual Serial Ports Emulator "  that can be download from <a href ="https://eterlogic.com/Products.VSPE_Download.html">HERE</a> or "cvspd" stand for "config Virtual Serial Port Driver" you can download from <a href ="https://www.virtual-serial-port.org/user-guides/standard/installation.html">HERE</a> 
 1. lets begin with "VSPE" you download it and open it then you press device then create then devise type choose pair then next choose the same com you choosed for your bluetooth module then press the play button then open protues run the simulation and the bluetooth module shape should change and work acording to how you programed it .</p>
2. if you are going to use "cvspd" you open it add pair enter the com you choosed then open protues run the simulation they should change there shape.</p>

7-the terminal will open for you when you run the simulation write there what you coded for me it was :</p>
  's' for start green led .</p>
  'p' for pause red led.</p>
  'w' for wait yellow led.</p>
  'a' for all it close all the leds .</p>
when you write them write them as spwa with or without space it work ethier way i hope it work with you.