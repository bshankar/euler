#lang racket
(require "114.rkt")

(define (size-with>=count min-red n)
  (for/first ([s (in-naturals)]
              #:when (> (count-blocks min-red s) n))
    s))

(time (size-with>=count 50 1000000))

(module+ test
  (require rackunit)
  (check-equal? (count-blocks 3 29) 673135)
  (check-equal? (count-blocks 3 30) 1089155)
  (check-equal? (count-blocks 10 56) 880711)
  (check-equal? (count-blocks 10 57) 1148904))
