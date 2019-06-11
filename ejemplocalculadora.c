#include <18f4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=1600000)
 
#define _DEBUG_SERIAL_

#ifdef _DEBUG_SERIAL_
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8, PARITY=N, STOP=1)
   #use fast_io(c)
   
#endif

void main (void){
   setup_oscillator(OSC_16MHZ);
   
      set_tris_a(0xff);
      set_tris_c(0x00);
      set_tris_d(0xff);
      set_tris_b(0xFF);
      set_tris_e(0x7);
      setup_adc_ports(NO_ANALOGS);

      int16 a=0,b=0,d=0,e=0;;
   while(1){
   
     delay_ms(500);
      e=input_e();
      if(e==0xe)
         {
            a=input_b();
            b=input_d();
            d=a+b;
         }
       else if(e==0xd)
         {
            a=input_b();
            b=input_d();
            d=a-b;
            
         }
        else if(e==0xb)
         {
            a=input_b();
            b=input_d();
            d=a*b;
         }
         else if(e==0xc)
         {
            
            a=input_b();
            b=input_d();
            d=a/b;
         }
         else
         d=0;
         
         
         
         
         output_a(d>>8);
         output_c(d);
         
         

   
   }

}
