/*  
Библиотека предназначена для работы arduino с
DHT11 - http://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-trema-modul.html
DHT22 - http://iarduino.ru/shop/Sensory-Datchiki/cifrovoy-datchik-temperatury-i-vlazhnosti-vysokoy-tochnosti-trema-modul.html
*/

#include <DHT_iarduino.h>
DHT	sensor;
int	result;

void setup() {
	Serial.begin(9600);
	delay(1000);
}
void loop() {
	result = sensor.read(4); // нужно указать № вывода (сейчас 4pin)
	switch(result){
		case DHT_OK:			Serial.println((String)	"CEHCOP B KOMHATE: "+sensor.hum+"% - "+sensor.tem+"*C");	break;
		case DHT_ERROR_CHECKSUM:	Serial.println(		"CEHCOP B KOMHATE: HE PABEHCTBO KC");				break;
		case DHT_ERROR_DATA:		Serial.println(		"CEHCOP B KOMHATE: OTBET HE COOTBETCTB. CEHCOPAM 'DHT'");	break;
		case DHT_ERROR_NO_REPLY:	Serial.println(		"CEHCOP B KOMHATE: HET OTBETA");				break;
		default:			Serial.println(		"CEHCOP B KOMHATE: ERROR");					break;
	}
//	Количество опрашиваемых сенсоров ограничено количеством свободных выводов и самих сенсоров.
//	Библиотека DHT.h сама определяет тип сенсора (DHT11, DHT21, DHT22)
//	Если нужно опросить еще датчик на 5 pin, то пишем без задержек:
//	result = sensor.read(5);
//	switch(result){
//		case DHT_OK:			Serial.println((String)	"CEHCOP 3A OKHOM: "+sensor.hum+"% - "+sensor.tem+"*C");	break;
//		case DHT_ERROR_CHECKSUM:	Serial.println(		"CEHCOP 3A OKHOM: HE PABEHCTBO KC");				break;
//		case DHT_ERROR_DATA:		Serial.println(		"CEHCOP 3A OKHOM: OTBET HE COOTBETCTB. CEHCOPAM 'DHT'");	break;
//		case DHT_ERROR_NO_REPLY:	Serial.println(		"CEHCOP 3A OKHOM: HET OTBETA");					break;
//		default:			Serial.println(		"CEHCOP 3A OKHOM: ERROR");					break;
//	}
	delay(2000);
}
