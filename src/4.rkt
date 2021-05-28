#lang racket

(define (palindrome? n)
  (let ([nl (string->list (number->string n))])
    (equal? nl (reverse nl))))

(apply max (filter palindrome?
            (map (λ (c) (apply * c))
               (combinations (range 101 1000) 2))))
