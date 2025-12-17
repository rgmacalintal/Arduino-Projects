int redPin =  14;
int greenPin =  18;
int bluePin =  15;

void setup()
{                
  Serial.begin(38400);
}

float code;
float celsius;
float fahrenheit;

void loop()                     
{
  code = analogRead(A9); // analogRead takes the pin as parameter
  celsius = 25 + (code - 512) / 11.3;
  fahrenheit = celsius * 1.8 + 32;
  Serial.print("temperature: ");
  Serial.print(celsius);
  Serial.print(" Celsius, ");
  Serial.print(fahrenheit);
  Serial.println(" Fahrenheit");
  delay(1000);
}