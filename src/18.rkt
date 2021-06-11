#lang racket

(define (read-input)
  (map (λ (s) (map string->number s))
    (map (λ (l) (string-split l " ")) (file->lines "../data/18.txt"))))

(define (get-weight grid i j)
  (list-ref (list-ref grid i) j))

(define (shortest-path grid [i 0] [j 0])
  (if (= i (sub1 (length grid)))
      (get-weight grid i j)
      (+ (get-weight grid i j) (max (shortest-path grid (add1 i) j)
                                    (shortest-path grid (add1 i) (add1 j))))))

(shortest-path (read-input))
