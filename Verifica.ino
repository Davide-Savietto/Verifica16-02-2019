int ledRosso = 12;
int ledGiallo = 6;
int ledBianco= 8;
int ledVerde = 10;
int tempoRossoGiallo;
int tempoBiancoVerde;
int cicli;
  int i = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledRosso, OUTPUT);
  pinMode(ledGiallo, OUTPUT);
  pinMode(ledBianco, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600);
  randomSeed(analogRead(1));//porta che non e collegata e quindi ha numeri random
  tempoRossoGiallo = random(100,10000);//crea variabili random tra 100 e 10000(ms)
  tempoBiancoVerde = random(100,10000);
  Serial.println("Tempo random Giallo Rosso:");
  Serial.println(tempoRossoGiallo);
  Serial.println("Tempo random Bianco verde:");
  Serial.println(tempoBiancoVerde);

  Serial.println("Inserire numeri di cicli");
  
  while (Serial.available() == 0) {

  }

  cicli = Serial.readString().toInt();
  Serial.println(cicli);
  /*Serial.println("Inserire tempo accensione rosso e giallo");

  while (Serial.available() == 0) {

  }

  tempoRossoGiallo = Serial.readString().toInt();
  Serial.println(tempoRossoGiallo);

Serial.println("Inserire tempo accensione Bianco e verde");

  while (Serial.available() == 0) {

  }

  tempoBiancoVerde = Serial.readString().toInt();
  Serial.println(tempoBiancoVerde);*/

}
void Fase1(){
  digitalWrite(ledBianco, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledRosso, HIGH);
  digitalWrite(ledGiallo, HIGH);
  delay(tempoRossoGiallo);
  }
  void Fase2(){
    digitalWrite(ledRosso, LOW);
  digitalWrite(ledGiallo, LOW);
    digitalWrite(ledBianco, HIGH);
  digitalWrite(ledVerde, HIGH);
  delay(tempoBiancoVerde);
  }
void loop() {
  // put your main code here, to run repeatedly:
  if(i<cicli)
  {
     Fase1();
     Fase2();
     
     i++;
  }
  if(i >= cicli){
    digitalWrite(ledRosso, LOW);
  digitalWrite(ledGiallo, LOW);
    digitalWrite(ledBianco, LOW);
  digitalWrite(ledVerde, LOW);
  i = 0;
    setup();//il programma ricomincia
    }
    
}
