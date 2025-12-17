int SER = 14;
int LATCH = 15;
int SRCLK = 16;
int myDelay = 500;

byte sevenSegmentDisplay[10] = {
  0b00000001, // 0
  0b01001111, // 1
  0b00010010, // 2
  0b00000110, // 3
  0b01001100, // 4
  0b00100100, // 5
  0b00100000, // 6
  0b00001111, // 7
  0b00000000, // 8
  0b00000100  // 9
};

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(SRCLK, OUTPUT);

  digitalWrite(SER, 0);
  digitalWrite(LATCH, 0);
  digitalWrite(SRCLK, 0);
}

void loop() {
  for(int tens = 0; tens < 10; tens++) {
    for(int ones = 0; ones < 10; ones++) {

      digitalWrite(LATCH, LOW);
      shiftOut(SER, SRCLK, LSBFIRST, sevenSegmentDisplay[ones]);
      shiftOut(SER, SRCLK, LSBFIRST, sevenSegmentDisplay[tens]);
      digitalWrite(LATCH, HIGH);

      delay(myDelay);

    }
  }
}