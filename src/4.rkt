#lang racket
(require "lib/misc.rkt")

(define (max-palindrome-product low high)
  (apply max (filter (compose palindrome? number->string)
                     (map (λ (c) (apply * c))
                          (combinations (range low high) 2)))))

(time (max-palindrome-product 101 1000))
