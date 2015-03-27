;*******************************************************************************
;   Lab 5b - traffic.asm
;
;   Description:  1. Turn the large green LED and small red LED on and
;                    delay 20 seconds while checking for orange LED.
;                    (If orange LED is on and 10 seconds has expired, immediately
;                    skip to next step.)
;                 2. Turn large green LED off and yellow LED on for 5 seconds.
;                 3. Turn yellow LED off and large red LED on.
;                 4. If orange LED is on, turn small red LED off and small green
;                    LED on.  After 5 seconds, toggle small green LED on and off
;                    for 6 seconds at 1 second intervals.  Finish by toggling
;                    small green LED on and off for 4 seconds at 1/5 second
;                    intervals.
;                    Else, turn large red LED on for 5 seconds.
;                 5. Repeat the stoplight cycle.
;
;   I, Spencer Wood certify this to be my source code and not obtained from any
;   student, past or current.
;
;*******************************************************************************
;                            MSP430F2274
;                  .-----------------------------.
;            SW1-->|P1.0^                    P2.0|<->LCD_DB0
;            SW2-->|P1.1^                    P2.1|<->LCD_DB1
;            SW3-->|P1.2^                    P2.2|<->LCD_DB2
;            SW4-->|P1.3^                    P2.3|<->LCD_DB3
;       ADXL_INT-->|P1.4                     P2.4|<->LCD_DB4
;        AUX INT-->|P1.5                     P2.5|<->LCD_DB5
;        SERVO_1<--|P1.6 (TA1)               P2.6|<->LCD_DB6
;        SERVO_2<--|P1.7 (TA2)               P2.7|<->LCD_DB7
;                  |                             |
;         LCD_A0<--|P3.0                     P4.0|-->LED_1 (Green)
;        i2c_SDA<->|P3.1 (UCB0SDA)     (TB1) P4.1|-->LED_2 (Orange) / SERVO_3
;        i2c_SCL<--|P3.2 (UCB0SCL)     (TB2) P4.2|-->LED_3 (Yellow) / SERVO_4
;         LCD_RW<--|P3.3                     P4.3|-->LED_4 (Red)
;   TX/LED_5 (G)<--|P3.4 (UCA0TXD)     (TB1) P4.4|-->LCD_BL
;             RX-->|P3.5 (UCA0RXD)     (TB2) P4.5|-->SPEAKER
;           RPOT-->|P3.6 (A6)          (A15) P4.6|-->LED 6 (R)
;           LPOT-->|P3.7 (A7)                P4.7|-->LCD_E
;                  '-----------------------------'
;
;*******************************************************************************
;*******************************************************************************
	            .cdecls  C,LIST,"msp430.h"      ; MSP430

	            .asg    "bis.b #0x08,&P4OUT",RED_ON
	            .asg    "bic.b #0x08,&P4OUT",RED_OFF
	            .asg    "xor.b #0x08,&P4OUT",RED_TOGGLE
	            .asg    "bit.b #0x08,&P4OUT",RED_TEST

	            .asg    "bis.b #0x04,&P4OUT",YELLOW_ON
	            .asg    "bic.b #0x04,&P4OUT",YELLOW_OFF
	            .asg    "xor.b #0x04,&P4OUT",YELLOW_TOGGLE
	            .asg    "bit.b #0x04,&P4OUT",YELLOW_TEST

	            .asg    "bis.b #0x02,&P4OUT",ORANGE_ON
	            .asg    "bic.b #0x02,&P4OUT",ORANGE_OFF
	            .asg    "xor.b #0x02,&P4OUT",ORANGE_TOGGLE
	            .asg    "bit.b #0x02,&P4OUT",ORANGE_TEST

	            .asg    "bis.b #0x01,&P4OUT",GREEN_ON
	            .asg    "bic.b #0x01,&P4OUT",GREEN_OFF
	            .asg    "xor.b #0x01,&P4OUT",GREEN_TOGGLE
	            .asg    "bit.b #0x01,&P4OUT",GREEN_TEST

	            .asg    "bis.b #0x40,&P4OUT",PED_RED_ON
	            .asg    "bic.b #0x40,&P4OUT",PED_RED_OFF
	            .asg    "xor.b #0x40,&P4OUT",PED_RED_TOGGLE
	            .asg    "bit.b #0x40,&P4OUT",PED_RED_TEST

	            .asg    "bis.b #0x10,&P3OUT",PED_GREEN_ON
	            .asg    "bic.b #0x10,&P3OUT",PED_GREEN_OFF
	            .asg    "xor.b #0x10,&P3OUT",PED_GREEN_TOGGLE
	            .asg    "bit.b #0x10,&P3OUT",PED_GREEN_TEST

