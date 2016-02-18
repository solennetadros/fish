int led = 9;    
int led1 = 10; 
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;

int offCount = 0;
bool blinkBlink = false;
int blinkBlinkCount;

boolean metronomBlink;
boolean blinkk;

unsigned long lastMillis;
unsigned long lastMillis2;

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(led, brightness);
  
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  if (millis() - lastMillis > 250) {
    lastMillis = millis();
    metronomBlink = !metronomBlink;
  }

  if (millis() - lastMillis2 > 1000) {
    lastMillis2 = millis();
    blinkk = !blinkk;
    blinkBlinkCount++;
  }

  digitalWrite(led1, metronomBlink);

  if (blinkBlink == true) {
    digitalWrite(led, blinkk);
  
    if (blinkBlinkCount > 1) {
       blinkBlink = false;
       blinkBlinkCount = 0;
       offCount ++;
    }
    
  } else {
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
      if (brightness == 0) {
         offCount ++;
      }
    }
    delay(30);
  }

  Serial.println(blinkBlink  % 5);
  Serial.println("=================");

  if (offCount % 4 == 0) {
     blinkBlink = true;
  }

  // wait for 30 milliseconds to see the dimming effect
}
