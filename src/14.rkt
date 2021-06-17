#lang racket/base
(require racket/list memoize)

(define/memo (collatz n)
    (cond
      [(= n 1) 1]
      [(even? n) (add1 (collatz (quotient n 2)))]
      [else (add1 (collatz (add1 (* 3 n))))]))

(time (argmax collatz (range 2 1000000)))
