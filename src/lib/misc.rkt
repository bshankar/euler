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

(define (descending-suffix-at l [i 0])
  (if (equal? l (sort l >))
      i
      (descending-suffix-at (rest l) (add1 i))))

(define (next-permutation l)
  (let ([i (descending-suffix-at l)])
    (if (zero? i)
        #f
        (let-values ([(xs ys) (split-at l i)])
          (let* ([yss (sort ys <)] [ysf (first yss)] [xl (last xs)])
            (append (take xs (sub1 (length xs)))
                    (list ysf)
                    (list xl)
                    (drop yss 1)))))))

(provide next-permutation)
