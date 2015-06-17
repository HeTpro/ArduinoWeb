#include <rDHT11.h>

// Establecemos el pin digital al que conectamos la línea de datos 
// del sensor
int rDHT11pin = 12;
// Declaramos una variable que será la utilizada para 
rDHT11 DHT11(rDHT11pin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int result = DHT11.update();
  int temperatura = 0;
  int humedad = 0;
    switch (result)
  {
    case rDHT11Definitions::OK: 
		//Serial.println("OK"); 
                // Mostramos los valores recogidos
                //Serial.print("Humidity (%): ");
               humedad = 10*((float)DHT11.getHumidity());
              //  Serial.print("Temperature (oC): ");
               temperatura = 10*((float)DHT11.getCelsius());
            //    Serial.print("Dew Point (oC): ");
              //  Serial.println(DHT11.getDewPoint());
              //Serial.println(humedad);
              //Serial.println(temperatura);
		break;
    case rDHT11Definitions::CHECKSUM_ERROR: 
		humedad = 1004;
                temperatura = 1004;
		break;
    case rDHT11Definitions::TIMEOUT_ERROR: 
		humedad = 1002;
                temperatura = 1002;
		break;
    default: 
		humedad = 1003;
                temperatura = 1003;
		break;
  }
  
  // Necesitamos esperar dos segundos entre dos peticiones de datos
  // consecutivas
  delay(2000);
  Serial.println(humedad);
  Serial.println(temperatura);
}
