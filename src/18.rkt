#lang racket
(require memoize)

(define (read-input [path "../data/18.txt"])
  (map (λ (s) (map string->number s))
    (map (λ (l) (string-split l " ")) (file->lines path))))
(provide read-input)

(define (get-weight grid i j)
  (list-ref (list-ref grid i) j))

(define/memo (shortest-path grid i j)
  (if (= i (sub1 (length grid)))
      (get-weight grid i j)
      (+ (get-weight grid i j)
         (max (shortest-path grid (add1 i) j)
              (shortest-path grid (add1 i) (add1 j))))))
(provide shortest-path)

(module* main #f
  (time (shortest-path (read-input) 0 0)))
