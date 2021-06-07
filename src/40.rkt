#lang lazy
(require "lib/number-theory.rkt" "lib/lazy-sequences.rkt")

(define Champerowne (foldr (λ (n a) (append (number->digits n) a)) '() Nat))

(define (product-10-pow-places limit)
  (let loop ([ch (take limit Champerowne)] [index 0] [acc 1])
    (if (>= index limit)
        acc
        (loop ch (+ 9 (* 10 index)) (* acc (list-ref ch index))))))

(product-10-pow-places 1000000)
