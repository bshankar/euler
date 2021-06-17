#lang racket
(require rackunit)

(define (zip . ls)
  (let loop ([ls ls] [res '()])
    (if (ormap empty? ls)
        res
        (loop (map rest ls) (append res (list (map first ls)))))))

(define (within-boundaries i max-width)
  (and  (>= i 0) (< i max-width)))

(define (indices-1d x window max-width f)
  (filter (λ (i) (within-boundaries i max-width))
          (map (λ (i) (f x i)) (range window))))

(define (possible-indices i j window max-width)
  (define left (indices-1d i window max-width -))
  (define right (indices-1d i window max-width +))
  (define down (indices-1d j window max-width +))

  (define right-2d (cartesian-product right (list j)))
  (define down-2d (cartesian-product (list i) down))
  (define diag-2d (zip right down))
  (define anti-diag-2d (zip left down))
  (list right-2d down-2d diag-2d anti-diag-2d))
(provide possible-indices)

(module+ test
  (check-equal? (zip '(1 2) '()) '())
  (check-equal? (zip '(1 2) '(3 4)) (list '(1 3) '(2 4)))
  (check-equal? (zip '(1 2) '(3 4) '(5 6 7)) (list '(1 3 5) '(2 4 6)))

  (check-equal? (possible-indices 0 0 3 5)
                (set '(0 0) '(0 1) '(0 2) '(1 1) '(2 2) '(1 0) '(2 0)))
  (check-equal? (possible-indices 4 0 3 5)
                (set '(4 1) '(4 2) '(3 1) '(2 2) '(4 0))))
