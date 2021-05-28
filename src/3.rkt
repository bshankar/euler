#lang racket

(define (div-to-death n p)
  (if (= 0 (remainder n p)) (div-to-death (/ n p) p) n))

(let loop ([n 600851475143] [p 3])
  (if (>= p n) p (loop (div-to-death n p) (+ p 2))))
