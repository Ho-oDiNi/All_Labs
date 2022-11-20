(defun cut (L x y)
  (cond ((or (null L) (zerop y)) nil)
        ((= x 1) (cons (car L) (cut (cdr L) 1 (1- y))))
        ((cut (cdr L) (1- x) y))))