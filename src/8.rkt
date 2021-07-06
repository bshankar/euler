#lang racket
(require "lib/number-theory.rkt")

(define input (apply string-append (file->lines "../data/8.txt")))

(define (prod input i w)
  (apply * (number->digits (string->number (substring input i (+ i w))))))

(define (largest-product input w)
  (let ([input input] [w w])
    (apply max (map (λ(i) (prod input i w))
                    (range (- (string-length input) w))))))

(time (largest-product input 13))
