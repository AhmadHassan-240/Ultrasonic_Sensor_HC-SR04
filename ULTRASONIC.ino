// Define pins for the trigger and echo
const int trigPin = 9; // Trigger pin connected to pin 9
const int echoPin = 10; // Echo pin connected to pin 10
const int led = 11; // LED pin connected to pin 11

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 bps
  pinMode(trigPin, OUTPUT); // Set the trigger pin as an output
  pinMode(echoPin, INPUT); // Set the echo pin as an input
  pinMode(led, OUTPUT); // Set the LED pin as an output
}

void loop() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); // Wait for 2 microseconds

  // Send a 10 microsecond pulse to trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Keep the trigger HIGH for 10 microseconds
  digitalWrite(trigPin, LOW); // Set the trigger pin back to LOW
  
  // Read the duration of the pulse on the echo pin
  long duration = pulseIn(echoPin, HIGH); // Wait for the echo pin to go HIGH and return the duration

  // Calculate the distance in centimeters (cm)
  float distance = (duration * 0.034) / 2; // Speed of sound is approximately 0.034 cm/us, divide by 2 for round trip
  
  // Check the distance and turn on/off the LED accordingly
  if (distance <= 12) {
    digitalWrite(led, HIGH); // Turn on the LED
  } else {
    digitalWrite(led, LOW); // Turn off the LED
  }
  
  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance); // Print the calculated distance
  Serial.println(" cm"); // Indicate that the unit is centimeters
  delay(1000); // Wait for a second before the next measurement
}




