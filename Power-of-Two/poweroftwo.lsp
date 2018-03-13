; Determines if @num is a power of two
;
; Determines if @num is a power of two by taking advantage
; of the fact that all powers of two have only a single bit flipped.
; Hence, if the result of a bit-wise 'and' operation on @num and
; @num - 1 results in 0, then the @num is a power of two.
;
; param num : any number
; return    : true if @num is a power of two, nil if not
(define (is-power-of-two-bitwise num)
    (if 
        (= num 0) nil
        (integer? num) (= (& num (- num 1)) 0)
    )
)

; Determines if @num is a power of two
;
; Determines if @num is a power of two by taking advantage
; of the fact that the log base two of any power of two
; will result in a whole number. 
; This method is inaccurate past 274877906944 due to 
; the way the log function handles large integers.
;
; param num : any number
; return    : true if @num is a power of two, nil if not
(define (is-power-of-two-logarithmic num) 
    (if 
        (= num 0) nil
        (= (floor (log num 2)) (log num 2))
    )
)
