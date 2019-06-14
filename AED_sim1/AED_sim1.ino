// Test program for the MD_YX5300 library
//

#include <MD_YX5300.h>

// Connections for serial interface to the YX5300 module
const uint8_t ARDUINO_RX = 0;    // connect to TX of MP3 Player module
const uint8_t ARDUINO_TX = 1;    // connect to RX of MP3 Player module

// buttons 
const uint8_t BLUE_BTN_PIN = 2;
const uint8_t RED_BTN_PIN = 3;

// Define global variables
MD_YX5300 mp3(ARDUINO_RX, ARDUINO_TX);
bool bFirstResuscitation = true;

void receive_msg(){
  while(!mp3.check());
}

void block(){
  do{
    receive_msg();
  }
  while(mp3.getStsCode() != MD_YX5300::STS_FILE_END);
}

void play(uint8_t track){
  mp3.playTrack(track + 1);
  block();
}

void wait_for_btn(uint8_t track1, int8_t track2, uint8_t btn){
  play(track1);
  if(track2 >= 0)
    play(track2);
}

void wait_for_btn(uint8_t track, uint8_t btn){
  wait_for_btn(track, -1, btn);
}

void setup_buttons(){
  pinMode(BLUE_BTN_PIN, INPUT_PULLUP);
  pinMode(RED_BTN_PIN, INPUT_PULLUP);
}

void init_mp3(){
  mp3.begin();
  mp3.setCallback(nullptr);
  mp3.setSynchronous(true);
}

void aed_play_init_sequence(){
  play(1);
  wait_for_btn(2, 0, BLUE_BTN_PIN);
  play(3);
  play(4);
  wait_for_btn(5, 0, BLUE_BTN_PIN);
  wait_for_btn(6, 0, BLUE_BTN_PIN);
}

void aed_play_resuscitation(bool first_run){
  play(7);
  delay(1000);
  wait_for_btn(8, RED_BTN_PIN);
  play(9);
  if(first_run){
    play(10);
    play(12);
    wait_for_btn(11, BLUE_BTN_PIN);
    play(13);
  } else {
    play(15);
  }
  play(14);
}

void setup() {
  setup_buttons();
  init_mp3();
  aed_play_init_sequence();
  bFirstResuscitation = true;
}

void loop() {
  aed_play_resuscitation(bFirstResuscitation);
  bFirstResuscitation = false;
  mp3.check();
}
