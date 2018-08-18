// TestRemote is for validating the operation of the simple RF receiver with the
// remote
//
// NOTE: the relationship between the pins on the receiver and buttons on the
// remote are reversed (i.e. "A" on the remote sets "D3" to high)

/* ----- DEFINITIONS ----- */
#define GND     31
#define V5      33
#define remoteA 41
#define remoteB 39

void setup() {
  Serial.begin(9600);
  pinMode(remoteA, INPUT);
  pinMode(remoteB, INPUT);
  pinMode(GND, OUTPUT);
  digitalWrite(30, LOW);
  pinMode(33, OUTPUT);
  digitalWrite(32, HIGH);
  Serial.println("Setup complete.");
}

void loop() {
  // Read pins where remote is connected to
  int remoteStateA = digitalRead(remoteA);
  int remoteStateB = digitalRead(remoteB);

  if (remoteStateA == HIGH) {
    Serial.println("A pressed!");
  }

  if (remoteStateB == HIGH) {
    Serial.println("B pressed!");
  }
}
