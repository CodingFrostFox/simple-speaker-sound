//Pressing the button on the breadboard activates a siren sound.

int led_L1 = 10; //left outside
int led_L2 = 8; //left inside
int led_R1 = 5; //right outside
int led_R2 = 6; //right inside
int siren = 7;
int button = 2;
bool turnOn = false;
int pitch = 0; //sound stage
int stepsPitch = 5; //sound increase


void setup() {
  pinMode(siren, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {

  if (digitalRead(button) == HIGH){
    turnOn = !turnOn;
    delay(200); // debouncing button
  }

  if (turnOn){
    analogWrite(led_L1, pitch); //no output setup necessary due to analogWrite
    analogWrite(led_L2, pitch);
    analogWrite(led_R1, pitch);
    analogWrite(led_R2, pitch);

    delay (10);

    pitch = pitch + stepsPitch;
    stepsPitch = (pitch == 0 || pitch == 250)? -stepsPitch : stepsPitch; //switch: if reached end of sound spectrum
    (pitch <= 125)? tone(siren, 655) : tone(siren, 400);

  } else {
      analogWrite(led_L1, 0);
      analogWrite(led_L2, 0);
      analogWrite(led_R1, 0);
      analogWrite(led_R2, 0);
      tone(siren, 0);
  }

}
