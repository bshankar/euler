#lang racket
(require math/number-theory)

(define (nth-permutation n len)
  (let loop ([n n] [len (sub1 len)] [res '()] [ds (range len)])
    (define count (factorial len))
    (define q (quotient n count))
    (define f (if (zero? (remainder n count)) (sub1 q) q))
    (define d (list-ref ds f))

    (if (= len 0)
        (append res ds)
        (loop (- n (* count f))
              (sub1 len)
              (append res (list d))
              (remove d ds)))))

(time (nth-permutation 1000000 10))
