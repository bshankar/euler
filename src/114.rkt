#lang racket
(require memoize)

(define/memo (count-blocks min-red size)
  (if (< size min-red)
      1
      (add1 (for*/sum ([st (range (- size min-red -1))]
                      [bs (range min-red (- size st -1))])
             (count-blocks min-red (- size st bs 1))))))
(provide count-blocks)

(module* main #f
  (time (count-blocks 3 50)))

(module+ test
  (require rackunit)
  (check-equal? (count-blocks 3 2) 1)
  (check-equal? (count-blocks 3 3) 2)
  (check-equal? (count-blocks 3 4) 4)
  (check-equal? (count-blocks 3 7) 17))
