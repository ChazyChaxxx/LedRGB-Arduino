#define LEDR 3
#define LEDG 5
#define LEDB 7
#define KNOBR 0
#define KNOBG 1
#define KNOBB 2

void setup() {
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop() {
  // Lit la valeur des potentiomètres
  int knobrValue = analogRead(KNOBR);
  int knobgValue = analogRead(KNOBG);
  int knobbValue = analogRead(KNOBB);

  // Map les potentiomètres sur une valeur de 1-255
  int intensityR = map(knobrValue, 1, 1024, 1, 255);
  int intensityG = map(knobgValue, 1, 1024, 1, 255);
  int intensityB = map(knobbValue, 1, 1024, 1, 255);

  // Envoie la valeur dans les sorties numériques
  analogWrite(3, knobrValue);
  analogWrite(5, knobgValue);
  analogWrite(7, knobbValue);
  
  
  //Moniteur série
  Serial.print("red:");
  Serial.println(intensityR);
  Serial.print("green:");
  Serial.println(intensityG);
  Serial.print("blue:");
  Serial.println(intensityB);
  Serial.print("\n");
  delay(800);
}
