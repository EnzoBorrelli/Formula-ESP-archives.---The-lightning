
#define LED_ROJO_PIN 4
#define LED_VERDE_PIN 2
#define LED_AZUL_PIN 15

const int led_rojo_PWM = 0;
const int led_verde_PWM = 1;
const int led_azul_PWM = 2;// 0-15

const int frequency = 10000; // Hz
const int resolution = 8; // resolution bits


int rojo[3] = {255,0,0};
int verde[3] = {0,255,0};
int azul[3] = {0,0,255};

void Color_RGB(int r, int g, int b){
  ledcWrite(led_rojo_PWM,r);
  ledcWrite(led_verde_PWM,g);
  ledcWrite(led_azul_PWM,b);
}


void setup()
{
  ledcSetup(led_rojo_PWM, frequency, resolution);
  ledcSetup(led_verde_PWM, frequency, resolution);
  ledcSetup(led_azul_PWM, frequency, resolution);

  ledcAttachPin(LED_ROJO_PIN, led_rojo_PWM);
  ledcAttachPin(LED_VERDE_PIN, led_verde_PWM);
  ledcAttachPin(LED_AZUL_PIN, led_azul_PWM);
}
void loop(){
 Color_RGB(rojo[0],rojo[1],rojo[2]);
 delay(1000);
 Color_RGB(verde[0],verde[1],verde[2]);
 delay(1000);
 Color_RGB(azul[0],azul[1],azul[2]);
 delay(1000);
}