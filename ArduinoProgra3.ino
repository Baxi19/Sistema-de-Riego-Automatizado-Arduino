//Instituto Tecnológico de Costa Rica
//Campus Tecnológico Local San Carlos
//Escuela de Ingenieria en computacion
//Proyecto en Arduino
//Randald Villegas
//Programa para medir la humedad del suelo por medio de un sensor
//Y activar un sistema de riego cuando la planta lo necesita
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
bool portada = false;
//funcion para imprimir en pantalla
void show(int columna, int fila, String texto ) {
  lcd.setCursor(columna, columna);
  lcd.print(texto);
  
}
//Funcion para configuraciones
void setup() {
  lcd.begin(16, 2);
  Serial.begin(115200);

}
//ciclo de aplicacion
void loop() {
  //Puerto que se utiliza en el arduino para la entrada de las lecturas del sensor de humedad en este caso
  int humedad = analogRead(A0);
  Serial.print("La humedad es: ");
  Serial.println(humedad);
  lcd.clear();
  if(portada == false ){
    String texto = "Tecnologico de";
    show(0,0,texto);
    String aux = "Costa Rica";
    show(1,0,aux);
    delay(3000);
    
    lcd.clear();
    String texto1 = "Ingenieria en";
    show(0,0,texto1);
    String aux1 = "Computacion";
    show(1,0,aux1);
    delay(3000);
    
    lcd.clear();
    String texto3 = "Campus TEC";
    show(0,0,texto3);
    String aux3 = "Local San Carlos";
    show(1,0,aux3);
    delay(3000);





    lcd.clear();
    String texto4 = "Estudiantes: ";
    show(0,0,texto4);
    delay(1000);
    
    lcd.clear();
    String texto5 = "Randald";
    show(0,0,texto5);
    String aux5 = "Villegas B.";
    show(1,0,aux5);
    delay(3000);
    
    lcd.clear();
    String texto6 = "Gabriel";
    show(0,0,texto6);
    String aux6 = "Ruiz C.";
    show(1,0,aux6);
    delay(3000);
    
    lcd.clear();
    String texto7 = "Kervin";
    show(0,0,texto7);
    String aux7 = "Sibaja R.";
    show(1,0,aux7);
    delay(3000);
    
    lcd.clear();
    String texto8 = "Daniel";
    show(0,0,texto8);
    String aux8 = "Vargas G.";
    show(1,0,aux8);
    delay(3000);




    
    lcd.clear();
    String texto2 = "Sistema de Riego";
    show(0,0,texto2);
    String aux2 = "Automatizado";
    show(1,0,aux2);
    delay(3000);
    lcd.clear();
    
    portada = true;
  }
  if (humedad >= 1000) {
    int lecturaPorcentaje = map(humedad, 1023, 0, 0, 100);
    Serial.print(lecturaPorcentaje);
    Serial.println( "%");
    Serial.println("El sensor se encuentra desconectado o fuera del suelo.....");
    String texto = "Fuera del Suelo";
    show(0,0,texto);
    String aux = "Humedad :";
    show(1,0,aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10,0,lecturaTexto);

  } else if (humedad < 1000 && humedad >= 600) {
    int lecturaPorcentaje = map(humedad, 1023, 0, 0, 100);
    Serial.print(lecturaPorcentaje);
    Serial.println( "%");
    Serial.println("El suelo se encuentra seco");
    String texto = "Suelo Seco!!";
    show(0,0,texto);
    String aux = "Humedad :";
    show(1,0,aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10,0,lecturaTexto);
    
  } else if (humedad < 600 && humedad >= 370) {
    int lecturaPorcentaje = map(humedad, 1023, 0, 0, 100);
    Serial.print(lecturaPorcentaje);
    Serial.println( "%");
    Serial.println("El suelo esta humedo");
    String texto = "Suelo Humedo";
    show(0,0,texto);
    String aux = "Humedad :";
    show(1,0,aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10,0,lecturaTexto);
    
  } else if (humedad <  370) {
    int lecturaPorcentaje = map(humedad, 1023, 0, 0, 100);
    Serial.print(lecturaPorcentaje);
    Serial.println( "%");
    Serial.println("El sensor esta practicamente en agua");
    String texto = "Sensor en Agua";
    show(0,0,texto);
    String aux = "Humedad :";
    show(1,0,aux);
    String lecturaTexto = (String) lecturaPorcentaje;
    show(10,0,lecturaTexto);
  }
  delay(1000);


}
