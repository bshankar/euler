#lang racket
(require math/base)

(define (fractional-part n)
  (- n (floor n)))

(define (diff p)
  (fractional-part (* (log 2 10) p)))

(define (nth-pow-with-prefix n pf)
  (define lower (fractional-part (log pf 10)))
  (define upper (fractional-part (log (add1 pf) 10)))

  (let loop ([p 1] [count 0] [prev 0])
    (cond
      [(= count n) prev]
      [(or  (< (diff p) lower) (>= (diff p) upper)) (loop (add1 p) count prev)]
      [else (loop (add1 p) (add1 count) p)])))

(module* main #f
  (time (nth-pow-with-prefix 678910 123)))

(module+ test
  (require rackunit)
  (check-equal? (nth-pow-with-prefix 1 12) 7)
  (check-equal? (nth-pow-with-prefix 2 12) 80)
  (check-equal? (nth-pow-with-prefix 45 123) 12710))
