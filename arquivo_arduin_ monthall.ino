int ledPin1 =  12; // output para o LED
int ledPin2 = 11;
int ledPin3 = 10;
int inPin1 =  7; // input (para o push button)
int inPin2 = 6;
int inPin3 = 5;

enum Estado { ligado, desligado } ep1, ep2, ep3;

void setup() {
  // put your setup code here, to run once:
  ep1 = ep2 = ep3 = desligado;
  pinMode(ledPin1, OUTPUT); // declare LED como output
  pinMode(inPin1, INPUT); // declare pushbutton como input
  pinMode(ledPin2, OUTPUT); // declare LED como output
  pinMode(inPin2, INPUT); // declare pushbutton como input
  pinMode(ledPin3, OUTPUT); // declare LED como output
  pinMode(inPin3, INPUT); // declare pushbutton como input
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int but1, but2, but3;
  do {
    but1 = digitalRead(inPin1);
    but2 = digitalRead(inPin2);
    but3 = digitalRead(inPin3);
  } while((but1==HIGH)&&(but2==HIGH)&&(but3==HIGH));
  if(but1==LOW) { ep1 = (ep1 == ligado)? desligado:ligado; ep2 = desligado; ep3 = desligado; Serial.println('0'); }
  if(but2==LOW) { ep1 = desligado; ep2 = (ep2 == ligado)? desligado:ligado; ep3 = desligado; Serial.println('1'); }
  if(but3==LOW) { ep1 = desligado; ep2 = desligado; ep3 = (ep3 == ligado)? desligado:ligado; Serial.println('2'); }
  if(ep1 == ligado)
    digitalWrite(ledPin1, HIGH);
  else
    digitalWrite(ledPin1, LOW);
  if(ep2 == ligado)
    digitalWrite(ledPin2, HIGH);
  else
    digitalWrite(ledPin2, LOW);
  if(ep3 == ligado)
    digitalWrite(ledPin3, HIGH);
  else
    digitalWrite(ledPin3, LOW);
  delay(500);
}
