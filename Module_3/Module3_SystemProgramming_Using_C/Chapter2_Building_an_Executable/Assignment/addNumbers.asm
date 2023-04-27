; -----------------------------------------------------------------------------
; A 64-bit function that returns the maximum value of its three 64-bit integer
; arguments.  The function has signature:
;
;   int64_t addNumbers(int64_t a, int64_t b)
;
; Note that the parameters have already been passed in rdi & rsi.  We
; just have to return the value in rax.
; -----------------------------------------------------------------------------

        global  addNumbers
        section .text
addNumbers:
        mov     rax, rdi                ; mov  a into rax
        adc     rax, rsi                ; rax + b
        ret                             ; the sum will be in rax