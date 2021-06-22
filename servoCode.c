/*Ramon Alonso Sistemas embebidos 4D*/
#include <16F877A.h>                                     //PIC 16F877A
#device ADC=10                                           //Habilitamos el uso del módulo ADC
#fuses XT, NOWDT, PUT, NOLVP, NOPROTECT                  //Bits de configuración
#use delay(clock=4000000)                                //Crista de 4HMz
#use fast_io(A)   
#use fast_io(B)   
#use fast_io(C)

// E0 Amarillo
// E1 Verde
// E2 Rojo


void ledOn(){
   output_high(PIN_e0);   //El led amarillo se activa
}
void ledOff(){
   output_low(PIN_e0);   //El led amarillo se activa
}
void ledBlink(){
   ledOn();
   delay_ms(250);
   ledOff();
   delay_ms(250);
   ledOn();
   delay_ms(250);
   ledOff();
}

void _60_(){
  // Mover a 90º
   output_high(PIN_c0);
   delay_us(1801);
   output_low(PIN_c0);
   delay_ms(20);
}

void _30_(){
   // Mover a 90º
   output_high(PIN_c0);
   delay_us(1645);
   output_low(PIN_c0);
   delay_ms(20);
}

void _00_(){
   // Mover a 90º
   output_high(PIN_c0);
   delay_us(1482);
   output_low(PIN_c0);
   delay_ms(20);
}
void m30(){
   // Mover a 90º
   output_high(PIN_c0);
   delay_us(1300);
   output_low(PIN_c0);
   delay_ms(20);
}
void _45_(){
   // Mover a 90º
   output_high(PIN_c0);
   delay_us(1237);
   output_low(PIN_c0);
   delay_ms(20);
}

int1 derecha;   //izquierda == a0
int1 izquierda;   //derecha == a1
int1 freno;   //freno  == a3

void main(){
   set_tris_a(0b00000000);
   set_tris_c(0);
   set_tris_e(0);
   
   output_high(PIN_a0);
   output_high(PIN_a1);
   output_high(PIN_a2);
   output_high(PIN_a3);
   
   output_low(PIN_e0);
   output_low(PIN_e1);  //Led amarillo activa
   output_low(PIN_e2);
   
   while(TRUE){
      derecha = input(pin_a0);
      if(derecha == 0){
         output_high(PIN_e2);   //El led rojo se activa
          _60_();
         delay_ms(500);
         _00_();
         delay_ms(500);
         _60_();
         delay_ms(500);
         _00_();
         delay_ms(500);
         _60_();
         delay_ms(500);
         _00_();
         delay_ms(500);
         _60_();
         delay_ms(500);
         _00_();
         delay_ms(500);
         _60_();
         delay_ms(500);
         _00_();
         output_low(PIN_e2);   //El led rojo se apaga
         ledBlink();
         delay_ms(250);
         ledblink();
      }
   izquierda = input(pin_a1);
      if(izquierda == 0){
        output_high(PIN_e2);   //El led rojo se activa
        _30_();
         delay_ms(750);
         _00_();
         delay_ms(750);
         _30_();
         delay_ms(750);
         _00_();
         delay_ms(750);
         _30_();
         delay_ms(750);
         _00_();
         delay_ms(750);
         _30_();
         delay_ms(750);
         _00_();
         output_low(PIN_e2);   //El led rojo se apaga
         ledBlink();
         delay_ms(250);
         ledblink();
      }
      freno = input(pin_a2);
      if(freno == 0){
         output_high(PIN_e1);   //El led verde se enciende
         m30();
         delay_ms(750);
         _00_();
         delay_ms(750);
         m30();
         delay_ms(750);
         _00_();
         delay_ms(750);
         m30();
         delay_ms(750);
         _00_();
         delay_ms(750);
         m30();
         delay_ms(750);
         _00_();
         delay_ms(750);
         output_low(PIN_e1);   //El led rojo se apaga
         ledBlink();
         delay_ms(250);
         ledblink();
      }
      freno = input(pin_a3);
      if(freno == 0){
         output_high(PIN_e1);
         _45_();
         delay_ms(750);
         _00_();
         delay_ms(750);
         _45_();
         delay_ms(750);
         _00_();
         delay_ms(750);
         _45_();
         delay_ms(750);
         _00_();
         delay_ms(750);
         _45_();
         delay_ms(750);
         _00_();
         output_low(PIN_e1);   //El led rojo se apaga
         ledBlink();
         delay_ms(250);
         ledblink();
      }
   } // FIN DEL WHILE
}
