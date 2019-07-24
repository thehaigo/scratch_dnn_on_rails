module Util
  class Converter
    def self.convert_pickle(file)
      pyimport :pickle
      pkl = open(file,'rb')
      weight_numpy  = pickle.load(pkl)
      weight_numpy.map { |k,v| [k,Numo::NArray.cast(deep_convert(v))] }.to_h
    end

    def self.deep_convert(value)
      ary = value.tolist().to_a
      ary.map!{ |a| a.to_a } if ary[0].class.to_s ==  "<class 'list'>"
      ary
    end

    # pixles_ex = dataset.to_tables[:pixels][0]
    def self.pixels_to_image(pixels)
      # convert binary string
      str = Numo::UInt8.cast(pixels * 255).to_string
      img = MiniMagick::Image.import_pixels(str,28,28,8,'gray','png')
      img.write("./public/output.png")
    end
  end
end
