#lang racket

(define (is-pythagorean-triplet a b c)
  (= (+ (sqr a) (sqr b)) (sqr c)))

(for ([i (in-range 1 1000)])
  (for ([j (in-range (+ i 1) (- 1000 (+ i 1)))])
    (let ([k (- 1000 (+ i j))])
      (if (is-pythagorean-triplet i j k) (display (* i j k)) 0))))
