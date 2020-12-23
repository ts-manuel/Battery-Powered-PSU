## Issues with the PCBs
The current PCBs have a couple of issues, to get them working perform the following steps.

### Battery
* Add 10K pull-up resistor to the uC reset pin
* Add 470K pull-up resistor to U50 pin 4
* Cut trace from U101 pin 1 to U100 pin 10 and jumper from U101 pin 1 to U100 pin 1
* Cut trace from connector J101 pin 7, install a series 15 Ohm resistor with a 5V zener diode to GND

### Front Panel Graphics
* No issues

### Front Panel
* No issues

### Power Supply
* Cut trace from resistor R207 and uC
* Cut trace from resistor R208 and uC
* Add jumper from uC pin 43 to R207
* Add jumper across D201
* swap I2C lines for U402 and U404
* Cut trace from U404 pin 1 and connect pull-up resistor to 5V
* Cut trace from U407 pin 2, leave pin 2 floating
* Remove C451, C452 and replace them with a 22uF electrolytic
* Remove C551, C552 and replace them with a 22uF electrolytic
* Put a 4.7uF electrolytic in parallel with R623
* Put a 4.7uF electrolytic in parallel with R523
* Change R520, R620, R670 to 22K