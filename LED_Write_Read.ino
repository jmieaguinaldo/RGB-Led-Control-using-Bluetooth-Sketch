char command;
String string;
boolean ledon = false;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColor(0, 0, 0);
}

void loop() {
  if (Serial.available() > 0) {
    string = "";
    setColor(0, 0, 0);
  }
  
  while(Serial.available() > 0) {
    command = ((byte)Serial.read());
    
    if(command == ':') {
      break;
    } else {
      string += command;
    }
    
    delay(1);
  }
  
  if(string == "BLINK") {
    setColor(25, 0, 0); // red
    delay(1000);
    
    setColor(0, 25, 0); // green
    delay(1000);
    
    setColor(0, 0, 25); // blue
    delay(1000);

    ledon = true;
  }

  if(string == "RED") {
    setColor(25, 0, 0); // red
    delay(1000);
    ledon = true;
  }

  if(string == "GREEN") {
    setColor(0, 25, 0); // green
    delay(1000);
    ledon = true;
  }

  if(string == "BLUE") {
    setColor(0, 0, 25); // blue
    delay(1000);
    ledon = true;
  }
  
  if(string =="TF") {
      setColor(0, 0, 0);
      ledon = false;
      Serial.println(string);
  }
  
  if ((string.toInt()>=0)&&(string.toInt()<=255)) {
    if (ledon==true) {
      setColor(255, 0, 0);
      Serial.println(string);
      delay(10);
    }
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue);
}


  
