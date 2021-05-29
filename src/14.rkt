#lang racket
(require memoize)

(define/memo (collatz n)
    (cond
      [(= n 1) 1]
      [(even? n) (add1 (collatz (/ n 2)))]
      [else (add1 (collatz (add1 (* 3 n))))]))

(define (longest-collatz-seed limit)
  (define seq (range 2 limit))
  (define chain-lengths (map collatz seq))
  (list-ref seq (index-of chain-lengths (apply max chain-lengths))))

(time (longest-collatz-seed 1000000))
