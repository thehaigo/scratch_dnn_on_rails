module Chainer
  module Functions
    module Array
      # Permute the dimensions of an array.
      class Transpose < FunctionNode
        # Permute the dimensions of an input variable without copy.
        #
        # @param [Chainer::Variable] x Input Variable.
        # @param [::Array<Integer>] axes By default, reverse the dimensions,
        #   otherwise permute the axes according to the values given.
        # @return [Chainer::Variable] Variable whose axes are permuted.
        def self.transpose(x, axes: nil)
          Transpose.new(axes: axes).apply([x]).first
        end

        def initialize(axes: nil)
          @axes = axes
        end

        def label
          'Transpose'
        end

        def forward(inputs)
          x = inputs.first
          [x.transpose(*@axes)]
        end

        def backward(indexes, grad_outputs)
          inv_axes = @axes
          if inv_axes
            axes_len = inv_axes.size

            axes = inv_axes.map { |ax| ax % axes_len }
            inv_axes = Numo::NArray[*axes].sort_index.to_a
          end

          Transpose.new(axes: inv_axes).apply(grad_outputs)
        end
      end
    end
  end
end

