#lang racket
(require math/base math/number-theory)

;; (1 + 2f)^h (1 - f)^(1000 - h) >= 1B
;; h log(1 + 2f) + (1000 - h) log (1 - f) >= 9
;; h >= (9ln(10) - 1000ln(1 - f))/(ln(1 + 2f) - ln(1 - f))
;;
;; We need to minimize h to maximize probability of getting 1B
;; Once this is done we can compute the probability.

(define (heads-lower-bound fr)
  (/ (- (* 9 (log 10)) (*  1000 (log (- 1 fr))))
     (- (log (add1 (* 2 fr))) (log (- 1 fr)))))

(define (derivative f x [h 1e-6])
  (/ (- (f (+ x h)) (f (- x h))) (* 2 h)))

(define (bisect f a b [eps 1e-12])
  (let loop ([a a] [b b])
    (define c (/ (+ a b) 2))
    (if (< (abs (f c)) eps)
        c
        (cond
          [(or (positive? (f a)) (negative? (f b))) #f]
          [(positive? (f c)) (loop a c)]
          [else (loop c b)]))))

(define h-min
  (inexact->exact
   (ceiling (heads-lower-bound
             (bisect (λ (x) (derivative heads-lower-bound x)) 0.14 0.15)))))

(define (probability h)
  (exact->inexact (/ (for/sum ([i (range h 1001)]) (binomial 1000 i))
                     (expt 2 1000))))

(time (probability h-min))
