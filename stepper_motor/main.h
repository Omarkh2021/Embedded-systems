/*
 * main.h
 *
 *  Created on: Aug 10, 2023
 *      Author: Omar
 */

#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 1000000 /* Define a CPU frequency of 1 Mega Hertz */
#define seg_0 0b00111111
#define seg_1 0b00000110
#define seg_2 0b01011011
#define seg_3 0b01001111
#define seg_4 0b01100110
#define seg_5 0b01101101
#define seg_6 0b01111101
#define seg_7 0b00000111
#define seg_8 0b01111111
#define seg_9 0b01101111

#define seg_0_DP 0b10111111
#define seg_1_DP 0b10000110
#define seg_2_DP 0b11011011
#define seg_3_DP 0b11001111
#define seg_4_DP 0b11100110
#define seg_5_DP 0b11101101
#define seg_6_DP 0b11111101
#define seg_7_DP 0b10000111
#define seg_8_DP 0b11111111
#define seg_9_DP 0b11101111

const u8 segmants[10]={seg_0,seg_1,seg_2,seg_3,seg_4,seg_5,seg_6,seg_7,seg_8,seg_9};
const u8 segmants_DP[10]={seg_0_DP,seg_1_DP,seg_2_DP,seg_3_DP,seg_4_DP,seg_5_DP,seg_6_DP,seg_7_DP,seg_8_DP,seg_9_DP};



#endif /* MAIN_H_ */
