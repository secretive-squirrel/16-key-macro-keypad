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
#include <Keypad.h>
#include <Keyboard.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
{'a','b','c','d'},              // Arranging and naming the buttons in the 4x4
{'e','f','g','h'},              // keypad so that they can be called upon.
{'i','j','k','l'},              // I found alphabetical to be more intuitive.
{'m','n','o','p'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {2, 3, 4, 5}; //connect to the column pinouts of the kpd
                                   //If you use a different pin out then this will 
                                   //be different for you.

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long loopCount;
unsigned long startTime;

const byte select = 10;     // physical toggle switch connected to pin 10


void setup() {
    Serial.begin(9600);
    loopCount = 0;
    startTime = millis();
    pinMode(select, INPUT); //Set up select switch as an input.
}


void loop() {
    loopCount++;                          // This isn't needed, but it's helpful
    if ( (millis()-startTime)>5000 ) {    // as a measure of efficiency
        Serial.print("Average loops per second = ");
        Serial.println(loopCount/5);
        startTime = millis();
        loopCount = 0;
    }

char pressedKey = 0;

    // Fills kpd.key[ ] array with up-to 10 active keys.
    // Returns true if there are ANY active keys.
    if (kpd.getKey())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
            {
                switch (kpd.key[i].kstate) {
                    case PRESSED:                   // Report active key state : PRESSED only
                    pressedKey = kpd.key[i].kchar;  // If key pressed, then save the key as a char which will
                    delay(20);                      // be used in the switch statement coming up.
                break;                              // Other functions like IDLE, RELEASE, etc are available 
                }                                   // in the 'KEYPAD' library, you'll want to read up there
            }                                       // for usage - I just grabbed what I needed for my usage.
        }
    }

/* USAGE for keys
// Keyboard.press(KEY_LEFT_CTRL);
// Keyboard.press(KEY_LEFT_SHIFT);
// Keyboard.press(KEY_LEFT_ALT);
// Keyboard.press(key);
// Keyboard.press(43); // ascii number for + key in decimal
//                        In places I used ascii decimal numbers
//                        instead of names. For instance, in Windows,
//                        ascii 206 is printscreen.
*/  


