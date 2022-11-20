(defun rep (x y L)
  (cond ((null L) nil)
        ((equal (car L) x) (cons y (rep x y (cdr L))))
        (t (cons (car L) (rep x y (cdr L))))))