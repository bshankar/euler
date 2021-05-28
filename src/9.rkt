#lang at-exp racket
(require infix math/base)


;; a + b + c = s
;; a^2 + b^2 = c^2
;; a + b > c (triangle inequality)
;; => (a + b - s)^2 = a^2 + b^2
;; => a = (2bs - s^2)/2(b-s)
;;
;; abc = ?

(define (to-triplet? b s)
  (let ([a @${(2*b*s - s*s)/(2 * (b-s))}])
    (if (integer? a) (list b a (sqrt (+ (sqr a) (sqr b)))) #f)))

(define (pythagorean-triple-from-sum s)
  (first (filter-map (λ(b) (to-triplet? b s)) (range 1 (quotient s 2)))))

(time (apply * (pythagorean-triple-from-sum 1000)))
