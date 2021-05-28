#lang racket
(require "lib/number-theory.rkt")

(-
 (+ (ap-sum 3 (floor 999/3) 3) (ap-sum 5 (floor 999/5) 5))
 (ap-sum 15 (floor 999/15) 15))
