#lang racket
(require math/base "lib/number-theory.rkt")

(define (sum-even-fibs limit)
  (sum (filter (λ(x) (even? x)) (fibs-less-than limit))))

(time (sum-even-fibs 4000000))
