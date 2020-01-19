int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor

bool blindClosed = false;



void setup() {
  Serial.begin(9600); //sets serial port for communication
  
  Serial.println("Autoblind Initiated");
  // Close all blinds when start
  blindClosed = true;
  // close the blind
  analogWrite(2, 255);
  Serial.println("Closing Blind");
  
}

void loop() {
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(sensorValue); //prints the values coming from the sensor on the screen

  // Open blind if it's normal outside and the blind is closed
  if (sensorValue > 350 && sensorValue < 1000 && blindClosed == true) 
  {
    blindClosed = false;
    // open the blind
    analogWrite(2, 0);
    Serial.println("Opening Blind");
  }
  // Close the blind when it's dark or really bright outside and the blind is opened
  else if ((sensorValue < 350 || sensorValue > 1000) && blindClosed == false)
  {
    blindClosed = true;
    // close the blind
    analogWrite(2, 255);
    Serial.println("Closing Blind");
  }

  
  delay(1000);
}
