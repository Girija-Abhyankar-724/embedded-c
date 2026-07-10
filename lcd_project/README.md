# Arduino Uno R3 Karaoke Machine

## Karaoke Machine using UART, I²C, and Embedded C

This project implements a simple **Karaoke Machine** on an **Arduino Uno R3 (ATmega328P)** using low-level Embedded C.

This 'Karaoke Machine' displays a menu on the Serial Terminal (I used RealTerm). The user is allowed to select a pre-loaded 'song' by entering the number corresponding to it. The song lyrics, (mostly) in sync with the music are displayed on the 16x2 LCD screen. In case of an invalid entry, the Serial Terminal displays "Enter a valid song number" while the LCD displays "Invalid Number". In both cases, the program asks the user to enter a song number once again.

## Hardware Used

- Arduino Uno R3 (ATmega328P)
- 16×2 HD44780 LCD
- PCF8574T I²C LCD Backpack
- USB connection for UART

---

## Features

- Written entirely in **Embedded C**
- Developed without the Arduino IDE
- UART driver implemented from scratch using AVR registers
- I²C (TWI) driver implemented from scratch
- LCD driver implemented from scratch without external libraries
- Modular project structure
- Compiled using **AVR-GCC**
- Uploaded using **AVRDUDE**

---

## Project Structure

```text
.
├── main.c
├── uart.c
├── uart.h
├── twi.c
├── twi.h
├── pcf8574.c
├── pcf8574.h
├── lcd.c
├── lcd.h
├── songs.c
├── songs.h
├── Makefile
└── README.md
```

---

## Building the Project

Compile the project:

```bash
avr-gcc -mmcu=atmega328p -DF_CPU=16000000UL -Os \
-o lcd.elf \
main.c uart.c twi.c pcf8574.c lcd.c songs.c
```

Generate the HEX file:

```bash
avr-objcopy -O ihex -R .eeprom lcd.elf lcd.hex
```

Upload the program to the Arduino Uno:

```bash
avrdude -c arduino -P COM4 -b 115200 -p m328p -U flash:w:lcd.hex:i
```

> **Note:** Replace `COM4` with the appropriate serial port on your system.

---

## How It Works

1. The Arduino initializes UART and the LCD.
2. A menu is displayed on the serial terminal.
3. The user enters the number corresponding to a song.
4. The selected song's lyrics are displayed on the LCD with timed delays.
5. If an invalid number is entered, an error message is shown on both the terminal and LCD 
6. User is prompted to enter a new song number.

---

## Author

**Girija Abhyankar**

First-year Electronics and Communication Engineering student with an interest in Embedded Systems, Digital Design, and Computer Architecture.
