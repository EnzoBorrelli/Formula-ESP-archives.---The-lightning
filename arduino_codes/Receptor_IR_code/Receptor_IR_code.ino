/*
----CODIGO DE Receptor IR----
este es el codigo del L.T.M. (medidor de tiempo de vuelta)
                                                           Formula ESP archives- 2022
*/

//corredores (1-250)
#define HONEY_BADGER 3
#define TOYO_CARS 9
#define THE_LIGHTNING 24
#define DBB_001 25

class Corredor {
private:
  int ID_corredor;

  enum PASADAS {
    INICIO = 1,
    PRIMERA_VUELTA,
    SEGUNDA_VUELTA,
    TERCERA_VUELTA,
    //limitador
  };

public:
  Corredor(int ID) {
    ID_corredor = ID;
  }

  String tiempos_vueltas(int dato_corredor) {
    dato_corredor = ID_corredor;
    int numero_pasadas;
    if (dato_corredor == ID_corredor) numero_pasadas++;

    //tiempos
    unsigned long tiempo_inicial;
    unsigned long tiempo_final_v1;
    unsigned long tiempo_primera_vuelta;
    unsigned long tiempo_final_v2;
    unsigned long tiempo_segunda_vuelta;
    unsigned long tiempo_final_v3;
    unsigned long tiempo_tercera_vuelta;

    //casos
    switch (numero_pasadas) {
      case INICIO:
        {
          tiempo_inicial = millis();
          break;
        }
      case PRIMERA_VUELTA:
        {
          tiempo_final_v1 = millis();
          tiempo_primera_vuelta = tiempo_final_v1 - tiempo_inicial;
          String primera_vuelta = "corredor " + String(dato_corredor) + " primera vuelta " + Conversor_tiempo(tiempo_primera_vuelta);
          return primera_vuelta;
          break;
        }
      case SEGUNDA_VUELTA:
        {
          tiempo_final_v2 = millis();
          tiempo_segunda_vuelta = tiempo_final_v2 - tiempo_final_v1;
          String segunda_vuelta = "dato_corredor " + String(dato_corredor) + " segunda vuelta " + Conversor_tiempo(tiempo_segunda_vuelta);
          return segunda_vuelta;
          break;
        }
      case TERCERA_VUELTA:
        {
          tiempo_final_v3 = millis();
          tiempo_tercera_vuelta = tiempo_final_v3 - tiempo_final_v2;
          String tercera_vuelta = "corredor " + String(dato_corredor) + " tercera vuelta " + Conversor_tiempo(tiempo_tercera_vuelta);
          return tercera_vuelta;
          break;
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

      String vuelta = "tiempo = " + String(minutes) + ":" + String(seconds) + ":" + String(miliseconds);
      return vuelta;
    }
  }
};

class Ultrasonido {
private:
#define TRIGGER 32
#define ECHO 33

  int _distancia;
  unsigned long _tiempo;

public:
  Ultrasonido() {

    pinMode(TRIGGER, OUTPUT);
    pinMode(ECHO, INPUT);
    digitalWrite(TRIGGER, LOW);
  }
  int GetDistancia() {
    digitalWrite(TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER, LOW);
    _tiempo = pulseIn(ECHO, HIGH);
    _distancia = _tiempo / 59;
    return _distancia;
  }
};

Corredor *Toyo_cars = new Corredor(TOYO_CARS);
Corredor *The_Lightning = new Corredor(THE_LIGHTNING);
Corredor *dbb_001 = new Corredor(DBB_001);
Corredor *Honey_Badger = new Corredor(HONEY_BADGER);

Ultrasonido *Sensor = new Ultrasonido();

void tiempo_corredores(int id) {
  Toyo_cars->tiempos_vueltas(id);
  The_Lightning->tiempos_vueltas(id);
  dbb_001->tiempos_vueltas(id);
  Honey_Badger->tiempos_vueltas(id);
  //agregar mqtt
}

void setup() {
  Serial.begin(1200);
}

void loop() {
  int dato;
  int sensor=Sensor->GetDistancia();
  
  if (Serial.available()) {
    dato = int(Serial.read());
    Serial.println(dato);
    Serial.println(sensor);
  }
}