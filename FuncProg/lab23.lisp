(defun counter (L x)
  (cond ((null L) 0)
        ((equal x (car L)) (+ 1 (counter (cdr L) x)))
        (t  (counter (cdr L) x))))