#lang at-exp racket
(require infix "lib/lazy-sequences.rkt")

;; a^2 + a^2 - (a - 1) + a^2 - 2(a - 1) + a^2 - 3(a - 1)
;; sum over odd numbers 4a^2 - 6(a-1)

(define (spiral-sum len)
  (add1 (for/sum ([i (range 3 (add1 len) 2)]) @${4 * i * i - 6 * (i - 1)})))

(time (spiral-sum 1001))
