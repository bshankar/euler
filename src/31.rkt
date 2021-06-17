#lang racket
(require memoize)

(define/memo (coin-partitions n coins i)
  (cond
    [(< n 0) 0]
    [(= n 0) 1]
    [(>= i (length coins)) 0]
    [else (+ (coin-partitions (- n (list-ref coins i)) coins i)
             (coin-partitions n coins (add1 i)))]))

(time (coin-partitions 200 '(1 2 5 10 20 50 100 200) 0))
