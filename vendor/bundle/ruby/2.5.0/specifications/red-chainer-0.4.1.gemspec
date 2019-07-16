# -*- encoding: utf-8 -*-
# stub: red-chainer 0.4.1 ruby lib

Gem::Specification.new do |s|
  s.name = "red-chainer".freeze
  s.version = "0.4.1"

  s.required_rubygems_version = Gem::Requirement.new(">= 0".freeze) if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib".freeze]
  s.authors = ["Yusaku Hatanaka".freeze]
  s.bindir = "exe".freeze
  s.date = "2019-04-08"
  s.description = "".freeze
  s.email = ["hatappi@hatappi.me".freeze]
  s.homepage = "https://github.com/red-data-tools/red-chainer".freeze
  s.licenses = ["MIT".freeze]
  s.rubygems_version = "2.7.6".freeze
  s.summary = "A flexible framework for neural network for Ruby".freeze

  s.installed_by_version = "2.7.6" if s.respond_to? :installed_by_version

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_runtime_dependency(%q<numo-narray>.freeze, [">= 0.9.1.1"])
      s.add_runtime_dependency(%q<red-datasets>.freeze, [">= 0.0.6"])
      s.add_development_dependency(%q<bundler>.freeze, [">= 0"])
      s.add_development_dependency(%q<rake>.freeze, ["~> 10.0"])
      s.add_development_dependency(%q<test-unit>.freeze, [">= 3.2.9"])
      s.add_development_dependency(%q<yard>.freeze, [">= 0.9.10"])
    else
      s.add_dependency(%q<numo-narray>.freeze, [">= 0.9.1.1"])
      s.add_dependency(%q<red-datasets>.freeze, [">= 0.0.6"])
      s.add_dependency(%q<bundler>.freeze, [">= 0"])
      s.add_dependency(%q<rake>.freeze, ["~> 10.0"])
      s.add_dependency(%q<test-unit>.freeze, [">= 3.2.9"])
      s.add_dependency(%q<yard>.freeze, [">= 0.9.10"])
    end
  else
    s.add_dependency(%q<numo-narray>.freeze, [">= 0.9.1.1"])
    s.add_dependency(%q<red-datasets>.freeze, [">= 0.0.6"])
    s.add_dependency(%q<bundler>.freeze, [">= 0"])
    s.add_dependency(%q<rake>.freeze, ["~> 10.0"])
    s.add_dependency(%q<test-unit>.freeze, [">= 3.2.9"])
    s.add_dependency(%q<yard>.freeze, [">= 0.9.10"])
  end
end
