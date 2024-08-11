ORG 0x0000



MAIN:
    MOV P2, #00H     ; P2 portunu çikis olarak ayarla
     JB P1.0, KARE   ; P1.0 butonu 1 ise atla 0 sa kare etiketine git
    JB P1.1, UCGEN  ; P1.1 butonu 1 ise atla 0 sa ucgen etiketine git
   
    JMP MAIN

 KARE:
    TKR:    LCALL BIRSN
    BIRSN:  MOV R7,#100 ;10000 I 100 KERE TEKRAR EDIP 1 SN OLUCAK
            SJMP TKR
    TKR1:    MOV TMOD,#00000001  ;TIMER0 DA MOD1'E AYARLADIK
            MOV TL0,#LOW(-10000) ;LOW KISMINI -10000 VE HIGH KISMINI -10000 YAPTIK
            MOV TH0,#HIGH(-10000)
            SETB TR0
            JNB TF0,$
            CLR TR0
            CLR TF0
            DJNZ R7,TKR1
            SJMP TKR
        RET
    SJMP MAIN

UCGEN:
    START:   CLR A
 
    INCR:     MOV P2,A
            INC A
            CJNE A,#0FFH,INCR
    DECR:   MOV A,#0FFH
            MOV P2,A
            DEC A
            CJNE A,#00H,DECR
		
			
			
            SJMP START
        RET
  END

