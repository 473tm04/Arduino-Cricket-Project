const int led = 9;             // the PWM pin the LED is attached to

const int brightness = 10;     // how bright the LED is

const int cricketPin_in = A2;
const int thresholdPin_in = A1;


void setup() {
  pinMode(led, OUTPUT);
  analogWrite(led,0);
}

void loop() {

  int spikeThreshold = setSpikeThreshold();
  detectSpikes(spikeThreshold);
  
}

int setSpikeThreshold(){
  int thresh = analogRead(thresholdPin_in);
  // modify threshold here?
  
}

void detectSpikes(int threshold){
  int cricketVoltage = analogRead(cricketPin_in);  //the input needed to pass threshhold value
  
  if (cricketVoltage > threshold) {
    analogWrite(led, brightness);
    delay(500);
    analogWrite(led, 0);
 }
}