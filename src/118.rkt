#lang racket
(require (only-in math/number-theory prime? divides?)
         "lib/number-theory.rkt" racket/trace)

(define (prepend-digit n d)
  (+ n (* d (expt 10 (add1 (inexact->exact (floor (log n 10))))))))

(define (prime-sets? ss)
  (filter (λ (s) (andmap prime? s)) ss))

(define (get perms p i)
  (list-ref (vector-ref perms p) i))

(define (valid-suffix? n)
  (and (odd? n) (not (divides? 5 n))))

(define (prime-append? ls d)
  (for/list ([i (range (length ls))]
             #:when (valid-suffix? (list-ref ls i)))
    (define-values (x y) (split-at ls i))
    (define yf (first y))
    (define ys (rest y))
    (if (or (even? yf) (divides? 5 yf)) '()
        (append x (list (prepend-digit (first y) d)) (rest y)))))

(define (with-digit ls d i)
  (if (empty? ls)
      (list (list d))
      (for/fold ([res '()]) ([l ls])
        (append res
                (prime-append? l d)
                (list (append l (list d)))))))

(define (pandigital-prime-sets digits)
  (define perms (list->vector (permutations (range 1 (add1 digits)))))
  (let loop ([p 0] [i 0] [sets '()] [acc (set)])
    (cond
      [(= p (vector-length perms)) (set-count acc)]
      [(= i digits) (loop (add1 p) 0 '()
                          (set-union
                           acc
                           (list->set (map list->set (prime-sets? sets)))))]
      [else (loop p (add1 i) (with-digit sets (get perms p i) i) acc)])))

(module* main #f
  (time (pandigital-prime-sets 9)))

(module+ test
  (require rackunit)
  (check-equal? (with-digit '() 1) (list '(1)))
  (check-equal? (with-digit (list '(2 3)) 1)
                (list '(21 3) '(2 31) '(2 3 1))))
