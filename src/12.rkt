#lang racket
(require "lib/number-theory.rkt")

(define (triangular-number-with-divisors d)
  ;; smallest number with 500 divisors is 2^4*3^4*5^4*7*11 = 62370000
  (define approx-c (floor (bisect triangular-number 1 100000 62370000)))
  (let loop ([t (triangular-number approx-c)] [c approx-c])
    (if (> (count-divisors t) d)
       t
       (loop (+ t (add1 c)) (add1 c)))))

(time (triangular-number-with-divisors 500))
