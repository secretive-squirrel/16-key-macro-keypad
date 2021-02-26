# 16-key-macro-keypad
16 key macro keypad for Arduino Pro Micro

============================================================================
     SECRETIVE SQUIRREL STUDIOS ~ LAZY EDITING KEYPAD
     Code for Pro-Micro (32u4 processor)
     Currently set up for Photoshop.
     
     Instantiates a 4x4 button matrix and sends keyboard 
     commands/presses to the computer when buttons are pressed.
     This is set up for single keypresses only.
     
     This was set up for Windows - Some key addresses may be 
     different in Mac, read up on the <KEYBOARD> Arduino 
     library reference to see the differences.
     
     ONLY SEND KEY COMMANDS IN RESPONSE TO A BUTTON PRESS OR SIMILAR 
     SORT OF STIMULUS - DON'T SET IT TO JUST KEEP TALKING CONSTANTLY.
     IF THE DEVICE IS SENDING KEY COMMANDS, THIS WILL INTERFERE WITH 
     PROGRAMMING - THERE IS A RISK YOU WILL BRICK YOUR PRO MICRO
     BECAUSE IT WON'T SHUT UP AND LISTEN TO THE PROGRAMMER. 
     THAT CAN BE FIXED, BUT IT'S A PAIN IN THE TAIL - I'VE NOT DONE
     IT SO I DON'T KNOW HOW YOU'D FIX IT - USE THE SERIAL PORT TO TEST
     THE FUNCTIONALITY BEFORE GOING HOG WILD.
     
     This uses a switch on pin 10 in order to
     select between two tasks according to whether pin 10 is 
     high or low at the time of the button press. I.E. set up for 
     use with two different programs according to the switch.
     
     The code simulates keyboard inputs according to which button is 
     pressed, these can be complex messages with multiple key presses.
     You can also write strings, look at the <KEYBOARD> library reference
     in the Arduino website for how to do this.
     
     This code was modified from the 'Multikey' example written by Mark 
     Stanley from the <KEYPAD> library written by  Mark Stanley and 
     Alexander Brevig  
     The keypad library can be found for in the library manager in arduino. 
     Go to Library manager and search for 'KEYPAD', select the one written by
     Mark Stanley and Alexander Brevig.
     Some code was also borrowed from brian lough's tutorial called 'The simplest diy macro keypad'
     I've just cobbled them together and set it up for photoshop shortcuts (and commented lots).
      
      For 32u4 Pro Micro
      Sketch uses 8160 bytes (28%) of program storage space. Maximum is 28672 bytes.
      Global variables use 557 bytes (21%) of dynamic memory, leaving 1963 bytes 
      for local variables. Maximum is 2560 bytes.
    
============================================================================
 
 A fritzing diagram. I'm using the wrong micro in this image. It's the only one I could find which lined up for the pins.
 The pro micro pins 2-5 are reading the columns, pins 6-9 are reading the rows. (I used a library, so I don't know which pins are high/low and which pins are read)
 The switch has power going to the center pin and led's attached to the sides so the switch supplies power - one arm of the switch is attached to pin 10 which also has a 10k pull down resistor attached to ground.
 ![fritz](https://user-images.githubusercontent.com/39419544/109363481-8fcd9b00-78f1-11eb-89c5-80b19dbe5c40.JPG)
The wires are crossing over because the keypad is flipped in my application (set into the lid of a flip open box).

This is what it looks like in real life.
![20210227_115017](https://user-images.githubusercontent.com/39419544/109363846-5f3a3100-78f2-11eb-9446-2093c213a6dd.jpg)
A more normal schematic - though I'm missing the 10k pull down resistor attached to pin 10 here.
![20210227_120434](https://user-images.githubusercontent.com/39419544/109364798-7548f100-78f4-11eb-927d-61fef3c2d793.jpg)

![20210222_085715](https://user-images.githubusercontent.com/39419544/109363817-4df12480-78f2-11eb-9ef9-15ef679e697b.jpg)
Asthetics n' all that, I used an old protractor case for my build. It's got rubber feet so as it skates about my desk less.
![20210226_191347](https://user-images.githubusercontent.com/39419544/109363836-5a757d00-78f2-11eb-8fe1-45667ed55e22.jpg)
