#include <Bounce2.h>

int ledPin =  14;
int buttonPin = 7;

volatile int ledState = LOW;

volatile int counter = 0;
int prevCount = 0;

Bounce debouncer = Bounce();

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  debouncer.attach(buttonPin);
  debouncer.interval(90); // interval in ms
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, FALLING);
}

void buttonISR() {
  counter++;
  // digitalWrite(ledPin, ledState);
}

void loop() {
  // Update the Bounce instance (YOU MUST DO THIS EVERY LOOP)
  debouncer.update();

  // <Bounce>.changed() RETURNS true IF THE STATE CHANGED (FROM HIGH TO LOW OR LOW TO HIGH)
  if (debouncer.changed()) {
    // THE STATE OF THE INPUT CHANGED
    // GET THE STATE
    int deboucedInput = debouncer.read();
    // IF THE CHANGED VALUE IS LOW
    if ( deboucedInput == LOW ) {
      Serial.print("Counter: ");
      Serial.println(counter);
      ledState = !ledState; // SET ledState TO THE OPPOSITE OF ledState
      digitalWrite(ledPin, ledState); // WRITE THE NEW ledState
    }
  }
  delay(90);
}
