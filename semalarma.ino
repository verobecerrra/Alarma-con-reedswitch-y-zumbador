/*Programa que contiene: 
  1. Semaforo para carros y peatonal con zumbador 
     La dinamica del semaforo se maneja de la forma de Reino Unido, donde el semaforo para los carros funciona de la siguiente manerna:
       *Verde, Amarillo, Rojo
       *Rojo, Amarillo, Verde
     El semanoforo peatonal son 2 colores, verde y rojo. Al oprimir el boton, el semaforo verde para el peaton esta activo, suena el Buzzer 
     para aquellas personas que no tienen la capacidad de ver. 
  2. Alarma con reedswitch y sensor PIR
     Existen muchos productos en la industria para tener una alarma:
       *Sensor de teperatura
       *Sensor de movimiento
       *entrada a un lugar
     En este programa se manejan as siguientes maneras:
       * Alarma con sensor de movimiento PIR: el PIR al detectar movimiento emite un sonido y prende una luz
       * Alarma con iman: el reedswitch al detectar una señal magnetica baja su voltaje/corriente provocando que emite un sonido y prenda una luz
 */

//SEMAFORO
const int CAR_RED = 7;    //luz roja vehicular inicializada en 7
const int CAR_YELLOW = 6; //luz roja vehicular inicializada en 6
const int CAR_GREEN = 5;  //luz roja vehicular inicializada en 5
const int PED_RED = 4;    //luz roja vehicular inicializada en 4
const int PED_GREEN = 3;  //luz roja vehicular inicializada en 3
const int BUTTON = 2;     //boton inicializado en 2
int crossTime = 10000; //time alloyoud to cross
unsigned long changeTime; //time since BUTTON pressed
int state = LOW; //if is push button

//ALARMA
//variables para sensor con reedswitch
int led = 9; //variable of the LED initialized in 9
int reedswitch = 11; //variable of the REED SWITCH initialized in 11
int buzzer = 10; //variable of the BUZZER initialized in 10
int val = 0; 
//variables ara sensor PIR
const int LEDPin= 8;
const int PIRPin= 12;


/*
The method setup() configures the pin of the lights of the traffic lights to behave like an exit with the method pinMode()
Also the method digitalWrite() Write a HIGH or a LOW value to a digital pin.
*/
void setup() {
  //SEMAFORO
  pinMode(CAR_RED, OUTPUT);
  pinMode(CAR_YELLOW, OUTPUT);
  pinMode(CAR_GREEN, OUTPUT);
  pinMode(PED_RED, OUTPUT);
  pinMode(PED_GREEN, OUTPUT);
  pinMode(BUTTON, INPUT); // button on pin 2
  digitalWrite(CAR_GREEN, HIGH);
  digitalWrite(PED_RED, HIGH);

  //ALARMA
    //pines para alarma con sensor de movimineto
  pinMode(LEDPin, OUTPUT);
  pinMode(PIRPin, INPUT);
  //pines para alarma con reedswitch
  pinMode(led, OUTPUT); //configure the LED pin to behave like an output 
  pinMode(reedswitch, INPUT); //configure the REED SWITCH pin to behave like an input
  pinMode(buzzer, OUTPUT); //configure the BUZZER pin to behave like an output 
}

/*
The method loop()has two conditions, one that verifies if the button is pressed, if it is true the variable "state" takes the value of "high",
the second validation is responsible for verifying if the variable "satate" has the value of "high" and if the time that has passed since
the button was pressed in greater than 10 seconds
*/
void loop() {
  //variables de lectura para reedswitch
  val = digitalRead(reedswitch); 
  //variables de lectura para sensor PIR
  int value= digitalRead(PIRPin); 
  
  //SEMAFORO: al llegar señal "HIGH" del boton
  if (digitalRead(BUTTON)) //Change of state is button is pressed
    state = HIGH;
  if (state == HIGH && (millis() - changeTime) > crossTime) {
    //realiza lo que se encuentra en el metodo "changeLight"
    changeLight();
    state = LOW;
  } else 

//ALARMA
//si el valor de señal del reedswitch es LOW
   if(val == LOW){ 
    //prende el led y el buzzer
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(200);  
  } else
  //si el valor del sensor es HIGH 
  if (value == HIGH)  {
    //el led prendey apaga 2 miliseg y el buzzer suena
    digitalWrite(LEDPin, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(LEDPin, LOW);
    digitalWrite(buzzer, HIGH);
    delay(50);
  } else {
    //al no encontrarse ningun valor en ninguna variable
    //leds y buzzer permanecen apagados
    digitalWrite(LEDPin, LOW);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);   
  }
}

/*
El metodo changeLight es utilizado para el cambio de luces de trafico con el metodo digitalWrite()
*/
void changeLight() {
  digitalWrite(CAR_GREEN, LOW); //green off
  digitalWrite(CAR_YELLOW, HIGH); //yellow on
  delay(2000); //wait 2 seconds
  digitalWrite(CAR_YELLOW, LOW); //green off
  digitalWrite(CAR_RED, HIGH); //yellow on
  delay(2000); //wait 2 seconds
  digitalWrite(PED_RED, LOW); //green off
  digitalWrite(PED_GREEN, HIGH); //yellow on
  delay(crossTime); //wait for
  for (int i = 0; i < 10; i++) {
    digitalWrite(PED_RED, HIGH); //Turn on red pedestrian traffic light
    delay(250);//wait 250 milliseconds
    digitalWrite(PED_GREEN, LOW);//Turn off green pedestrian traffic light
    delay(250);//wait 250 milliseconds
  }
  digitalWrite(PED_RED, HIGH);//Turn on red pedestrian traffic light
  delay(500);//wait 500 milliseconds
  digitalWrite(CAR_YELLOW, HIGH);//turn on the yellow light of the traffic lights of the vehicles
  digitalWrite(CAR_RED, LOW);//turn on the red light of the traffic lights of the vehicles
  delay(1000);//wait 500 milliseconds
  digitalWrite(CAR_GREEN, HIGH);//turn on the green light of the traffic lights of the vehicles
  digitalWrite(CAR_YELLOW, LOW);//turn on the yellow light of the traffic lights of the vehicles

  //record the time size last change of lights
  changeTime = millis();
  //then return to the my program loop
}


