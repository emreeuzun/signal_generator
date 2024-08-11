#include <REG51.h>
#include <intrins.h>

sbit button1 = P1^0;// Buton için kullanilacak pin
sbit button2 = P1^1;
sbit button3 = P1^2;

unsigned char sine[50] = {52,57,62,66,70,74,77,80,82,84,85,86,86,86,85,83,81,78,75,72,69,65,61,56,52,48,44,39,35,31,28,25,22,19,17,15,14,14,14,15,16,18,20,23,26,30,34,38,43,48};
 
void delay(unsigned int);



void main()
{
	
	 unsigned char dutyCycle = 0;
    unsigned char increment = 5;
	 
    unsigned char index = 0;
	
	if(button1==0)
		{
	 while(button2==1 && button3==1) 
		 {
       P2 = 0x7F;   // Kare dalga yüksek seviyede
        delay(50);

        P2 = 0x00;   // Kare dalga düsük seviyede
        delay(50);
    }
	}

  if(button2==0)
		{
    while(button1==1 && button3==1)
			{
	      P2 = sine[index];
        delay(1);

        index++;
        if (index >= sizeof(sine))
            index = 0;
		 }
	 }
if(button3==0){
	   while(button1==1 && button2==1) 
			 {
           P2 = dutyCycle;
        delay(1);

        dutyCycle += increment;
        if (dutyCycle >= 255)
            increment = -5;
				
        else if (dutyCycle <= 0)
            increment = 5;
				
        }
			}
		}
    
	
void delay(unsigned int ms)
{
    unsigned int i, j;
    for (i = 0; i < ms; i++)
        for (j = 0; j < 112; j++);
}


	

	
	

	

	
	