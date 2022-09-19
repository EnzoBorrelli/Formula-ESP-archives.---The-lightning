void ID(int corredor) {
  switch (usuario) {
    case 1:
      {
      }
  }
}

unsigned long vuelta(int corredor) {

  enum PASADAS {
    INICIO = 1,
    PRIMERA_VUELTA,
    SEGUNDA_VUELTA,
    TERCERA_VUELTA,
  };

  int ID = 0;
  int numero_pasadas;
  if (ID == corredor) numero_pasadas++;

  switch (numero_pasadas) {
    case INICIO:
      {
      }
    case PRIMERA_VUELTA:
      {
      }
    case SEGUNDA_VUELTA:
      {
      }
    case TERCERA_VUELTA:
      {
      }
  }
}

String Conversor_tiempo(int tiempo) {
  unsigned int seconds = 0;
  unsigned int minutes = 0;
  unsigned long miliseconds = tiempo;

  while (tiempo > 1) {
    if (miliseconds > 999) {
      miliseconds = miliseconds - 1000;
      seconds++;
    }
    if (seconds > 59) {
      seconds = seconds - 60;
      minutes++;
    }
    if (miliseconds <= 999) tiempo = 0;

    String vuelta = "el tiempo de vuelta es = " + String(minutes) + ":" + String(seconds) + ":" + String(miliseconds);
    return vuelta;
  }
}

void setup() {
  Serial.begin(1200);
}

void loop() {
  int dato;
  if (Serial.available()) {
    dato = int(Serial.read());
  }
}