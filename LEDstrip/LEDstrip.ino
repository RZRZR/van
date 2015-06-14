/*
  Van Code

Arduino is booted on door opening. 
Aim is to have the LED strip to stay on only if it's dark enough. 
If it is dark enough the lights should stay on for 2 minutes, before testing light levels again.
Lights can stay on for a maximum of 10 mins.

Relay: ----------------------------------------------------
Relay is on PIN 8.
LED wiring on the relay is on NC - so
LOW = LED ON
HIGH = LED OFF
----------------------------------------------------

Photocell: ----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------

----------------------------------------------------

*/

int relay = 8;
int lightPin = 0;
int count = 0;
int lightValue;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);  //Begin serial communcation
  pinMode(relay, OUTPUT);
  pinMode(lightPin, INPUT);
  digitalWrite(relay, HIGH);    // turn the LEDs off
}

// the loop routine runs over and over again forever:
void loop() {
  while (count < 5) { // only run through this loop 5 times (max 10 minutes)
    lightValue = analogRead(lightPin);
    delay(10);
    Serial.println(lightValue); //Write the value of the photoresistor to the serial monitor
    if (lightValue < 600) { // If light sensor read less than 60
      digitalWrite(relay, LOW);   // turn the LEDs on
      Serial.print("wait 2 minutes");
      delay(120000);               // wait for a two minutes
      count++; // add 1 to count
    }
    delay(10);
    lightValue = analogRead(lightPin);
    if (lightValue > 600) {
    digitalWrite(relay, HIGH);
    }
  }
  Serial.print("count finished");
  delay(10);
}
