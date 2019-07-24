module Util
  class Dataset
    def self.load_mnist(type=:all)
      if [:all, :train].include?(type)
        train = Datasets::MNIST.new(type: :train).to_table
        x_train = Numo::NArray.cast(train[:pixels])
        t_train = Numo::NArray.cast(train[:label])
        return x_train, t_train if type == :train
      end
      if [:all, :test].include?(type)
        test  = Datasets::MNIST.new(type: :test).to_table
        x_test  = Numo::NArray.cast(test[:pixels])
        t_test  = Numo::NArray.cast(test[:label])
        return x_test, t_test if type == :test
      end
      return x_train, t_train, x_test, t_test if type == :all
    end
  end
end
