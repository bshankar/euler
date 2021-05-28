#lang racket
(require math/base "lib/number-theory.rkt")

(sum (filter (λ(x) (even? x)) (fibs-less-than 4000000)))
