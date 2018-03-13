; determines if @num is a power of two
;
; param num : a positive whole integer
; return    : true if @num is a power of two, false if not
(define (is-power-of-two num)
    (if (integer? num)
        (if (= (& num (- num 1)) 0))
    )
)
