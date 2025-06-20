# ESP32 WiFi Rover

A WiFi-controlled robotic rover built with an ESP32 microcontroller and a Raspberry Pi-based controller.  
This was a solo project focused on understanding embedded systems, basic electronic and robotic engineering, networking (UDP), and C++/Python integration.

## Features
- Remote control over WiFi (UDP-based)
- Manual keyboard inputs from Python controller
- Modular structure (easy to add sensors or camera)
- Basic sound/buzzer trigger (ESP32 PWM)

## Hardware Used
- ESP32 Dev Module
- L298N Motor Driver
- TT DC Motors + Wheels
- 3D Printed Rover chassis
- Raspberry Pi 4 (or any computer running the controller script)
- Male to female and male to male jumper cables
- Breadboard
- Piezo buzzer
- 2000mAh 7.4V lithium ion 2 cell battery pack
- Wago 221-413's

## How to Use
1. Flash `main.cpp` to ESP32 using Arduino IDE or PlatformIO.
2. Run `controller.py` on a computer, ensuring you're connected on the same network.
3. Use the following keyboard commands:

| Command | Action   |
|---------|----------|
| `t`     | Forward  |
| `g`     | Reverse  |
| `f`     | Left     |
| `h`     | Right    |
| `x`     | Stop     |
| `b`     | Beep     |

(You can change these how you like)


![ESP32 Rover in Action](media/rover-demo.gif)



## Future Plans
- Add a camera module
- Add Bluetooth fallback control
- Speed control via PWM

## Author
Jonathan Balysma | 19 years old 
BSc Cybersecurity at De Montfort University
Self-studying electronics, working towards mastering calculus for robotic applications
📷 [Instagram](https://instagram.com/jbaly1)  
💻 [GitHub](https://github.com/Jbaly1)

Feel free to DM on GitHub or my Instagram if you're working on similar stuff or just curious about the project.
