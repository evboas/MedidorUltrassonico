//Acionamento do aparelho
#define BOTAO 11
#define BUZZER 8

//Luzes de sinalização para funcionamento
#define LEDVERM 10
#define LEDVERDE 9

//Pinos do sensor ultrassonico
#define TRIGGER 7
#define ECHO A1

//Definindo o tom do efeito sonoro
#define NOTE_C4  262

int nMedidas = 30; // número de medições que devem ser realizadas

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BOTAO, INPUT_PULLUP);
  pinMode(LEDVERM, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(TRIGGER, LOW);
  digitalWrite(LEDVERM, 1);
  digitalWrite(LEDVERDE, 1);
  delay(1000);
  digitalWrite(LEDVERM, 0);
}

void loop() { 
  if(digitalRead(BOTAO) == 0){
    LerBotao();
  }
}

void LerBotao(){
  if(digitalRead(BOTAO) == 0){
    tone(BUZZER, NOTE_C4, 1000);
    digitalWrite(LEDVERDE, 0);
    Medir();
    digitalWrite(LEDVERDE, 1);
  }
}

void Medir(){
  Serial.println("ID; Distancia;");
  for(int i = 0; i < nMedidas; i++){
    digitalWrite(LEDVERM, 1);
    DisparaPulso();
    float tempEcho = pulseIn(ECHO, HIGH);// Vai medir o tempo de retorno do pulso
    float distancia = CalculaDistancia(tempEcho); //Chama a função que calcula a distância em cm
    Serial.println(String(i + 1) + ";" + String(distancia)); //em cm
    digitalWrite(LEDVERM, 0);
    delay(500);
  }
  tone(BUZZER, NOTE_C4, 1000);
}

void DisparaPulso(){
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); //De acordo com a documentação do sensor, deve-se emitir um um sinal de 10 us
  digitalWrite(TRIGGER, LOW);
}

float CalculaDistancia(float tempo){
  //return tempo/58.8;
  return((tempo*0.034)/2);
}
