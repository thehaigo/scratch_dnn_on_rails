module Ch3
  class NeuralnetMnist < ActiveType::Object
    attribute :x_test
    attribute :t_test
    attribute :network

    def get_data
      self.x_test, self.t_test = Util::Dataset.load_mnist(:test)
    end

    def init_network
      self.network = Util::Converter.convert_pickle("./public/sample_weight.pkl")
    end

    def predict(x)
      w1, w2, w3 = network["W1"], network["W2"], network["W3"]
      b1, b2, b3 = network["b1"], network["b2"], network["b3"]
      a1 = x.dot(w1) + b1
      z1 = sigmoid(a1)
      a2 = z1.dot(w2) + b2
      z2 = sigmoid(a2)
      a3 = z2.dot(w3) + b3
      softmax(a3)
    end

    def test
      acc = 0
      x_test.shape[0].times do |i|
        y = predict(x_test[i-1,true]).max_index
        acc += 1 if y == t_test[i-1]
      end
      "Accurancy: #{acc.to_f / x_test.shape[0]}"
    end
  end
end
