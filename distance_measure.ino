const int echoLeft = 30;
const int trigLeft = 31;
const int echoRight = 32;
const int trigRight = 33;

long durationLeft;
long durationRight;
int minimumDistance = 51; //51cm~20in
int distanceLeft;
int distanceRight;

void setup() {
  pinMode(trigLeft, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoLeft, INPUT); // Sets the echoPin as an Input
  pinMode(trigRight, OUTPUT);
  pinMode(echoRight, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigLeft, LOW);
  digitalWrite(trigRight, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigLeft, HIGH);
  digitalWrite(trigRight, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigLeft, LOW);
  digitalWrite(trigRight, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  durationLeft = pulseIn(echoLeft, HIGH);
  durationRight = pulseIn(echoRight, HIGH);
  // Calculating the distance
  distanceLeft = durationLeft * 0.034 / 2;
  distanceRight = durationRight * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if (distanceLeft < minimumDistance && distanceRight < minimumDistance) {
    Serial.println("Both Safe: ");  //lit both safety LED in front
  } else if (distanceLeft > minimumDistance && distanceRight < minimumDistance) {
    Serial.print("Right Safe: "); //lit right front safety LED
    Serial.print(distanceRight);
    Serial.println("cm");
  } else if (distanceLeft < minimumDistance && distanceRight > minimumDistance) {
    Serial.print("Left Safe: "); //lit left front safety LED
    Serial.print(distanceLeft);
    Serial.println("cm");
  } else {
    Serial.println("Both Unsafe");
  }
}

