// C++ code
//
int distance = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(4, OUTPUT);

  distance = 0;
}

void loop()
{
  distance = 0.01723 * readUltrasonicDistance(6, 5);
  if (distance <= 50) {
    digitalWrite(4, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
  } else {
    digitalWrite(4, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
  }
}