// Test program for the MD_YX5300 library
//

#include <MD_YX5300.h>

// Connections for serial interface to the YX5300 module
const uint8_t ARDUINO_RX = 0;    // connect to TX of MP3 Player module
const uint8_t ARDUINO_TX = 1;    // connect to RX of MP3 Player module

// Define global variables
MD_YX5300 mp3(ARDUINO_RX, ARDUINO_TX);
bool bUseSynch = true;   // use synchronous? 

void play(uint8_t track){
  mp3.playTrack(track + 1);
}

void init_mp3(){
  mp3.begin();
  mp3.setCallback(nullptr);
  mp3.setSynchronous(bUseSynch);
}

void setup() {
  init_mp3();
  play(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
