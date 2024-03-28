//transmitter
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);      // set LED pin as output
  digitalWrite(LED_BUILTIN, LOW);    // switch off LED pin

  Serial.begin(9600);               // initialize serial communication at 9600 bits per second:
  Serial1.begin(9600);            // initialize UART with baud rate of 9600
}

void loop() {
  if (Serial.available() > 0) { // Check if data is available to read from Serial
    char receivedChar = Serial.read(); // Read the incoming byte
    if (receivedChar == '1') {
      Serial1.println('1'); // Transmit data over Serial1 to another ESP32
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("LEDs ON");
    } else if (receivedChar == '0') {
      Serial1.println('0'); // Transmit data over Serial1 to another ESP32
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("LEDs OFF");
    }
  }
}