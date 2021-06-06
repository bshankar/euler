#lang racket
(require math/number-theory)

(define (lattice-paths n)
  (/ (factorial (* n 2)) (sqr (factorial n))))

(time (lattice-paths 20))
