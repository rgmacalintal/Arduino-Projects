int SER = 14;
int LATCH = 15;
int SRCLK = 16;
int myDelay = 100;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(SRCLK, OUTPUT);
}

void loop() {
  int bitArray[] = {0, 1, 3, 7, 15, 31, 63, 127, 255};

  // count up first 8 bits
  for(int i = 0; i < 9; i++) {
    digitalWrite(LATCH, LOW);
    // shift first 8 bits ends up in the second SR
    shiftOut(SER, SRCLK, MSBFIRST, 0);
    // shift second 8 bits ends up in the first SR
    shiftOut(SER, SRCLK, MSBFIRST, bitArray[i]);
    digitalWrite(LATCH, HIGH);
    delay(myDelay);
  }

  // count up second 8 bits
  for(int i = 0; i < 8; i++) {
    digitalWrite(LATCH, LOW);
    // shift first 8 bits ends up in the second SR
    shiftOut(SER, SRCLK, MSBFIRST, bitArray[i+1]);
    // shift second 8 bits ends up in the first SR
    shiftOut(SER, SRCLK, MSBFIRST, 255);
    digitalWrite(LATCH, HIGH);
    delay(myDelay);
  }

  // count down second 8 bits
  for(int i = 7; i >= 0; i--) {
    digitalWrite(LATCH, LOW);
    // shift first 8 bits ends up in the second SR
    shiftOut(SER, SRCLK, MSBFIRST, bitArray[i]);
    // shift second 8 bits ends up in the first SR
    shiftOut(SER, SRCLK, MSBFIRST, 255);
    digitalWrite(LATCH, HIGH);
    delay(myDelay);
  }

  // count down first 8 bits
  for(int i = 7; i >= 0; i--) {
    digitalWrite(LATCH, LOW);
    // shift first 8 bits ends up in the second SR
    shiftOut(SER, SRCLK, MSBFIRST, 0);
    // shift second 8 bits ends up in the first SR
    shiftOut(SER, SRCLK, MSBFIRST, bitArray[i]);
    digitalWrite(LATCH, HIGH);
    delay(myDelay);
  }

}