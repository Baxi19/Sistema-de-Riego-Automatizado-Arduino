/*---------------------------------------------------------------------------------------------------------*/
//Instituto Tecnológico de Costa Rica
//Campus Tecnológico Local San Carlos
//Escuela de Ingeniería en computación
//Proyecto en Arduino
//Randald Villegas
//Programa para medir la humedad del suelo por medio de un sensor
//Y activar un sistema de riego cuando la planta lo necesita


/*---------------------------------------------------------------------------------------------------------*/
//import y variables para el sistema
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool portada = false;
int relay = 6;
bool riegoActivado = false;
int contador = 0;

/*VARIABLES QUE SE PUEDEN REGULAR*/
int sensorDesconectado = 4;
int tierraSeca = 10;
int tierraHumeda = 45;
int sensorAgua = 65;

/*---------------------------------------------------------------------------------------------------------*/
//funcion para imprimir en pantalla
void show(int columna, int fila, String texto ) {
  lcd.setCursor(columna, columna);
  lcd.print(texto);
}

/*---------------------------------------------------------------------------------------------------------*/
//funcion para imprimir portada
void imprimePortada() {
  lcd.clear();
  String texto = "Tecnologico de";
  show(0, 0, texto);
  String aux = "Costa Rica";
  show(1, 0, aux);
  delay(2000);

  lcd.clear();
  String texto1 = "Ingenieria en";
  show(0, 0, texto1);
  String aux1 = "Computacion";
  show(1, 0, aux1);
  delay(2000);

  lcd.clear();
  String texto3 = "Campus TEC";
  show(0, 0, texto3);
  String aux3 = "Local San Carlos";
  show(1, 0, aux3);
  delay(2000);

  lcd.clear();
  String texto10 = "Profesor: ";
  show(0, 0, texto10);
  delay(1000);

  lcd.clear();
  String texto11 = "Jorge";
  show(0, 0, texto11);
  String aux11 = "Alfaro V.";
  show(1, 0, aux11);
  delay(2000);

  lcd.clear();
  String texto4 = "Estudiantes: ";
  show(0, 0, texto4);
  delay(1000);

  lcd.clear();
  String texto5 = "Randald";
  show(0, 0, texto5);
  String aux5 = "Villegas B.";
  show(1, 0, aux5);
  delay(2000);

  lcd.clear();
  String texto6 = "Gabriel";
  show(0, 0, texto6);
  String aux6 = "Ruiz C.";
  show(1, 0, aux6);
  delay(1000);

  lcd.clear();
  String texto7 = "Kervin";
  show(0, 0, texto7);
  String aux7 = "Sibaja R.";
  show(1, 0, aux7);
  delay(1000);

  lcd.clear();
  String texto8 = "Daniel";
  show(0, 0, texto8);
  String aux8 = "Vargas G.";
  show(1, 0, aux8);
  delay(1000);

  lcd.clear();
  String texto2 = "Sistema de Riego";
  show(0, 0, texto2);
  String aux2 = "Automatizado";
  show(1, 0, aux2);
  delay(2000);
  lcd.clear();

  portada = true;
}

/*---------------------------------------------------------------------------------------------------------*/
//Funcion para configuraciones
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(A0, INPUT);
  pinMode(relay, OUTPUT);
  
}

/*---------------------------------------------------------------------------------------------------------*/
//ciclo de aplicacion
void loop() {

 
  //Puerto que se utiliza en el arduino para la entrada de las lecturas del sensor de humedad en este caso
  int humedad = analogRead(A0);
  lcd.clear();
  int lecturaPorcentaje = map(humedad, 1023, 0, 0, 100);
  String lecturaTexto = (String) lecturaPorcentaje;
  int tamano = lecturaTexto.length();
    
  //si es la primera iteracion se imprime la portada
  if (portada == false ) {
    digitalWrite(relay, LOW);
    imprimePortada();
  }

  
  //Si el porcentaje se encuentra fuera del rango
  if((tamano >= 3)&& (lecturaPorcentaje != 100 )){
    lcd.clear();
    String texto = "Verificar";
    show(0, 0, texto);
    String aux = "sensor...";
    show(1, 0, aux);
    digitalWrite(relay, LOW);
  
  //si esta fuera del suelo  se mantine la bomba apagada ( > 4%)
  }else if ((lecturaPorcentaje >= 0) && (lecturaPorcentaje < sensorDesconectado) ) {
    String texto = "Fuera del Suelo";
    show(0, 0, texto);
    String aux = "Humedad :";
    show(1, 0, aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10, 0, lecturaTexto);
    digitalWrite(relay, LOW);
    

    //si el suelo  esta seco se enciende la bomba ( > 4% y < 20%)
  } else if ((lecturaPorcentaje > sensorDesconectado) && (lecturaPorcentaje <= tierraSeca ) ) {
    String texto = "Suelo Seco!!";
    show(0, 0, texto);
    String aux = "Humedad :";
    show(1, 0, aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10, 0, lecturaTexto);
    digitalWrite(relay, HIGH);
    

    //si ya se encuentra lo suficientemente humedo se apaga la bomba ( > 30% y < 45%)
  } else if ((lecturaPorcentaje > tierraSeca) && (lecturaPorcentaje <= tierraHumeda )) {
    String texto = "Suelo Humedo";
    show(0, 0, texto);
    String aux = "Humedad :";
    show(1, 0, aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10, 0, lecturaTexto);
    digitalWrite(relay, LOW);
    

  //si se encuentra dentro del agua( > 65% )
  } else if ((lecturaPorcentaje >= sensorAgua )) {
    String texto = "Sensor en Agua";
    show(0, 0, texto);
    String aux = "Humedad :";
    show(1, 0, aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10, 0, lecturaTexto);
    digitalWrite(relay, LOW);
    
  }

  contador += 1;
  if (contador == 180) {
    portada = false;
    contador = 0;
  }
  delay(1000);


}
