#include <16F877A.h>                                     //PIC 16F877A
#device ADC=10                                           //Habilitamos el uso del m�dulo ADC
#fuses XT, NOWDT, PUT, NOLVP, NOPROTECT                  //Bits de configuraci�n
#use delay(clock=4000000)                                //Crista de 4HMz
#use fast_io(A)   
#use fast_io(B)   
#use fast_io(C)

unsigned int16 analog;
int1 derecha;   //izquierda == a0
int1 izquierda;   //derecha == a1
int1 freno;   //freno  == a3
int1 vel;   //velocidad == a2

void main(){
   set_tris_a(0b00000000);
   set_tris_c(0);
   set_tris_e(0);
   //set_tris_c(0b11111111);
   output_high(PIN_a0);
   output_high(PIN_a1);
   output_high(PIN_a2);
   output_high(PIN_a3);
   
   output_low(PIN_e0);
   output_high(PIN_e1);  //Led amarillo activa
   output_low(PIN_e2);
   
   output_low(PIN_c1);
   output_low(PIN_c2);
   
   while(TRUE){
      derecha = input(pin_a0);
      if(derecha == 0){
         output_high(PIN_e0);   //El led verde se activa
         output_low(PIN_e1);   //El led amarillo se apaga
         output_high(PIN_c1);
         output_low(PIN_c2);
      }
   izquierda = input(pin_a1);
      if(izquierda == 0){
         output_high(PIN_e0);   //El led se activa
         output_low(PIN_e1);   //El led amarillo se apaga
         output_high(PIN_c2);
         output_low(PIN_c1);
      }
      freno = input(pin_a3);
      if(freno == 0){
         output_high(PIN_e1);   //El led se amarillo activa
         output_low(PIN_e0);   //El led verde se apaga
         output_low(PIN_e2);   //El led azul de la velocidad se apaga
         output_low(PIN_c2);
         output_low(PIN_c1);
      }
      freno = input(pin_a2);
      if(freno == 0){
         output_high(PIN_e2);   //El led se amarillo activa
         output_low(PIN_e1);   //El led verde se apaga
         set_pwm2_duty(2000);
      }
   } // FIN DEL WHILE
}
