int SER = 14;
int LATCH = 15;
int SRCLK = 16;
int myDelay = 50;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(SRCLK, OUTPUT);
}

void loop() {
  int theBits = 1;

  // shift up
  for(int i = 0; i < 7; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, SRCLK, MSBFIRST, theBits);
    digitalWrite(LATCH, HIGH);
    delay(100);
    theBits <<= 1;
  }

  // shift down
  for(int i = 0; i < 7; i++) {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, SRCLK, MSBFIRST, theBits);
    digitalWrite(LATCH, HIGH);
    delay(100);
    theBits >>= 1;
  }

}