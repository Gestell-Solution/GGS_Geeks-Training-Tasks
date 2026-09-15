# Code document
The bluetooth module "HC-05" is used for wireless communication it work on UART driver .</p>
1- we write the UART drive.</p>
2- we choose the pins which are TX AND RX from atmega32 the TX as input and RX as output .</p>
3- i make a bluetooth driver to setup the uart by :</p>
 1. selecting mode = uart asynchronous.</p>
 2. stop bit = 1 stop bit.</p>
 3. parity = no parity.</p>
 4. speed mode =normal.</p>
 5. baud rate = 9600.</p>
 6. size of the character = 8 bit .</p>
 7. select is for enabling TX only or RX only or both i used both.</p>
 8. interrupt = disable.</p>

4- still in the same bluetooth driver ,i make a variable to store the coming data.</p>
5- In the main.c init the leds and bluetooth module and make a variable to receive the data  and in while(1) i receive the coming data and then i use __if statement__ to see if the received data is the same as what i want if yes i do the command and they are :</p>
  's' for start green led .</p>
  'p' for pause red led.</p>
  'w' for wait yellow led.</p>
  'a' for all it close all the leds .</p>