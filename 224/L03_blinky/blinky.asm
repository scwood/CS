;*******************************************************************************
;   CS/ECEn 124 Lab 3 - blinky.asm: Software Toggle P1.0
;
;   Description: Quickly blink P1.0 every 10 seconds.  Calculate MCLK, CPI, MIPS
;        Arthor:
;
;             MSP430G5223
;             -----------
;            |       P1.0|-->LED1-RED LED
;            |       P1.3|<--S2
;            |       P1.6|-->LED2-GREEN LED
;
; Show all calculations:
;
;   MCLK = 10,800,423 cycles / 10 = 1,080,042 hz
;    CPI = 10,800,423 cycles/  instructions = 1.5 Cycles/Instruction
;   MIPS = MCLK / CPI / 1000000 = 0.7 MIPS
;
;*******************************************************************************
           .cdecls C,"msp430.h"              ; MSP430

COUNT        .equ    2000                   ; delay count
HUNDRED      .equ    100
TENTH_SECOND .equ    36000
;------------------------------------------------------------------------------
            .text                            ;
;------------------------------------------------------------------------------
start:       mov.w   #0x0280,SP              ; 2
             mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; 4
             bis.b   #0x01,&P1DIR            ; 4

mainloop:    bis.b   #0x01,&P1OUT            ; 5
             mov.w   #COUNT,r15              ; 2
             mov.w   #HUNDRED,r14            ; 2

delayloop:   sub.w   #1,r15                  ; 1
               jnz   delayloop               ; 2
             bic.b   #0x01,&P1OUT            ; 4

hundredloop: mov.w   #TENTH_SECOND,r13       ; 2
			 call    #tenth                  ; 5
			 sub.w   #1,r14                  ; 1
				jnz  hundredloop             ; 2
			 jmp	 mainloop                ; 2

tenth: 		 sub.w   #1,r13                  ; 1
			 	jnz	 tenth                   ; 2
			 ret                             ; 3
;------------------------------------------------------------------------------
;           Interrupt Vectors
;------------------------------------------------------------------------------
            .sect   ".reset"                 ;
            .word   start                    ;
            .end
