/**************************************************************
Con este proyecto de facil aplicacion
se puede controlar y activar una alarma la cual envia la notificacion
al Correo electronico, de que se ha detectado movimiento.
 **************************************************************/

#define BLYNK_PRINT Serial    //Comente esto para desactivar impresiones y ahorrar espacio
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Su authtoken generado por la aplicacion Blynk
char auth[] = "4EEJuRsEh0puffvPe1wBcxAB6hOkhljJ";


//Datos para la conexion de Red Wifi.
char ssid[] = "FLIA.WEITZEL"; //Nombre de la red WIFI
char pass[] = "20203030"; //contraseña de la red WIFI

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);

  // Envia correo electrónico cuando el hardware se conecte al servidor de Blynk
  //Parametros por defecto "Correo electronico", "Asunto", "Mensaje a enviar"
  
  Blynk.email("andres96energy@hotmail.com","Conexion Activa", "El ESP8266 esta Online.");
  pinMode(5, INPUT);// pin D1(GPIO5) como entrada
  pinMode(4,OUTPUT);// pin D2(GPIO4) como Salida
}
//Creo una funcion alarma
void Alarma()
{
  // si la alarma se activa este envia un correo y espera 15 segundos.

  int Sensor = digitalRead(5); // variable para almacenar los estados del PIR(lee el pin de entrada)
 
  if (Sensor == 1) // si el sensor detecta movimiento
  {
    Serial.println("Alarma Activada"); //Imprime por el monitor serial
    Blynk.email("andres96energy@hotmail.com","AlarmaWIFI", "Se ha detectado movimiento!!.");
     delay(200);
  }
}
void loop()
{
  Alarma();//Invoca  nuestra funcion creada
  Blynk.run();//Invoca la funcion run de la Libreria Blynk

  //ACLARAR QUE CADA 15 SEG SE MANDA UN MSJ DE ACTIVACION DE LA ALARMA, EN CASO DE QUE LA DETECCION 
  //SEA CONTINUA, RESPETA LA ESPERA DE LA MISMA.eSTO ES CONFIGURACION DE LA LIBRERIA.
  
}
