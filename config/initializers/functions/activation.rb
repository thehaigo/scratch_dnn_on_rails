def sigmoid(x)
  return 1 / (1 + Numo::NMath.exp(-x))
end

def softmax(a)
  exp_a = Numo::NMath.exp(a)
  sum_exp_a = exp_a.sum
  y = exp_a / sum_exp_a
end
