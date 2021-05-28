#lang at-exp racket
(require infix)

(define (sum-sqr-minus-sum-of-sqrs n)
  @${(n * n * (n + 1) * (n + 1)) / 4 - (n * (n + 1) * (2 * n + 1) / 6)})

(sum-sqr-minus-sum-of-sqrs 100)