TWENTY			.equ	200
TEN				.equ	100
ELEVEN			.equ	101
SIX				.equ	60
FIVE			.equ	50
FOUR			.equ	40
ONE				.equ	10
FIFTH			.equ	2
TENTH       	.equ    9530
X5				.equ	5
X20				.equ	20

;------------------------------------------------------------------------------
            	.text                           ; beginning of executable code
            	.retain                         ; Override ELF conditional linking
;-------------------------------------------------------------------------------
start: 		    mov.w   #__STACK_END,SP         ; init stack pointer
	            mov.w   #WDTPW+WDTHOLD,&WDTCTL  ; stop WDT

	            bis.b   #0x08,&P4DIR            ; lights
				bis.b   #0x04,&P4DIR
				bis.b   #0x02,&P4DIR
				bis.b   #0x01,&P4DIR
				bis.b   #0x40,&P4DIR
				bis.b   #0x10,&P3DIR

       			bic.b  	#0x0f,&P1DIR          	; switches
          		bis.b  	#0x0f,&P1OUT
          		bis.b  	#0x0f,&P1REN

				GREEN_OFF						; Light macros
				RED_OFF
				YELLOW_OFF
				ORANGE_OFF
				PED_GREEN_OFF
				PED_RED_OFF

; Green cycle
;-------------------------------------------------------------------------------

green:			GREEN_ON
				PED_RED_ON
				mov.w	#ELEVEN,r14
				mov.w	#TWENTY,r15
green_delay:	bit.b  	#0x02,&P4OUT
					jeq	no_st
				cmp.w	r14,r15
					jge	no_st
				GREEN_OFF
				jmp		yellow
no_st:			call	#tenth
				sub.w	#1,r15
					jnz	green_delay
				GREEN_OFF

; Yellow cycle
;-------------------------------------------------------------------------------

yellow:			YELLOW_ON
				mov.w	#FIVE,r15
yellow_delay:	call	#tenth
				sub.w	#1,r15
					jnz yellow_delay
				YELLOW_OFF

; Red cycle
;-------------------------------------------------------------------------------

red:			RED_ON
				bit.b  	#0x02,&P4OUT   		  ; orange LED on?
            		jeq ped_off               ; n
         		jmp    	ped                   ; y
ped_off:		mov.w	#FIVE,r15
red_delay:		call	#tenth
				sub.w	#1,r15
					jnz red_delay
				RED_OFF
				jmp		green

; Pedestrian cylce
;-------------------------------------------------------------------------------

ped:			ORANGE_OFF
				PED_RED_OFF
				PED_GREEN_ON
				mov.w	#SIX,r15
ped_delay:		call	#tenth
				sub.w	#1,r15
					jnz	ped_delay
				mov.w	#X5,r14
ped_toggle:		mov.w	#ONE,r15
				PED_GREEN_TOGGLE
ped_second:		call	#tenth
				sub.w	#1,r15
					jnz	ped_second
				sub.w	#1,r14
					jnz	ped_toggle
				mov.w	#X20,r14
ped_toggle_2:	mov.w	#FIFTH,r15
				PED_GREEN_TOGGLE
ped_fifth:		call	#tenth
				sub.w	#1,r15
					jnz	ped_fifth
				sub.w	#1,r14
					jnz	ped_toggle_2
				RED_OFF
				jmp		green

; Tenth second delay
;-------------------------------------------------------------------------------

tenth:			push 	r15
				push	r14
				mov.w 	#TENTH,r15
tenth_delay:	mov.b  	&P1IN,r14             ; test switch
          		and.b  	#0x0f,r14
          		xor.b  	#0x0f,r14
            		jeq switch_off
          		bis.b  	#0x02,&P4OUT          ; turn on orange if pressed
switch_off:		sub.w	#1,r15
				  jnz	tenth_delay
				pop		r14
				pop		r15
				ret

;------------------------------------------------------------------------------
; Stack Pointer definition
;------------------------------------------------------------------------------
            	.global __STACK_END
            	.sect 	.stack

;------------------------------------------------------------------------------
; Interrupt Vectors
;------------------------------------------------------------------------------
            	.sect   ".reset"               ; MSP430 RESET Vector
            	.word   start                  ; start address
            	.end
