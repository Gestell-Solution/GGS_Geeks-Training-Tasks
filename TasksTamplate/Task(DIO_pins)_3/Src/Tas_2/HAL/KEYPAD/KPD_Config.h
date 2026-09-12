#ifndef _KPD_CONFIG_H
#define _KPD_CONFIG_H
#pragma once
#include "../../MCAL/DIO/DIO_Private.h"
#include "KPD_Private.h"

//ROWPIN
#define kpd_R0Pin   Dio_Pin0
#define kpd_R1Pin   Dio_Pin1
#define kpd_R2Pin   Dio_Pin2
#define kpd_R3Pin   Dio_Pin3
//ROWGROUP
#define kpd_R0Group   Dio_GroupC
#define kpd_R1Group   Dio_GroupC
#define kpd_R2Group   Dio_GroupC
#define kpd_R3Group   Dio_GroupC 
//==========================================================//
//COLOMPIN
#define kpd_C0Pin   Dio_Pin4
#define kpd_C1Pin   Dio_Pin5
#define kpd_C2Pin   Dio_Pin6
#define kpd_C3Pin   Dio_Pin7
//COLOMGROUP
#define kpd_C0Group   Dio_GroupC
#define kpd_C1Group   Dio_GroupC
#define kpd_C2Group   Dio_GroupC
#define kpd_C3Group   Dio_GroupC
//=========================================================//


#define kpd_keyvalue { \
    {'1','2','3','A'}, \
    {'4','5','6','B'}, \
    {'7','8','9','C'}, \
    {'E','0','X','D'} }




#endif