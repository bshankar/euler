#lang racket

(define input
  (apply string-append (file->lines "../data/8.txt")))

(define (prod-of-digits n)
  (let loop ([n n] [p 1])
    (if (= n 0) p (loop (quotient n 10) (* p (remainder n 10))))))

(define (prod input i w)
  (prod-of-digits (string->number (substring input i (+ i w)))))

(let ([input input] [w 13])
  (apply max (map (λ(i) (prod input i w)) (range (- (string-length input) w)))))
