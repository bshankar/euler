#lang racket
(require memoize)

(define/memo (collatz n)
    (cond
      [(= n 1) 1]
      [(even? n) (add1 (collatz (quotient n 2)))]
      [else (add1 (collatz (add1 (* 3 n))))]))

(define (longest-collatz-seed limit)
  (let* ([chain-lengths (build-vector limit (λ(i) (+ 2 i)))])
    (+ 2 (vector-argmax collatz chain-lengths))))

(time (longest-collatz-seed 1000000))
