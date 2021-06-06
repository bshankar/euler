#lang lazy
(require "lib/lazy-sequences.rkt")

(define (sum-even-fibs limit)
  (apply + (filter even? (takef (λ (i) (< i limit)) Fib))))

(time (!!(sum-even-fibs 4000000)))
