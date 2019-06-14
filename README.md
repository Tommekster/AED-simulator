# AED Simulator

AED Simulator is basicly an audio player playing records with resusctitation instructions. 

# Hardware

It is based on *Arduino Nano* and [MP3/WAV player] with *YX5300* chipset. 

[MP3/WAV player]: https://www.dx.com/p/uart-control-serial-mp3-music-player-module-for-arduino-avr-arm-pic-blue-silver-2045959#.XQJ3togzY_4

## Hardware connections

| Player |     | Arduino Nano |
|--------|-----|--------------|
| VCC    | <-> | VCC          |
| GND    | <-> | GND          |
| RX     | <-> | TX           |
| TX     | <-> | RX           |

# Software

The program uses [MD_YX5300 library](https://github.com/MajicDesigns/MD_YX5300). 

# Usage

## Quiet mode

In quiet mode the device is powered, silent and ready. To switch the device to quiet mode:

1. hold red button
1. press green button

## Normal mode

In normal mode the device plays AED instructions. To switch the device to normal mode press the green button. 
Then listen the instructions and enyoj. 
