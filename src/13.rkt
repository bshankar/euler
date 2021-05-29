#lang racket

(define nos (map (compose string->number) (file->lines "../data/13.txt")))

(define (first-k-digits n k)
  (string->number (substring (number->string n) 0 k)))

(time (first-k-digits (apply + nos) 10))
