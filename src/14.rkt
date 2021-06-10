#lang racket/base
(require racket/list memoize)

(define/memo (collatz n)
    (cond
      [(= n 1) 1]
      [(even? n) (add1 (collatz (quotient n 2)))]
      [else (add1 (collatz (add1 (* 3 n))))]))

(define (longest-collatz-seed limit)
  (argmax collatz (range 2 limit)))

(time (longest-collatz-seed 1000000))
