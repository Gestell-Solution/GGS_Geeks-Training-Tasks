#ifndef EXIT_PRIVATE_H_
#define EXIT_PRIVATE_H_

//EICRA_REG interuupt3
#define EXIT_ISC31 7
#define EXIT_ISC30 6
#define EXIT_ISC21 5
#define EXIT_ISC20 4
#define EXIT_ISC11 3
#define EXIT_ISC10 2
#define EXIT_ISC01 1
#define EXIT_ISC00 0
//they work with anyiscnn n represent number
 #define EXIT_lowLevel    0
 #define EXIT_fallingEdge 2
 #define EXIT_risingEdge  3
//EICRB_REG interuupt7
#define EXIT_ISC71 7
#define EXIT_ISC70 6
#define EXIT_ISC61 5
#define EXIT_ISC60 4
#define EXIT_ISC51 3
#define EXIT_ISC50 2
#define EXIT_ISC41 1
#define EXIT_ISC40 0
 #define EXIT_ISC_lowLevel    0
 #define EXIT_ISC_anyLogic    1
 #define EXIT_ISC_fallingEdge 2
 #define EXIT_ISC_risingEdge  3
//eimsk_reg for enable
#define EXIT_INT7 7
#define EXIT_INT6 6
#define EXIT_INT5 5
#define EXIT_INT4 4
#define EXIT_INT3 3
#define EXIT_INT2 2
#define EXIT_INT1 1
#define EXIT_INT0 0
//EIFR_REG for flag
#define EXIT_INTF7 7
#define EXIT_INTF6 6
#define EXIT_INTF5 5
#define EXIT_INTF4 4
#define EXIT_INTF3 3
#define EXIT_INTF2 2
#define EXIT_INTF1 1
#define EXIT_INTF0 0

#define EXIT_INTERRUPT3_3 0
#define EXIT_INTERRUPT3_2 1
#define EXIT_INTERRUPT3_1 2
#define EXIT_INTERRUPT3_0 3
#define EXIT_INTERRUPT7_7 4
#define EXIT_INTERRUPT7_6 5
#define EXIT_INTERRUPT7_5 6
#define EXIT_INTERRUPT7_4 7

#define EXIT_INTERRUPT_Request7 7
#define EXIT_INTERRUPT_Request6 6
#define EXIT_INTERRUPT_Request5 5
#define EXIT_INTERRUPT_Request4 4
#define EXIT_INTERRUPT_Request3 3
#define EXIT_INTERRUPT_Request2 2
#define EXIT_INTERRUPT_Request1 1
#define EXIT_INTERRUPT_Request0 0

#endif