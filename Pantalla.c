#include <Pantalla.h>
#include <LCD.c>   //incluyo la libreria del lcd
#use rs232(xmit=PIN_C6, rcv=PIN_C7, ERRORS)   //digo que voy a usar la conexión rs232

float temperatura2;     // declaro que la variable temperatura2 va a ser de tipo flotante
unsigned int8 dato;             //declaro que la variable dato va a ser de 8 bits

void main()
{
   lcd_init();          //prendo el lcd
   while(TRUE)          
   {
   if(kbhit())             //pregunto si el pic recibe datos del otro pic a través de la conexion rs232
   {                       //si recibe entonces:
   temperatura2 = getc();  //los datos recibidos los guardo en la variable temperatura2
   printf(lcd_putc, "\fTEMPERATURA \n %f C", temperatura2);   //el lcd va a mostrar en la parte superior la palabra "TEMPERATURA"
                                                              // y en la parte inferior los datos recibidos
   if(temperatura2<30)                //pregunto si la variable temperatura2 es menor a 30
   {
   dato = 1;                           //si es menor a 30, entonces la variable dato será 1
   }
   else if(temperatura2 > 40)          //si no, entonces pregunto si temperatura2 es mayor a 40
   {
   dato = 2;                        //si es mayor a 40, entonces la variable dato será 2
   }
   else
   {
   dato = 3;                  //si no, entonces la variable dato será 3
   }
   putc(dato);              //envío el valor que tiene dato para que el otro pic lo reciba a través de la conexion rs232  
   delay_ms(250);             //espero 250 milisegundos
   }                         //si no recibe, entonces vuelvo a preguntar
   }
}
