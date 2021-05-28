#lang racket
(require "lib/number-theory.rkt")

(time (list-ref (sieve 120000) 10000))
