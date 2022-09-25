#include <PS4Controller.h>
#include <ps4.h>
#include <ps4_int.h>

/* ____________________________________
   Formula ESP archives - The Lightning
   ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯

Codigo principal del proyecto 

                               Enzo G. Borrelli A. - 2022 
 */

TaskHandle_t Tarea_EMISOR;

#define CAR_ID 24

#define PIN_LED 23  // 2 corresponde a GPIO2

// propiedades PWM
#define FRECUENCIA 38000  // frecuencia que usa el receptor
#define PWM_LED 0         // canal pwm 0-15
#define RESOLUCION 8      //resolucion 8 bits para un valor maximo de 255

void EmisorIR(void* pvParameters) {

  for (;;) {
    ledcWrite(PWM_LED, 255);  // led en valor maximo (HIGH)
    int ID = CAR_ID;          //cambiar esto por su "ID" a enviar al receptor
    Serial.println(ID);       //mensaje a enviar por TX0
  }
}

//defines motores

#define PIN_MOTOR_IN_1 27
#define PIN_MOTOR_IN_2 26
#define PIN_MOTOR_IN_3 25
#define PIN_MOTOR_IN_4 33

#define PWM_MOTOR_IN_1 0
#define PWM_MOTOR_IN_2 1
#define PWM_MOTOR_IN_3 2
#define PWM_MOTOR_IN_4 3

#define FREQ_MOTOR 10000

class Motores {

public:
  Motores() {


    ledcSetup(PWM_MOTOR_IN_1, FREQ_MOTOR, RESOLUCION);
    ledcSetup(PWM_MOTOR_IN_2, FREQ_MOTOR, RESOLUCION);
    ledcSetup(PWM_MOTOR_IN_3, FREQ_MOTOR, RESOLUCION);
    ledcSetup(PWM_MOTOR_IN_4, FREQ_MOTOR, RESOLUCION);

    ledcAttachPin(PIN_MOTOR_IN_1, PWM_MOTOR_IN_1);
    ledcAttachPin(PIN_MOTOR_IN_2, PWM_MOTOR_IN_2);
    ledcAttachPin(PIN_MOTOR_IN_3, PWM_MOTOR_IN_3);
    ledcAttachPin(PIN_MOTOR_IN_4, PWM_MOTOR_IN_4);
  }

  void Avanzar(int velocidad) {
    ledcWrite(PWM_MOTOR_IN_1, velocidad);
    ledcWrite(PWM_MOTOR_IN_2, LOW);

    ledcWrite(PWM_MOTOR_IN_3, velocidad);
    ledcWrite(PWM_MOTOR_IN_4, LOW);
  }

  void Retroceder(int velocidad) {
    ledcWrite(PWM_MOTOR_IN_2, velocidad);
    ledcWrite(PWM_MOTOR_IN_1, LOW);

    ledcWrite(PWM_MOTOR_IN_4, velocidad);
    ledcWrite(PWM_MOTOR_IN_3, LOW);
  }

  void Parar() {
    ledcWrite(PWM_MOTOR_IN_1, LOW);
    ledcWrite(PWM_MOTOR_IN_2, LOW);

    ledcWrite(PWM_MOTOR_IN_3, LOW);
    ledcWrite(PWM_MOTOR_IN_4, LOW);
  }
};

class Stepper {
private:

public:
  Stepper() {
  }
};

class Led_rgb {
private:

public:
  Led_rgb() {
  }
};

class Buzzer {
private:

public:
  Buzzer() {
  }
};


Motores* Ruedas = new Motores();

//logica principal
void PS4_logic() {
  if (PS4.isConnected()) {
    if (PS4.Right()) Serial.println("Right Button");
    if (PS4.Down()) Serial.println("Down Button");
    if (PS4.Up()) Serial.println("Up Button");
    if (PS4.Left()) Serial.println("Left Button");

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");

    if (PS4.UpRight()) Serial.println("Up Right");
    if (PS4.DownRight()) Serial.println("Down Right");
    if (PS4.UpLeft()) Serial.println("Up Left");
    if (PS4.DownLeft()) Serial.println("Down Left");

    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.Share()) Serial.println("Share Button");
    if (PS4.Options()) Serial.println("Options Button");
    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {
      Ruedas->Retroceder(100);
    }
    if (PS4.R2()) {
      Ruedas->Avanzar(100);
    }
    delay(50);
  }
}
void setup() {

  PS4.begin("c0:38:96:af:ac:b9");
  Serial.begin(1200);

  /* [bloque de codigo del emisor] */

  // setup del led
  ledcSetup(PWM_LED, FRECUENCIA, RESOLUCION);
  ledcAttachPin(PIN_LED, PWM_LED);

  //se crea una tarea que ejecutara EmisorIR(), con prioridad 1 y en el nucleo 0.
  xTaskCreatePinnedToCore(
    EmisorIR,       /* Funcion de la tarea. */
    "Tarea_EMISOR", /* nombre de la tarea. */
    10000,          /* tamaño de la tarea */
    NULL,           /* parametro de la tarea */
    1,              /* prioridad de la tarea */
    &Tarea_EMISOR,  /* Controlador de tareas */
    0);             /* pin de la tarea a nuecleo 0 */
  delay(200);
  //
}

void loop() {
  // put your main code here, to run repeatedly:
}