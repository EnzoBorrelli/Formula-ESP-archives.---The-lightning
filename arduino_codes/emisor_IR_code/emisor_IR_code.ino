/*
----CODIGO DE MODULO EMISOR IR----
este codigo se debera agregar al codigo principal, verificando lo puesto en los comentarios


                                                           Formula ESP archives- 2022
*/
// numero del pin del LED
const int ledPin = 22;  // 2 corresponde a GPIO2

// propiedades PWM
const int freq = 38000; // frecuencia que usa el receptor
const int ledChannel = 0; // canal pwm 0-15 (verificar los canales ya usados)
const int resolution = 8; //resolucion 8 bits para un valor maximo de 255
 
void setup(){
  Serial.begin(1200);
  // setup del led
  ledcSetup(ledChannel, freq, resolution);
  
  // se une el pin con el canal pwm
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
    ledcWrite(ledChannel,255);// led en valor maximo (HIGH)
    int count=1; //cambiar esto por su "codigo" a enviar al receptor
    Serial.println(count); //mensaje a enviar por TX0
  
  }
