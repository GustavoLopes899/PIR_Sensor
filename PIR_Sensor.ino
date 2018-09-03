// Program used to control a PIR Sensor using a led to show activity //

const int led = 9;        // led pin
int sensor_pin = 8;       // pir sensor pin
int sensor_status = 0;    // status of sensor; 0 (no activity) and 1 (activity)
int calibration = 45;     // calibration variable

void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(sensor_pin, INPUT);
  
  Serial.print("Calibrating the sensor...");
  for (int i = 0; i < calibration; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Sensor activated.");
  delay(500);
}

void loop() {
  sensor_status = digitalRead(sensor_pin);

  Serial.print("Value of the PIR Sensor: ");
  Serial.println(sensor_status);

  if (sensor_status == 1) {
    led_on();
  } else {
    led_off();
  }
}

void led_on() {
  digitalWrite(led, HIGH);

}
void led_off() {
  digitalWrite(led, LOW);
}
