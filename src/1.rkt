#lang racket
(require "lib/number-theory.rkt")

(define (sum-multiples limit)
  (-
   (+ (ap-sum 3 (quotient limit 3) 3) (ap-sum 5 (quotient limit 5) 5))
   (ap-sum 15 (quotient limit 15) 15)))

(time (sum-multiples 999))
