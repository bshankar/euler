#lang racket
(require math/number-theory)

(define (applicable? p fnext [next (fnext p)])
  (if (prime? next) (applicable? next fnext) (= next 0)))

(define (without-first-digit n)
  (inexact->exact (remainder n (expt 10 (floor (log n 10))))))

(define (truncatable? p)
  (and (applicable? p (λ (p) (quotient p 10)))
       (applicable? p without-first-digit)))

(time (apply + (filter truncatable? (next-primes 19 60000))))
