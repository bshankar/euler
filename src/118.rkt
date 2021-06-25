#lang racket
(require (only-in math/number-theory prime? factorial)
         data/collection)

(define (valid-set-with? s lv)
  (and (prime? lv) (or (empty? s) (> lv (last s)))))

(define (prime-set-from? perm)
  (let loop ([perm (cdr perm)] [n (car perm)] [current #()] [acc 0])
    (cond
      [(empty? perm) (if (valid-set-with? current n) (add1 acc) acc)]
      [(valid-set-with? current n)
       (+ (loop perm 0 (conj current n) acc)
          (loop (cdr perm) (+ (car perm) (* 10 n)) current acc))]
      [else (loop (cdr perm) (+ (car perm) (* 10 n)) current acc)])))

(define (valid-permutation? p)
  (not (or (even? (last p)) (= (last p) 5))))

(define (pandigital-prime-sets size)
  (define perms (permutations (stream->list (range 1 (add1 size)))))
  (apply + (map prime-set-from? (filter valid-permutation? perms))))

(time (pandigital-prime-sets 9))
