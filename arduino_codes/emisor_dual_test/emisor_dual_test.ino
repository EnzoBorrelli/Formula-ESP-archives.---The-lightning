/*
----MODULO EMISOR IR----
este codigo se debera agregar al codigo principal, modificando lo especificado en los comentarios.


                                                           Formula ESP archives- 2022
*/
// [bloque de codigo a incluir fuera del setup]
TaskHandle_t Tarea_EMISOR;

// numero del pin del LED (cambiar por el pin que utilices)

#define PIN_LED 2  // 2 corresponde a GPIO2

// propiedades PWM
#define FRECUENCIA 38000  // frecuencia que usa el receptor (NO MODIFICAR)
#define PWM_LED 0         // canal pwm 0-15 (verificar los canales ya usados)
#define RESOLUCION 8      //resolucion 8 bits para un valor maximo de 255 (NO MODIFICAR)

void EmisorIR(void* pvParameters) {

  for (;;) {
    ledcWrite(PWM_LED, 255);  // led en valor maximo (HIGH)
    int ID = 1;               //cambiar esto por su "ID" a enviar al receptor
    Serial.println(ID);       //mensaje a enviar por TX0
  }
}
//

void setup() {

  /* [bloque de codigo a incluir en el setup] */

  Serial.begin(1200);
  // setup del led
  ledcSetup(PWM_LED, FRECUENCIA, RESOLUCION);

  // se une el pin con el canal pwm
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
}