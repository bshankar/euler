#lang racket
(require "lib/grid.rkt")

(define (read-grid)
  (map (compose (λ (l)  (map string->number l)) string-split)
       (file->lines "../data/11.txt")))

(define (get-grid-values grid keys)
  (map (λ (key) (match key
                  [(list x y) (list-ref (list-ref grid x) y)]
                  [else #f]))
       keys))

(define (max-product grid window)
  (define width (length grid))
  (define groups
    (for*/list ([i (range width)] [j (range width)])
      (map (λ (l) (apply * l))
           (map (λ (k) (get-grid-values grid k))
                (possible-indices i j window width)))))
  (apply max (flatten groups)))

(time (max-product (read-grid) 4))