int switchState = digitalRead(select);  //Check if the switch is high or low.

  if (pressedKey) {           // The following only happens if a key has been pressed, otherwise it
    switch (pressedKey) {                       // will just loop back to the start again
      //**************************  BUTTON  A
      case 'a':
      if (switchState == HIGH){         // If the top left button has been pressed then;
        Serial.println("press a");      // send this message to the serial port
        Keyboard.press('a');            //  send a keypress for this letter
      }
      else{                             // Otherwise if pin 10 is pulled low then press the 
        Keyboard.press(KEY_ESC);        // ESC key
      }
        break;
        //************************  BUTTON  B
      case 'b':
        if (switchState == HIGH){
        Serial.println("pressed b");    // This could be made more efficient by using a constant 
        Keyboard.press('b');            // string and a variable, but whatever. I'm lazy, it's fine.
      }
      else{
        Keyboard.press(KEY_DELETE);        //DEL key
      }
        break;
        //************************  BUTTON  C
      case 'c':
        if (switchState == HIGH){
        Serial.println("press c");
        Keyboard.press('c');
      }
      else{
        Keyboard.press(KEY_LEFT_ALT);        // ALT+F4
        Keyboard.press(KEY_F4);
      }
        break;
        //************************  BUTTON  D
      case 'd':
        if (switchState == HIGH){
        Serial.println("press d");
        Keyboard.press('d');
      }
      else{
        Serial.println("10up && D");
        Keyboard.press(9);     //TAB key (Could also be written (KEY_TAB)
      }
        break;
        //************************  BUTTON  E
      case 'e':
       if (switchState == HIGH){
        Serial.println("press e");
        Keyboard.press('e');
      }
      else{
        Serial.println("10up && E");
        Keyboard.press(KEY_LEFT_ALT); //ALT + TAB
        Keyboard.press(9);            //
      }
        break;
        //************************  BUTTON  F
      case 'f':
        if (switchState == HIGH){
        Serial.println("press f");
        Keyboard.press('f');
      }
      else{
        Keyboard.press(KEY_LEFT_ALT); // ALT+i+i
        Keyboard.press('i');          // Image Size in photoshop
        delay(20);                    // The keyboard release and 
        Keyboard.releaseAll();        // delay is needed here because
        Keyboard.press('i');          // the 'I' key is pressed twice
      }
        break;
        //************************  BUTTON  G
      case 'g':
       if (switchState == HIGH){
        Serial.println("press g");
        Keyboard.press('g');
      }
      else{
        Keyboard.press(KEY_LEFT_CTRL);  // CTRL+W
        Keyboard.press('w');
      }
        break;
        //************************  BUTTON  H
      case 'h':
        if (switchState == HIGH){
        Serial.println("press h");
        Keyboard.press('h');
      }
      else{
        Keyboard.press(32);   // Ascii for SPACE BAR
      }
        break;
        //************************  BUTTON  I
      case 'i':
        if (switchState == HIGH){
        Serial.println("press i");
        Keyboard.press('i');
      }
      else{
        Keyboard.press(KEY_LEFT_CTRL);
        Keyboard.press(KEY_LEFT_ALT);   //CTRL+ALT+S
        Keyboard.press('s');            //SAVE AS (photoshop)
      }
        break;
        //************************  BUTTON  J
      case 'j':
        if (switchState == HIGH){
        Serial.println("press j");
        Keyboard.press('j');
      }
      else{
        Keyboard.press(206);    //PRINT SCREEN (WINDOWS)
      }
        break;
        //************************  BUTTON  K
      case 'k':
        if (switchState == HIGH){
        Serial.println("press k");
        Keyboard.press('k');
      }
      else{
        Keyboard.press(KEY_LEFT_CTRL);  //CTRL+N
        Keyboard.press('n');
      }
        break;
        //************************  BUTTON  L
      case 'l':
        if (switchState == HIGH){
        Serial.println("press l");
        Keyboard.press('l');
      }
      else{
        Keyboard.press(KEY_LEFT_ALT); //ALT+I+P
        Keyboard.press('i');          //crop command in photoshop
        Keyboard.press('p');
      }
        break;
        //************************  BUTTON  M
      case 'm':
        if (switchState == HIGH){
        Serial.println("press m");
        Keyboard.press('m');
      }
      else{
        Keyboard.press(KEY_LEFT_CTRL);  // CTRL+ALT+Z
        Keyboard.press(KEY_LEFT_ALT);   // step backward in photoshop
        Keyboard.press('z');            // basically CTRL+Z 
      }
        break;
        //************************  BUTTON  N
      case 'n':
        if (switchState == HIGH){
        Serial.println("press n");
        Keyboard.press('n');
      }
      else{
        Keyboard.press(KEY_LEFT_CTRL);  // CTRL+C
        Keyboard.press('c');            // COPY
      }
        break;
        //************************  BUTTON  O
      case 'o': 
        if (switchState == HIGH){
        Serial.println("press o");
        Keyboard.press('o');
      }
      else{
        Keyboard.press(KEY_LEFT_CTRL);  // CTRL+V
        Keyboard.press('v');            // PASTE
      }
        break;
        //************************  BUTTON  P
      case 'p':
        if (switchState == HIGH){
        Serial.println("press p");
        Keyboard.press('p');
      }
      else{
        Keyboard.press(10);         // ASCII FOR RETURN KEY
      }
        break;
        //************************  BUTTON  END
    }
    delay(100);
    Keyboard.releaseAll(); // this releases any keys so that they are
  }                        // inactive before the next loop. I could have
}                          // done this for every command, but the effect 
                           // is the same if it's here.
