#lang racket

(define (remove-powers n k)
  (if (= 0 (remainder n k)) (remove-powers (/ n k) k) n))

(define (largest-prime-factor n)
  (let loop ([n n] [k 3])
    (if (>= k n) k (loop (remove-powers n k) (+ k 2)))))

(time (largest-prime-factor 600851475143))
