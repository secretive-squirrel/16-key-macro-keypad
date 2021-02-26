# 16-key-macro-keypad
16 key macro keypad for Arduino Pro Micro

/***************************************************************************
 *    SECRETIVE SQUIRREL STUDIOS ~ LAZY EDITING KEYPAD
 *    Code for Pro-Micro (32u4 processor)
 *    Currently set up for Photoshop.
 *    
 *    Instantiates a 4x4 button matrix and sends keyboard 
 *    commands/presses to the computer when buttons are pressed.
 *    This is set up for single keypresses only.
 *    
 *    This was set up for Windows - Some key addresses may be 
 *    different in Mac, read up on the <KEYBOARD> Arduino 
 *    library reference to see the differences.
 *    
 *    ONLY SEND KEY COMMANDS IN RESPONSE TO A BUTTON PRESS OR SIMILAR 
 *    SORT OF STIMULUS - DON'T SET IT TO JUST KEEP TALKING CONSTANTLY.
 *    IF THE DEVICE IS SENDING KEY COMMANDS, THIS WILL INTERFERE WITH 
 *    PROGRAMMING - THERE IS A RISK YOU WILL BRICK YOUR PRO MICRO
 *    BECAUSE IT WON'T SHUT UP AND LISTEN TO THE PROGRAMMER. 
 *    THAT CAN BE FIXED, BUT IT'S A PAIN IN THE TAIL - I'VE NOT DONE
 *    IT SO I DON'T KNOW HOW YOU'D FIX IT - USE THE SERIAL PORT TO TEST
 *    THE FUNCTIONALITY BEFORE GOING HOG WILD.
 *    
 *    This uses a switch on pin 10 in order to
 *    select between two tasks according to whether pin 10 is 
 *    high or low at the time of the button press. I.E. set up for 
 *    use with two different programs according to the switch.
 *    
 *    The code simulates keyboard inputs according to which button is 
 *    pressed, these can be complex messages with multiple key presses.
 *    You can also write strings, look at the <KEYBOARD> library reference
 *    in the Arduino website for how to do this.
 *    
 *    This code was modified from the 'Multikey' example written by Mark 
 *    Stanley from the <KEYPAD> library written by  Mark Stanley and 
 *    Alexander Brevig  
 *    The keypad library can be found for in the library manager in arduino. 
 *    Go to Library manager and search for 'KEYPAD', select the one written by
 *    Mark Stanley and Alexander Brevig.
 *    Some code was also borrowed from brian lough's tutorial called 'The simplest diy macro keypad'
 *    I've just cobbled them together and set it up for photoshop shortcuts (and commented lots).
 *     
 *     For 32u4 Pro Micro
 *     Sketch uses 8160 bytes (28%) of program storage space. Maximum is 28672 bytes.
 *     Global variables use 557 bytes (21%) of dynamic memory, leaving 1963 bytes 
 *     for local variables. Maximum is 2560 bytes.

 *    
 **************************************************************************/
 
 
 
