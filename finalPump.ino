int analogPin = A1;

int analogPinS = A2;

int soil = 0; // varibale soil created, inital value set to 0

int val = 0; // variable to store the value read

int ledR = 12; //Red led Pin Number

int ledG = 13; //Green led Pin Number

int ledpump = 6;
int pump = 5;
int pump2 = 3;


void setup() {

// put your setup code here, to run once:

Serial.begin(9600); // setup serial

pinMode(6, OUTPUT);

pinMode(ledR, OUTPUT);

pinMode(ledG, OUTPUT);

pinMode(ledpump, OUTPUT);

}

void loop() {

// put your main code here, to run repeatedly:

soil =analogRead(analogPinS);
val = analogRead(analogPin); // read the input pin

Serial.println("Water in water basin!");
Serial.println(val); // debug value
Serial.println("Moister in soil!");
Serial.println(soil);// shows soil value
delay(1000);

digitalWrite(ledR, LOW);

digitalWrite(ledG, LOW);

if (val < 290){

digitalWrite(ledR, HIGH);} //Water value turns on Red LED

if (val > 290) {

digitalWrite(ledG, HIGH);} //Water value turns on Green LED

pinMode(ledpump, HIGH);

delay(1000);

soil = analogRead(analogPinS);

digitalWrite(ledpump, LOW);

if (soil > 100)

{

analogWrite(ledpump, 0);
analogWrite(pump, 0);
analogWrite(pump2, 0);
}

if (soil < 100)

{

analogWrite(ledpump, 225);
analogWrite(pump, 225);
analogWrite(pump2, 225);
}


}
