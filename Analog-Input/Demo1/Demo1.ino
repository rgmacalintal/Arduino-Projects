int redPin =  14;
int greenPin =  18;
int bluePin =  15;

void setup()   {
  Serial.begin(38400);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

int redIntensity = 0;
int greenIntensity = 255;

void loop()                     
{
  // read the pot position
  redIntensity = analogRead(A8) / 4;
  greenIntensity = 255 - redIntensity;
  
  // set all 3 pins to the desired intensity
  analogWrite(redPin, redIntensity);
  analogWrite(greenPin, greenIntensity);
  analogWrite(bluePin, 0);

  Serial.print("Red Intensity: ");
  Serial.print(redIntensity);
  Serial.print(", Green Intensity: ");
  Serial.println(greenIntensity);

  // remain at this color, but not for very long
  delay(10);
}