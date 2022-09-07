#define PIN_MOTOR_IN_1 32
#define PIN_MOTOR_IN_2 33
#define PIN_MOTOR_IN_3 26
#define PIN_MOTOR_IN_4 27

const int PWM_MOTOR_IN_1 = 0;
const int PWM_MOTOR_IN_2 = 1;
const int PWM_MOTOR_IN_3 = 2;
const int PWM_MOTOR_IN_4 = 3;

const int frecuencia = 10000;
const int resolucion = 8;

void setup() {

  ledcSetup(PWM_MOTOR_IN_1, frecuencia, resolucion);
  ledcSetup(PWM_MOTOR_IN_2, frecuencia, resolucion);
  ledcSetup(PWM_MOTOR_IN_3, frecuencia, resolucion);
  ledcSetup(PWM_MOTOR_IN_4, frecuencia, resolucion);

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