#include <Termometro.h>
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7, ERRORS)    //digo que voy a usar la conexion rs232

int8 temperatura, temperatura1;         //declaro que temperatura y temperatura1 van a ser variables de 8 bits
float dato1;                           //declaro que dato1 va a ser de tipo flotante

void main()
{
setup_adc(ADC_CLOCK_INTERNAL);     //digo qu voy a usar el reloj interno para el CAD
SETUP_ADC_PORTS(AN0);            //digo que voy a usar un solo CAD que es el AN0 del pic en el puerto A0

while(TRUE)
{
set_adc_channel(0);           //utilizo el canal 0 del CAD
delay_us(10);                 //espero 10 microsegundos
temperatura1 = read_adc();     //leo el CAD y los datos obtenidos los guardo en la variable temperatura
temperatura1 = temperatura*2; //los datos obtenidos los multiplico por dos para tener valores exactos y los guardo en la variable temperatura1
putc(temperatura1);           //envío los valores de temperatura1 a través de la conexión rs232

if(kbhit())                    //pregunto si el pic recibe datos del otro pic a través de la conexion rs232
{                              //si recibe entonces:
 dato1 = getc();               //los datos recibidos los guardo en la variable dato1
 if(dato1 == 1)               //pregunto si dato1 es igual a 1
 {
 output_high(PIN_B0);         //si lo es, entonces prendo el led azul
 output_low(PIN_B1);          //apago el led verde
 output_low(PIN_B2);          //apago el led rojo
 output_high(PIN_B3);         //prendo el buzzer
 }
 else if(dato1 == 2)          //si no, entonces pregunto si es igual a 2
 {
 output_low(PIN_B0);          //si lo es, entonces apago el led azul
 output_low(PIN_B1);          //apago el led verde
 output_high(PIN_B2);         //prendo el led rojo
 output_high(PIN_B3);         //prendo el buzzer
 }
 else                         //si no, entonces 
 {
 output_low(PIN_B0);          //apago el led azul
 output_high(PIN_B1);         //prendo el led verde
 output_low(PIN_B2);          //apago el led rojo
 output_low(PIN_B3);          //apago el buzzer
 }
 }                            //si no, entonces no hago lo anterior
 delay_ms(250);               //espero 250 milisegundos
 }
}
