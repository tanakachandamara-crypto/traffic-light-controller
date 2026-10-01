# 4-Way Traffic Light Controller with LCD Telemetry

An embedded state-machine traffic management system built on the ATmega328P microcontroller with priority interval timing and real-time countdown display.

## Hardware & Architecture
- **MCU:** Microchip ATmega328P
- **Display:** 16x2 HD44780 LCD via 4-bit parallel interface
- **Simulation Tool:** Proteus VSM
- **Compiler / IDE:** PlatformIO / GCC C++

## Schematic & Simulation Preview
![Simulation Preview](media/simulation_screenshot.png)

## Key Technical Features
- **Deterministic State Timing:** Non-blocking hardware timer logic replacing delay loops.
- **Multiplexed Indicator Drive:** Safe current distribution across active LED arrays.
- **Dynamic LCD Telemetry:** Real-time state countdown feedback.

## How to Run the Simulation
1. Clone this repository.
2. Open `hardware/schematics/circuit.pdsprj` in Proteus 8.x or later.
3. Verify the firmware target points to the compiled firmware in `/firmware`.
4. Press **Run**.