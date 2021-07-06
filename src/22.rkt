#lang racket

(define (read-input) (string-split (file->string "../data/22.txt")))

(define (word-score wl)
  (apply + (map (λ (c) (- (char->integer c)
                          (char->integer #\A) -1)) wl)))

(define (word-scores wls)
  (let loop ([i 1] [a 0] [wls wls])
    (match wls
      ['() a]
      [(cons x xs) (loop (add1 i) (+ a (* i (word-score x))) xs)])))

(word-scores (map string->list
                  (sort (remove-duplicates (read-input)) string<?)))
