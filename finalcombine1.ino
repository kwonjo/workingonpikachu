// servo motor
Servo myservo;  // create servo object to control a servo
int potpin = 4;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

// PIR sensor
int LEDPin = D7;
int PIRPPin = A2;
int PIRState = LOW;
int var = 0;

// ButtonLED
int ledPin = D1;
int buttonPin = D0;

// HTML
int page = 0;

void setup() {
// servo motor  
  myservo.attach(2);  // attaches the servo on pin 9 to the servo object  
  
// PIR 
  pinMode(PIRPPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  
// buttonLED
  pinMode( buttonPin , INPUT_PULLUP); 
  pinMode( ledPin , OUTPUT ); 
}


void loop() 
{
  // servo motor/potentiometer
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15); // waits for the servo to get there
  
  if (val == 1023){
    page = 3;
    Particle.publish ("3", page);
  }
  // PIR
  var = digitalRead(PIRPPin);
 
   if(var == HIGH) {
    digitalWrite(LEDPin,HIGH);
    delay(1);
    }
    
  else {
    digitalWrite(LEDPin,LOW);
    }
//ButtonLED
   int buttonState = digitalRead( buttonPin );


  if( buttonState == LOW )
  {
   
    digitalWrite( ledPin, HIGH);
  }else{
   
    digitalWrite( ledPin, LOW);

  }
}
