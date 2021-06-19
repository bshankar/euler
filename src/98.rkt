#lang racket
(require (only-in math/number-theory perfect-square)
         "lib/number-theory.rkt")

(define (read-input)
  (map string->list (string-split (file->string"../data/98.txt"))))

(define (word->number? word digit-map)
  (define digits (map (λ (k) (hash-ref digit-map k)) word))
  (and (positive? (first digits)) (digits->number digits)))

(define (mappings ls width)
  (foldr append '() (map permutations (combinations ls width))))

(define (words->numbers? words mapping ws)
  (define digit-map (for/hash ([w ws] [m mapping]) (values w m)))
  (define number-groups (map (λ (word) (word->number? word digit-map)) words))
  (and (not (member #f number-groups))
       (not (member #f (map perfect-square number-groups)))
       number-groups))

(define (words->squares? words)
  (define ws (list->set (first words)))
  (filter-map (λ (m) (words->numbers? words m ws))
              (mappings (range 0 10) (set-count ws))))

(define (anagram-groups words)
  (filter (λ (g) (> (length g) 1))
          (group-by (λ (e) (sort e char<?)) words)))

(define (max-anagram-square input)
  (apply max (flatten (filter-map words->squares?
                                  (anagram-groups input)))))

(time (max-anagram-square (read-input)))
