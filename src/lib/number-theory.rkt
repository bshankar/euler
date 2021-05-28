#lang at-exp racket
(require infix math/base)
(require data/bit-vector)

(define (ap-sum a n d)
  @${n*(2*a + (n-1)*d) / 2})

(provide ap-sum)

(define (fibs-less-than n)
  (let loop ([acc '(0)] [a 0] [b 1])
    (if (>= a n)
        acc
        (loop (append acc (list b)) b (+ a b)))))

(provide fibs-less-than)

(define (sieve limit)
  (define bv (make-bit-vector (+ limit 1) #f))
  (bit-vector-set! bv 0 #t)
  (bit-vector-set! bv 1 #t)
  (for* ([i (in-range (add1 (sqrt limit)))] #:unless (bit-vector-ref bv i)
         [j (in-range (sqr i) (bit-vector-length bv) i)])
    (bit-vector-set! bv j #t))
  (for/list ([i (bit-vector-length bv)] #:unless (bit-vector-ref bv i)) i))

(provide sieve)
