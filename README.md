# IR Room Occupancy Counter Controller

## Overview

This project is an IR Room Occupancy Counter Controller built with embedded C. It uses infrared (IR) sensors to detect room entry and exit events, counts the number of people present, and displays real-time occupancy status on an LCD. Additionally, it controls a light (LED) based on occupancy.

## Features

- **Entry/Exit Detection:** Uses two IR sensors to monitor both entry and exit points.
- **Real-Time Occupancy Counter:** Counts number of people present in the room.
- **LCD Display:** Shows current count, room status (empty/full/occupied), and updates automatically.
- **Maximum Capacity Control:** Notifies when the room reaches full capacity.
- **Timeout Management:** Resets detection state if sensors remain active for too long.
- **Automatic Lighting:** Turns on a LED when room is occupied.

## How It Works

- The system uses a simple state machine to interpret sensor changes:
  - **Idle:** Waits for sensor input.
  - **Entry Detected:** Marks the beginning of an entry sequence.
  - **Exit Detected:** Marks the beginning of an exit sequence.
  - Increments or decrements the counter based on completed sequences.
- The count is displayed on the LCD, which updates whenever occupancy changes.
- The LED is controlled by the occupancy count (`Counter > 0` => light ON).
- Maximum room capacity can be set (default is `10`).

## Core System Structure

- **Sensors:** Connected to PORTB (input pins).
- **LCD:** Connected to PORTD.
- **LED:** Output pin on PORTB.
- **Timer0:** Used for timeout handling to improve sensor accuracy.

## Code Highlights

- Entry and exit events are debounced and managed in interrupts.
- LCD updates and lighting decisions are made based on global counter value.
- User can adjust maximum capacity in code.

## Requirements

- Microcontroller compatible with standard embedded C (example: PIC).
- Two IR sensors for entry/exit detection.
- 2x16 Character LCD display.
- LED (for room light indication).

## Getting Started

1. **Clone the repository:**  
   `git clone https://github.com/Ahmed0Tawfik/IR-Room-Occupancy-Counter-Controller.git`

2. **Flash the code:**  
   Build and deploy `MyProject.c` to your microcontroller.

3. **Connect hardware:**
   - PORTB: Connect IR sensors and LED as described in code comments.
   - PORTD: Connect the LCD according to pin definitions.

4. **Set maximum room capacity:**  
   Edit `int MaxCapacity` variable in `MyProject.c` as needed.

## Project Structure

```
.
├── MyProject.c     # Main program (sensor logic, LCD, LED control)
```

## Authors

- [Ahmed0Tawfik](https://github.com/Ahmed0Tawfik)
- [MAhmoud Almokaber](https://github.com/Mahmoud-Elmokaber)
- [omargamal233](https://github.com/omargamal233)
- [Naruto109k](https://github.com/Naruto109k)
