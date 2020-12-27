# Home-Automation-using-ESP8266-01
This repository contains code for DHT11 sensor connected to ESP8266 in standalone mode, please read README.md to get started with procedure involved to flash sketch using arduino-uno to ESP8266-01 module

# To configure a new ESP8266-01 using arduino-IDE and arduino-uno

1. Download the latest version of arduino-IDE from "https://www.arduino.cc/en/Main/Software"
2. Connect arduino-uno to system,
3. Now make sure there is no other code running on the arduino,
   Navigate to "File->Examples->01.Basics->BareMinimum" then upload this to the arduino-uno board
4. Open the preferences window from the Arduino IDE. Go to "File > Preferences"
5. Enter "http://arduino.esp8266.com/stable/package_esp8266com_index.json" into Additional Board Manager URLs field and click the “OK” button
6. Open boards manager. Go to Tools > Board > Boards Manager…
7. select the ESP8266 board menu and install “ESP8266 platform”
8. Choose your ESP8266 board from Tools > Board > Generic ESP8266 Module
9. Get your code ready check https://github.com/SatyamOzaR/Home-Automation-using-ESP8266-01/blob/main/blynk_temp/blynk_temp.ino to see code structure
10. ![ ](https://raw.githubusercontent.com/SatyamOzaR/Home-Automation-using-ESP8266-01/main/blynk_temp/cheatsheet.jpeg)

# Connections to dump code on ESP8266-01 using arduino uno
esp8266 --> arduino-uno
Rx      --> Rx
Tx      --> Tx
VCC     --> 3.3v
CP_HD   --> 3.3v
GPIO 0  --> GND
GND     --> GND
GPIO 2  --> unwired
RST     --> unwired

# Connections to run on standalone mode (here no arduino required, esp8266 get powered by external source like battery (make sure 3.3v exact or else module get damaged))
esp8266 --> arduino-uno
Rx      --> Rx
Tx      --> Tx
VCC     --> 3.3v
CP_HD   --> 3.3v
GPIO 0  --> To sensor output (may be unwired if required
GND     --> GND
GPIO 2  --> unwired (or sensor output)
RST     --> unwired

# In my case I used DHT11 sensor connected to standalone ESP8266-01
![ ](https://raw.githubusercontent.com/SatyamOzaR/Home-Automation-using-ESP8266-01/main/blynk_temp/dht11_specs.jpeg)


