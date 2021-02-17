/*********************************************************************************/
/* Author    : Mario Refaat	                                                         */
/* Version   : V02                                                               */
/* Date      : 8 DEC 2020                                                       */
/*********************************************************************************/


#ifndef SSD_CONFIG_H
#define SSD_CONFIG_H


#define COM_ANOD    0
#define COM_CATHOD  1

/* the SSD Common type   */
/* Options : COM_ANOD
  			 COM_CATHOD  */
#define SSD_COM  COM_ANOD



#if SSD_COM == COM_CATHOD

/*Define number representation for common cathode*/
#define _0 0X3f
#define _1 0x06
#define _2 0x5b
#define _3 0x4f
#define _4 0x66
#define _5 0x6d
#define _6 0x7d
#define _7 0x07
#define _8 0x7f
#define _9 0x6f


#elif SSD_COM == COM_ANOD
/*Define number representation for common anode*/
#define _0 0X03
#define _1 0x9f
#define _2 0x25
#define _3 0x0d
#define _4 0x99
#define _5 0x49
#define _6 0x41
#define _7 0x1f
#define _8 0x01
#define _9 0x09

#endif

#endif
