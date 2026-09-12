# ATMEGA128 

 

 

 

|DRIVERS | Atmega32 | Atmega128 |
|--------|----------|-----------|
|DIO     | 4 groups {A,B,C,D} |7 groups{A,B,C,D,E,F,G(only 5pins)} |
|vector interrupt|  • It have 4 interrupt vector.            |• It have 7 interrupt vector .      |
| External interrupt |  • It have interrupt 1,0 with its sense. |• It have 4 external interrupt for register A and other 4 for register B  with it sense . | 
| external interrupt request flag|   • It have 3 external interrupt request flag.  |• 1byte for external interrupt flag.|
| genral interrupt                  |    • It have 3 bit for general interrupt flag.   |it doesnt have any bit for it. |
|External Interrupt Mask Register |it doesnt have one .|• 1byte for external interrupt request.      |
|ADC  |It have special function register and it consist of 3bit that are called auto trigger they do certain job when assigned to zero and ones              |   It doesn’t have it a special function register and they are the same in the rest of things           |

  
