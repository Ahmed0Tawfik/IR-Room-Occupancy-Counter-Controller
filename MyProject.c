sbit SensorIN at PORTB.B4;
sbit SensorOUT at PORTB.B5;

int Counter = 0;
char State = 0;
int OverFlows = 0;
int OverFlows_counter = 0;

double Time0OverFlows(int time)
{
    double overflowtime = 0.032768;
    double result = ceil(time / overflowtime);
    return result ;
}
void main() {

     OverFlows = Time0OverFlows(1); // Configure overflow for timeouts
     TRISB = 0b11111110; //pin 0 output
     TRISD = 0;
     INTCON.RBIE = 1;
     INTCON.GIE = 1;
     INTCON.TMR0IE = 1;
     OPTION_REG = 0b00000111; // Prescalar 256 only
     PORTB = 0;
     PORTD = 0;
     TMR0 = 0;

     


     while(1)
     {

         PORTD = Counter;
         
         if(Counter > 0) PORTB.B0 = 1;
         else PORTB.B0 = 0;
         
         if(State != 0)
         {

             if(OverFlows <= OverFlows_counter)
             {

                          OverFlows_counter = 0;
                          State = 0;
                          
                          
             }
         }

     }
}


void interrupt()
{
    if (INTCON.RBIF == 1)
    {
        delay_ms(50);

        switch(State)
        {
            case 0:
                if (SensorIN == 1)
                {
                   State = 1;
                   OverFlows_counter = 0;
                   
                }
                if (SensorOUT == 1)
                {
                   State = 2;
                   OverFlows_counter = 0;
                   
                }
                break;

            case 1:
                if (SensorOUT == 1) {
                    Counter++;
                    State = 0;
                }
                break;

            case 2:
                if (SensorIN == 1) {
                    if(Counter != 0) Counter--;
                    State = 0;
                }
                break;
        }

        INTCON.RBIF = 0;
    }

    if(INTCON.TMR0IF == 1)
    {
                     OverFlows_counter++;
                     INTCON.TMR0IF = 0;
                     TMR0 = 0;
    }
    
}