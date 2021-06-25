#lang racket
(require (only-in math/number-theory prime? factorial)
         data/collection)

(define (valid-set-with? s lv)
  (and (prime? lv) (or (empty? s) (> lv (last s)))))

(define (prime-set-from? perm)
  (let loop ([i 1] [n (ref perm 0)] [current #()] [acc 0])
    (cond
      [(= i (length perm)) (if (valid-set-with? current n) (add1 acc) acc)]
      [(valid-set-with? current n)
       (+ (loop i 0 (conj current n) acc)
          (loop (add1 i) (+ (ref perm i) (* 10 n)) current acc))]
      [else (loop (add1 i) (+ (ref perm i) (* 10 n)) current acc)])))

(define (pandigital-prime-sets size)
  (apply + (map prime-set-from?
                (permutations (stream->list (range 1 (add1 size)))))))

(time (pandigital-prime-sets 9))
