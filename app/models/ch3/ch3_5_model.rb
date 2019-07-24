module Ch3
  class Ch35Model < ActiveType::Object
    attribute :network

    def init_network
      self.network = {}
      network[:w1] = Numo::NArray[[0.1, 0.3, 0.5],[0.2,0.4,0.6]]
      network[:b1] = Numo::NArray[0.1,0.2,0.3]
      network[:w2] = Numo::NArray[[0.1,0.4],[0.2,0.5],[0.3,0.6]]
      network[:b2] = Numo::NArray[0.1,0.2]
      network[:w3] = Numo::NArray[[0.1,0.3],[0.2,0.4]]
      network[:b3] = Numo::NArray[0.1,0.2]
    end

    def forward(x)
      x = Numo::NArray.cast(x)
      w1, w2, w3 = network[:w1], network[:w2], network[:w3]
      b1, b2, b3 = network[:b1], network[:b2], network[:b3]

      a1 = x.dot(w1) + b1
      z1 = sigmoid(a1)
      a2 = z1.dot(w2) + b2
      z2 = sigmoid(a2)
      a3 = z2.dot(w3) + b3
    end
  end
end
