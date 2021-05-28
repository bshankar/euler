#lang racket

(define (palindrome? s)
  (let loop ([i 0] [j (- (string-length s) 1)])
    (if (>= i j) #t
        (if (equal? (string-ref s i) (string-ref s j))
            (loop (add1 i) (sub1 j)) #f))))

(provide palindrome?)

