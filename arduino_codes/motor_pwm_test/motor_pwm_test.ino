#define PIN_MOTOR_IN_1 27
#define PIN_MOTOR_IN_2 26
#define PIN_MOTOR_IN_3 25
#define PIN_MOTOR_IN_4 33

#define PWM_MOTOR_IN_1 0
#define PWM_MOTOR_IN_2 1
#define PWM_MOTOR_IN_3 2
#define PWM_MOTOR_IN_4 3

#define FREQ 10000
#define RESOLUCION 8

void setup() {

  ledcSetup(PWM_MOTOR_IN_1, FREQ, RESOLUCION);
  ledcSetup(PWM_MOTOR_IN_2, FREQ, RESOLUCION);
  ledcSetup(PWM_MOTOR_IN_3, FREQ, RESOLUCION);
  ledcSetup(PWM_MOTOR_IN_4, FREQ, RESOLUCION);

  ledcAttachPin(PIN_MOTOR_IN_1, PWM_MOTOR_IN_1);
  ledcAttachPin(PIN_MOTOR_IN_2, PWM_MOTOR_IN_2);
  ledcAttachPin(PIN_MOTOR_IN_3, PWM_MOTOR_IN_3);
  ledcAttachPin(PIN_MOTOR_IN_4, PWM_MOTOR_IN_4);
}

void loop() {
  int CT = 0;  //ciclo de trabajo
  while (CT < 255) {
    ledcWrite(PWM_MOTOR_IN_1, CT);
    delay(50);
    CT++;
  }
  CT = 0;
  while (CT < 255) {
    ledcWrite(PWM_MOTOR_IN_2, CT);
    delay(50);
    CT++;
  }
  CT = 0;
  while (CT < 255) {
    ledcWrite(PWM_MOTOR_IN_3, CT);
    delay(50);
    CT++;
  }
  CT = 0;
  while (CT < 255) {
    ledcWrite(PWM_MOTOR_IN_4, CT);
    delay(50);
    CT++;
  }
  CT = 0;
}