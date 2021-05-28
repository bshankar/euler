#lang racket
(require math/base "lib/number-theory.rkt")

(time (sum (sieve 2000000)))
