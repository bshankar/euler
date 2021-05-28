#lang racket
(require "lib/number-theory.rkt")

(define (highest-pow-less-than n b)
  (inexact->exact (expt b (floor (log n b)))))

(define (smallest-div-by-1-n n)
  (apply * (map (λ(b) (highest-pow-less-than n b)) (sieve n))))

(time (smallest-div-by-1-n 20))
