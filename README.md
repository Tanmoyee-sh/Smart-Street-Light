# Smart Street Light

This mini project will detail our implementation of our smart street light system, which is an advanced kind of street lighting that uses sensors and a microcontroller (e.g., Arduino) to control the illumination. The system is designed to be more energy efficient, economically effective, and ecologically benign than standard street lighting systems.


This project will investigate a potential smart street lighting system intended specifically for illuminating roadways only when necessary. The system is constructed in such a way that the lamps only glow at night and when vehicles and people pass by. In addition, a speed monitoring capability is introduced to the system, which captures and shows a vehicle's speed.


# Code Algorithm


At first, the void measure_distance() function calculates the distance to a vehicle and the speed based on the change in distance over time using an ultrasonic
range finder. The vehicle is assumed to be approaching the ultrasonic range finder. The speed is calculated by comparing the distance travelled over time
between consecutive readings and is then displayed on the serial monitor.


When the light level is extremely low and the distance is less than 10cm, the code in the void loop() function compares the readings from the LDR sensor and the ultrasonic range finder and turns on the LED.


Finally, the LCD display is interfaced with using the LiquidCrystal library. The void setup() function initialises the LCD and displays "Your speed is:" on it. The
void loop() function changes the speed of the vehicle on the second line of the display whenever a vehicle or an object passes by the ultrasonic range finder.
