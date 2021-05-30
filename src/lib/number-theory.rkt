#lang at-exp racket
(require infix math/base data/bit-vector racket/trace)

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
  (define lim (add1 (quotient (integer-sqrt limit) 2)))
  (define bv (make-bit-vector (quotient (- limit 3) 2) #f))
  (for* ([i (in-range lim)] #:unless (bit-vector-ref bv i)
         [j (in-range @${2*i*i + 6*i + 3} (bit-vector-length bv) @${2*i + 3})])
    (bit-vector-set! bv j #t))
  (cons 2 (for/list ([i (bit-vector-length bv)] #:unless (bit-vector-ref bv i)) @${2*i + 3})))

(provide sieve)

(define (digit-sum n)
  (let loop ([n n] [sum 0])
    (if (= n 0)
        sum
        (loop (quotient n 10) (+ sum (remainder n 10))))))

(provide digit-sum)

(define (smallest-prime-factor n)
  (findf (λ (d) (= 0 (remainder n d))) (sieve (add1 (integer-sqrt n)))))

(provide smallest-prime-factor)

(define (euler-phi n)
  (let ([f (smallest-prime-factor n)])
    (if (false? f)
        (sub1 n)
        (let ([m f] [n (/ n f)])
          (/ (* (sub1 m) (euler-phi n)))))))

(provide euler-phi)

(define (pow-of-factor n k)
  (let loop ([pow 0] [n n])
    (if (= 0 (remainder n k))
      (loop (add1 pow) (/ n k))
      pow)))

(define (count-divisors n)
  (let ([f (smallest-prime-factor n)])
    (if (false? f)
        (if (= n 1) 1 2)
        (let ([pow (pow-of-factor n f)])
          (* (add1 pow) (count-divisors (quotient n (expt f pow))))))))

(provide count-divisors)

(define (triangular-number n) @${n*(n+1)/2})
(provide triangular-number)

(define (bisect f a b result [eps 1e-8])
  (let ([c (/ (+ a b) 2)])
    (cond
      [(> (- (f c) eps) result) (bisect f a c result)]
      [(< (+ (f c) eps) result) (bisect f c b result)]
      [else c])))

(provide bisect)
