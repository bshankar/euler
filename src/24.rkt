#lang racket
(require math/number-theory)

(define (nth-lexicographic-pandigital n [len 10])
  (let loop ([n n] [len (sub1 len)] [res '()]
                   [unseen (range len)]
                   [count (factorial (sub1 len))])

    (define q (quotient n count))
    (define f (if (zero? (remainder n count)) (sub1 q) q))
    (define d (list-ref unseen f))

    (if (= len 0)
        (append res unseen)
        (loop (- n (* count f))
              (sub1 len)
              (append res (list d))
              (remove d unseen)
              (factorial (sub1 len))))))

(time (nth-lexicographic-pandigital 1000000 10))
