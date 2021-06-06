#lang at-exp lazy
(require infix)

(define Nat (cons 1 (map add1 Nat)))
(define Fib (list* 0 1 (map + Fib (rest Fib))))
(define Tri (map (λ(n) @${n*(n+1)/2}) Nat))

(define (takef f seq)
  (let loop ([seq seq] [e (first seq)] [acc '()])
    (if (f e)
        (loop (rest seq) (second seq) (append acc (list e)))
        acc)))

(provide Nat)
(provide Fib)
(provide takef)
