#lang racket

(define (palindrome? s)
  (let loop ([i 0] [j (- (string-length s) 1)])
    (if (>= i j) #t
        (if (equal? (string-ref s i) (string-ref s j))
            (loop (add1 i) (sub1 j)) #f))))

(provide palindrome?)

(define (item-frequencies l)
  (for/hash ([i (list->set l)]) (values i (count (λ(e) (equal? e i)) l))))

(provide item-frequencies)

(define (choose-item cc k)
  (define v (hash-ref cc k))
  (if (= v 1)
      (hash-remove cc k)
      (hash-set cc k (sub1 v))))

(define (permutations-with-repeating l max-size [acc '()])
  (let loop ([cc (item-frequencies l)] [current '()])
    (if (= (length current) max-size)
        (set! acc (cons current acc))
        (for/list ([k (hash-keys cc)])
          (loop (choose-item cc k) (cons k current)))))
  acc)

(provide permutations-with-repeating)
