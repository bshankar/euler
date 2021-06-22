#lang racket
(require data/collection math/number-theory)

(define (sum-even-fibs limit)
  (for/sum ([i (map fibonacci (naturals))]
            #:when (even? i)
            #:break (> i limit))
    i))

(time (sum-even-fibs 4000000))
