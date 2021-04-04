unsigned char clk;
void Pulso();

void main()
{
  TRISD=0;
  PORTB=0;
  
  while (8)
  {
   Portd.Rd1=1;
   Portd.Rd0=1;
   Portd.Rd0=0;
   delay_ms(400);

   clk=14;
   while (clk)
        {
         Pulso();
        }
        
   Portd.Rd1=0;
   Portd.Rd0=0;
   Portd.Rd0=1;

   }
}

void Pulso()
{
 PortD.Rd0=~PortD.Rd0;
 delay_ms(250);
 clk--;
}